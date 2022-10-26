

# REWORKING CONCEPT

FUN from main.c to .h class.

Make .so for python.

Make Docker with cpp and python modules running Jupyter Lab in the browser.

Connect it to my https://www.pythonanywhere.com/ projeckt.

try it https://www.khronos.org/api/webgl

Add pyscrypt.

---
## Description

Welcome to my project.

Aim of this project is to show my knowledge in Computer Science. You will see how I use modern C++ technologies,
Python and Shell scripts to solve the Binary Tree problems and analyze its performance.

You will see implementation of this algorithm in Huffman coding.

## Table of Contents
* [Files](#project-files)
* [Linked List](#linked-list-(LL))
* [Serealization](#serealization)
* [Rotation](#primitives)
* [Binary Tree problem](#binary-tree-problem-description-(bt))
* [LL & BT in Python3](py_analog)
* [Set to Tree](#set-to-tree)
* [OpenGL](#openGL)

## Project Files
This project contained files:

* [/nbt](nbt) : directory with header file <b>nbt.h</b> and supdirectories with libraries.
<b>nbt.h</b> header file, that collects BT, LL and Serealization classes to <b>nbt::</b> - namespace binary tree

* [/cpp_src](cpp_src) : C++ source files to be compiled as binaries

* [/py_analog](py_analog) : same projects but on Python3

* [/data](data) : direactory with data files with serealized objects

* [/art](art) : collection of visual files

* [/OpenGl](openGL) : OpenGL directory

* [gen_rand.py](py_analog/gen_rand.py) : Python3 script generating set of random unique integers

* [bt_analise.ipynb](bt_analise.ipynb) : Jupyter Notebook document with algorithm analysis and visualization

* [py_lab.ipynb](py_lab.ipynb) : same functions on Python3

* [school-math.ipynb](school-math.ipynb) : basic functions will be used in the OpenGL project

* [push.sh](push.sh) : script to push project to reposetory <i>$ sh push.sh "Commit Text"</i>

* [py venv](requirements.txt) : requirements for Python venv to run Jupyter-Lab

* [MakeFile](Makefile) : script compiling C++ sources

---
## Linked List (LL)

A Linked List (LL) is a kind of Data Structure, where the next element is pointed by the current. It is not a random access array, but elements still can have their IDs. LLs use much more memory
 (+8 bytes) for each element then arrays, but have some advantages:
 1. Adding a new element to the end or beginning of the list does not require memory reallocation for the whole list, only memory for the new element;
 2. New elements can be inserted or deleted without copying and moving list: <b>A->B => A->C->B</b>; Bigger list you have -- more profit you have;
 3. LL can care mixed data types, which is impossible with <i>standard</i> array in C/C++;
 4. Greater size of element you care -- less difference against the array you have. E.g. you have an object size of 128 bytes. It will be: in the arrey 128 bytes, in the LL 136 bytes. 128~136;
<br><br>
Chart Format: |Linked List ; Array | 

Complexity\Problem |Find Element|Find by ID|Push Forward`|Push Back|Insert   |Replace  |Delete|
-------------------|------------|----------|-------------|---------|---------|---------|------|
<b> Space </b>     |            |          |O(1)/O(n)    |O(1)/O(n)|O(1)/O(n)|O(1)/O(1)|RanD  |
<b> Time </b>      | O(n)/O(n)  |O(n)/O(1) |O(1)/O(n)    |O(n)/O(n)|O(n)/O(n)|O(n)/O(1)|RanD  |
<b> Performance</b>| same       |✘/✔       |✔/✘          |✔/✘      |✔/✘      |✘/✔      |RanD  |

` Push Forward : works extremely slow with array and vary rapid in LL. To add an element at the beginning of the array OS have to reallocate all array. To push the element forward at the beginning of the LL program will only allocate the memory for the new element, and rewrite the root pointer.

Classes you can find in [LL header directory.](nbt/ll_head)

---
## Serealization

To save, transmit and load BT we use serealization. Serealization library saves all/any object which was constructed in the memory allocated by char (byte) array. Like in this [manual.](https://www.ibm.com/docs/en/i/7.3?topic=only-destructors-c)

```
#include <new>
#include <iostream>
using namespace std;
class A {
  public:
    A() { cout << "A::A()" << endl; }
    ~A() { cout << "A::~A()" << endl; }
};
int main () {
  char* p = new char[sizeof(A)];
  A* ap = new (p) A;
  ap->A::~A();
  delete [] p;
}
```
To restore the BT, and objects saved there, we need to have the size and type of an object. Size is stored and saved first in <i>int o_len;</i> format. After that goes <i>unsigned char et;</i> variable representing type of object. Next, we have an array of bytes storing the object. One object is stored in format:<br>
* <b>Size of Object</b> - four bytes
* <b>Element Type</b> - one byte
* <b>Array of Bytes</b> - object

As any object is represented in the memory as a structure of the variables, methods of class are stored separately, we can write and read objects represented in the byte array.

---
## Primitives

2D/3D [primitives](nbt/prim_head/) disigned to use with [OpenGL](openGL/). Potantionaly would by used with different C++ framework. 

---
## Binary Tree Problem Description (BT)

Binary Tree (BT) is a kind of graph, and definition you can find on [Wiki.](https://en.wikipedia.org/wiki/Binary_tree#Definitions)
I wanted to show how I had solved this problem using C++20. You will find algorithm analysis and visualization using Python and SQLite3 as well.

You will see realization of this probleblem using structure and class.

<br>

### Binary Tree based on structure
My algorithm uses an unsorted set of integers as input, sorting them and converting it to the tree. But during the tree generation
the program makes some duplicates. You can find more information about that step [here.](#set-to-tree-(structure))

### Set to Tree (structure)

To generate sets of random unique integers I have used [gen_rang.py.](py_analog/gen_rand.py) There are two ways you can get sets: print to stdout or return NumPy array of sets. You can find implementation of set-to-tree algorithm in [st_bt.hpp](nbt/tree_head/st_bt.hpp) in <i><b>tb_node* gen_tree(int* iarr, int start, int finish)</b></i> function. How it works you can find in [Jupyter file.](bt_analise.ipynb)

---
### OpenGL
<br>

https://www.opengl.org/
<br>
In the [OpenGL](/openGL) directory, you can find the <i>main.cpp</i> source code file using the <b>nbt::Rot</b> class. This program displays several animated primitives in 2D/3D. Movement depends on $Δt$ inside an infinite loop.<br>
$f(Δt)= x + Δt*const$<br><br>

In case OpenGL is a cross-platform framework, please mind, FPS or refresh rate could be locked on diffirent [devices.](https://support.apple.com/en-us/HT210742)

And please, remamber the float rounding error!!! $(0.2-0.2)>0 AND (0.8+0.2)>1$; Not only $0.1+0.3$ problem. Use inegers to find the coordinates first, then covert it into the pixels positions on your devices.
