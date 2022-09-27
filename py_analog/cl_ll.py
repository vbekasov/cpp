class DT:
    def __init__(self, input):
        self.data = input
        self.next = None

    def add_next(self, input):
        self.next = DT(input)

class LL:
    def __init__(self, input):
        self.__first = DT(input)

    def find_lst(self):
        pass
    
    def push_back(self, input):
        tmp = self.__first
        while(tmp.next != None):
            tmp = tmp.next
        tmp.next = DT(input)

    def push_forword(self, input):
        tmp = self.__first
        tmpFst = DT(input)
        #print(tmp is self.__first)
        self.__first = tmpFst
        self.__first.next = tmp

    def print_ll(self):
        tmp = self.__first
        print(tmp.data, end=' | ')
        while(tmp.next != None):
            tmp = tmp.next
            print(tmp.data, end=' | ')
        print()

    def ll_length(self):
        if (self.__first.next == None):
            print('1')
            return 1
        
        tmp = self.__first.next
        l = 2
        while(tmp.next != None):
            l += 1
            tmp = tmp.next
        print(l)
        return l

    def insert_after(self, find, input):
        tmp = self.__first
        while(tmp.data != find and tmp.next != None):
            tmp = tmp.next
        if (tmp.data != find and tmp.next == None):
            return
        ins = DT(input)
        ins.next = tmp.next
        tmp.next = ins

    def del_el(self, el):
        if (self.__first.next == None):
            return

        prev = self.__first
        tmp = self.__first.next
        while(tmp.data != el):
            prev = tmp
            tmp = tmp.next

        if (tmp == None):
            return
        prev = tmp.next
        #del(tmp)
                

        

if __name__ == "__main__":
    print("Main Works")
    Obj1 = LL(123)
    Obj1.push_back("ABC")
    Obj1.push_back(987)
    Obj1.push_forword("QWERTY")
    Obj1.insert_after("ABC", 4444)
    Obj1.del_el("ABC")

    Obj1.print_ll()