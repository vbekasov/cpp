# Linked List Header

<b>tl.h</b> is a top LL header. It collects all support <i>*.hpp</i> headers, and only this one should be included in your <i>cpp</i> file.

## Table of Contents
* [Files](#project-files)
* [State of LL Project](#current-state)
* [Next Steps](#next-steps)
* [LL Methods](#ll-class-methods)
* [Implementation](#implementation)

### Project Files

This library contained files:

* [tl.h](tl.h) : header file only one has to be included in your project
* [st_ns.hpp](st_ns.hpp) : struct namespace. Header with structure used in <i>LinkedList</i> class. Functions to be overloaded to determine classes in the linked list. Objects and variables stored in <i>ClassData</i> are written in this structure. To copy struct content and destuct struct, change st_node::et to '+' after copying and before call destructor.
* [cl_ll_ns.hpp](cl_ll_ns.hpp) : class LinkedList in namespace. Header with <i>LinkedList</i> class. Usage you can find in [implementation.](#implementation)
* [cl_fun_over.hpp](cl_fun_over.cpp) : classes and functions to be overloaded by user.
* [cl_dt_ns.hpp](cl_dt_ns.hpp) : class data namespace. Template <i>ClassData</i> to store variables and classes.


## Current State

LL multiple data, operator[], basic LL function

## Next steps

Save and load LL

## LL class methods

Public methods:
* `template< typename T> void push_back(T add_val);`<br>
This function receives any argument and add it at the end of LL.
* <i>template< typename T> void push_forword(T add_val);</i><br>
This function receives any argument and add it at tne begining of LL.
* <i>template< typename T> T ret_object(size_t num = 0);</i><br>
This template function receives < datatype> and element number, and returns object.
* <i>size_t ll_length();</i><br>
This function returns length of LL.
* <i>void print_val(size_t num = 0);</i><br>
This function prints element if it is char, int, double or string. Otherwise prints "Object".
* <i>void print_ll();</i><br>
This function prints all LL elements if it is char, int, double or string. Otherwise prints "Object".
* <i>template< typename T> void   l_insert(size_t pos, T insert);</i><br>
This function inserts an element to the LL after position. Position >= 0. If <i>pos>length</i> of the LL function does nothing.

## Implementation

To enter string use <b>std::string temp = "TEXT";</b> or use <b>rs("TEXT")</b> function.