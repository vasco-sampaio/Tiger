#!/nix/store/1q8n6fwvg2najl1hk8cap6999iicrasq-system-path/bin/python

from argparse import ArgumentParser
from pathlib import Path
from dataclasses import dataclass, field
from typing import List

import subprocess as sp
import termcolor
import yaml
import os

from difflib import unified_diff

@dataclass
class TestCase:
    name: str
    input: str
    retcode: int
    checks: List[str] = field(default_factory=lambda: ["stdout", "stderr", "exitcode"])

OK_TAG = f"[ {termcolor.colored('OK', 'green')} ]"
KO_TAG = f"[ {termcolor.colored('KO', 'red')} ]"

def diff(expected: str, actual: str) -> str:
    expected_lines = expected.splitlines(keepends=True)
    actual_lines = actual.splitlines(keepends=True)
    return ''.join(unified_diff(expected_lines, actual_lines, fromfile='expected', tofile='actual'))

def run_shell(shell: str, stdin: str) -> sp.CompletedProcess:
    return sp.run([shell, "-X", "-o", "--parse", stdin], capture_output=True, text=True)

def run_shellTC2(shell: str, stdin: str) -> sp.CompletedProcess:
    return sp.run([shell, "-o", "-XA", stdin], capture_output=True, text=True)

def perform_checks(expected, actual: sp.CompletedProcess):
    assert expected == actual.returncode, \
            f"Exited with {actual.returncode} expected {expected}"

def compare_code(actual: sp.CompletedProcess, ret):
    assert ret == actual.returncode, \
            f"Exited with {actual.returncode} expected {ret}"

def compare_out(expected, actual: sp.CompletedProcess, ret):
    assert ret == actual.returncode, \
            f"Exited with {actual.returncode} expected {ret}"

    assert expected == actual.stdout, \
            f"stdout differ\n{diff(expected, actual.stdout)}"

if __name__ == "__main__":
    parser = ArgumentParser("Testsuite")
    parser.add_argument("--binary", required=True, type=Path)
    args = parser.parse_args()

    binary_path = args.binary.absolute()
    print(f"Testing {binary_path}")

    for i in range(1,2):
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
    for file in os.listdir("samples/tc2/tests/files"):
            sh_proc = run_shellTC2(binary_path, "samples/tc2/tests/files/" + file)
            try:
                compare_out(open("samples/tc2/tests/res/"+file, "r").read(), sh_proc, 0)
            except AssertionError as err:
                print(f"{KO_TAG} {file} 2\n{err}")
            else:
                print(f"{OK_TAG} {file} 1")
            text_file = open("tmp.tig", "w")
            n = text_file.write(sh_proc.stdout)
            text_file.close()
            sh_proc2 = run_shellTC2(binary_path, "tmp.tig")
            try:
                compare_out(open("samples/tc2/tests/res/"+file, "r").read(), sh_proc2, 0)
            except AssertionError as err:
                print(f"{KO_TAG} {file} 2\n{err}")
            else:
                print(f"{OK_TAG} {file} 2")
    for file in os.listdir("samples/tc2/tests/good"):
            sh_proc = run_shellTC2(binary_path, "samples/tc2/tests/good/" + file)
            try:
                compare_code(sh_proc, 0)
            except AssertionError as err:
                print(f"{KO_TAG} {file} 2\n{err}")
            else:
                print(f"{OK_TAG} {file} 1")
            text_file = open("tmp.tig", "w")
            n = text_file.write(sh_proc.stdout)
            text_file.close()
            sh_proc2 = run_shellTC2(binary_path, "tmp.tig")
            try:
                compare_code(sh_proc2, 0)
            except AssertionError as err:
                print(f"{KO_TAG} {file} 2\n{err}")
            else:
                print(f"{OK_TAG} {file} 2")
