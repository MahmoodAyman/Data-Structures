# Vector

one of the most easy and common data structures 
used class called Vector with captial V to differentiate from the built in STL

Vector is just an array with more flexability so it's intuitive to use array internally 
but array inside vector will have size and pointer 

every line in code will be explained by comment beside 

---

### this is about the data 

## what about functions? 

functions like insert, remove, find, sort, reverse,...

---

## let's start coding: 

### first with the basic:  

``` cpp
class Vector{
private:
    int *arr= nullptr;   // initial array by default is nullptr
    int size=0;   // size with initial value 0
public:
    Vector(int sz): // constructor 

        size(sz){ // initialize size to be sz 
        
            if(sz<0)sz=1; // condition to handle if someting wierd happend like intializing vector with size less than 0! make it one

            arr=new int [sz]{}; // create array with size sz
    }
    ~Vector(){ // destructor
        delete []arr; // delete array
        arr= nullptr;
    }
};
```
- the code above is contains a constructor and destructor
- **constructor** will take size of array and initialize it 
    and will handle the case if the size less than 0

- **destructor** will delete the array and set it to nullptr

### Getters and Setters

``` cpp
int get(int idx){
    return arr[idx];
}
void set(int idx,int val){
    arr[idx]=val;
}
```
- **get** will return the value of the array at index *idx*
- **set** will set the value of the array at index *idx* to be *val*

#### we can add some verifications to the getters and setters:
    
``` cpp
int get(int idx){
     assert((idx>=0 && idx<=size) && "index out of range");
    return arr[idx];
}
void set(int idx,int val){
     assert((idx>=0 && idx<=size) && "index out of range");
    arr[idx]=val;
}
```
---

## Operations: 

### Print 

``` cpp
void print(){
    for(int i=0;i<size;i++)cout<<arr[i]<<" ";
    cout<<endl;
}
```
just print the vector elements 

### find: 
```cpp
int find(int val){
    for(int i=0;i<size;i++){
        if(arr[i]==val)return i;
    }
    return -1;
}
```

return the index of the first occurance of the value *val* in the vector

if not found will return -1 

this is a linear time operation

### print front and back: 

``` cpp
int get_front(){
    return arr[0];
}
int get_back(){
    return arr[size-1];
}
```
---

### Appending:

there is a little problem in appending or pushing back since we created array with fixed size *size* and we want to append *size+1* elements! 

we need to resize the array by creating new array with size *size+1* and copy the old array to the new one! 

this is seems stupid but it's the way to do it till we reach the capacity trick 😉 


``` cpp
void push_back(int val){
    int *temp=new int[size+1];
    for(int i=0;i<size;i++){
        temp[i]=arr[i];
    }
    temp[size++]=val;
    swap(arr,temp);
    delete[]temp;
}
```
1. first we create a new array with size *size+1*
2. copy the old array to the new one
3. add the new value to the end of the array
4. delete the old array
5. set the old array to be the new one
6. delete the new array

## Capacity trick: 
now the code above is not efficient at all! what about we pushing back 10^6 elements?

which mean the 10 ^ 6 loop will take 10 ^ 12 steps!

think about make push_back faster by not creating new array every time we want to append to the vector

### what if the user ask for a vector with capacity of 10 we reserved array of size 3000?  sound good right?

but after 2990 steps the array will be full again!

let's multiply with 2 and now we have array of 6000 

when we reach for 6000 steps we will have to resize the array to 2 * 6000 = **12000**

now one value will take linear time but all of the other values will pushed in **2** steps only 

for that we need two sizes the real size (the user thinke he has) and the capacity(real size)! 
    
``` cpp
class Vector{
private:
    int *arr= nullptr;   // initial array by default is nullptr
    int size=0;   // size with initial value 0
    int capacity=0;

    void expand_capacity(){ // this will work as the old push_back
        // but the number of times this function will work is a little
        capacity*=2;
        int *temp = new int [capacity]{};
        for(int i=0;i<size;i++)temp[i]=arr[i];
        swap(arr,temp);
        delete []temp;
    }
public:
    Vector(int sz):
        size(sz){
            if(sz<0)sz=1;
            capacity=sz+10;
            arr=new int [capacity]{}; // see we created the array with capacity
            // not size!
    }
    void push_back(int val){
        if(size==capacity)expand_capacity(); //function that will be called when real size is full
        arr[size++]=val; // this will work normal cause there is more space
        // than size actually
    }
    
}
```
I hope this is clear enough!

