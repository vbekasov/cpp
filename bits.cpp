#include <iostream>
#include <string>
#include "bin_tree.h"

int main()
{
	//int tst_arr[] = {1,2,3};
	char *obj_space = new char[sizeof(BITR)];
	BITR *Obj1 = new (obj_space) BITR;
	//Obj1->show_lf();
	Obj1->get_vals(namebi::pick_vals());
	Obj1->BITR::~Bi_tree();  
	delete [] obj_space;

	return 0;
}
