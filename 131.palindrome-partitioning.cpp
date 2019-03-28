/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 *
 * https://leetcode.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (39.68%)
 * Total Accepted:    155.6K
 * Total Submissions: 389.1K
 * Testcase Example:  '"aab"'
 *
 * Given a string s, partition s such that every substring of the partition is
 * a palindrome.
 * 
 * Return all possible palindrome partitioning of s.
 * 
 * Example:
 * 
 * 
 * Input: "aab"
 * Output:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 * 
 * 
 */
//回溯

/*

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> result;
        
        partition(res,result,s,0);
        
        return res;
    }
    
private:
    void partition(vector<vector<string>>& res,vector<string>& result,string& s,int index){
        //boundary
        if(index==s.size()){
            res.push_back(result);
            return ;
        }
        
        string sub_str;
        
        for(int i=index;i<s.size();i++){
            sub_str+=s[i];
            if(is_revearse(sub_str)){
                result.push_back(sub_str);
                partition(res,result,s,i+1);
                result.pop_back();
            }
            
        }
        
        
        
    }
    
    bool is_revearse(string str){
        if(str.size()<2) return true;
        
        for(int i=0;i<=str.size()/2;i++){
            
            if(str[i]!=str[str.size()-i-1]) return false;
            
        }
        
        return true;
    }
};
*/
class Solution {
    vector<vector<string>> res;
    
    void DFS(string& s, int begin, vector<string>& t){
        if(begin>=s.length())
            res.push_back(t);
        else{
            t.push_back("");
            for(int end=begin;end<s.length();end++)
                if(isParl(s, begin, end)){
                    t[t.size()-1] = s.substr(begin, end-begin+1);
                    DFS(s, end+1, t);
                }
            t.pop_back();
        }
    }
    
    
    bool isParl(string& s, int begin, int end){
// 可以用DP存储加速
        while(begin<end){
            if(s[begin]!=s[end])
                return false;
            begin++;
            end--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> t;
        DFS(s, 0, t);
        return res;
    }
};

