#!/bin/sh
# zig as an x86-64 Windows (MinGW ABI, UCRT) C/C++ cross compiler for CMake,
# which wants a compiler path without arguments (cmake/zig-windows.cmake).
tool=${0##*/}
case "$tool" in
    *c++*) exec "${ZIG:-zig}" c++ -target x86_64-windows-gnu "$@" ;;
    *ar*)  exec "${ZIG:-zig}" ar "$@" ;;
    *ranlib*) exec "${ZIG:-zig}" ranlib "$@" ;;
    *rc*)  exec "${ZIG:-zig}" rc "$@" ;;
    *)     exec "${ZIG:-zig}" cc -target x86_64-windows-gnu "$@" ;;
esac
