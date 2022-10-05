#include "../tree_head/st_bt.hpp"
#include <iostream>


int main(int argc, char* argv[])
{
	size_t				len = argc -1;
	int					i = 1;
	int					iarr[len];
	nbt::tb_node		*root;
	std::vector<int>	out;

	for ( ; i < argc; i++)
	{
		iarr[i - 1] = atoi(argv[i]);
	}

	root = nbt::gen_tree(&iarr[0], 0 , len);
	nbt::treeto_vec(root, &out);
	auto v_dup = nbt::find_dup(out, len);
	
	//char* p = new char[sizeof(namebi::bin_tree_dup_int)];
	//namebi::bin_tree_dup_int* ap = new (p) namebi::bin_tree_dup_int;
	//ap->namebi::bin_tree_dup_int::~bin_tree_dup_int();
	//delete [] p;

	return 0;
}
