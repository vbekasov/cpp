#include <iostream>
#include "bin_tree.h"

int main(int argc, char* argv[])
{
	size_t				len = argc -1;
	int					i = 1;
	int					iarr[len];
	namebi::tb_node		*root;
	std::vector<int>	out;

	for ( ; i < argc; i++)
	{
		iarr[i - 1] = atoi(argv[i]);
	}

	root = namebi::gen_tree(&iarr[0], 0 , len);
	namebi::treeto_vec(root, &out);
	auto v_dup = namebi::find_dup(out, len);
	//namebi::prnt_tree(root); std::cout << std::endl;
	//COUT"Dups : ";
	//namebi::prnt_vec(&v_dup);
	//namebi::del_dup(root, &v_dup);
	//namebi::prnt_tree(root); std::cout << std::endl;
	
	//char* p = new char[sizeof(namebi::bin_tree_dup_int)];
	//namebi::bin_tree_dup_int* ap = new (p) namebi::bin_tree_dup_int;
	//ap->namebi::bin_tree_dup_int::~bin_tree_dup_int();
	//delete [] p;

	return 0;
}
