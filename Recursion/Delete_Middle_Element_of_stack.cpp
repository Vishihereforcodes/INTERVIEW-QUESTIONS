stack<int> deleteMiddleElement(stack<int>s)
{
    int n = s.size();
    if(n == 0)
        return s;

    int k = n/2 + 1;

    solve(s,k);
    return s;
}

void solve(stack<int>& s,int k)
{
    if(k == 1)
    {
        s.pop();
        return;
    }

    int val = s.top();
    s.pop();

    solve(s,k-1);
    s.push(val);
}