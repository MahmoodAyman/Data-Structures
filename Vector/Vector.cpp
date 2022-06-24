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
    int get(int idx){// get function to get array of index 
        assert(0 <= idx && idx < size);// condition must be true to continue otherwise it will throw an error exception or do nothing
        // and this is for vrifiction purpose and in practice we don't write this
        return arr[idx]; // return array of index
    }
    int set(int idx,int value){ // set function to set array of index with value 
        assert(0<= idx && idx < size);//
        arr[idx] = value; // set array of index to value
    }
    void print(){// just a simple function to print the vector which is not part of built in vector
        for (int i = 0; i < size;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int find(int value){// function to find a specific value in vector
        for (int i = 0; i < size;i++){
            if(arr[i]==value)
                return i;
        }
        return -1; // return -1 if not found 
    }
};
int main(){
    Vector v(10); // initializing vector with size 10 and all indices has 0 value
    for (int i = 0; i < 10;i++){
        v.set(i, i); // use set function to set values form 0 -> 9 to array
        // set index of i with value i 
    }
    v.print(); // use print function that we created above
    cout << v.find(5) << " " << v.find(-10) << endl; // use find function to find value in vector
    // find value 5 will return 5 position since it inserted at 5 position and -10 will return -1 since it is not inserted in vector
} 