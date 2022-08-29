#ifndef BIN_TREE_H
#define BIN_TREE_H

#define BITR namebi::Bi_tree
#define STDIV std::vector<int>
#define STRUC namebi::tb_node

#include <iostream>
#include <vector>

namespace namebi{
	struct s_bi_node
	{
		int val;
		s_bi_node *left;
		s_bi_node *right;
	} typedef tb_node ;	
	
	template <class T>
		void prnt_vec(T *out)
		{
			for (auto it = out->begin();  it != out->end(); it++)
			{
				std::cout << *it << " !";
			}
			std::cout << std::endl;
		};

	template <typename T>
		void prnt_vec(T *iarr, int len)
		{
			for (size_t i = 0; i < len; i++)
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
		void prnt_dup(T out)
		{
			std::sort(out.begin(), out.end());
			std::cout << "Sorted : ";
			prnt_vec(&out);
			
			auto tmp = out[0];
			auto iter = out.begin();
		}

}
#endif
