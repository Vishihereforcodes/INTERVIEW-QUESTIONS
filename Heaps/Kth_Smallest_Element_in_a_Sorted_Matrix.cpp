/* https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

Question:- Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Approach:- As we have to find kth smallest element so we will make a maximum heap and will pop element from heap everytime its size becomes greater than k because it will have 
element greater than the required element on its top.

*/

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int>q;
        for(auto i : matrix)
        {
            for(auto y : i)
            {
                q.push(y);
                if(q.size() > k)
                    q.pop();
            }
        }
        return q.top();
    }
};
