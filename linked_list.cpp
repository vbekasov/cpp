#include <iostream>
#include <string>

template <typename T>
	struct s_list
	{
		T		m;
		s_list<T>	*next;
	};

template <class T>
	class c_scnd
	{
	private:
		s_list<T>	loc;
		T			var;
		s_list<T>*	ret_last();
	public:
		c_scnd(T s_list);
		~c_scnd() { std::cout<< "del\n";}
		void	add_el(T nel);
		void	del_last();
		void	prnt_list();
	};
	
template<class T> c_scnd<T>::c_scnd(T fst)
{
	loc.m = fst;
	loc.next = NULL;
}

template<class T> void c_scnd<T>::prnt_list()
{
	s_list<T>	*el;
	el = &loc;
	std::cout<<"List : ";
	while (el->next != NULL)
	{
		std::cout << el->m << " ";
		el = el->next;
	}
	std::cout<< el->m <<std::endl;
}

template<class T> s_list<T>* c_scnd<T>::ret_last()
{
	s_list<T>	*el;
	el = &loc;
	while (el->next != NULL)
		el = el->next;

	return el;
}

template<class T> void c_scnd<T>::add_el(T nel)
{
	s_list<T>	*el;
	el = new(s_list<T>);
	el->m = nel;
	std::cout << "New el " << el->m << std::endl;
	
	s_list<T>	*last = ret_last();
	last->next = el;
}

template<class T> void c_scnd<T>::del_last()
{
	if (loc.next == NULL)
		return ;

	s_list<T>	*el;
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
