/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.84%)
 * Total Accepted:    238.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */
class Solution {
public:
    int numDecodings(string s) {
        int res=0;
        numDecodings(res,s,0);
        
        return res;
    }
private:
    void numDecodings(int &res,string s,int k){
        if(k==s.size()) {res++;return ;}
        int temp=0;
        for(int i=k;i<s.size();i++){
            temp=temp*10+s[i]-'0';
            
            if(temp>26||temp<=0) break;
          //  cout<<temp<<" ";
            numDecodings(res,s,i+1);
        }
            
    }
};
