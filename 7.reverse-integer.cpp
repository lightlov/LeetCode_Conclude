/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 *
 * https://leetcode-cn.com/problems/reverse-integer/description/
 *
 * algorithms
 * Easy (31.45%)
 * Total Accepted:    80.4K
 * Total Submissions: 255.8K
 * Testcase Example:  '123'
 *
 * 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * 
 * 示例 1:
 * 
 * 输入: 123
 * 输出: 321
 * 
 * 
 * 示例 2:
 * 
 * 输入: -123
 * 输出: -321
 * 
 * 
 * 示例 3:
 * 
 * 输入: 120
 * 输出: 21
 * 
 * 
 * 注意:
 * 
 * 假设我们的环境只能存储得下 32 位的有符号整数，则其数值范围为 [−231,  231 − 1]。请根据这个假设，如果反转后整数溢出那么就返回 0。
 * 
 */
/*
method:
反转整数,可用整除余数乘10进行反转
判断溢出.当正数大于INT_MAX或者当负数小于INT_MIN时肯定溢出,由于判断后会有res*10+pop.因此
当res>INT_MAX/10或者res<INT_MIN/10时肯定溢出
个位数,正整数INT_MAX的个位数为7,因此当res==INT_MAX,且pop>7则溢出
同理,负整数INT_MIN个位数为8,当res==INT_MIN/10,且pop<-8,则溢出.
*/
class Solution {
public:
    int reverse(int x) {
        int res=0;
        while(x!=0){
            int pop=x%10;
            x=x/10;
            
            if(res>INT_MAX/10||(res==INT_MAX/10&&pop>7)){return 0;}
            if(res<INT_MIN/10||(res==INT_MIN/10&&pop<-8)){return 0;}
            res=res*10+pop;
        }
        return res;
    }
};
