// Question:- Delete middle element of the given stack.

/*
Approach:-
1. Base case:- If stack is empty then simply return it.
2. Otherwise call solve fxn , in solve fxn , we will check if middle of the stack is at the top of the stack , if yes then pop the top .
3. Otherwise, store the top of the stack in temp variable and call solve with k-1 until middle element is at top of the stack .
4. Atlast push the temp again into the stack.
*/

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
