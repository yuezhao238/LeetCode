#include<bits/stdc++.h>

using namespace std;

class MinStack {
public:
    stack<int> xstk;
    stack<int> mstk;
    MinStack() {
        mstk.push(INT_MAX);
    }
    
    void push(int val) {
        xstk.push(val);
        mstk.push(min(mstk.top(), val));
    }
    
    void pop() {
        xstk.pop();
        mstk.pop();
    }
    
    int top() {
        return xstk.top();
    }
    
    int getMin() {
        return mstk.top();
    }
};

int main() {
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    cout << obj->getMin() << endl;
    obj->pop();
    cout << obj->top() << endl;
    cout << obj->getMin() << endl;
}