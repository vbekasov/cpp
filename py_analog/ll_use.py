from module_ll import LL

class TstClass:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y
    
    def print_xy(self):
        print("x={} | y={}".format(self.__x, self.__y))

    def set_xy(self, x, y):
        self.__x = x
        self.__y = y

if __name__ == "__main__":
    Obj1 = LL(123)
    Obj1.push_back("QWERTY")
    Obj1.push_forword("ABC")

    Obj2 = TstClass(987, "XYZ")
    Obj1.insert_after(123, Obj2)

    Obj1.print_ll()
    tmp = Obj1.ret_el(Obj2)
    tmp.print_xy()
