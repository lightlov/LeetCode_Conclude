/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (31.18%)
 * Total Accepted:    380.2K
 * Total Submissions: 1.2M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int len=haystack.length();
        int len_needle=needle.length();
        if(needle=="") return 0;
        if(len<len_needle) return -1;
        int i=0;
        int j;
        
        for(;i<len-len_needle+1;i++){
            if(haystack[i]==needle[0]){
                for(j=1;j<len_needle;j++){
                    if(haystack[i+j]!=needle[j]) break;
                }
            }
            if(j==len_needle) break;
        }
        if(i>len-len_needle) return -1;
        else{return i;}
    }
};
