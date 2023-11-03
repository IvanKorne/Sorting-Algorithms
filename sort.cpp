#include <iostream>
int main();
void select(double array[], std::size_t cap);
std::size_t is_sorted(double const array[], std::size_t const cap);
void swap(double &first,double &second);
std::size_t max(double array[], std::size_t cap);
void insert(double array[],std::size_t cap);
void insert_sort(double array[],std::size_t cap);


int main(){
    double array[10] = {4,2,10,7,9,3,1,6,8,5};
    select(array,10);
    for(int i = 0; i < 10; i++){
        std::cout<<array[i]<<std::endl;
    }

    return 0;
}

//Check if sorted.
std::size_t is_sorted(double const array[], std::size_t const cap){
    for(std::size_t i{1}; i < cap; i++){
        if(array[i]<array[i-1]){
            return i;
        }
    }
    return cap;
}

//Selection Sort.
void swap(double &first, double &second){
    double tmp = first;
    first = second;
    second = tmp;
}
std::size_t max(double array[], std::size_t cap){
    std::size_t x = 0;
    for(std::size_t k = 1; k<cap; k++){
        if(array[k]>array[x]){
            x = k;
        }
    }
    return x;
}

void select(double array[], std::size_t cap){
    for(std::size_t k = cap-1; k > 0; k--){
        std::size_t n = max(array,k+1);
        swap(array[n],array[k]);
    }
}

//Insert sort.
void insert(double array[],std::size_t cap){
    double value = array[cap-1];
    std::size_t k = 0;
    for(k = cap-1;(k>0) && (array[k-1] > value); k--){
        array[k] = array[k-1];
    }
    array[k] = value;
}
void insert_sort(double array[],std::size_t cap){
    for(std::size_t k = 2; k <= cap; k++){
        insert(array, k);
    }
}