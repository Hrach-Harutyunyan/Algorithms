#include <iostream>
#include <vector>
#include <iterator>


template <typename Iter>
void insertionSort(Iter,Iter);

template <typename T>
void swap(T&, T&);


int main() {
    
    std::vector<int> vec {15,15, 2,36,4,5,44,75,6,95,222,12};
    
    insertionSort(vec.begin(), vec.end());

    for(auto& el : vec){
        std::cout << el << ",\t";
    }
    std::cout << std::endl;

    return 0;
}


template<typename  Iter>
void insertionSort(Iter it1, Iter it2) {
    for(auto tmpIter1 = it1; tmpIter1 != it2 - 1; ++tmpIter1) {
        for(auto tmpIter2 = std::next(tmpIter1);(tmpIter2  > it1) && (*(std::prev(tmpIter2)) > *tmpIter2); --tmpIter2){
            swap(*(std::prev(tmpIter2)), *tmpIter2);
        }
    }
}

template<typename T>
void swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}