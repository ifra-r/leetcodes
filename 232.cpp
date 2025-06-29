// 232. Implement Queue using Stacks
class MyQueue {
public:
    stack<int> st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> temp;
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();
        }
        int top = temp.top();     
        temp.pop();             // first el removed

        // now correct the order
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        } 
        return top;
    }
    
    int peek() {
        stack<int> temp;
        while(!st.empty()) {
            temp.push(st.top());
            st.pop();

        }
        int top = temp.top();
        // now correct the order
        while(!temp.empty()) {
            st.push(temp.top());
            temp.pop();
        }
        return top; 
    }
    
    bool empty() {
        return st.empty();
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