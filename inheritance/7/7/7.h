// spusok.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include<iostream>

using namespace std;

class list
{		//node's structure
public:
	long num;
	list* prev, *next;
	list( ) : num( 0 ), prev( NULL ), next( NULL ) { }
	list( long n, list *pr, list *nx ): num( n ), prev( pr ), next( nx ) {  }
	list( list &pnew ) 
	{ 
		num = pnew.num; 
		prev = pnew.prev;
		next = pnew.next;
	}
};
/////////////////////////////////////////

//base class forms list, containing all information
//
class linklist{
private:
	list* last;		// вказ≥вники початку ≥ к≥нц€ списку
	list* first;
	unsigned count;
public:
	linklist() 
	{ 
		last=NULL; 
		first=NULL; 
		count = 0 ;
	}
	~linklist()		 //зв≥льненн€ динам≥чноњ пам'€т≥
	{
		clear( );
	}
	void clear( );
	void InsertElem( );
	void AddElem ( list *pnew, list *pold );
	bool PrintList ( void ) const ;
	list* DeleteElem ( list* pdel );
	list *getlast( ) const;					// returns last element
	list *getfirst( ) const;					//and first
	void setfirst( list *pel ) ;    // allows you to set first element
	void setlast( list *pel );		//and last
	unsigned getcount( ) const
	{
		return count; 
	}
};

/////////////////////////////////////////
//child class
//containes all list-information and structure from parent class
//removes all elements which sum of digits exceeds 25 and you can view the percentage of deleted items
class derlist : private linklist
{
	
public:
	derlist( );
	~derlist ( ) ;
	void putinfo ( );
	void add( list *pnew, list *pold ) ;
	bool print( ) const;
	bool revprint( ) const;
	list *del ( list *pdel ) ;
	bool delnum ( long d ) ;
	int count( ) const
	{ 
		return getcount( ); 
	}
	int sum ( long n ) ;		//returnss the sum of numbers in long n
	unsigned delmax (  ) ;  //removes all elements which sum of digits exceeds 25 and returns the percentage of deleted items
	
};

/////////////////////////////////////////