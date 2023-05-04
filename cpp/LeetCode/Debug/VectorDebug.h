#include <vector>

template <typename T>
void printVector(const std::vector<T>& v){
    if(v.size()==0){
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[ ";
    for(T n : v){
        std::cout << n << ", ";
    }
    std::cout << "\b\b]" << std::endl;
}

template <typename T>
void print2DVector(const std::vector<std::vector<T>>& v){
    if(v.size()==0){
        std::cout << "[]" << std::endl;
        return;
    }
    std::cout << "[" << std::endl;
    for(std::vector<T> r : v){
        std::cout << "  [";
        for(T n : r){
            std::cout << n << ",";
        }
        std::cout << "\b]" << std::endl;
    }
    std::cout << "]" << std::endl;
}

template <typename T>
void refresh2DVector(const std::vector<std::vector<T>>& v){
    system("CLS");
    print2DVector(v);
}