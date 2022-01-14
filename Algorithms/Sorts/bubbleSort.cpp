#include <iostream>
#include <vector>


template<typename Iter>
void bubbleSort(Iter,Iter);

template <typename T>
void swap(T&, T&);



int main() {
    
    std::vector<int> vec {11,15, 2,1555,36,4,5,44,75,6,95,222,12};
    
    bubbleSort(vec.begin(), vec.end());

    for(auto& el : vec){
        std::cout << el << ",   ";
    }
    std::cout << std::endl;

    return 0;
}



template <typename Iter>
void bubbleSort(Iter it1, Iter it2) {
    for(; it1 != it2 ; ++it1) {
        for(auto tmp = std::next(it1); tmp != it2; ++tmp) {
            if(*it1 > *tmp) {
                swap(*it1, *tmp);
            }
        }
    }
}

template<typename T1>
void swap(T1& lhs, T1& rhs) {
    T1 tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}