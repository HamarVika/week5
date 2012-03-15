// 9.cpp : Defines the entry point for the console application.
//9.	Сформувати з введених довгих цілих чисел список типу черга. 
//Створити новий список типу стек, в який перенести введені елементи в порядку 
//	зростання їх значень. Використати функцію для визначення найменшого елемента списку-черги. 

#include "stdafx.h"
#include"9.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Queue q ;
	Stack s ;

	listel *el ;
	q.addelq( ) ;  //add new elements
	q.printq( ) ;   //print list
	cout<<endl;

	while ( ( el = q.minim ( ) ) != NULL )    //seeks minimal element
		s.addels ( el );						//fnd add them to the stack
	cout<<"Resulting stack: ";
	s.prints( );					//print stack
	system("pause");
	return 0;
}

//------------------------------------------------------------------
//put entered information ( long number ) to the list element
//returning list element method addelem takes as a parameter and adds to the existing list element
listel * List::putinfo( )
	{
		listel *pel;
		pel = new listel;
		if( pel == NULL )		//if new returns NULL(cant allocate a memory)
		{
			cout<<"\nError! There not enought memory!";		//we have an error
			exit( 1 );
		}
		cout<<"\n Enter long integer: ";		//else
		cin>>pel->data;						//save entered info in list element
		pel->is = false;
		return pel;
	}

//------------------------------------------------------------------
//removiong last element.
void List::pop ( long * n )
	{
		listel *p = first;
		if ( p == NULL )		//if the list is empty
		{
			cout<<" \nEmpty! ";
			*n = 0;
		}
		else
		{
			*n  = p->data;    //saving element we want to remove
			first = first->next;		//now first is the next element
			delete p;			//and remove
		}
	}

//------------------------------------------------------------------
//removing all list
void List::clear ( )
	{
		listel *pel;
		
		while ( first != NULL )		
		{
			pel = first;
			first = first->next;
			delete pel;
		}
	}

//------------------------------------------------------------------
// print all list
void List::print( )
	{
		listel *pel = first ;  // refers to the first element
		if ( pel == NULL )		//if the list is empty
			cout<<" Empty " ;
		
		while ( pel != NULL )
		{
			cout<<pel->data<<" ";		//printing long number
			pel = pel->next;			//
		}
	}

//------------------------------------------------------------------
///////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
//Queue class metods
//constructor

Queue::Queue( ) 
{
	List::List( );	//calls parent constructor
	last = NULL;	//there no such element, last is only in queue
}

//------------------------------------------------------------------
//destructor
Queue::~Queue( ) 
{
	clear( ) ;			//calls methods removing all list
	last = NULL ; 
}

//------------------------------------------------------------------
//removes one element(first)
void Queue::popq ( ) 
{ 
	long l;
	List::pop ( &l ) ;   //calls parent method
	if ( l != NULL )
		cout<<l;			//print deleted element 
}

//------------------------------------------------------------------
// adds new element to the list
void Queue::addelq( )
{
	char ch ;
	listel *pel ;
	
	do
	{
		pel = List::putinfo( ) ;   //allocate memory and returns element with entered information
		pel->next = NULL ;			//it's the last element
		if ( first == NULL )		//if there no any elements
			first = last = pel ;		//it becomes first and last simultaneously
		else
		{
			last->next = pel ;
			last = pel ;			//it becomes last
		}
		cout<<" \n Next number?(y/n) " ;
		cin>>ch;
	}
	while ( ch == 'y' ) ;		// if we want to add one more number
}

//------------------------------------------------------------------
//printing all list
void Queue::printq ( )
{
	cout<<" \nList: " ;
	List::print( );		//call parent method
}

//------------------------------------------------------------------
//returns minimal element
//if we find minimal element his field 'is' becomes true
//so continuing while this field in all elements wont be true
//minimal element we add to the stack
listel * Queue::minim( )
{
	if ( first == last )  //if there is only one element
	{ 
		if ( first->is == false )		//we havent such element in stack
		{
			first->is = true ;			//now we have
			return first ;
		}
		else return NULL;			//we have
	}
	listel *pel = first, *min;
	bool f = true;

	while ( ( f == true ) && ( pel != NULL ) )		//looking for new elements
	{
		if ( pel->is == false )				//if we havent such element in stack
		{
			f = false ;
			min = pel ;
			continue ;
		}
		pel = pel->next ;
	}

	if ( f == true )		//no more items
		return NULL;
	pel = first->next ;

	while ( pel != NULL )
	{
		if ( ( pel->is == false ) && ( pel->data < min->data ) )		//if we havent such element in stack and his number is less then minimal
			min = pel ;
		pel = pel->next ;
	}

	min->is = true ;
	return min ;
}

//------------------------------------------------------------------
///////////////////////////////////////////////////////////////////////
//------------------------------------------------------------------
//Class Stack
//Constructor
Stack::Stack( ) 
{ 
	List::List( ) ;		//call parent constructor
}

//------------------------------------------------------------------
//destructor
Stack::~Stack( ) 
{ 
	clear( ) ;   //removing all list
}

//------------------------------------------------------------------
//removes one element(first)
void Stack::pops( )
{ 
	long l;
	List::pop ( &l ) ;
	if ( l != NULL )
		cout<<l; 
}

//------------------------------------------------------------------
//add new element
void Stack::addels ( listel *pel )
{		
	listel *newel = new listel ;
		
	if ( newel == NULL )		//if new cant allocate memory
	{
		cout<<"\nError! There not enought memory! " ;
		exit ( 1 ) ;
	}	
	newel->data = pel->data ;
	if ( first == NULL )		//if the list is empty
	{
		newel->next = NULL ;
		first = newel ;		//new element becomes first
	}
	else
	{
		newel->next = first ;		
		first = newel ;
	}
}

//------------------------------------------------------------------
//printing all list
void Stack::prints( )
{
	cout<<"\nList: ";
	List::print( );
}

//------------------------------------------------------------------
