
//-----------------
//structure with information about point
//----
struct Point
{
	double x;
	double y;
	Point *next;
};

//------------------------------------------------------------------
//parent class forms list, containing all information about stack 
class Stack
{
	Point* top;			//pointer to the top element
public:
	Stack ( ): top ( NULL ) { }
	~Stack ( ) ;
	Point * stackputinfo( );
	void stackpush ( ) ;
	Point * stackpop ( ) ;
	void stackdel ( ) ;
	void stackclear ( ) ;
	void stackprint ( ) ;
	Point *gettop ( )    // returns top element
	{
		return top; 
	}
	void settop ( Point *pel )     // allows you to set top element
	{
		top = pel;
	}
};


//------------------------------------------------------------------
//child class
//derives all list-information and structure from parent class
//realizes the search for the minimum distance between two points and deleting this poins
class Distance : private Stack
{
public:
	Distance ( )  {  
		Stack( ); 
	}
	~Distance ( ) 
	{
		stackclear( ); 
	}
	double dist ( Point * p1, Point *p2 ) ;
	bool findmin ( );
	void delelem ( Point *pdel ) ;
	void push ( ) 
	{
		stackpush( );
	} 
	Point * pop ( ) 
	{
		stackpop( );
	}
	void del ( ) 
	{
		stackdel( ); 
	}
	
	void print ( ) 
	{
		stackprint( );
	}
};

