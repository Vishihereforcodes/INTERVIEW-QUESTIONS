/* https://leetcode.com/problems/top-k-frequent-elements/

Question:- Given a non-empty array of integers, return the k most frequent elements.

Approach:-
As we have to find k most frequent elements so their frequency should be maximum so we will make a minimum heap and will take a pair in it and will store frequency of elements 
as its first and the element as its first .

*/

typedef pair<int,int> p ;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(auto i : nums)
            m[i]++ ;
        
        priority_queue<p , vector<p> , greater<p>>q;
        for(auto i : m)
        {
            q.push(make_pair(i.second , i.first));
            if(q.size() > k)
                q.pop();
        }
        
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
