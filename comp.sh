#!/bin/bash

# Compile

rm -f bi_tree_bin;

FLAGS=" -Wall -Wextra -Werror -std=c++20"

c++ dups.cpp $FLAGS -o gen_bi_tree;
