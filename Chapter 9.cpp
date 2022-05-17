#include "std_lib_facilities.h"



struct Date{
	int y;
	int m;
	int d;
	    };



void init_date(Date& date, int yy, int mm, int dd)
{
	if (yy < 0 || mm < 0 || mm > 12 || dd < 1  || dd > 31)
		error ("Invalid date"); 
	
		date.y = yy;
		date.m = mm;
		date.d = dd;
		
	
}



void add_day(Date& date, int n)
{
	
	date.d += n;		// add n-days to date
}



ostream& operator<<(ostream& os, const Date& d)
{
	return os << d.y << '-' << d.m << '-' << d.d ;
	
}



int main()
try {
	Date today;		// for checking valid values
	Date invalid;		// for checking invalid values
	
	init_date(today, 1978, 6, 25);	
	
	Date tomorrow(today);

	add_day(tomorrow, 1);  // add 1 to today to become tomorrow 

	cout << "Today is " << today << endl;
			
	cout << "Tomorrow is " << tomorrow << endl;


	// for invalid date
		
	init_date(invalid, 2004, 13, -5);
	
	cout << invalid << endl;

	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}

//Q2!!//

#include "std_lib_facilities.h"


struct Date
  {
	int y, m, d;
	

Date(int yy, int mm, int dd)
 {
	if (yy < 0 || mm < 1 || mm > 12 || dd < 1  || dd > 31)
		error ("Invalid date input");  
	
		y = yy;
		m = mm;
		d = dd;
		
 }




void add_day( int n)
	{
	d=d+n;	// to increase date by ndays
	}
  }; // ';'is obligatory after structs


	ostream& operator<<(ostream& os, const Date& d)

     {
		return os << d.y << '-' << d.m << '-' << d.d ;
     }



int main()
try 
 {
	// initiallizing today
	Date today = {1978, 6, 25};
	cout << " Today is: " << today << endl;
	
	//checking tomorrow
	Date tomorrow = today; //to give tomorrow's same value as today then add n over it
	tomorrow.add_day(1);  // in that case n is 1 
	cout << " Tomorrow is: " << tomorrow << endl;   // print tomorrow ( today+1)
 		
	
	//checking invalid date
		
	Date invalid = {2004, 13, -5};
	cout << invalid << endl;
	
	
	
		return 0;
 }
 catch (exception& e)
{
	cerr << e.what() <<endl;
		return 1;
}

//Q3!!//

#include "std_lib_facilities.h"
  class Date
  {
  private:
  
  	int y, m, d; 		// Implementation or Class members 
  
  public:
  	
  	Date( int y, int m, int d);
  	void add_day(int n);
  	int month() const { return m; }
  	int day() const { return d; }
  	int year() const { return y; }
  	
  };
  	
  Date::Date(int yy, int mm, int dd): y{yy}, m{mm}, d{dd}
  
  {
  	if (yy < 0 || mm < 1 || mm > 12 || dd < 1  || dd > 31) error ("Invalid Input");	
  }
  
  	void Date::add_day (int n)
   {
  		d+=n;
  		if (d > 31) d %= 31;
   }
   	ostream& operator <<(ostream& os, const Date& d)
     {
		return os << d.year() << '-' << d.month() << '-' << d.day() ;
     }
     
     	int main()
try
 { 
 	// initiallizing today
    Date today(1978, 6, 25);
    cout << "Today is: " << today << '\n';
    
    Date tomorrow = today;
    tomorrow.add_day(1); // add 1 to tomorrow 
    cout << "Tomorrow is: " << tomorrow << '\n'; // print tomorrow ( today+1)
   
     //checking invalid date
     Date invalid = {2004, 13, -5};
	cout << invalid << endl;
     return 0;
  }
  catch (exception& e)
{
	cerr << e.what() <<endl;
		return 1;
}

//Q4!!//

#include "std_lib_facilities.h"


 enum class Month {
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
  	 	   };

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}
vector<string> months {
	"January" , "February" , "March" , "April",	"May" , "June" , "July" , "August" , "September" , "October" , "November" , "December"
};

ostream& operator<<(ostream& os, Month m)  	//define output operator
{
	return os << months[int(m)];  // int is essential 

}

