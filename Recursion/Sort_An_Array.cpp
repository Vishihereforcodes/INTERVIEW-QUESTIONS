void insert(vector<int>& v,int val)
{
    if(v.empty() || v.back() <= val)
    {
        v.push_back(val);
        return;
    }
    
    int temp = v.back();
    v.pop_back();
    
    insert(v,val);
    
    v.push(temp);
}

void sort(vector<int>& v)
{
    if(v.size() == 1)
        return;
        
    int val = v.back();
    v.pop_back();
    
    sort(v);
    
    insert(v,val);
}