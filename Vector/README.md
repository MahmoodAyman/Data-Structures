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
    // and append_back function will loop every time the size of array + 1 
   // so steps per call are 1 + 2 + 3 + 4 + ..... + n = n* (n+1)/2 steps 
   // so total steps are n^2 which is 10 ^ 12 steps 
}
```
which mean the 10 ^ 6 loop will take 5 million steps 

but there is a capacity trick 😉

### Capacity 
think about make push_back faster 
what if the user ask for a vector with capacity of 10 we reserved array of size 3000?  
sound good right?
but after 2990 steps the array will be full again!
let's multiply with 2 and now we have array of 6000 
when we reach for 6000 steps we will have to resize the array to 2 * 6000 = 12000

. now one value will take linear time but all of the other values will pushed in 2 steps only 

for that we need two sizes the real size and the capacity