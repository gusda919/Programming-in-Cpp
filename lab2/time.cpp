#include "time.h"
#include <sstream>
#include <ostream>
#include <iostream>
#include <iomanip>

using namespace std;

//Checks if time is valid
bool is_valid(current_time const& time) {
    if (time.hour < 0 || time.hour > 23 || time.minute < 0 || time.minute > 59 || time.second < 0 || time.second > 59) {
        return false;
    } else {
        return true;
    }
}

//Checks if the time is before 12:00
bool is_am(current_time const& time) {
    return time.hour < 12;
}

//Converts the time from ints to a string, 
string to_string(current_time const& time, bool const& is_twelve){
     std::ostringstream time_string{};
    // setfill is now used once 
    time_string << std::setw(2) << std::setfill('0');
    string pm_am{};

    if (is_twelve)
    {
        if (time.hour == 0)
        {
            time_string << 12;
            pm_am = " am";
        }
        else if (is_am(time) or time.hour <= 12)
        {
            pm_am = " am";
            time_string << time.hour;
        }
        else
        {
            time_string << time.hour - 12;
            pm_am = " pm";
        }
    }
    else
    {
	    time_string << time.hour;
    }
    
     time_string << ":" << std::setw(2) << time.minute << ":"
       << std::setw(2) << time.second << pm_am;
					   
    return time_string.str();
}

current_time operator +(current_time const& time, int const& seconds_added) {
    current_time new_time{time};
    new_time.second = time.second + seconds_added;

    while (new_time.second >= 60) {
        new_time.second = new_time.second - 60;
        new_time.minute = new_time.minute + 1;
      
        while (new_time.minute >= 60) {
            new_time.minute = new_time.minute - 60;
            new_time.hour  = new_time.hour + 1;

            if (new_time.hour >= 24) {
                new_time.hour = new_time.hour - 24;
            }
        }
    }

   return new_time;
}

current_time operator -(current_time const& time, int const& added_time) {
    current_time new_time{time};
    new_time.second = time.second - added_time;
   
    while (new_time.second < 0) {
        new_time.minute = new_time.minute - 1;
        new_time.second = new_time.second + 60;
        

        while (new_time.minute < 0) {
            new_time.hour = new_time.hour - 1;
            new_time.minute = new_time.minute + 60;

            if (new_time.hour < 0) {
            new_time.hour = new_time.hour + 24;
            }
        }
    }

    return new_time;
}

//PREFIX
current_time& operator ++(current_time& time) {
    time = time + 1;
    return time;
}

//POSTFIX
current_time operator ++(current_time& time, int) {
     current_time tmp{time}; 
     ++time;
     return tmp;
}

//PREFIX
current_time& operator --(current_time& time) {
    time = time - 1;
    return time;
}

//POSTFIX
current_time operator --(current_time& time, int) {
    current_time tmp{time};
    --time;
    return tmp;
}

//Compare two times
bool operator <(current_time const& time1 , current_time const& time2) {
    int time1_secs = time1.hour*3600 + time1.minute*60 + time1.second;
    int time2_secs = time2.hour*3600 + time2.minute*60 + time2.second;

    if(time1_secs > time2_secs) {
        return false;
    }

    return true;
}

//Checks if two times are not the same
bool operator !=(current_time const& time1, current_time const& time2) {
    if(time1 < time2 || time2 < time1) {
        return true;
    }

    return false;
}

//Compares two times
bool operator >(current_time const& time1, current_time const& time2) {
    bool is_less_than = time1 < time2;
    
    if(!is_less_than && time1 != time2) {
        return true;
    }

    return false;
}

//Checks if two times are the same
bool operator ==(current_time const& time1, current_time const& time2) {
    if (time1 != time2) {
        return false;
    }
    
    return true;
}

bool operator <=(current_time const& time1, current_time const& time2) {
    if (time1 < time2 || time1 == time2) {
        return true;
    }

    return false;
}

bool operator >=(current_time const& time1, current_time const& time2) {
    if (time1 > time2 || time1 == time2) {
        return true;
    }
    
    return false;
}

//Prints the string
std::ostream& operator <<(std::ostream& os, current_time const& time) {
    os << to_string(time, false);
    return os;
}

//Takes in a time and puts it in current_time
std::istream& operator >>(std::istream& is, current_time& time) {
    current_time temp{};

    is >> temp.hour;
    is.ignore(1, ':');
    is >> temp.minute;
    is.ignore(1, ':');
    is >> temp.second;

    if (not is_valid(temp)) {
	    is.setstate(std::ios_base::failbit);
        return is;
    }

    time = temp;

    return is;
}