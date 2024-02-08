#include<bits/stdc++.h>
using namespace std;
class stack
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node(int data) : data(data){};
    };
    Node *head{};
    int len = 0;

public:
    bool isEmpty()
    {   
        return !head;
    }
    int size()
    {
        return len;
    }
    void push(int val)
    {
        len++;
        Node *new_ele = new Node(val);
        if (!head)
        {
            head = new_ele;
            return;
        }
        new_ele->next = head;
        head = new_ele;
    }
    void top()
    {
        assert(!isEmpty());
        cout << head->data << endl;
    }
    void pop(){
        assert(!isEmpty());
        Node *cur = head;
        head = head->next;
        delete cur; 
    }
};