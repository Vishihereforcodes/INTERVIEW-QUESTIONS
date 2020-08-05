int towerOfHanoi(int n,int source,int destination,int helper)
{
    //If only one disk then move disk and return
    if(n == 1)
    {
        cout << "move disk 1 From " << source << " To " << destination << "\n";
        return;
    }
    
    //Move Top n-1 disks from source to helper
    towerOfHanoi(n-1,source,helper,destination);
    
    //Move last disk From Source to Destination
    cout << "move disk " << n << " From " << source << " To " << destination << "\n";
    
    //Move n-1 disks from helper to destination
    towerOfHanoi(n-1,helper,destination,source);
}