/* https://leetcode.com/problems/kth-largest-element-in-an-array/

Question:- Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Approach:-
As we have to find kth largest so we will make a minimum heap , and will pop the element from it if its size is greater than k because everytime its size is greater than k
then it will have the element smaller than kth largest element at its top .

*/

//Solution 1: Time Complexity O(N*k*logk). extra k because of size() function
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>q;
        
        for(auto i : nums) //O(N)
        {
            q.push(i);  //O(logk)
            if(q.size() > k) //O(K)
                q.pop();
        }
        
        return q.top() ;
    }
};

//Solution 2: Same solution but without use of size() function because time complexity of size() is O(K)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>>q; 
        
        for(int i=0, n = nums.size(); i<n ; i++) //O(N)
        {
            q.push(nums[i]);  //O(logk)
            
            if(i+1 > k)  //O(1)
                q.pop();
        }
        
        return q.top() ;
    }
};
