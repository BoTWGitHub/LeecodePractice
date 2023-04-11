/*
Design an algorithm that collects daily price quotes for some stock and returns the span of that stock's price for the current day.

The span of the stock's price today is defined as the maximum number of consecutive days (starting from today and going backward) 
for which the stock price was less than or equal to today's price.

For example, if the price of a stock over the next 7 days were [100,80,60,70,60,75,85], then the stock spans would be [1,1,1,2,1,4,6].
Implement the StockSpanner class:

StockSpanner() Initializes the object of the class.
int next(int price) Returns the span of the stock's price given that today's price is price.
*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class StockSpanner {
public:
    int next(int price) {
        int ans = 1;
        while (!stack.empty() && stack.top().first <= price) {
            ans += stack.top().second;
            stack.pop();
        }
        
        stack.push({price, ans});
        return ans;
    }
private:
    stack<pair<int,int>> stack;
};

int main(void){
    StockSpanner ss;
    cout << ss.next(100) << endl;
    cout << ss.next(80) << endl;
    cout << ss.next(60) << endl;
    cout << ss.next(70) << endl;
    cout << ss.next(60) << endl;
    cout << ss.next(75) << endl;
    cout << ss.next(85) << endl;
    return 0;
}