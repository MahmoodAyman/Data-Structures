# Linked List 
### Table of Contents
1. [Singly Linked List](#basic-structure)
2. [insert node at the end](#basic-structure)
3. [insert node at the beginning](#insert-at-the-beginning)
4. [print the linked list](#basic-structure)
5. [get the nth node from front](#get-the-nth-node-on)
6. [get the nth node from back](#get-the-nth-node-from-back)
7. [Find the value](#find-a-value-in-the-list-return-the-index-if-found-in-zero-based-indexing-or--1)
8. [Deletion](#now-lets-talk-about-deletion)

Now let's start building our linked list.
- ## Basic structure
```cpp
struct node { // this is the node
    int data;
    node *next;

    node(int data) : data(data) {};
};

class linked_list{
private:
    node* head{};
    node* tail{};
public:
    void print(){ // this is for printing the list 
        while(head != nullptr){
            cout<<head->data<<endl;
            head=head->next;
        }
    }
    void insert(int val){ // this is will insert to  the end of the list
        node* new_item=new node(val);
        if(!head) {
            head = tail = new_item;
        }else{
            tail->next=new_item;
            tail=new_item;
            tail->next= nullptr;
        }
    }
};
int main() {
    linked_list list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.print();
}
```
- this is the basic linked list 

## Some Random Function 
- ### Get the nth node O(n)
    ```cpp
    // this function inside linked_list class
        node* get_nth(int idx){
            int i=0;
            node* it=head;
            while(it != nullptr){
                i++;
                if(i==idx){
                    return it;
                }
                it=it->next;
            }
            return nullptr;
        }
        int main() {
        linked_list l;
        l.insert(1);
        l.insert(2);
        l.insert(3);
        l.insert(5);
        l.insert(4);
        l.insert(9);
        l.insert(7);
        l.insert(19);
        cout<<l.get_nth(5)->data<<endl;
    }
    ```

- ## Find a value in the list return the index if found in zero based indexing or -1
    ### O(n)
    ```cpp
    // this function inside linked_list class
        int find(int val){
        int i=0;
        node *it=head;
        while(it!= nullptr){
            if(it->data==val){
                return i;
            }
            i++;
            it=it->next;
        }
        return -1;
      }
        int main() {
        linked_list l;
        l.insert(1);
        l.insert(2);
        l.insert(3);
        l.insert(5);
        l.insert(4);
        l.insert(9);
        l.insert(7);
        l.insert(19);
        cout<<l.find(9)<<endl;
    }
    ```
- ## Destructor
    ### O(n)
    our linked list is dynamic so we need to release the memory
    ```cpp
    // this function inside linked_list class
    ~linked_list(){
        while(head){
            node *it=head->next;
            delete head;
            head=it;
        }
    }
    ```
- ## Insert at the beginning
    ### O(1)
    ```cpp
    // this function inside linked_list class
    void insert_at_beginning(int val){
        node* new_item=new node(val);
        if(!head){
            head=tail=new_item;
        }else{
            new_item->next=head;
            head=new_item;
        }
    }
    ```
- ## Delete from the beginning
    ### O(1)
    ```cpp
    // this function inside linked_list class
    void delete_front(){
        if(!head){
            return;
        }else{
            node* it=head;
            head=head->next;
            delete it;
        }
    }
    ```
- get the nth node from the back 
simply this is a math relation between the nth node from the back and the nth node from the front

Subtraction: 

it's the size of the list minus the nth node from the front

- ### Get the nth node from back
```cpp
 node *get_nth_back(int idx) {
        if (length < idx)return nullptr; // length is the lentgt of the list
        return get_nth(length - idx + 1);
    }
```
don't forget you need to increase the length in insert functions and decrease it in delete functions 

---- 
## Now let's talk about deletion 
- ### Delete the first node
### O(1)
```cpp
// this function inside linked_list class
void delete_front() {
    if (!head) {
        return;

    } else {
        node *it = head;
        head = head->next;
        delete it;
    }
    length--;
}
```
- ### Delete the last node 
### O(n)
```cpp
// this function inside linked_list class
 void delete_back(){
        if(length<=1){
            delete_front();
        }else{
            node *prev= get_nth(length-1);// remember this function? 
            delete tail;
            tail=prev;
            tail->next= nullptr;
        }
        length--;
    }
```
- ### Delete the nth node
### O(n)
```cpp
// this function inside linked_list class
void delete_nth(int idx) {
    if (idx == 1) {
        delete_front();
    } else if (idx == length) {
        delete_back();
    } else {
        node *prev = get_nth(idx - 1);
        node *it = prev->next;
        bool is_tail = it == tail; // this is a bool value
        prev->next = it->next;
        if (is_tail)tail = prev;
        delete it;
    }
    length--;
}
```