I put the **expand_capacity** function in the private section cause we don't want the user to call it directly from the vector object

---
## let's continue with the operations:
### Size: 
return the size of the vector

```cpp
int get_size(){
    return size;
}
```
### is empty:
return true if the vector is empty

```cpp
bool is_empty(){
    return size==0;
}
```
### clear:
clear the vector

```cpp
void clear(){
    size=0;
}
```
### remove:
remove value at index idx
```cpp
    void remove(int idx){
        assert(idx>=0 && idx<=size && "index out of range");
        // shift all elements to the left
        for(int i=idx;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;// decrease size by one
    }
```
### pop back:
remove the last element in the vector

```cpp
void pop_back(){
    size--;
}
```

### insert:
insert value at index idx

the time complexity of this operation is **O(n)**

```cpp
    void insert(int idx,int val){

        assert(idx>=0 && idx<=size && "index out of range");
        // check if we can add at all
        if(size==capacity)expand_capacity();
        // shift all elements to the right
        for(int i=size;i>idx;i--){
            arr[i]=arr[i-1];
        }
        arr[idx]=val; // add the new value
        size++;// increase size by one
    }
```

---


--- 


you can access the elements of the vector by using get function 

but what if you want to access them by **[]** 

here you need somethink called **[operator overloading](https://github.com/MahmoodAyman/OOP-CPP/tree/main/6-Operator%20overloading)**

time to code now!
```cpp
int operator[] (int idx){ // you specify the [] to be a function that return value in the array
    return arr[idx];
}
```

---
## this is about vector of integers what about If we want to make vector of **any type**?

you can just copy the code and change the type of the array to be the type you want

but this is not practical at all!

c++ has a feature called **templates** which allow us to make a class that can work with any type

```cpp
template <typename T> 
// template T is the type will specify later
class Vector{
private:
    T *arr= nullptr; // initial array of type T by default is nullptr
    int size=0;
    int capacity=0;
    void expand_capacity();
public:
// and so on
```
---

### there is a lot to make your code more typical and more efficient like abstracting the code and making it more readable but this is none of the data structures perspectives

capcity trick code:

```cpp
template <typename T>
class Vector{
private:
    T *arr= nullptr; // initial array of type T by default is nullptr
    int size=0;
    int capacity=0;
    void expand_capacity(){
        capacity*=2;
        T *temp = new T [capacity]{};
        for(int i=0;i<size;i++)temp[i]=arr[i];
        swap(arr,temp);
        delete []temp;
    }
public:
    Vector(int sz):
        size(sz){
            if(sz<0)sz=1;
            capacity=sz+10;
            arr=new T [capacity]{}; // see we created the array with capacity
            // not size!
    }
    void push_back(T val){
        if(size==capacity)expand_capacity();
        arr[size++]=val;
    }
    int get_size(){
        return size;
    }
    bool is_empty(){
        return size==0;
    }
    void clear(){
        size=0;
    }
    void remove(int idx){
        assert(idx>=0 && idx<=size && "index out of range");
        // shift all elements to the left
        for(int i=idx;i<size-1;i++){
            arr[i]=arr[i+1];
        }
        size--;// decrease size by one
    }
    void pop_back(){
        size--;
    }
    void insert(int idx,T val){
        assert(idx>=0 && idx<=size && "index out of range");
        // check if we can add at all
        if(size==capacity)expand_capacity();
        // shift all elements to the right
        for(int i=size;i>idx;i--){
            arr[i]=arr[i-1];
        }
        arr[idx]=val; // add the new value
        size++;// increase size by one
    }
    T operator[] (int idx){ // you specify the [] to be a function that return value in the array
        return arr[idx];
    }
};
```