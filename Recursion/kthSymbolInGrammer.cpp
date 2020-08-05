int kthSymbolInGrammer(int n,int k)
{
    if(n == 1 && k == 1)
        return 0;
        
    int mid = 1 << (n-2); // which is 2^(n-1)/2 == 2^(n-2)
    
    if(k <= mid)
        return kthSymbolInGrammer(n-1,k);
    else
        return !kthSymbolInGrammer(n-1,k-mid);
}