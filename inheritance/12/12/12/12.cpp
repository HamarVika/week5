// 12.cpp : Defines the entry point for the console application.
//12.	З введених дійсних чисел, відсортованих за зростанням значень, сформувати двонапрямлений список. 
//Роздрукувати створений список в обох напрямках. Розробити функцію, яка вводить у список новий елемент, 
//зберігаючи його впорядкованість. На основі цієї  функції доповнити список 4-а новими числами

#include "stdafx.h"
#include"12_def.h"

int _tmain(int argc, _TCHAR* argv[])
{
	newlist ln;
	char ch;
	cout<<" \n\t Enter data: \n";
	do
	{
		ln.InputEl();
		cout<< "\n Continue? (y/n) ";
		cin>>ch;
	}
	while ( ch!='n' );
	cout<<"\n\t List: ";
	ln.PrintL();								//виведення сформованого списку
	
	cout<<" \n Insert four element: \n";
	ln.Insert4El();
	ln.PrintL();								

	cout<< "\n Reverse:  \n";
	ln.PrintRev();
	do
	{
		cout<<"\n To delete number press '-'.\n To exit press 0\n Make your choice... ";
		cin>>ch;
		if (ch == '-')
		{
			ln.DeleteElem();
			ln.PrintL();
		}
	}
	while (ch!='0');
	system("pause");
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////
// input list item
void linklist::InputElem ( )
{
	double num;
	static int n = 1;
	list *pel, *pins;
	cout<<n++<<" . Number: ";
	cin>>num;
	pel = new list;					//allocate in dynamic memory
	if (pel == NULL)				// error
	{
		cout<< " Error! There is no anought memory! ";
		exit(1);
	}
	pel->number = num;						// put number to the field
	if ( first == NULL )						//it's first element 
	{
		pel->next = pel->prev = NULL;
		first = last = pel;							
		return;
	}
	pins = first;
	while ( pins != NULL && num > pins->number )	// find righ place to insert element.
		pins = pins->next;								// numbers are in ascending order
	AddElem ( pel, pins );								// add new element before pins
}

// inserts exactly 4 elements in list
void newlist::Insert4El ( )
{
	for (int i = 0; i<4; i++)
		InputElem();
}

//join the the list element pnew front element pold
void linklist::AddElem(list* pnew, list *pold)
{
	if ( pold == first )							//new element became the first in the list
	{
		first->prev = pnew;
		pnew->next = first;
		pnew->prev = NULL;
		first = pnew;
		return;
	}
	if ( pold != NULL )								// new element is introduced in the middle of the list
	{
		pnew->next = pold;
		pnew->prev = pold->prev;
		pold->prev->next = pnew;
		pold->prev = pnew;
	}
	else										//new element becomes the last in the list
	{
		last->next = pnew;
		pnew->prev = last;
		pnew->next = NULL;
		last = pnew;
	}
}

// print list element
void linklist::PrintList()
{
	list* pel = first;
	cout<<"\n Linklist:  \n";
	while ( pel!=NULL )
	{
		cout << pel->number << endl;
		pel = pel->next;
	}
}

// delete some element
void newlist::DeleteElem()
{
	double n;
	cout<< " \n Enter number to delete: ";
	cin>>n;
	list* pel = first;
	while ( pel->number!=n && pel!=NULL )
		pel = pel->next;
	if ( !pel )
		cout<< " Wrong number! ";
	else
		Del(pel);
}

// Remove item (returns a pointer to the next for the deleted item)
list* newlist::Del (list* pdel)
{
	if ( pdel == first )				//Remove the first item in the list
	{
		first = first->next;
		first->prev = NULL;
		delete pdel;
		return first;;
	}
	if (pdel == last)						//Remove the last item in the list
	{
		last = last->prev;
		last->next = NULL;
		delete pdel;
		return NULL;
	}
	else									 //removal of the median list item
	{
		list* pnext;
		pdel->next->prev = pdel->prev;
		pnext = pdel->prev->next = pdel->next;
		delete pdel;
		return pnext;
	}
	cout<<"\n Delete...";
}

linklist::~linklist()									//  free dynamic memory
{
	clear();
}

void linklist::clear()
{
	list* cur = first;
	list* temp;
	while ( cur!=NULL )
	{
		temp = cur;
		cur = cur->next;
		delete temp;
    }
}

// print reverse list
void newlist::PrintRev()
{
	list* pel = last;
	while ( pel!=NULL )
	{
		cout << pel->number << endl;
		pel = pel->prev;
	}
}