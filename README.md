
## REWORKING CONCEPT

FUN from main.c to .h class.

Make .so for python.

Make Docker with cpp and python modules running Jupyter Lab in the browser.

Connect it to my https://www.pythonanywhere.com/ projeckt.

Add pyscrypt.

## Description

Welcome to my project. 

Aim of this project is to show my knowledge in Computer Science. You will see how I use modern C++ technologies,
Python and Shell scripts to solve the Binary Tree problems and analyze its performance.

You will see implementation of this algorithm in Huffman coding.

## Table of contents
* [Files](#project-files)
* [Binary Tree problem](#problem-description)
* [Set to Tree](#set-to-tree)


## Project Files

This project contained files:

* bin_tree.h : header file with with Binary Tree class and support functions in
        namebi - namespace binary tree

* dups.cpp : C++ file with main function generating and printing binary tree

* MakeFile : script compiling C++ sources
    
* gen_rand.py : Python3 script generating set of random unique integers

* check_dup.sh : Shell script running binary with random integers

* dup_fun.ipynb : Jupyter Notebook document with algorithm analysis and visualization

## Problem Description

Binary Tree is a kind of graph, and definition you can find on [Wiki](https://en.wikipedia.org/wiki/Binary_tree#Definitions).
I wanted to show how I had solved this problem using C++20. You will find algorithm analysis and visualization using Python and SQLite3 as well.

My algorithm uses an unsorted set of integers as input, sorting them and converting it to the tree. But during the tree generation
the program makes some duplicates. You can find more information about that step [here](#set-to-tree).

## Set to Tree

To generate sets of random unique integers I use <i>gen_rang.py</i>. There are two ways you can get sets: print to stdout or
return NumPy array of sets. You can find implementation of set-to-tree algorithm in <i>bi_tree.h</i> in 
<i><b>tb_node* gen_tree(int* iarr, int start, int finish)</b></i> function. How it works you can find in 
[Jupyter file](dup_fun.ipynb).
