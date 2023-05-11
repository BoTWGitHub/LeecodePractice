/*
There is an exam room with n seats in a single row labeled from 0 to n - 1.

When a student enters the room, they must sit in the seat that maximizes the distance to the closest person. 
If there are multiple such seats, they sit in the seat with the lowest number. 
If no one is in the room, then the student sits at seat number 0.

Design a class that simulates the mentioned exam room.

Implement the ExamRoom class:

ExamRoom(int n) Initializes the object of the exam room with the number of the seats n.
int seat() Returns the label of the seat at which the next student will set.
void leave(int p) Indicates that the student sitting at seat p will leave the room. 
It is guaranteed that there will be a student sitting at seat p.
*/
#include <iostream>
#include <set>

class ExamRoom {
public:
    ExamRoom(int n) {
        this->n = n;
        seats.clear();
    }
    
    int seat() {
        if(seats.empty()){
            seats.insert(0);
            return 0;
        }
        else{
            int maxDiff = 0;
            int res= 0;
            if(seats.count(0)==0){
                maxDiff = *seats.begin();
            }

            int last = -1;
            for(int s : seats){
                if(last!=-1){
                    if((s-last)/2>maxDiff){
                        maxDiff = (s-last)/2;
                        res = last+maxDiff;
                    }
                }
                last = s;
            }

            if(seats.count(n-1)==0){
                if(n-1-*seats.rbegin()>maxDiff){
                    res = n-1;
                }
            }
            seats.insert(res);
            return res;
        }
    }
    
    void leave(int p) {
        seats.erase(p);
    }
private:
    int n;
    std::set<int> seats;
};

int main(void){
    ExamRoom er(10);
    std::cout << er.seat() << std::endl;
    std::cout << er.seat() << std::endl;
    std::cout << er.seat() << std::endl;
    std::cout << er.seat() << std::endl;
    er.leave(4);
    std::cout << er.seat() << std::endl;
    return 0;
}