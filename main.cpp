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

static STRUC* gen_triple(int* iarr, int start, int finish)
{
	STRUC	*m = new(STRUC);
	int		pos = (finish - start) / 2;

	m->val = iarr[pos];
	if ((pos - start) / 2 > 0) {
		m->left = gen_triple(iarr, start , pos);}
	else {
		STRUC *l = new(STRUC);
		l->val = iarr[pos - 1];
		l->left = NULL;
		l->right = NULL;
		m->left = l;}
	if ((finish - pos ) > 2) {
		m->right = gen_triple(&iarr[pos + 1], 0, finish - pos - 1);}
	else {
		STRUC *r = new(STRUC);
		r->val = iarr[pos + 1];
		r->left = NULL;
		r->right = NULL;
		m->right = r;}

	return m;
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

	root = gen_triple(&iarr[0], 0 , len);
	namebi::treeto_vec(root, &out);
	namebi::find_dup(out, len);
	namebi::bin_tree_dup_int Obj1;
	//delete(Obj1);

	return 0;
}
