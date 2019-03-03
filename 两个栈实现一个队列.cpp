class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
            //���ص�
            while(!s2.empty())
            {
                s1.push(s2.top());
                s2.pop();
            }
            s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() { 
        assert(!s1.empty());
        while(s1.size() != 1)
        {
         //������
            s2.push(s1.top());
             s1.pop();
        }
       int ret = s1.top();
        s1.pop();
        while(!s2.empty())
        {
            //���ص�
            s1.push(s2.top());
            s2.pop();
        }
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        while(s1.size() != 1)
        {
            //������
            s2.push(s1.top());
            s1.pop();
        }
        int ret = s1.top();
        return ret;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty()&&s2.empty();
    }
private:
    stack<int> s1;
    stack<int> s2;
};