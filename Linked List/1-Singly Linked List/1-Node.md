# The Node 

## Introduction
we didn't use the node in vector cause it's just an array with some extra features,

but in linked list we need to create a node class to store the data and the pointer to the next node.

also this will be helpful in create different data structures like stack and queue.

array is one big block of memory, and it must be continuous, what if the requested memory not continuous but still available?

ok it's make us access elements in O(1) time, but what about expanding the array?

even with capacity trick it's still O(n) time 

### How to avoid this problem? 
can we expand the array with a single element in O(1) time?

#### See the code below
```cpp
int *val1=new int (1);
int *val2=new int (2);
int *val3=new int (3);
int *val4=new int (4);
``` 
### Can we group these elements together? 
can we link val1 to val2, val2 to val3, val3 to val4 and so on if there are more? 

---

## This is the Node Data Structure
```cpp
struct Node{
    int data;
    Node *next;
    Node(int data):data(data){};
};
```
- there is an int data to store the value
- and a pointer of type **Node** to point to the next node! 
    this looks like a recursive relationship, but it's not, it's just a pointer to the next node.

See the image: 

![NODE](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAdwAAABqCAMAAAAhmRAbAAABZVBMVEX///8AAABkZGT29vbDw8Px8fEpKSmioqJaWlp1dXVHR0fe3t6MjIz5+flVVVWsrKzW1tY3Nze6urp+fn5BQUHm5uaVlZXPz8/5//+ysrJ8fHylx01XtUL167L378De4ZvK1nj39+T///RtbW04zb4UtHfW/P9a0b8AqVRr19Genp6RkZEUFBQAsGzT24YAqEq29P0RqC2D4eUArDr79NQAr2Cm7uro//8AsX9jtizs8r0xqC3j8uUApRoeHh79+u3M6NK37+284cSO5e2KxXRVsQfm9txgzsDn78pPx56cx2dnuDppsyFEx6v89tBKsTiO1blOxYXF4qR0xoRvxYZP085dzZel16xhzKpYtTiy043w5p50tkYAsHe20nyO055zxHFgvFtxxpXB8v606LW40WiFwVev6NvN7OTf5697xWuw1ot31bBfvWjB3rSh17ayzF6Z39OayG/b8b9DsUV/37JDuVXIaMuFAAAID0lEQVR4nO2d6V/aSBiAZ1QELw4vQDkEL7SihqigkKKlq6IF67XWlqpttx5rrW3X9e/fmcRuDU7SRBiQ/N7nA2IM4/A+ycybzAwgBAAAAAAAAABATejy/XxQE3n5vfaVAapK5I9xH1qSJh78YW7x4TagsYgsUrnpBELZTIacv9FMJkM2ZzKrILfhiSyuIVnu+qYk5JORDUmKLaBgWhrdArmNTmRTFARRTERfFXzFrUTkNYouFqKllC8sgNxGJ7K5vZzZSSdC4vbuiTjuK+7ubRWK6X1ySoPcRiey+Kfc54bS+YODg5Ul6c3BIci1Bh3ZkiI3spkay76dfSfkQmnSLL8fOxJBbmPjwvbjbeVSiCRUEkmoTqVYoOC7SEv5xf161w6ohH6MO+tdB4APfox76l0HgA+TcN5aFju4tSwujAfqXQeADySXelbvOgB8gFzKukAuZV1c4NayQC5lXSYhl7IsfjhvLQvkUtYFcinr4oLrW+vhdss/IJeyIhi3IMilLArG/TA2b1X8uLUZcimL4iWJFLi1KsOY4PE899e7IkD1keUSXPWuCFAVmlvu4VXcerwtJuioU817cKW4tQvvrbjw2gVCm46K34XO/Q6vo6kyHC3ahXfi562GwJi5eQrrHJZO9msMF/5U5DpddiMM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)

--- 
### create a link:

```cpp
struct Node{
    int data;
    Node* next;
    Node(int data):data(data){};
}
int main() {
    node *node1 = new node(1);
    node *node2 = new node(2);
    node *node3 = new node(3);
    node *node4 = new node(4);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next= nullptr;

}
```

**This is actually the linked list.**

as you see the node 1 connect to node 2, node 2 connect to node 3, node 3 connect to node 4, node 4 connect to nullptr. and so on... 

if you want to add a new node just create it and link it

--- 

## Navigation

see this code
    
```cpp
    struct node {
    int data;
    node *next;

    node(int data) : data(data) {};
};

int main() {
    node *node1 = new node(1);
    node *node2 = new node(2);
    node *node3 = new node(3);
    node *node4 = new node(4);
    node1->next=node2;
    node2->next=node3;
    node3->next=node4;
    node4->next= nullptr;
    cout<<node1->next->next->next->data<<endl;
    cout<<node2->next->next->data<<endl;
    cout<<node3->next->data<<endl;

}
```
what is the output? 

    4
    4
    4 

if you confused just trace this again 
---
### if you are comfortable with this, let's go deeper 

- we will call the first node as head node 
- and will call the last node as tail node

#### How can we print the list of nodes? 
```cpp
void print(node* head){ // pass you first node to the function which is head node
    while(head != nullptr){ // print till the last node which is the tail
        cout<<head->data<<endl; // print the data of the node
        head=head->next;// move the pointer to the next node
    }
}
```
#### Here is the code in recursive way in case you curious about it
```cpp
void prin(node*head){
    if(head==nullptr)return;
    cout<<head->data<<endl;
    prin(head->next);
}
```
#### and this is for the reverse way :"D
```cpp
void printReverse(node*head){
    if(head==nullptr)return;
    printReverse(head->next);
    cout<<head->data<<endl;
}
```

### write print function with for loop
```cpp
void print(node* head){
    for(node* cur=head ;cur != nullptr;cur=cur->next){
        cout<<cur->data<<endl;
    }
}
```

---