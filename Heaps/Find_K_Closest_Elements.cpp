/* https://leetcode.com/problems/find-k-closest-elements/ 

Question:- Given a sorted array arr, two integers k and x , find the k closest elements to x in the array. 
The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Approach:- 
We have to find closest elements which means that the distance between both elements should be minimum and as there is minimum word so we will make a maximum heap.
we will take a pair in it in which first we will take the absolute diff of two elements and in seconn we will take the array element.

*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>>q;
        vector<int>ans;
        
        for(int i = 0 ; i < arr.size() ; i++)
        {
            q.push(make_pair(abs(arr[i]-x) , arr[i]));
            if(q.size() > k)
                q.pop();
        }
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};
