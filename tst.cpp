#include <iostream>

template <class T>
	struct fst
	{
		T	m;
	};

template <class T>
	class c_scnd
	{
	private:
		fst<T>	loc;
		T		var;
	public:
		void prnt_str_type();
	};
	
template<class T> void c_scnd<T>::prnt_str_type()
{
	std::cout << "fst " << sizeof(var) << std::endl;
}

int main()
{
	fst<int>	a;
	fst<char>	b;

	std::cout << "ta " << sizeof(a.m) << " tb " << sizeof(b.m) << std::endl;

	c_scnd<int> Obj1;
	Obj1.prnt_str_type();
	
	return 0;
}
