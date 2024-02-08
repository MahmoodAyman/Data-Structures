#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int size{};
    int top{};
    // I prefare dynamic array
    int *arr{};

public:
    // initialization list
    Stack(int sz) : size(sz), top(-1)
    {
        arr = new int[sz];
    }
    // checker functions
    bool isFull()
    {
        return top == size - 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    // main functions of stack
    int peek()
    {
        assert(!isEmpty());
        return arr[top];
    }
    int pop()
    {
        assert(!isEmpty());
        return arr[top--];
    }
    void push(int val)
    {
        assert(!isFull());
        arr[++top] = val;
    }
    void print()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};