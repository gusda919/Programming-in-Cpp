
#include <string>


struct current_time
{
   
    int hour{0};
    int minute{0};
    int second{0};
};




//Checks if time is valid
bool is_valid(current_time const& time);

//Checks if the time is before 12:00
bool is_am(current_time const& time);
//Converts the time from ints to a string, 
std::string to_string(current_time const& time, bool const& is_twelve);

current_time operator +(current_time const& time, int const& seconds_added) ;

current_time operator -(current_time const& time, int const& added_time);

//PREFIX
current_time& operator ++(current_time& time) ;
//POSTFIX
current_time operator ++(current_time& time, int) ;
//PREFIX
current_time& operator --(current_time& time) ;

//POSTFIX
current_time operator --(current_time& time, int);

//Compare two times
bool operator <(current_time const& time1 , current_time const& time2);

//Checks if two times are not the same
bool operator !=(current_time const& time1, current_time const& time2);

//Compares two times
bool operator >(current_time const& time1, current_time const& time2);

//Checks if two times are the same
bool operator ==(current_time const& time1, current_time const& time2);

bool operator <=(current_time const& time1, current_time const& time2);

bool operator >=(current_time const& time1, current_time  const& time2);

//Prints the string
std::ostream& operator <<(std::ostream& os, current_time const& time);
//Takes in a time and puts it in current_time
std::istream& operator >>(std::istream& is, current_time& time);