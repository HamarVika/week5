#include<iostream>
using namespace std;
//-----------------------------------------------
// ----- structure  - list element ----
struct listel
{
	bool is;
	long data;		    //long number
	listel *next;		//pointer to the next list element 
};

//-----------------------------------------------
// parent class with the shared list information
//methods pop, print, clear are similar for both classes( queue and stack )
class List
{
protected:
	listel * first;			//pointer to the first list element
public:
	List( ): first( NULL )  { }
	~List ( ) 
	{
		clear( );
	}
	listel * putinfo( ) ;
	void pop ( long * n ) ;
	void clear ( ) ;
	void print( ) ;
		
};

//-----------------------------------------------
//a child class, in addition to the pointer to the first element has a pointer to the last
//creates a queue with long integer
class Queue : private List
{
	listel *last ;
public:
	Queue( ) ;
	~Queue( ) ;
	void popq () ;
	void addelq( ) ;
	void printq( ) ;
	listel * minim( ) ;

};
//-----------------------------------------------
//a child class. has only pointer to the first(top) element
//creates a stack with numbers from queue and puts them in chronological order
class Stack : private List
{
public:
	Stack( ) ;
	~Stack( ) ;
	void pops( ) ;
	void addels( listel *pel ) ;
	void prints( ) ;
}
//-----------------------------------------------

