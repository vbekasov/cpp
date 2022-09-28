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
        if (tmp.data > input):
            tmp.left = Node(input)
        else:
            tmp.right = Node(input)

    def print_tree(self, tmp = self.__root):
        pass

if __name__ == "__main__":
    Obj1 = PyBinTree(231)
    Obj1.add_el(123)
    Obj1.add_el(321)
    Obj1.print_tree()
