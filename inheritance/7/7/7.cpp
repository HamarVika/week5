// 7.cpp : Defines the entry point for the console application.
//7.	З введених довгих цілих чисел сформувати двонапрямлений список. 
//Роздрукувати створений список в обох напрямках. Вилучити зі списку всі елементи,
//	що містять числа, сума цифр яких перевищує 25, використовуючи функцію для визначення 
//	суми цифр заданого довгого цілого. Визна¬чити відсоток вилучених елементів. 

#include "stdafx.h"
#include"7.h"
int sum ( long n ) ;

int _tmain(int argc, _TCHAR* argv[])
{
	
	derlist d;
	cout<<"\n Make your choise: Press \n";
	cout<<" '+' to add number"<<endl;
	cout<<" '-' to delete number "<<endl;
	cout<<" 'b' to remove all elements which sum of digits exceeds 25 and view the percentage of deleted items"<<endl;
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
		case 'b': cout<<d.delmax( ); break;
		case 'p': 
			{
			if ( d.print( )==0 ) 
				cout<<"List is empty!";
			break;
				
			}
		case 'c': cout<<"\n  "<<d.count()<<" %"; break;
		}

	} while ( ch != '0' );
	system("pause");
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
		count++;
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
	count--;
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
			count--;
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
	first = pel; 
}

//-------------------------------------------
//allows to set last element
void linklist::setlast( list *pel )
{
	last = pel;
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
	InsertElem( ); 
	
}

//-------------------------------------------
//link new element
void derlist::add( list *pnew, list *pold ) 
{
	AddElem( pnew, pold ); 
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
	return DeleteElem ( pdel );
	
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
//returnss the sum of numbers in long n
 //removes all elements which sum of digits exceeds 25 and returns the percentage of deleted items
int derlist::sum ( long n ) 
	{
		int sum = 0;
  
		while ( n != 0 )
		 {
			 sum += n%10;
			 n /= 10;
		 }
		
		return abs(sum);   //if sum number is negative
	}
//-------------------------------------------	
//removes all elements which sum of digits exceeds 25 and returns the percentage of deleted items
unsigned derlist::delmax (  )
	{
		int n=0, c=getcount();
		list *pel, *max, *temp;
		pel = max = getfirst( );
		while ( pel != NULL )
		{
			if( sum(pel->num) > 25 ){		// if sum of digits exceeds 25
				temp = pel;
				n++;
				pel = del( temp );			//remove
				cout<<"Removing...";

			}
			else
				pel = pel->next;		//else move to the next number
		}

		return (((double)n/c)*100);			//returns the percentage of deleted items
	}
	