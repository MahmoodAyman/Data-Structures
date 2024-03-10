// this implementaion is closer to LinkedList
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data{};
    Node *left{};
    Node *right{};
    Node(int data) : data(data){};
};
class BinaryTree
{
private:
    Node *Root{};
    int dir = -1;

public:
    BinaryTree(int rootVal) : Root(new Node(rootVal)){};

    // this is print function to print in LRV : L for Lfet , V for current value , and R for Right
    void PrintPostOrder(Node *current)
    {
        if (!current)
            return;
        PrintPostOrder(current->left);
        PrintPostOrder(current->right);
        cout << current->data << " ";
    }
    // print in LVR : L for Lfet , V for current value , and R for Right
    void PrintInOrder(Node *current)
    {
        if (!current)
            return;
        PrintInOrder(current->left);
        cout << current->data << " ";
        PrintInOrder(current->right);
    }
    // print in VLR
    void PrintPreOrder(Node *current)
    {
        if (!current)
            return;
        cout << current->data << " ";
        PrintPreOrder(current->left);
        PrintPreOrder(current->right);
    }
    
};

int main()
{
}