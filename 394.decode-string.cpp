/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 *
 * https://leetcode.com/problems/decode-string/description/
 *
 * algorithms
 * Medium (43.94%)
 * Total Accepted:    91.1K
 * Total Submissions: 206.7K
 * Testcase Example:  '"3[a]2[bc]"'
 *
 * 
 * Given an encoded string, return it's decoded string.
 * 
 * 
 * The encoding rule is: k[encoded_string], where the encoded_string inside the
 * square brackets is being repeated exactly k times. Note that k is guaranteed
 * to be a positive integer.
 * 
 * 
 * You may assume that the input string is always valid; No extra white spaces,
 * square brackets are well-formed, etc.
 * 
 * Furthermore, you may assume that the original data does not contain any
 * digits and that digits are only for those repeat numbers, k. For example,
 * there won't be input like 3a or 2[4].
 * 
 * 
 * Examples:
 * 
 * s = "3[a]2[bc]", return "aaabcbc".
 * s = "3[a2[c]]", return "accaccacc".
 * s = "2[abc]3[cd]ef", return "abcabccdcdcdef".
 * 
 * 
 */
class Solution {
public:
    string decodeString(string s) {
        string res;
        int i=0;
        while(i<s.size()){
            if(s[i]>='0'&&s[i]<='9'){
                i=decodeString(res,s,i);
            }
            else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
    
    int decodeString(string &res,string &s,int index){
        //根据index所指字符的数字，循环将中括号里的字符放入res
        //返回下一个index（可能指向数字，也可能指向字符）
        
        int num=0;
        while(s[index]<='9'&&s[index]>='0'){
            num=num*10+s[index]-'0';
            index++;
        }
        index=index+1;
        int i=index;
        int end_index;
        string result;
        while(s[i]!=']'){
           if(s[i]>='0'&&s[i]<='9'){
               i=decodeString(result,s,i);
            }
            else{
                result+=s[i];
                i++;
            }
        }
        
        end_index=i+1;
        
        while(num--){
            res+=result;
        }
        
        return end_index;
    }
};
