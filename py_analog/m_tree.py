class Node:
    def __init__(self, fst = None):
        self.data = fst
        self.left = None
        self.right = None

class PyBinTree:
    def __init__(self, input):
        self.__root = Node(input)

    def add_el(self, input):
        tmp = self.__root
        out = True
        while (out == True):
            if (tmp.data > input):
                if (tmp.left != None):
                    tmp = tmp.left
                else:
                    tmp.left = Node(input)
                    out = False
            if (tmp.data < input):
                if (tmp.right != None):
                    tmp = tmp.right
                else:
                    tmp.right = Node(input)
                    out = False

    def __print_three(self, node):
        print(node.data)
        if (node.left != None):
            tmp = node.left
            print(tmp.data, " <-", end=" | ")
        else:
            print("None <-", end=" | ")
        
        if (node.right != None):
            tmp = node.right
            print("-> ", tmp.data)
        else:
            print("-> None")
    
    def __sup_print(self, node):
        if (node.left != None):
            self.__sup_print(node.left)
        if (node.right != None):
            self.__sup_print(node.right)

        #print(node.data)
        self.__print_three(node)

    def print_tree(self):
        self.__sup_print(self.__root)

if __name__ == "__main__":
    Obj1 = PyBinTree(231)
    Obj1.add_el(123)
    Obj1.add_el(321)
    Obj1.add_el(200)
    Obj1.add_el(150)
    Obj1.add_el(160)
    Obj1.print_tree()
