# Linked List Header

<b>tl.h</b> is a top LL header. It collects all support <i>*.hpp</i> headers, and only this one should be included in your <i>cpp</i> file.

## Table of Contents
* [Files](#project-files)
* [State of LL Project](#current-state)
* [Next Steps](#next-steps)
* [Implementation](#implementation)

### Project Files

This library contained files:

* tl.h : header file only one has to be included in your project
* st_ns.hpp : struct namespace. Header with structure used in <i>LinkedList</i> class. Functions to be overloaded to determine classes in the linked list. Objects and variables stored in <i>ClassData</i> are written in this structure.
* cl_ll_ns.hpp : class LinkedList in namespace. Header with <i>LinkedList</i> class. Usage you can find in [implementation.](#implementation)
* cl_fun_over.hpp : classes and functions to be overloaded by user.
* cl_dt_ns.hpp : class data namespace. Template <i>ClassData</i> to store variables and classes.


## Current State

LL saves char double int string in root, and prints out data

## Next steps

Object templates

Save and load LL

User defined objects

## Implementation

To enter string use <b>std::string temp = "TEXT";</b> or use <b>rs("TEXT")</b> function.