/*
 * @lc app=leetcode id=306 lang=cpp
 *
 * [306] Additive Number
 *
 * https://leetcode.com/problems/additive-number/description/
 *
 * algorithms
 * Medium (28.17%)
 * Total Accepted:    39K
 * Total Submissions: 138.3K
 * Testcase Example:  '"112358"'
 *
 * Additive number is a string whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for
 * the first two numbers, each subsequent number in the sequence must be the
 * sum of the preceding two.
 * 
 * Given a string containing only digits '0'-'9', write a function to determine
 * if it's an additive number.
 * 
 * Note: Numbers in the additive sequence cannot have leading zeros, so
 * sequence 1, 2, 03 or 1, 02, 3 is invalid.
 * 
 * Example 1:
 * 
 * 
 * Input: "112358"
 * Output: true 
 * Explanation: The digits can form an additive sequence: 1, 1, 2, 3, 5,
 * 8. 
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "199100199"
 * Output: true 
 * Explanation: The additive sequence is: 1, 99, 100, 199. 
 * 1 + 99 = 100, 99 + 100 = 199
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 */
class Solution {
public:
    bool isAdditiveNumber(string num) {
        if(num.size()<3) return false;
        
        long first=0;
        int i,j;
        
        for( i=1;i<=num.size()/2;i++){
            if(num[0]=='0'&&i>1){
                return false;
            }
            first=first*10+num[i-1]-'0';
            long second=0;
            for( j=1;num.size()-i-j>=max(i,j);j++){
                if(num[i]=='0'&&j>1) break;
                second=second*10+num[i+j-1]-'0';
                if(isvalid(first,second,i+j,num)){
                    return true;
                }
            }
            
            
            
            
        }
        
        return false;
    }
    
    
    bool isvalid(long first,long second,int start,string &num){
        
        if(start==num.size()) return true;
        if(start>num.size()) return false;
        
        second=first+second;
        first=second-first;
        string sum=to_string(second);
        
        if(num.compare(start,sum.size(),sum)!=0){
            return false;
            
        }
        else return isvalid(first,second,start+sum.size(),num);
    }
};

