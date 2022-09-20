#include <iostream>

template <typename T>
	struct fst
	{
		T		m;
		fst<T>	*next;
	};

template <class T>
	class c_scnd
	{
	private:
		fst<T>	loc;
		T		var;
	public:
		void	prnt_str_type();
		fst<T>*	add_el(T nel);
		fst<T>*	ret_last();
		fst<T>*	prnt_list();
	};
	
template<class T> void c_scnd<T>::prnt_str_type()
{
	loc.m = 3;
	loc.next = NULL;
}

template<class T> fst<T>* c_scnd<T>::prnt_list()
{
	fst<T>	*el;
	el = &loc;
	std::cout<<"List : ";
	while (el->next != NULL)
	{
		std::cout << el->m << " ";
		el = el->next;
	}
	std::cout<< el->m <<std::endl;
	return el;
}

template<class T> fst<T>* c_scnd<T>::ret_last()
{
	fst<T>	*el;
	el = &loc;
	while (el->next != NULL)
		el = el->next;

	return el;
}

template<class T> fst<T>* c_scnd<T>::add_el(T nel)
{
	fst<T>	*el;
	el = new(fst<T>);
	el->m = nel;
	std::cout << "New el " << el->m << std::endl;
	
	fst<T>	*last = ret_last();
	last->next = el;
	return el;
} 

int main()
{
	c_scnd<int> Obj1;
	Obj1.prnt_str_type();
	Obj1.add_el(1234);
	Obj1.add_el(987);
	Obj1.prnt_list();
	
	return 0;
}
