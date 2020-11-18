/*


Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.



*
/







class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st1,st2;
    MinStack() {
        // st1.clear();
        // st2.clear();
        while(!st1.empty())
            st1.pop();
        while(!st2.empty())
            st2.pop();
    }
    
    void push(int x) {
        if(st1.empty()&&st2.empty())
        {
            st1.push(x);
            st2.push(x);
            return;
        }
        st1.push(x);
        if(x<=st2.top())
        {
            st2.push(x);
        }
    }
    
    void pop() {
        if(st1.empty()&&st2.empty())
            return;
       int x  = st1.top();
        int y = st2.top();
        if(x==y)
        {
            st1.pop();
            st2.pop();
        }
        else
            st1.pop();
    }
    
    int top() {
        if(st1.empty())
            return -1;
        return st1.top();
        
    }
    
    int getMin() {
        if(st2.empty())
            return -1;
        return st2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */