#include <iostream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
const int buffer_size = 5;
int delay = 90;
void producer() {
    int data = 0;
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return buffer.size() < buffer_size; });
        buffer.push(data);
        std::cout << "==> Produced: " << data << "," << buffer.size() << std::endl;
        ++data;
        lock.unlock();
        cv.notify_one();
        if(buffer.size()==5){
            delay = 110;
        }
        else if(buffer.size()==1){
            delay = 90;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}

void consumer() {
    while (true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{ return !buffer.empty(); });
        int data = buffer.front();
        buffer.pop();
        std::cout << "<== Consumed: " << data << std::endl;
        lock.unlock();
        cv.notify_one();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}