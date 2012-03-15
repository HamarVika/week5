// 6.cpp : Defines the entry point for the console application.
//6.	Введену послідовність записів з координатами (x,y) точок площини 
//занести в список типу стек. Визначити пару точок, віддаль між якими найменша, 
//	і вилучити їх зі списку. Використати функцію, яка визначає 
//	віддаль між двома заданими точками площини. 

#include "stdafx.h"
#include<iostream>
#include<cmath>
#include"6.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	Distance d;

	cout<<"\n Make your choise: Press \n";
	cout<<" '+' to add point"<<endl;
	cout<<" '-' to delete top - point "<<endl;
	cout<<" 'p' to print all points "<<endl;
	cout<<" 'f' to find and delete pair of points with minimal distance between ";
	cout<<" '0' to exit"<<endl;
	char ch;
	
	do
	{
		cout<<"\nMake your choise, please: ";
		cin>>ch;
		switch ( ch ){
		case '+': d.push( ); break;
		case '-': d.del( ); break;
		case 'p': d.print( ); break;
		case 'f': 
			{
				if( d.findmin( ) )
					cout<<"\nError!There isnt enought elements!";
				break;
			}
		
		}

	} while ( ch != '0' );

	system( "pause" );
	return 0;
}



//------------------------------------------------------------------
////removing all list
void Stack::stackclear ( )
	{
		Point *pel;
		
		while ( top != NULL )		
		{
			pel = top;
			top = top->next;
			delete pel;
		}
	}

//------------------------------------------------------------------

Stack::~Stack ( ) 
	{ 
		stackclear ( ) ; 
	}
//------------------------------------------------------------------

//put entered information ( point ) to the list element
//returnes list element
//method addelem takes them as a parameter
//and adds to the existing list element
Point * Stack::stackputinfo( )
	{
		Point *pel;
		pel = new Point;
		if( pel == NULL )		//if new returns NULL(cant allocate a memory)
		{
			cout<<"\nError! There not enought memory!";		//we have an error
			exit( 1 );
		}
		cout<<"\n Enter koordinates(x, y): \n";		//else
		cout<<" x: ";
		cin>>pel->x;							//save entered information in list element
		cout<<" Y: ";
		cin>>pel->y;
		return pel;
	}

//------------------------------------------------------------------
//add new element

void Stack::stackpush (  )
{		
	char ch ; 
	Point *newel ;
	do
	{
		newel = stackputinfo( );		//allocate memory and returns element with entered information
		if( top == NULL )				//if the list is empty
		{
			newel->next = NULL;			
			top = newel;				//new element becomes first
			
		}
		else				//if list isnt empty
		{
			newel->next = top;     //new element becomes top
			top = newel;
		}
		cout<<"\nNext point? (y/n)";
		cin>>ch;
	}while ( ch == 'y' );
}

//------------------------------------------------------------------
//returns one element(top)
Point * Stack::stackpop ( ) 
{
	if ( top == NULL )
		cout<<"\n The list is empty! ";
	else
	{
		Point *temp = top;
		top = top->next;
		return temp;
	}
}


//------------------------------------------------------------------
//removes one element(top)
void Stack::stackdel ( )
{
	Point *pdel = top ;
	if ( pdel == NULL )
		cout<<"\n The list is empty! ";
	else
	{
		top = top->next ;
		delete pdel;
		cout<<"Removing...";
	}
}

//------------------------------------------------------------------
//printing all list
void Stack::stackprint ( ) 
{
	Point *pel = top ;
	cout<<"\nList: ";
	if ( pel == NULL )
		cout<<"\nThe list is empty!";
	while ( pel != NULL )
	{
		cout<<" ( "<<pel->x<<" , "<<pel->y<<" )   ";
		pel = pel->next ;
	}
}

//------------------------------------------------------------------
//removes one element in the middle
void Distance::delelem ( Point * pdel ) 
{
	Point *pel, *beg = gettop( ) ;
	if ( pdel == beg )    //if it is the first element
	{
		if ( pdel->next == NULL )   // and  only one
		{
			settop ( NULL );
			delete pdel;
		}
		else
		{
			settop( pdel->next );
			delete pdel;
		}
	}
	else		
	if ( pdel->next == NULL )		//if it is the first element
	{
		while ( beg->next != pdel )
			beg = beg->next;
		beg->next = NULL;
		delete pdel;
	}
	else
	{
		beg = gettop( );
		pel = beg->next;
		while ( pel != pdel )		//move while next element isnt pdel
		{
			beg = beg->next;
			pel = pel->next;
		}
		beg->next = pel->next;			//we find
		delete pdel;					//and delete
	}
	cout<<"\nRemoving...";
}
	

//------------------------------------------------------------------
// returns distance between two points
double Distance::dist ( Point * p1, Point *p2 ) 
{
	double res,pp1,pp2;
	pp1=p1->x-p2->x;
	pp2=p1->y-p2->y;
	res = pow(pp1,2) + pow(pp2,2);
	return sqrt(res);
}

//------------------------------------------------------------------
//deletes 2 points with minimal distance between
bool Distance::findmin ( )
{
	Point *pp1, *pp2;
	Point *ttop = gettop ( );
	double lmin, len;
	if ( ( ttop == NULL ) || ( ttop->next == NULL ) )		//if we have only 1 element or empty list
		return 1;
	lmin = dist ( ttop, ttop->next ) ;					
	Point *min1 = ttop, *min2 = ttop->next;
	for( pp1 = ttop; pp1 != NULL; pp1 = pp1->next )
		for( pp2 = pp1->next ; pp2!=NULL; pp2 = pp2->next )
		{
			len = dist ( pp1, pp2 );
			if(  len < lmin )
				{
					lmin = len;
					min1 = pp1;
					min2 = pp2;
				}
		}						//we find the minimal distance
		delelem( min1 );			//and delete that elements
		delelem( min2 );
	return 0;
}