class Date {
private:
	int y,d;
	Month m;
			// Implementation or Class members 
	
	bool is_valid()
	{
		if (y < 0 ||  d < 1 || d > 31) return false;
			
			return true;				
	}

public:
	Date(): y(2001), m(Month::jan), d(1) {}	// Default value

	Date(int yy, Month mm, int dd): y(yy), m(mm), d(dd)
	{
		if (!is_valid()) error("Invalid date");
			
		
	}
			// Constructor , Instanciation
	int get_year()  { return y; }
	Month get_month()  { return m; }
	int get_day()  { return d; }
	void set_year (int yy) 
	{ 
		if (yy < 0) error ("Invalid year");
		y = yy; 	
	}
	void set_month (Month mm) 
	{
		m = mm;
	}
	void set_day (int dd) 
	{ 
		if (dd < 1  || dd > 31) error ("Invalid day");
		d = dd; 
	}
	void add_day(int n)
	{
		d+=n;
		if (d > 31)
		{
			d=1;
			++m;
			if (m == Month::jan)
			{
				++y;
			}
		}
	}
			// Interface of the class 		
			
}; // ";" must follow clases and structs





	ostream& operator<<(ostream& os, Date& date)
	
{
	return os << date.get_year() << "-" << date.get_month() << "-" << date.get_day() << " ";
}



 
	int main()
	
try {
	Date today (1978, Month::jun, 25);
	cout << Today is: << today << endl;		// check today 
	
	Date tomorrow = today; 
	tomorrow.add_day(1);  	// add 1 to today to become tomorrow 
	cout << Tomorrow is:  << tomorrow << endl;	// print tomorrow 
	
	Date invalid(2004, Month::apr, -5);		// for Invalid dates
	cout << invalid << endl;
		
	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}

//Q5!!//

#include "std_lib_facilities.h"


 enum class Month {
	jan, feb, mar, apr, may, jun, july, aug, sept, oct, nov, dec
  	 	   };

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m)+1);
	return m;
}
vector<string> months {
	"January" , "February" , "March" , "April",	"May" , "June" , "July" , "August" , "September" , "October" , "November" , "December"
};

ostream& operator<<(ostream& os, Month m)  	//define output operator
{
	return os << months[int(m)];  // int is essential 

}

class Date {
private:
	int y,d;
	Month m;
			// Implementation or Class members 
	
	bool is_valid()
	{
		if (y < 0 ||  d < 1 || d > 31) return false;
			
			return true;				
	}

public:
	Date(): y(2001), m(Month::jan), d(1) {}	// Default value

	Date(int yy, Month mm, int dd): y(yy), m(mm), d(dd)
		{
	
		if (!is_valid()) error("Invalid date");
				
		}
			// Constructor , Instanciation
	int get_year() const { return y; }
	Month get_month() const { return m; }
	int get_day() const { return d; }
	void set_year (int yy) 
		{ 
		if (yy < 0) error ("Invalid year");
		y = yy; 	
		}
	void set_month (Month mm) 
	{
		m = mm;
	}
	void set_day (int dd) 
	{ 
		if (dd < 1  || dd > 31) error ("Invalid day");
		d = dd; 
	}
	void add_day(int n)
	{
		d+=n;
		if (d > 31)
		{
			d=1;
			++m;
			if (m == Month::jan)
			{
				++y;
			}
		}
	}
			// Interface of the class 		
			
}; // ";" must follow clases and structs





	ostream& operator<<(ostream& os, const Date& date)
	
{
	return os << date.get_year() << "-" << date.get_month() << "-" << date.get_day() << " ";
}



 
	int main()
	
try {
	const Date today (1978, Month::jun, 25);
	cout << "Today is: " << today << endl;		// check today 
	
	Date tomorrow = today; 
	tomorrow.add_day(1);  	// add 1 to today to become tomorrow 
	cout << "Tomorrow is: " << tomorrow << endl;	// print tomorrow 
	
	Date invalid(2004, Month::apr, -5);		// for Invalid dates
	cout << invalid << endl;
		
	return 0;
} catch (exception& e) {
	cerr << e.what() <<endl;
	return 1;
}
