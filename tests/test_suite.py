#!/nix/store/1q8n6fwvg2najl1hk8cap6999iicrasq-system-path/bin/python

from argparse import ArgumentParser
from pathlib import Path
from dataclasses import dataclass, field
from typing import List

import subprocess as sp
import termcolor
import yaml
import os

@dataclass
class TestCase:
    name: str
    input: str
    retcode: int
    checks: List[str] = field(default_factory=lambda: ["stdout", "stderr", "exitcode"])

OK_TAG = f"[ {termcolor.colored('OK', 'green')} ]"
KO_TAG = f"[ {termcolor.colored('KO', 'red')} ]"

def run_shell(shell: str, stdin: str) -> sp.CompletedProcess:
    return sp.run([shell, "-X", "--parse", stdin], capture_output=True, text=True)

def perform_checks(expected, actual: sp.CompletedProcess):
    assert expected == actual.returncode, \
            f"Exited with {actual.returncode} expected {expected}"

if __name__ == "__main__":
    parser = ArgumentParser("Testsuite")
    parser.add_argument("--binary", required=True, type=Path)
    args = parser.parse_args()

    binary_path = args.binary.absolute()
    print(f"Testing {binary_path}")

    for i in range(1,3):
        for file in os.listdir("samples/tc"+str(i)+"/tests/good"):
            expected = 0
            sh_proc = run_shell(binary_path, "samples/tc1/tests/good/" + file)

            try:
                perform_checks(expected, sh_proc)
            except AssertionError as err:
                print(f"{KO_TAG} {file}\n{err}")
            else:
                print(f"{OK_TAG} {file}")
        for file in os.listdir("samples/tc"+str(i)+"/tests/lex"):
            expected = 2
            sh_proc = run_shell(binary_path, "samples/tc1/tests/lex/" + file)

            try:
                perform_checks(expected, sh_proc)
            except AssertionError as err:
                print(f"{KO_TAG} {file}\n{err}")
            else:
                print(f"{OK_TAG} {file}")
        for file in os.listdir("samples/tc"+str(i)+"/tests/syntax"):
            expected = 3
            sh_proc = run_shell(binary_path, "samples/tc1/tests/syntax/" + file)

            try:
                perform_checks(expected, sh_proc)
            except AssertionError as err:
                print(f"{KO_TAG} {file}\n{err}")
            else:
                print(f"{OK_TAG} {file}")