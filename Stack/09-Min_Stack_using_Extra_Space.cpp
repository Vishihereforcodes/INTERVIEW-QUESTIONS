/* https://leetcode.com/problems/min-stack/

*/
class MinStack {
public:
    stack<int>s , ss;
    
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(ss.empty() || ss.top() >= x)
            ss.push(x);
        return;
    }
    
    void pop() {
        if(s.empty())
            return ;
        int ans = s.top();
        if(ss.top() == ans)
            ss.pop();
        s.pop();
    }
    
    int top() {
        if(s.empty())
        {
            return 0;
        }
        return s.top();
    }
    
    int getMin() {
        if(ss.empty())
            return -1;
        return ss.top();
    }
};
