/*
 * @lc app=leetcode id=423 lang=cpp
 *
 * [423] Reconstruct Original Digits from English
 *
 * https://leetcode.com/problems/reconstruct-original-digits-from-english/description/
 *
 * algorithms
 * Medium (45.37%)
 * Total Accepted:    18.3K
 * Total Submissions: 40.3K
 * Testcase Example:  '"owoztneoer"'
 *
 * Given a non-empty string containing an out-of-order English representation
 * of digits 0-9, output the digits in ascending order.
 * 
 * Note:
 * 
 * Input contains only lowercase English letters.
 * Input is guaranteed to be valid and can be transformed to its original
 * digits. That means invalid inputs such as "abc" or "zerone" are not
 * permitted.
 * Input length is less than 50,000.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "owoztneoer"
 * 
 * Output: "012"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "fviefuro"
 * 
 * Output: "45"
 * 
 * 
 */
class Solution {
public:
    string originalDigits(string s) {
        string res;
        map(char,int) m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        l=s.szie();
        while(l>0){
            if(m['z']>0){
                res+='0';
                m['z']--;
                m['e']--;
                m['r']--;
                m['o']--;
                continue;
            }
            if(m['w']>0){
                res+='2';
                m['t']--;
                m['w']--;
                m['o']--;
                continue;
          }
            if(m['u'>0]){
                res+='4';
                m['f']--;
                m['o']--;
                m['u']--;
                m['r']--;
                continue;
            }
            if(m['x']>0;){
                res+='6';
                m['s']--;
                m['i']--;
                m['x']--;
                continue;
            }
            if(m['g']>0){
                res+='8';
                m['e']--;
                m['i']--;
                m['g']--;
                m['h']--;
                m['t']--;
                continue;
            }
            if(m['f']>0){
                res+='5';
                m['f']--;
                m['i']--;
                m['v']--;
                m['e']--;
                continue;
            }
            if(m['r']>0){
                res+='3';
                m['t']--;
                m['h']--;
                m['r']--;
                m['e']--;
                m['e']--;
                continue;
            }
            if(m['s']>0){
                res+='7';
                m['s']--;
                m['e']--;
                m['v']--;
                m['e']--;
                m['n']--;
                continue;

            }
            if(m['o']>0){
                res+='1';
                m['o']--;
                m['n']--;
                m['e']--;
                continue;
            }
            if(m['i']>0){
                res+='9';
                m['n']--;
                m['i']--;
                m['n']--;
                m['e']--;
                continue;
            }

        }
        sort(res.begin(),res.end());
        return res;
        

    }
    
};

