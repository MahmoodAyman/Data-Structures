## Doubly linked list
a doubly linked list is as simple as everything we have learned in singly linked list but with one more pointer to the previous node.

this means we can move forward and backward in the list.

```cpp
struct node {
    int data;
    node *next{};
    node *prev{};
    node(int data) : data(data) {};
    void set(node *next,node *prev){
        this->next=next;
        this->prev=prev;
    }
};
```

### See the Visualisation of the doubly linked list
![Doubly linked list](https://media.geeksforgeeks.org/wp-content/cdn-uploads/gq/2014/03/DLL1.png);

- ### this is make printing the list reversed easier
```cpp
class linked_list{
private:
    node* head{};
    node* tail{};
public:
    void print_rev(){
        for(node* cur=tail;;cur=cur->prev){
            cout<<cur->data<<endl;
        }
    }
};
```

### what is the main advantage of this? 
- now we can insert and delete in O(1) time
