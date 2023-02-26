# Linked List

Text

## Proplem Description

Text

## LL Node class

```
class LLNode{
    private:
        char*   val;
        int     ID;
        LLNode*   next;
    public:
        LLNode();
        LLNode(const auto vl);
        void    add_val(const auto vl);
        void    add_val(const char* vl);
        void    add_val(const auto vl[], int sz);
        char*   return_val();
};
```

Class members:
* Private:
  - `char* val;` - value stored in the char (byte) array. Passed argument will be copied to this array, so if you have huge object it will be doubled. Please, remamber to free the memary, if you are not going to use the object outside the LL.
  - `int ID;` - ID of the node.
  - `LLNode* next;` - pointer to the next node.
* Public:
  - `LLNode();` - constructor. Sets <i>val</i> and <i>next</i> to the <i>nullptr</i>.
  - `LLNode(const auto vl);` - constructor. Sets <i>val</i> to vl, and <i>next</i> to the <i>nullptr</i>.
  - `void add_val(const auto vl);` - changes <i>val</i> to <i>vl</i>.
  - `void add_val(const char* vl);` - changes <i>val</i> to <i>"text passed in quotes"</i>.
  - `void add_val(const auto vl[], int sz);` - changes <i>val</i> to array passed by <i>vl[]</i>. <i>int sz</i> - total amount of memary ocupited by the array <i>(sizeof(array))</i>.
  - `char* return_val();` - returns pointer to <i>val</i>.

