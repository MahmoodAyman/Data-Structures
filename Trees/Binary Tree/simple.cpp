#include <bits/stdc++.h>
using namespace std;
class BinaryTree
{
private:
    int data{};
    BinaryTree *Left{};
    BinaryTree *Right{};
    int dir = -1;

public:
    // Initializer List
    BinaryTree(int val) : data(val){};

    // DFS Traversal
    // this is print function to print in LRV : L for Lfet , V for current value , and R for Right
    void PrintPostOrder()
    {
        if (Left)
            Left->PrintInOrder();
        if (Right)
            Right->PrintInOrder();
        cout << data << " ";
    }
    // print in LVR : L for Lfet , V for current value , and R for Right
    void PrintInOrder()
    {
        if (Left)
            Left->PrintInOrder();
        cout << data << " ";
        if (Right)
            Right->PrintInOrder();
    }
    void printInOrdere_Iterative()
    {
        stack<pair<BinaryTree *, bool>> nodes;
        nodes.push({this, false});
        while (!nodes.empty())
        {
            BinaryTree *cur = nodes.top().first;
            bool print = nodes.top().second;
            nodes.pop();
            if (print)
            {
                cout << cur->data << " ";
            }
            else
            {
                if (cur->Right)
                {
                    nodes.push({cur->Right, false});
                }
                nodes.push({cur, true});
                if (cur->Left)
                {
                    nodes.push({cur->Left, false});
                }
            }
        }
        cout << endl;
    }
    // print in VLR
    void PrintPreOrder()
    {
        cout << data << " ";
        if (Left)
            Left->PrintInOrder();
        if (Right)
            Right->PrintInOrder();
    }

    // BFS Traversal
    void traverseByLevel()
    {
        queue<BinaryTree *> q;
        q.push(this);
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                BinaryTree *Cur = q.front();
                q.pop();

                if (Cur->Left)
                {
                    q.push(Cur->Left);
                }

                if (Cur->Right)
                {
                    q.push(Cur->Right);
                }
            }
            level++;
        }
    }

    void Add(vector<int> path, string dir)
    {
        assert(path.size() == dir.size());
        BinaryTree *current = this;
        for (int i = 0; i < path.size(); i++)
        {
            if (dir[i] == 'L')
            {
                if (!current->Left)
                {
                    current->Left = new BinaryTree(path[i]);
                }
                else
                {
                    assert(current->Left->data = path[i]);
                }
                current = current->Left;
            }
            else
            {
                if (!current->Right)
                {
                    current->Right = new BinaryTree(path[i]);
                }
                else
                {
                    assert(current->Right->data = path[i]);
                }
                current = current->Right;
            }
        }
    }
    int treeMax()
    {
        int mx = data;
        if (Left)
            mx = max(mx, Left->treeMax());
        if (Right)
            mx = max(mx, Right->treeMax());
        return mx;
    }
    int treeHight()
    {
        int hight = 0;
        if (Left)
            hight = max(hight, 1 + Left->treeHight());
        if (Right)
            hight = max(hight, 1 + Right->treeHight());
        return hight;
    }
    int totalNodes()
    {
        int nodes = 1;
        if (Left)
            nodes += Left->totalNodes();
        if (Right)
            nodes += Right->totalNodes();
        return nodes;
    }
    int leafCounts()
    {
        int leafs = !Left and !Right;
        if (Left)
            leafs = Left->leafCounts();
        if (Right)
            leafs = Right->leafCounts();
        return leafs;
    }

    // search about value in a tree
    bool isExist(int value)
    {
        bool exist = value == data;
        if (!exist and Left)
            exist = Left->isExist(value);
        if (!exist and Right)
            exist = Right->isExist(value);
        return exist;
    }

    // check if the tree perfect
    bool isPerfectTree(int height = -1)
    {
        // first step call treeHight to calc the hight of the tree
        if (height == -1)
            height = treeHight();
        // if no left and no right then we are in a leaf node height should be zero!
        if (!Left and !Right)
        {
            return height == 0;
        }

        // check if Internal nodes has 2 children
        if ((!Left and Right) or (!Right and Left))
        {
            return false;
        }

        // recurse with height - 1 till you reach the leafs
        return Left->isPerfectTree(height - 1) and Right->isPerfectTree(height - 1);
    }

    // check if perfect tree by formula that calc the number of nodes by height in a perfect tree
    bool isPerfectTree_Formula()
    {
        int height = treeHight();
        int nodes_count = totalNodes();
        int nodes_formula = pow(2, height + 1) - 1;
        return nodes_count == nodes_formula;
    } // shorter but not efficient

    // print boundries
    void leftBoundry()
    {
        BinaryTree *cur = this;
        cout << cur->data << " ";
        if (!cur->Left and !cur->Right)
            return;
        if (cur->Left)
        {
            cur->Left->leftBoundry();
        }
        else if (cur->Right)
        {
            cur->Right->leftBoundry();
        }
    }
    ~BinaryTree()
    {
        clear();
    }
    void clear()
    {
        if (Left)
        {
            delete Left;
            Left = nullptr;
        }
        if (Right)
        {
            delete Right;
            Left = Right;
        }
    }
};

int main()
{
    
}