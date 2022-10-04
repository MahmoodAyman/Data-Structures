# Data-Structures


### 1- What is a Data Structures? 
it's just a way to organize data and operations over them 

---

### 2- Why Data Structures?
array is limited what if you want to delete element or add element? 

so you need to create something more dynamic

---


#### there is built-in Data Structures in almost all programming language 

#### for example in c++ built in data structure called STLs, in Java and C# called collections

this is because there are common tasks and during software history we could recognize them 
some data and operation on them are common and repetitive 
### 3- Why not just use built-in DS?
using built in DS as a black box without understanding their details is a big risk 

- you need to realize time and memory order
- you will not be able to recognize the difference between different DS 
- from time to time you will be need to build your own DS

---

## Pre-requisites

- in order to understand DS you need to have a basic **[OOP](https://github.com/MahmoodAyman/OOP-CPP)** knowledge

- You need to know about **Assertions** 
    actually this is not very important we just will use **assert** for verifications 

    like check if the size of array is not negative or check if the index is not out of bound

    
## handling with assert:
assert is a function that will check if the condition is true if not it will stop the program and print the error message

```cpp
assert(idx>=0 && idx<=size); 
```
- this will check if the index is in the range of the vector

if not the output will be: 
> Assertion failed: (idx>=0 && idx<=size)

else your program will continue normally


- you can print your own message by adding a string to the assert function

```cpp
assert(idx>=0 && idx<=size && "index out of range");
```
- the same example but with custom message
if condition is false the output will be:
> Assertion failed: (idx>=0 && idx<=size) && "index out of range"

else your program will continue normally