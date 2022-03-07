#!/nix/store/1q8n6fwvg2najl1hk8cap6999iicrasq-system-path/bin/python

from argparse import ArgumentParser
from pathlib import Path
from dataclasses import dataclass, field
from typing import List

import subprocess as sp
import termcolor
import yaml

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

def perform_checks(expected, actual: sp.CompletedProcess, checks):
    assert "exitcode" not in checks or expected == actual.returncode, \
            f"Exited with {actual.returncode} expected {expected}"

if __name__ == "__main__":
    parser = ArgumentParser("Testsuite")
    parser.add_argument("--binary", required=True, type=Path)
    args = parser.parse_args()

    binary_path = args.binary.absolute()
    print(f"Testing {binary_path}")

    with open("tests.yml", "r") as file:
        testsuite = [TestCase(**testcase) for testcase in yaml.safe_load(file)]

    for testcase in testsuite:
        stdin = testcase.input
        name = testcase.name
        expected = testcase.retcode
        sh_proc = run_shell(binary_path, stdin)

        try:
            perform_checks(expected, sh_proc, testcase.checks)
        except AssertionError as err:
            print(f"{KO_TAG} {name}\n{err}")
        else:
            print(f"{OK_TAG} {name}")
