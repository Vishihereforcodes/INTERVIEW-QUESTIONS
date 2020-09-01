// https://leetcode.com/problems/scramble-string/

class Solution
{
public:
    bool isScramble(string s1, string s2)
    {
        if (s1.compare(s2) == 0)
            return true;

        if (s1 == "")
            return false;

        int n = s1.length();
        bool flag = false;

        for (int i = 1; i < n; i++)
        {
            if ( (isScramble(s1.substr(0,i), s2.substr(n-i,i)) && isScramble(s1.substr(i,n-i), s2.substr(0,n-i)) )
                || (isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i,n-i), s2.substr(i,n-i)) ) )
            {
                flag = true;
                break;
            }
        }
        return flag;
    }
};
