/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 *
 * https://leetcode-cn.com/problems/palindrome-number/description/
 *
 * algorithms
 * Easy (56.05%)
 * Total Accepted:    69.6K
 * Total Submissions: 124.1K
 * Testcase Example:  '121'
 *
 * 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * 
 * 示例 1:
 * 
 * 输入: 121
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: -121
 * 输出: false
 * 解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
 * 
 * 
 * 示例 3:
 * 
 * 输入: 10
 * 输出: false
 * 解释: 从右向左读, 为 01 。因此它不是一个回文数。
 * 
 * 
 * 进阶:
 * 
 * 你能不将整数转为字符串来解决这个问题吗？
 * 
 */
/*
method1 :
反转x成为x',判断x?=x'

method2: 
利用vector,将整数x的每个位置上的数存入vector,判断收尾是否相等
*/
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
/*class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int res=0;
        int pop;
        int x1=x;
        while(x1!=0){
            pop=x1%10;
            x1=x1/10;
            if(res>INT_MAX/10||(res==INT_MAX/10&&pop>7)){return false;}
            res=res*10+pop;
        }
        if(res==x) {return true;}
        else{return false;}
    }
};*/
class Solution {
public:
    bool isPalindrome(int x){
        if(x<0) return false;
        vector<int> S;
        while(x!=0){
            int pop=x%10;
            x=x/10;
            S.push_back(pop);
        }
        int i=0;
        int j=S.size()-1;
        while(i<=j){
            if(S[i]!=S[j]){return false;}
            i++;
            j--;
        }
        return true;

    }
};
