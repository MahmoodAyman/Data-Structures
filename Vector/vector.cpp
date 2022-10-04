#include<bits/stdc++.h>
#include<cassert>

#define NDEBUG
using namespace std;

template<class T>
class Vector {
private:
    T *arr = nullptr;
    int sz = 0;
    int capacity = 0;

    void expand_capacity() {
        capacity *= 2;
        T *temp = new T[capacity]{};
        for (int i = 0; i < sz; i++) {
            temp[i] = arr[i];
        }
        swap(arr, temp);
        delete[]temp;
    }

public:
    Vector(int size) :
            sz(size) {
        if (size < 0)sz = 1;
        capacity = size + 10;
        arr = new T[capacity]{};
    }

    Vector() {
        sz = 0;
        capacity = 0;
    }

    ~Vector() {
        delete[]arr;
        arr = nullptr;
    }

    void set(int idx, T val) {
        assert(0 <= idx && idx >= sz && "index out of Range");
        arr[idx] = val;
    }

    int get(int idx) {
        assert(idx < 0 && idx >= sz && "index out of Range");
        return arr[idx];
    }

    int size() {
        return sz;
    }

    int find(T val) {
        for (int i = 0; i < sz; i++) {
            if (arr[i] == val)return i;
        }
        return -1;
    }

    int front() {
        return arr[0];
    }

    int back() {
        return arr[sz - 1];
    }

    void push_back(T val) {
        T *temp = new T[sz + 1];
        for (int i = 0; i < sz; i++) {
            temp[i] = arr[i];
        }
        temp[sz++] = val;
        swap(arr, temp);
        delete[]temp;
    }

    void emplace_back(T val) {
        if (sz == capacity)expand_capacity();
        arr[sz++] = val;
    }

    bool is_empty() {
        return sz == 0;
    }

    void clear() {
        sz = 0;
    }

    void pop_back() {
        sz--;
    }

    void remove(int idx) {
        assert(idx >= 0 && idx <= sz && "index out or Range");
        for (int i = idx; i < sz - 1; i++)arr[i] = arr[i + 1];
        sz--;
    }

    void insert(int idx, T val) {
        assert (idx >= 0 && idx <= sz && "index out or Range");
        if (sz == capacity)expand_capacity();
        for (int i = sz; i > idx; i--)arr[i] = arr[i - 1];
        arr[idx] = val;
        sz++;
    }

    void print() {
        for (int i = 0; i < sz; i++)cout << arr[i] << " ";
        cout << endl;
    }

    T &operator[](int idx) {
        assert (idx >= 0 && idx <= sz && "index out or Range");
        return arr[idx];
    }
};

int main() {
    Vector<string> v(2);
    v[0] = "Mahmoud";
    v[1] = "Ayman";
    v.push_back("CS Student");
    v.print(); // Mahmoud Ayman CS Student
    cout << v.find("mahmouud") << endl; // -1
// -- Honestly some function not working correctly with string, and I am not figuring out why --
// this is an anouncement for me to fix it later 

    Vector<char> x;
    cout << (x.is_empty() ? "YES" : "NO") << endl;
    x.emplace_back('1');
    x.print(); // 1
    x.emplace_back('2');
    x.print();//1 2
    x.emplace_back('3');
    x.print();// 1 2 3
// ------------------------------------------------------------
    Vector<int> nums;
    nums.emplace_back(1);
    nums.emplace_back(2);
    nums.emplace_back(3);
    nums.emplace_back(4);
    nums.emplace_back(5);
    nums.emplace_back(6);
    cout << nums.size() << endl;
    nums.print();


}
