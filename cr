#!/usr/bin/env bash

clang $1 -o $1.out && ./$1.out
