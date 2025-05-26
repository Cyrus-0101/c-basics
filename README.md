# C Basics

This repository contains my journey learning C programming through various resources:
- The C Programming Language (K&R)
- Linux man pages
- Open source projects on GitHub

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