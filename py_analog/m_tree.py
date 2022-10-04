from re import S


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
            if (tmp.data == input):
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
        self.__print_three(node)

    def print_tree(self):
        self.__sup_print(self.__root)

    def __sup_plot_three(self, node):
        if (node.left != None):
            tmpl = node.left
            tmpl = tmpl.data
        else:
            tmpl = node.data
        if (node.right != None):
            tmpr = node.right
            tmpr = tmpr.data
        else:
            tmpr = node.data
        return tmpl, tmpr

    def __sup_plot(self, node, lvl):
        lvl += 1
        l = list()
        if (node.left != None):
            l += (self.__sup_plot(node.left, lvl ))
        if (node.right != None):
            l += (self.__sup_plot(node.right, lvl))
        tmpl, tmpr = self.__sup_plot_three(node)
        tmp = [lvl, node.data, tmpl, tmpr]
        l += [tuple(tmp)]
        return l

    def l_plot(self):
        l_t = list()
        l_t += self.__sup_plot(self.__root, 0)
        return l_t

    def __sup_vector(self, node):
        l = list()
        if (node.left != None):
            l += (self.__sup_vector(node.left))
        if (node.right != None):
            l += (self.__sup_vector(node.right))
        l.append(node.data)
        return l

    def vectorize_tree(self):
        l_v = list()
        l_v += self.__sup_vector(self.__root)
        l_v.sort()
        return l_v

    def __sup_balance(self, l_v):
        tmp = int(len(l_v)/2)
        #print(tmp, len(l_v))
        if (len(l_v) > 1):
            self.add_el(l_v[tmp])
        else:
            self.add_el(l_v[0])
        if (tmp > 0):
            self.__sup_balance(l_v[:tmp])
            self.__sup_balance(l_v[tmp:])

    def balance_tree(self, vec = None):
        if (vec == None):
            l_v = self.vectorize_tree()
        else:
            l_v = vec
            l_v.sort()
        self.__root = None
        self.__root = Node(l_v[int(len(l_v)/2)])
        self.__sup_balance(l_v)


if __name__ == "__main__":
    Obj1 = PyBinTree(231)
    Obj1.add_el(123)
    Obj1.add_el(321)
    Obj1.add_el(200)
    Obj1.add_el(150)
    Obj1.add_el(160)
    Obj1.print_tree()
    #print(Obj1.l_plot())
    Obj1.balance_tree()
