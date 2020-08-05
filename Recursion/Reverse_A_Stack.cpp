void insert(stack<int>& s,int val)
{
    if(s.empty())
    {
        s.push(val);
        return;
    }

    int temp = s.top();
    s.pop();

    insert(s,val);

    s.push(temp);
}

void reverseStack(stack<int>& s)
{
    if(s.size() == 1)
        return;
    
    int temp = s.top();
    s.pop();
    
    reverseStack(s);
    
    insert(s,temp);
}