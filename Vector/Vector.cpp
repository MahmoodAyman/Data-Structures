#include<bits/stdc++.h>
using namespace std;
class Vector{
    private:
        int *arr = nullptr; // initial array by default is nullptr
        int size; // size with initial value 0
    public:
    Vector (int size): // constractor take variable size and initialize size with passed size 
        size(size){
            if(size<0) // condition to handle if someting wierd happend like intializing vector with size less than 0! make it one 
                size = 1;
            arr = new int[size]{}; // creating internal array with size of passed size
        }
    ~Vector(){ // destructor
        delete[] arr; // deleting internal array
        arr=nullptr; // setting internal array to nullptr
    }
};