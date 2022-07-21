# Toy Robot Sample
Sample console program simulating a toy robot

Tools used
-------------
1. [Visual Studio Code](https://code.visualstudio.com/)
2. [MSYS2](https://www.msys2.org/) 
3. [CMake](https://cmake.org/)
4. [Doctest](https://github.com/doctest/doctest)

Setting up
-------------

1. Install Visual Studio Code
    1. After installation, open Visual Studio Code from the start menu
    2. Once opened, look for Extensions on the left panel and search for C++ and CMake extensions

2. Install MSYS2 for the MinGW-w64 toolchain
    1. After installation, open MSYS2 shell from start menu
    2. Run `pacman -Sy pacman` to update the package database
    3. Re-open the shell, run `pacman -Syu` to update the package database and core system packages
    4. Re-open the shell, run `pacman -Su` to update the rest
    5. Run `pacman -S mingw-w64-x86_64-toolchain` to install the compiler
    6. Select which package to install, default is all
    7. Open a terminal, run `g++ --version`.
        - If not working, include the compiler path (default: _C:\msys64\mingw64\bin_) to PATH environment variable
    9. Go to compiler path and copy mingw32-make.exe to the same folder and rename it as make.exe

3. Install CMake
    - After installation, run `cmake --version`.
        - If not working, include the cmake path (default: _C:\Program Files\CMake\bin_) to PATH environment variable
  
How to build the application
-------------

1. On Visual Studio Code, go to File > Open Folder, navigate and select the topmost directory of the source code (with the CMakeLists.txt file)
2. Go to Terminal > New Terminal, run `cmake -S . -B bin -G "MinGW Makefiles"`
3. Run `cmake --build .\bin\` to generate the executable files
    - Run `.\bin\run_tests.exe` to run the unit tests
    - Run `.\bin\run_app.exe <path\to\input\file>` to run the application. Sample input files are located in _tst\input_samples_

Folder structure
-------------
- \lib - contains 3rd party libraries. Only doctest should be here.
- \src - contains the source code
- \tst - contains the test cases
- \tst\input_samples - contains sample inputs used for testing

