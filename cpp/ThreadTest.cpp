#include <iostream>
#include <thread>
using namespace std;

void func(){
    cout << "Hello from thread" << endl;
}

int main(void){
    thread t(func);
    t.join();

    return 0;
}