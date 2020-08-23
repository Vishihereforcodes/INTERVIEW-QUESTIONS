/* https://leetcode.com/problems/sort-characters-by-frequency/

Question:- Given a string, sort it in decreasing order based on the frequency of characters.

Approach:- 
As we have to sort them in decreasing order so we will take maximum heap and take a pair in it and will take frequency as its first and the character as its second .

*/

typedef pair<int,char> p;
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int>m;
        for(auto i : s)
            m[i]++ ;
        
        priority_queue<p>q;
        for(auto i = 0 ; i < s.size() ; i++)
        {
            q.push(make_pair(m[s[i]] , s[i]));
        }
        
        string ans = "";
        while(!q.empty())
        {
            for(int i = 0 ; i < q.top().first ; i++){
                ans += q.top().second;
                q.pop();
            }
           
        }
        return ans;
    }
};
