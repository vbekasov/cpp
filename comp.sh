#!/bin/bash

# Compile

rm -f ts;

FLAGS=" -Wall -Wextra -Werror -std=c++20"

c++ main.cpp $FLAGS -o bi_tree_bin;
