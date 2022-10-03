# Vector

one of the most easy and common data structures 
used class called Vector with captial V to differentiate from the built in STL

Vector is just an array with more flexability so it's intuitive to use array internally 
but array inside vector will have size and pointer 

every line in code will be explained by comment beside 

watch out that append_back function take linear time of steps 

for example: 
``` cpp
Vector v(10);
// this loop will loop 10 ^6 times 
for(int i=0;i<1000000;i++){ 
    v.append_back(i); 

}
```
and append_back function will loop every time the size of array + 1 

so steps per call are 1 + 2 + 3 + 4 + ..... + n = n* (n+1)/2 steps 

so total steps are n^2 which is 10 ^ 12 steps
---

this is about the data 
what about functions? 

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
    if(idx<0 || idx>=size)throw "out of range";
    return arr[idx];
}
void set(int idx,int val){
    if(idx<0 || idx>=size)throw "out of range";
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

### Capacity trick: 
now the code above is not efficient at all! what about we pushing back 10^6 elements?

which mean the 10 ^ 6 loop will take 5 million steps!

think about make push_back faster by not creating new array every time we want to append to the vector

what if the user ask for a vector with capacity of 10 we reserved array of size 3000?  
sound good right?

but after 2990 steps the array will be full again!

let's multiply with 2 and now we have array of 6000 

when we reach for 6000 steps we will have to resize the array to 2 * 6000 = **12000**

now one value will take linear time but all of the other values will pushed in **2** steps only 

for that we need two sizes the real size and the capacity! 
    
``` cpp
```

---

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

