// 26.cpp : Defines the entry point for the console application.
//закінчуються літерами 'а' або 'я'.
//26.	Сформувати з введених довгих цілих чисел двонапрямлений список. 
//Вилучити зі списку всі елементи, які більше, ніж у три рази перевищують  
//значення найменшого елемента списку. Використати окрему функцію для визначення найменшого елемента списку. 


#include "stdafx.h"
#include"26.h"

int _tmain(int argc, _TCHAR* argv[])
{
	
	derlist d;
	cout<<"\n Make your choise: Press \n";
	cout<<" '+' to add number"<<endl;
	cout<<" '-' to delete number "<<endl;
	cout<<" '3' to delete all numbers bigger than minimal x 3"<<endl;
	cout<<" 'p' to print all numbers "<<endl;
	cout<<" '0' to exit"<<endl;
	char ch;
	
	do
	{
		cout<<"\nMake your choise, please: ";
		cin>>ch;
		switch ( ch ){
		case '+': d.putinfo( ); break;
		case '-': 
			{
				long temp;
				cout<<" \nEnter number you want to delete: "; 
				cin>>temp;
				if ( d.delnum ( temp ) == 1 )
					cout<<"Error! Such element doesnt exist!";
			    break;
			}
		case '3': d.delmin( ); break;
		case 'p': 
			{
			if ( d.print( )==0 ) 
				cout<<"List is empty!";
			break;
				
			}
		}

	} while ( ch != '0' );

	return 0;
}





//methods parent's class
//-------------------------------------------
void linklist::InsertElem( )
{
	list *pel, *pins;
	char ch;
	do
	{
		pel = new list;		
		if( pel == NULL )		//if new returns NULL(cant allocate a memory)
		{
			cout<<"\nError! There not enought memory!";		//we have an error
			exit( 1 );
		}
		cout<<"Enter long number: ";   //else
		cin>>pel->num;   	//save entered information in list element
		if ( first == NULL )		//if list is empty 
		{
			pel->next = pel->prev = NULL;
			first = last = pel;	  //new element becomes first and last simultainesly
			return;
		}
		pins = first;
		while ( ( pins != NULL ) && ( pel->num < pins->num ) )	//set new element in its position(we have sorted list)
			pins = pins->next;
		AddElem ( pel, pins );		//add new element before *pins
		cout<<"Next number? (y/n)";
		cin>>ch;
	}
	while (ch == 'y' );
}

//-------------------------------------------
// add new element pnew before *pold
void linklist::AddElem ( list* pnew, list *pold )
{
	if  (pold == first )  //new element becomes first
	{
		first->prev = pnew;
		pnew->next = first;
		pnew->prev = NULL;
		first = pnew;
		return;
	}
	if ( pold != NULL ) //set new element in the middle of the list
		{
		pnew->next = pold;
		pnew->prev = pold->prev;
		pold->prev->next = pnew;
		pold->prev = pnew;
	}
	else //new element becomes last
	{
		last->next = pnew;
		pnew->prev = last;
		pnew->next = NULL;
		last = pnew;
	}
}

//-------------------------------------------
// remove element(returns pointer to the next element after removed)

list* linklist::DeleteElem ( list* pdel )
{
	if ( pdel == first ) //removing first element
	{
		if( pdel == last )
		{
			delete pdel;
			first=NULL;
			last=NULL;
		}

		else
		{
			first = first->next;
			first->prev = NULL;
			delete pdel;
			return first;;
		}
	}
	else
	if ( pdel == last ) //removing last element
	{
		last = last->prev;
		last->next = NULL;
		delete pdel;
		return NULL;
	}
	else //else
	{
		list* pnext;
		pdel->next->prev = pdel->prev;
		pnext = pdel->prev->next = pdel->next;
		delete pdel;
		return pnext;
	}
	cout<<"\n Removing...";
}

//-------------------------------------------
////removing all list
void  linklist::clear( )
{
		list* cur = first;
		while ( cur != NULL )
		{
			list* temp = cur;
			cur = cur-> next;
			delete temp;
	    }
}

//-------------------------------------------
//printing all list

bool linklist::PrintList( ) const
{
	if ( first == NULL && last == NULL)
		return 0;
	list* pel = first;
	cout<<"\n Long numbers: ";
	while ( pel != NULL )
	{
		cout<<pel->num<<",  ";
		pel = pel->next;
	}
	return 1;
}

//-------------------------------------------
//returns last element
list *linklist::getlast( ) const 
{ 
	return last; 
}

//-------------------------------------------
//returns first element
list *linklist::getfirst( ) const
{
	return first;
}

//-------------------------------------------
//allows to set first element
void linklist::setfirst( list *pel ) 
	{
	first=pel; 
}

//-------------------------------------------
//allows to set last element
void linklist::setlast( list *pel )
{
	last=pel;
}

/////////////////////////////////////////////////////
//--------------------------------
//methods child's class
////////////////////////////////////////////////////
//print all list starting from the last element
bool derlist::revprint( ) const
{
	list* pel = getlast( );
	if( ( pel == NULL ) && ( getlast( ) == NULL ) )
		return 0;
	cout<<"\nEntered long numbers: ";
	while ( pel != NULL)
	{
		cout<<pel->num<<",  ";
		pel = pel->prev;
	}
}

//-------------------------------------------
//delete all numbers greater than minimal * 3
void derlist::delmin( ) 
{
	list *min = getlast( ), *pel, *temp;
	pel = getfirst( );
	while ( pel != NULL )
	{
		if( pel->num > 3*(min->num) ){
			temp = pel;
			pel = del( temp );
			cout<<"Removing...";

		}
		else
		pel = pel->next;
	}

}

//-------------------------------------------
//constructor
derlist::derlist( )
{
	linklist::linklist( ); 
}

//-------------------------------------------
//destructor
derlist::~derlist ( ) 
{
	setfirst ( NULL ); 
	setlast ( NULL ); 
}

//-------------------------------------------
// add new element 
void derlist::putinfo ( )
{ 
	linklist::InsertElem( ); 
}

//-------------------------------------------
//link new element
void derlist::add( list *pnew, list *pold ) 
{
	linklist::AddElem( pnew, pold ); 
}

//-------------------------------------------
//printing all list
bool derlist::print( ) const
{ 
	return PrintList( ); 
}

//-------------------------------------------
//removes one element in the middle
list *derlist::del ( list *pdel ) 
{
	return linklist::DeleteElem ( pdel );
}

//-------------------------------------------
//removes element with number == n
bool derlist::delnum ( long d ) 
{
	list* pel = getfirst( );
	while ( ( pel != NULL ) && ( pel->num != d ) )
		pel = pel->next;
	if ( pel == NULL ) 
		return 1;
	if ( pel->num == d )
		pel = del ( pel );
	cout<<" Deleted! ";
	return 0;
}

//-------------------------------------------