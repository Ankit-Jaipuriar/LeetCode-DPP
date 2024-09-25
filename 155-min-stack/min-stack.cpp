class MinStack {
public:
    stack<long long> s;
    long long mini;
    
    MinStack() {
        mini = LONG_MAX;
    }
    
    void push(int val) {
        if(s.empty()) {
            s.push((long long)val);  
            mini = (long long)val; 
        } else {
            if(val < mini) {
                s.push(2LL * val - mini); 
                mini = (long long)val;  
            } else {
                s.push((long long)val);  
            }
        }
    }
    
    void pop() {
        if(s.empty()) return;
        
        long long topVal = s.top();
        s.pop();
        
        if(topVal < mini) {
            mini = 2LL * mini - topVal;
        }
    }
    
    int top() {
        long long topVal = s.top();
        return (topVal < mini) ? (int)mini : (int)topVal;
    }
    
    int getMin() {
        return (int)mini; 
    }
};

   /**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */