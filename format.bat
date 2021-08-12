@echo off
set back=%cd%
for /d %%i in (Z:\GithubRepositories\Algorithms\CPP\*) do (
    cd "%%i"
    echo "%%i":
    clang-format -style=microsoft -i *.cpp --verbose
    clang-format -style=microsoft -i *.h --verbose
    clang-format -style=microsoft -i *.c --verbose
)
cd %back%