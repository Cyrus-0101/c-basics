# C Basics

This repository contains my journey learning C programming through various resources:
- The C Programming Language (K&R)
- Linux man pages
- Open source projects on GitHub

## Getting Started
Our application entrypoint is `main_menu.c`, which runs the applications
built. 
1. Create an outputs folder.
2. Build all your projects, individually (TO-DO: Add build-all script)

```sh
    # Example build and run (test) script.
    clang -o ./outputs/word_length_vertical_histogram ./arrays/word_length_vertical_histogram.c && ./outputs/word_length_vertical_histogram
```

3. Build main-menu and run, with the same script (minding the dirs).You should see 
something like this:

```sh
    🔥 Mini Tool Suite 🔥
    -----------STRING OPS----------------
    1. Celsius to Fahrenheit Table
    2. Character Count
    3. Word Count
    4. Word Per Line

    ----------ARRAY OPS----------------
    5. Count Frequencies (Histogram)
    6. Word Length (Vertical Histogram)

    -----------POINTER OPS-------------
    7. Function Pointers Demo

    -----------------------------------
    0. Exit
    Choose a program to run: 
```

## Topics Covered

### Function Pointers
Function pointers are variables that store the address of a function. They allow:
- Dynamic function calls at runtime
- Callbacks implementation
- Plugin architectures
- Strategy pattern implementation

#### Compile Script
```sh
    clang function-pointer.c -o function-pointer 
    # or if you use gcc
    gcc function-pointer.c -o function-pointer
```

#### Debug Script
To trace system calls:
```sh
    strace -f ./function-pointer
```

The server will listen on `0.0.0.0:8181`

#### Run Script
Start the server:
```sh
    ./function-pointer
```
In another terminal tab use telnet to send a request:
```sh
env - telnet localhost 8181
# Send some data and get back a generic response
```