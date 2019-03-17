/*
 * @lc app=leetcode id=214 lang=cpp
 *
 * [214] Shortest Palindrome
 *
 * https://leetcode.com/problems/shortest-palindrome/description/
 *
 * algorithms
 * Hard (27.12%)
 * Total Accepted:    70.8K
 * Total Submissions: 260.5K
 * Testcase Example:  '"aacecaaa"'
 *
 * Given a string s, you are allowed to convert it to a palindrome by adding
 * characters in front of it. Find and return the shortest palindrome you can
 * find by performing this transformation.
 * 
 * Example 1:
 * 
 * 
 * Input: "aacecaaa"
 * Output: "aaacecaaa"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "abcd"
 * Output: "dcbabcd"
 */

/*
method:
注意到，题目要求是在字符串前方插入字符串，意味着（0，i），i<s.size（），是回文串
将此题目分为两个子问题
1、找出字符串s的最大回文子串，i为子串的长度，即回文子串最后一位index+1；
2、从index开始将字符复制并插入s的前方
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        int location;
        for(int i=0;i<s.size();i++){
            if(is_P(s,i)) location=i+1;
        }

        if(location=s.size()) return s;

        string str(s,location,s.size()-location);
        
        reverse(str.begin(),str.end());
        str=str+s;
        return str;

    }

    bool is_P(string s,int index){
        int i=0;
        int j=index;
        while(j>i){
            if(s[j]!=s[i]) return false; 
            j--;
            i++;
        }

        return true;
    }

    
};

