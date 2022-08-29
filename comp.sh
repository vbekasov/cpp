#!/bin/bash

# Compile

rm -f bi_tree_bin;

FLAGS=" -Wall -Wextra -Werror -std=c++20"

c++ main.cpp $FLAGS -o bi_tree_bin;
