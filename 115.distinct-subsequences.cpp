/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * https://leetcode.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (34.56%)
 * Total Accepted:    102.2K
 * Total Submissions: 295.1K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * Given a string S and a string T, count the number of distinct subsequences
 * of S which equals T.
 * 
 * A subsequence of a string is a new string which is formed from the original
 * string by deleting some (can be none) of the characters without disturbing
 * the relative positions of the remaining characters. (ie, "ACE" is a
 * subsequence of "ABCDE" while "AEC" is not).
 * 
 * Example 1:
 * 
 * 
 * Input: S = "rabbbit", T = "rabbit"
 * Output: 3
 * Explanation:
 * 
 * As shown below, there are 3 ways you can generate "rabbit" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: S = "babgbag", T = "bag"
 * Output: 5
 * Explanation:
 * 
 * As shown below, there are 5 ways you can generate "bag" from S.
 * (The caret symbol ^ means the chosen letters)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 * 
 */
//method1: 回溯法(超时)
/*
class Solution {
public:
    int numDistinct(string s, string t) {
        int count=0;
        
        for(int i=0;i<s.size();i++){
            numDistinct( s , t,  count, i,0);
        }
        
        
        
        return count;
    }
    
    void numDistinct(string& s , string& t, int& count, int index_s,int index_t){
        //boundary
        
        if(index_s>=s.size()||s[index_s]!=t[index_t]) return;
        if(index_t==t.size()-1&&s[index_s]==t[index_t]) {count++;return ;}
        
        //search
        
        for(int i=index_s+1;i<s.size();++i){
            numDistinct(s,t,count,i,index_t+1);
        }
        
        
    }
};
*/
class Solution {
public:
    int numDistinct(string s, string t) {
        int ls=s.size();
        int lt=t.size();
        vector<vector<long>> dp(lt+1,vector<long>(ls+1,0));
        for(int j=0;j<ls+1;++j){
            dp[0][j]=1;
        }
        
        for(int i=1;i<=lt;++i){
            for(int j=1;j<=ls;++j){
                if(s[j-1]==t[i-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
                    
                }
                else{
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
        
        return dp[lt][ls];
        
    }
};

