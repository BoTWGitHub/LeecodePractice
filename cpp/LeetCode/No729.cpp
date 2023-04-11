/*
You are implementing a program to use as your calendar. 
We can add a new event if adding the event will not cause a double booking.

A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).

The event can be represented as a pair of integers start and end that represents a booking on the half-open interval [start, end)
, the range of real numbers x such that start <= x < end.

Implement the MyCalendar class:

MyCalendar() Initializes the calendar object.
boolean book(int start, int end) Returns true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.
*/
#include <iostream>
#include <utility>
#include <set>
using namespace std;

class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        pair<int, int> event = {start, end};
        set<pair<int, int>>::iterator nextEvent = calender.lower_bound(event);
        if(nextEvent!=calender.end() && nextEvent->first<end){
            return false;
        }
        if(nextEvent!=calender.begin()){
            set<pair<int, int>>::iterator pre = prev(nextEvent);
            if(pre->second>start){
                return false;
            }
        }
        calender.insert(event);
        return true;
    }
private:
    set<pair<int, int>> calender;
};

int main(){
    MyCalendar c;

    cout << c.book(10, 20) << endl;
    cout << c.book(15, 25) << endl;
    cout << c.book(20, 30) << endl;

    return 0;
}
