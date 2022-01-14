#include <iostream>
#include <vector>
#include <iterator>

template <typename Type, typename Iter>
Iter binarySearch(Iter, Iter, const Type);


int main() {
    std::vector <int> vec {15,52,66,77,99,125,365};
    auto search = 455;

    auto result = binarySearch(vec.begin(),vec.end(),search);

    std::cout << *result;

    return 0;
}


template <typename Type, typename Iter>
Iter binarySearch(Iter it1, Iter it2, const Type element) {
    static Iter InteratorEnd = it2;
    Iter IterForSize = it1;
    int size = 0;
    
    while(IterForSize < it2 ) {
        ++size;
        ++IterForSize;
    }

    auto mid = it1 + size/2;
    if (it1 >= it2) return InteratorEnd; 
    if (element == *mid) return mid;
    if (element == *it1) return it1;
    if (element == *it2) return it2;
    if (element > *mid) {
        it1 = std::next(mid);
        return binarySearch(it1,it2,element);
    }else {
        it2 = std::prev(mid);
        return binarySearch(it1,it2,element);
    }
}