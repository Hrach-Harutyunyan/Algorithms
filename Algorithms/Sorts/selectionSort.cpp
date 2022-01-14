#include <iostream>
#include <vector>


template <typename Iter>
void selectionSort(Iter, Iter);

template <typename T>
void swap(T&, T&);


int main() {
    
    std::vector<int> vec {15, 2,36,4,5,44,75,6,95,222,12};
    
    selectionSort(vec.begin(),vec.end());

    for(auto& el : vec){
        std::cout << el << ",\t";
    }
    std::cout << std::endl;

    return 0;
}


template <typename Iter>
void selectionSort(Iter it1, Iter it2) {
    for(; it1 != std::prev(it2); ++it1) {
        auto max = it1; 
        for(auto tmpIter = std::next(it1); tmpIter != it2; ++tmpIter) {
            if (*max > *tmpIter) {
                max = tmpIter;
            }
        }
        swap(*it1, *max);
        
    }
};

template<typename T>
void swap(T& lhs, T& rhs) {
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}
