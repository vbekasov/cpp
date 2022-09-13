#include <iostream>
#include "bin_tree.h"

struct str_info
{
	int len;
	int *arr;
}typedef td_info;


void read_triple(STRUC *m);

void prnt_left(STRUC *root)
{
	std::cout << "l root = " << root->val << std::endl;
	if (root->left != NULL) { prnt_left(root->left);}
}

void prnt_right(STRUC *root)
{
	std::cout << "r root = " << root->val << std::endl;
	if (root->left != NULL) { prnt_right(root->right);}
}

void read_triple(STRUC *m)
{
	std::cout << "Root  = " << m->val << std::endl;
	if (m->left)
		std::cout << "  <-Left  = " << m->left->val << std::endl;
	else
		std::cout << "  <-Left  = NULL\n";
	if (m->right)
		std::cout << "  ->Right = " << m->right->val << std::endl;
	else
		std::cout << "  ->Right = NULL\n";
}

void prnt_tree(STRUC *root, STDIV *out)
{
	if (root->left)
		prnt_tree(root->left, out);
	if (root->right)
		prnt_tree(root->right, out);
	out->push_back(root->val);
}

int main(int argc, char* argv[])
{
	size_t	len = argc -1;
	int		i = 1;
	int		iarr[len];
	STRUC	*root;
	STDIV	out;

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
