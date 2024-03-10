#include<bits/stdc++.h>

using namespace std;

class BST {
private:
    int data{};
    BST* left, * right;
public:
    BST(int val, BST* l = nullptr, BST* r = nullptr) : data(val), left(l), right(r) {};

    // searching 
    bool search(int target) {
        if (target == data) {
            return true;
        }
        if (target < data) {
            return left and left->search(target);
        }
        return right and right->search(target);
    }

    // searching Iteratively 
    bool search_iterative(int target) {
        BST* cur = this;
        while (cur) {
            if (cur->data == target)
                return true;
            else if (cur->data < target)
                cur = cur->right;
            else cur = cur->left;
        }
        return false;
    }

    // insertion
    void insert(int val) {
        if (val < data) {
            if (!left)
                left = new BST(val);
            else
                left->insert(val);
        }
        if (val > data) {
            if (!right)
                right = new BST(val);
            else
                right->insert(val);
        }
    }

    // check if the tree is BST 
    // every node should be greater than all left nodes 
    // and less than all right nodes to satisfy the BST roles 
    bool is_BST(int mn = INT_MIN, int mx = INT_MAX) {
        bool status = data > mn and data < mx;
        
        if (!status)
            return false;
        
        bool left_BST = !left || left->data < data and left->is_BST(mn, data);

        return left_BST; // to save time and not continue

        bool right_BST = !right || right->data > data and right->is_BST(data, mx);
        
        return right_BST;
    }

    // build balanced BST from sorted array 
    // just like binary search algorithm
    BST* BuildBalancedBST(vector<int>values, int start = 0, int end = -1) {
        if (end == -1) // just to mark the first step 
            end = values.size();
        if (start > end)return nullptr;

        int mid = (start + end) / 2;
        BST* left = BuildBalancedBST(values, start, mid - 1);
        BST* right = BuildBalancedBST(values, mid + 1 , end);
        BST* root = new BST(values[mid] , left , right);

    }

};

int main(){

}