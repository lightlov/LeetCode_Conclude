/*
 * @lc app=leetcode id=395 lang=cpp
 *
 * [395] Longest Substring with At Least K Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/description/
 *
 * algorithms
 * Medium (37.92%)
 * Total Accepted:    43K
 * Total Submissions: 113K
 * Testcase Example:  '"aaabb"\n3'
 *
 * 
 * Find the length of the longest substring T of a given string (consists of
 * lowercase letters only) such that every character in T appears no less than
 * k times.
 * 
 * 
 * Example 1:
 * 
 * Input:
 * s = "aaabb", k = 3
 * 
 * Output:
 * 3
 * 
 * The longest substring is "aaa", as 'a' is repeated 3 times.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * s = "ababbc", k = 2
 * 
 * Output:
 * 5
 * 
 * The longest substring is "ababb", as 'a' is repeated 2 times and 'b' is
 * repeated 3 times.
 * 
 * 
 */
class Solution {
public:
    int longestSubstring(string s, int k) {
        return longestSubstring(s,k,0,s.size()-1);
    }
    
    int longestSubstring(string& s,int k,int start,int end){
        if(start>end||end>=s.size()||end<0||start<0||start>=s.size()) return 0;
        if(end-start+1<k) return 0;
        map<char,int> temp;
        for(int i=start;i<=end;i++){
            temp[s[i]]++;
        }
        int res_max=0;
        int start_i=start;
        int start_j;
        for(int i=start;i<=end;i++){
            if(temp[s[i]]<k){
                start_j=i-1;
                res_max=max(res_max,longestSubstring(s,k,start_i,start_j));
                start_i=i+1;
            }
        }
        
        if(start_i==start) return end-start+1;
        else {return max(res_max,longestSubstring(s,k,start_i,end));}
 
    }
};

