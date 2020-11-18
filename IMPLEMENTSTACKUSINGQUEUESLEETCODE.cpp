class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1,q2;
    int cursize;
    MyStack() {
        cursize=0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        cursize++;
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> q = q1;
        q1=q2;
        q2=q;
        
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if(q1.empty())
            return -1;
        int x = q1.front();
        q1.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        if(q1.empty())
            return -1;
        return q1.front();
        
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */