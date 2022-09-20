#include <iostream>
#include <string>

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
		c_scnd(T fst);
		~c_scnd() { std::cout<< "del\n";}
		fst<T>*	add_el(T nel);
		fst<T>*	ret_last();
		fst<T>*	prnt_list();
	};
	
template<class T> c_scnd<T>::c_scnd(T fst)
{
	loc.m = fst;
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
	std::cout << "\nPRG MAIN START\n";

	char* p = new char[sizeof(c_scnd<int>)];
	c_scnd<int>* Obj1 = new (p) c_scnd<int>(1);
	Obj1->add_el(1234);
	Obj1->add_el(987);
	Obj1->prnt_list();
	Obj1->~c_scnd();
	delete [] p;

	std::cout<<std::endl;
	
	p = new char[sizeof(c_scnd<std::string>)];
	c_scnd<std::string>* Obj2 = new (p) c_scnd<std::string>("FST");
	Obj2->add_el("ABC");
	Obj2->add_el("QWERTY");
	Obj2->prnt_list();
	Obj2->c_scnd::~c_scnd();
	delete [] p;

	std::cout << "\nPRG MAIN FINISHED\n";
	
	return 0;
}
