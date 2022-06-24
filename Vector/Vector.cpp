#include<bits/stdc++.h>
using namespace std;
class Vector{
    private:
        int *arr = nullptr; 
        // initial array by default is nullptr
        int size {0};
         // size with initial value 0
        int capacity{}; 
        // capacity for making push_back fast 

    public:
    Vector (int size): 
    // constractor take variable size and initialize size with passed size 
        size(size){
            if(size<0)
             // condition to handle if someting wierd happend like intializing vector with size less than 0! make it one 
                size = 1;
            capacity = size + 10;
            arr = new int[capacity]{};
             // creating internal array with size of passed size
        }
    ~Vector(){ 
        // destructor
        delete[] arr;
         // deleting internal array
        arr=nullptr;
         // setting internal array to nullptr
    }
    void get(int idx){
        // get function to get array of index 
        assert(0 <= idx && idx < size);
        // condition must be true to continue otherwise it will throw an error exception or do nothing
        // and this is for vrifiction purpose and in practice we don't write this
         arr[idx];
         // return array of index
    }
    void set(int idx,int value){ 
        // set function to set array of index with value 
        assert(0<= idx && idx < size);
        arr[idx] = value;
         // set array of index to value
    }
    void print(){
        // just a simple function to print the vector which is not part of built in vector
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
        return -1; 
        // return -1 if not found 
    }
    int get_front(){
        return arr[0]; 
        // return first element of vector
    }
    int get_back(){
        return arr[size-1]; 
        // return last element of vector
    }
    void append_back(int value){ 
        // this called push_back in built in vector 
        int *temp = new int[size+1]{}; 
        // create an array with a new size
        for (int i = 0; i < size;i++){
            temp[i] = arr[i]; 
            // copy old array to new temp array 
        }
        temp[size++] = value;
         // assign last element of temp array to value
        swap(arr, temp);
        // assign new values to array 
        delete[] temp; 
        // delete useless data 
    }
    void expand_capacity(){ 
        // function will do our old push_back code -> append_back without adding value just expand size
        capacity *= 2;
        int *temp = new int[capacity]{}; 
        // create an array with a new size
        for (int i = 0; i < size;i++){
            temp[i] = arr[i]; 
            // copy old array to new temp array 
        }
        swap(arr, temp);
        // assign new values to array 
        delete[] temp; 
        // delete useless data 
    }
    // function with handling the time problem
        void push_back(int value){
        // emplace back is more faster than append as you see 
        if (size==capacity){
            expand_capacity();// function to multiply size by 2 
        }
        arr[size++] = value;
    }
};
int main(){
    int n = 4;
    Vector v(n); 
    // initializing vector with size 4 and all indices has 0 value
    for (int i = 0; i < n;i++){
        v.set(i, i); 
        // use set function to set values form 0 -> 9 to array
        // set index of i with value i 
    }
    // v.print(); 
    // use print function that we created above
    // cout << v.find(5) << " " << v.find(-10) << endl;
    // find value 5 will return 5 position since it inserted at 5 position and -10 will return -1 since it is not inserted in vector
    for (int i = 0; i < 100;i++)
        v.push_back(50);
    v.print();
} 