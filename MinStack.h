#include<stack>
#include<vector>
using namespace std;
class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if (minChain.empty() || x <= (minChain.back()))
        {
            minChain.push_back(x);
        }
    }
    void pop() {
        if (!minChain.empty() && s.top() == minChain.back())
        {
            minChain.pop_back();
        }
        s.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minChain.back();
    }
private:
    stack<int> s;
    vector<int> minChain;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */