#ifndef BIN_TREE_H
#define BIN_TREE_H

#define BITR	namebi::Bi_tree
#define STDIV	std::vector<int>
#define STRUC	namebi::tb_node
#define COUT	std::cout<<

#include <iostream>
#include <vector>
#include "stdio.h"

namespace namebi{
	struct s_bi_node
	{
		int			val;
		s_bi_node	*left;
		s_bi_node	*right;
	} typedef tb_node ;	
	
	template <class T>
		void prnt_vec(T *out)
		{
			COUT"VEC : ";
			for (auto it = out->begin();  it != out->end(); it++)
			{
				std::cout << *it << " !";
			}
			std::cout << std::endl;
		};

	template <typename T>
		void prnt_vec(T *iarr, int len)
		{
			COUT"ARR : ";
			for (int i = 0; i < len; i++)
			{
				std::cout << iarr[i] << " |";
			}
			std::cout << std::endl;
		}
	
	template <class T, class Y>
		void treeto_vec(T *root, Y *out)
		{
			if (root->left)
				treeto_vec(root->left, out);
			if (root->right)
				treeto_vec(root->right, out);
			out->push_back(root->val);
		}

	template <class T>
		void prnt_tree(T *root)
		{
			if (root->left)
				prnt_tree(root->left);
			if (root->right)
				prnt_tree(root->right);
			std::cout << root->val;
			if (!root->left && !root->right)
				std::cout << "~";
			std::cout << " ";
		}

	template <class T>
		T find_dup(T out, size_t len)
		{
			std::sort(out.begin(), out.end());
			
			T ret;
			auto tmp = out[0];
			auto iter = out.begin();
			iter++;
			size_t count = 0;
			size_t total = 0;
			for ( ; iter != out.end(); iter++){
				if (tmp == *iter)
					{
						count++;
						ret.push_back(tmp);
					}
				else if (count != 0){
					count = 0;
					total++;
					}
				tmp = *iter;
			}
			std::cout << len << " " << total << std::endl;
			return ret;
		}
	
	template <class T>
		void find_el_tree(T find, tb_node *root)
		{
			if (root == NULL)
			{
				COUT"Not in tree\n";
				return ;
			}
			if (find == root->val)
			{
				std::cout << "Found " << find << std::endl;
			}
			else if (find < root->val)
			{
				std::cout << root->val << " ";
				find_el_tree(find, root->left);
			}
			else
			{
				std::cout << root->val << " ";
				find_el_tree(find, root->right);
			}
		}

	template <class T, class Y>
		void del_el(T *root, Y *d_val)
		{
			if (*d_val == root->val && !root->left && !root->right)
				delete root;
			else if (root->left)
				del_el(root->left, d_val);
			else if (root->right)
				del_el(root->right, d_val);
		}
	
	class bin_tree_dup_int
	{
	private:
		STRUC	*root;
		STRUC*	gen_triple(int* iarr, int start, int finish);
	public:
		bin_tree_dup_int();
		virtual ~bin_tree_dup_int();
		void tst();
		template<class T> void find_dup(T out, size_t len);
	};
	
	bin_tree_dup_int::bin_tree_dup_int()
	{
		root = NULL;
	}
	
	bin_tree_dup_int::~bin_tree_dup_int()
	{
		root = NULL;
		COUT"Finished\n";
	}

	STRUC* bin_tree_dup_int::gen_triple(int* iarr, int start, int finish)
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

	template<class T> void bin_tree_dup_int::find_dup(T out, size_t len)
	{
		std::sort(out.begin(), out.end());
		
		auto tmp = out[0];
		auto iter = out.begin();
		iter++;
		size_t count = 0;
		size_t total = 0;
		for ( ; iter != out.end(); iter++){
			if (tmp == *iter)
				count++;
			else if (count != 0){
				count = 0;
				total++;
				}
			tmp = *iter;
		}
		std::cout << len << " " << total << std::endl;
	}

	void bin_tree_dup_int::tst()
	{
		COUT"WORKS\n";
	}
	

}
#endif
