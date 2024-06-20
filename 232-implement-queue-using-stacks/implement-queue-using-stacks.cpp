class MyQueue {
public:
    stack<int> a,b;
    MyQueue() {
        
    }
    
    void push(int x) {
        a.push(x);
    }
    
    int pop() {
        if(a.empty()) return -1;

        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        int val = b.top();
        b.pop();
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        }
        return val;
    }
    
    int peek() {
        while(!a.empty()){
            b.push(a.top());
            a.pop();
        }
        int val = b.top();
        while(!b.empty()){
            a.push(b.top());
            b.pop();
        } 
        return val;
    }
    
    bool empty() {
        return a.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */