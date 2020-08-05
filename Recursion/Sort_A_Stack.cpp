void insert(stack<int>& s,int val)
{
    if(s.empty() || s.top() <= val)
    {
        s.push(val);
        return;
    }
    
    int temp = s.top();
    s.pop();
    
    insert(s,val);
    
    s.push(temp);
}

void sort(stack<int> & s)
{
    if(s.size() == 1)
        return;
        
    int val = s.top();
    s.pop();
    
    sort(s);
    
    insert(s,val);
}