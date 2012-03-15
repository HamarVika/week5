
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;

// class of list element
class list{	
public:
	double number;
	list* prev, *next;					// pointer to next and previos element
	list(): number(0), prev(NULL), next(NULL) {}
	list (double n, list* nx, list* p): number(n), next(nx), prev(p)  {}
	list (list& l) 
	{ 
		number = l.number; 
		next = l.next;
		prev = l.prev;
	}
};

//parent class. Double linked list
class linklist{
protected:
	list* last;									// pointer to first and last element
	list* first;
	void AddElem (list* pnew, list* pold);		// add element to the list in definite position
	void clear();								// free memory
public:
	linklist()  { last = NULL; first = NULL; }
	void InputElem ( );						// input data from the keyboard
	void PrintList ();			
	~linklist();								
};

/////////////////////////////////////////////////////
// Derivative class, could insert 4 element to the right place and remove element, print reverse list
class newlist: private linklist
{
public:
	newlist() : linklist() {}
	void InputEl () { linklist::InputElem(); }
	void Insert4El ();
	void AddEl(list *pnew, list *pold) { linklist::AddElem(pnew, pold); }
	void PrintL() { linklist::PrintList(); }
	void PrintRev();
	list* Del (list* pdel); 
	void DeleteElem();
	~newlist() { first = last = NULL; }
};