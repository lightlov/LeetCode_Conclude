/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.14%)
 * Total Accepted:    245.7K
 * Total Submissions: 764.4K
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a character sequence consists of non-space
 * characters only.
 * 
 * Example:
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res=0;
        int length=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){//
                if(length!=0) {res=length;length=0;}
               // res=length;
                //length=0;
            }
            else{length++;}

        }
        if(length!=0) res=length;
        return res;
    }
};

