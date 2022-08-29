import random
import sys

class Rand_set:
	def __init__(self, tot_numb):
		self.__numb = tot_numb
		self.__row = set()
		self.__gen_row()

	def __gen_row(self):
		tmp = 0
		r_len = len(self.__row)
		for i in range(self.__numb):
			r_len += 1
			while (r_len > len(self.__row)):
				tmp = random.randint(-10000, 10000)
				self.__row.add(tmp)
	
	def prnt_row(self):
		for i in self.__row:
			print(i, end = ' ')

if __name__ == "__main__":
	numb = int(sys.argv[1])
	Obj1 = Rand_set(5)
	Obj1.prnt_row()
	del(Obj1)