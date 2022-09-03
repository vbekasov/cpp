import random
import sys
import pandas as pd
import numpy as np

class Rand_set:
	def __init__(self, i_start, i_stop, i_step):
		self.__sss = np.arange(int(i_start), int(i_stop), int(i_step))
	
	def gen_rand_prnt(self, prnt = 0, ret = 0):
		#out = set()
		if (ret != 0):
			r_arr = np.array([], dtype=int)
		for rng in self.__sss:
			l = 0
			out = np.random.randint(low= -999999, high= 999999, size= rng)
			if (prnt != 0):
				print(out)
			if (ret != 0):
				r_arr = np.append(r_arr, set(out))
			out = set()
		if (ret != 0):
			return r_arr

	def test_fun(self, tst):
		print("TEST TEXT", tst)

	def __del__(self):
		print("Obj destroyed")

if __name__ == "__main__":
	Obj1 = Rand_set(sys.argv[1], sys.argv[2], sys.argv[3])
	out = Obj1.gen_rand_prnt(ret= 1)
	print(out)
	del(Obj1)