/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * algorithms
 * Medium (34.27%)
 * Total Accepted:    304.9K
 * Total Submissions: 886.8K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * Given a non-empty string s and a dictionary wordDict containing a list of
 * non-empty words, determine if s can be segmented into a space-separated
 * sequence of one or more dictionary words.
 * 
 * Note:
 * 
 * 
 * The same word in the dictionary may be reused multiple times in the
 * segmentation.
 * You may assume the dictionary does not contain duplicate words.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "leetcode", wordDict = ["leet", "code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
 * 
 * 
 */

/*
method1:
暴力搜索，超时
*/
/*
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(),wordDict.end());
        
        
        return wordBreak(s,wordDict,0);
        
        
        
    }
    
    bool wordBreak(string s, vector<string>& wordDict,int location){
        if(location==s.size()) return true;
        
        for(int i=wordDict.size()-1;i>=0;i--){
            if(s[location]==wordDict[i][0]&&match(s,wordDict[i],location)){
                if(wordBreak(s,wordDict,location+wordDict[i].size())) return true;
            }
        }
        
        return false;
    }
    
    bool match(string s,string word,int location){
        if(word.size()>s.size()-location) return false;
        int i=location;
        int j;
        for(j=0;j<word.size();j++){
            if(i>=s.size()) break;
            if(word[j]!=s[i]) break;
            i++;
        }
        if(j==word.size()) return true;
        
        return false;
    }
};
*/
/*
method2
动态规划
*/

