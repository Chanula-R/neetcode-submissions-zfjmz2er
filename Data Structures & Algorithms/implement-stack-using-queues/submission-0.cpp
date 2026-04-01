using namespace std;
class MyStack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);    
    }
    
    int pop() {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        if (q1.size() == 1)
        {
            int item1 = q1.front();
            q1.pop();
            return item1;
        }
        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            if (q2.size() == 1)
            {
                int item2 = q2.front();
                q2.pop();
                return item2;
            }
        }
    }
    
    int top() {
        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        if (q1.size() == 1)
        {
            int item1 = q1.front();
            return item1;
        }
        if (q1.empty())
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            if (q2.size() == 1)
            {
                int item2 = q2.front();
                return item2;
            }
        }
        
    }
    
    bool empty() {
        return (q1.empty() && q2.empty());
        
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