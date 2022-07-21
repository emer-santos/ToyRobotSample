# Toy Robot Sample
Sample console program simulating a toy robot

Tools used
-------------
1. Visual Studio Code (https://code.visualstudio.com/)
2. MSYS2 (https://www.msys2.org/) 
3. CMake (https://cmake.org/)
4. Doctest (https://github.com/doctest/doctest)

Setting up
-------------

1. Install Visual Studio Code
  1.a Open Visual Studio Code from the start menu
  1.b Once opened, look for Extensions on the left panel and search for C++ and CMake extensions

2. Install MSYS2 for the MinGW-w64 toolchain
  2.a After installation, open MSYS2 shell from start menu
  2.b Run pacman -Sy pacman to update the package database
  2.c Re-open the shell, run pacman -Syu to update the package database and core system packages
  2.d Re-open the shell, run pacman -Su to update the rest
  2.e Run pacman -S mingw-w64-x86_64-toolchain to install the compiler
  2.f Select which package to install, default is all
  2.g Open a terminal, run g++ --version. If not working, include the compiler path (default: C:\msys64\mingw64\bin) to PATH environment variable
  2.h Go to compiler path and copy mingw32-make.exe to the same folder and rename it as make.exe

3. Install CMake
  3.a After installation, run cmake --version. If not working, include the cmake path (default: C:\Program Files\CMake\bin) to PATH environment variable
  
How to build the application
-------------

1. On Visual Studio Code, go to File > Open Folder, navigate and select the topmost directory of the source code (with the CMakeLists.txt file)
2. Go to Terminal > New Terminal, run cmake -S . -B bin -G "MinGW Makefiles"
3. Run cmake --build .\bin\ to generate the executable files
3.a Run .\bin\run_tests.exe to run the unit tests
3.b Run .\bin\run_app.exe <path\to\input\file> to run the application. Sample input files are located in tst\input_samples


