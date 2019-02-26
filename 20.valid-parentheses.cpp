/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (36.29%)
 * Total Accepted:    45.1K
 * Total Submissions: 124.3K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        if(len==0){return true;}
        stack<char> buff;
        int i=0;
        while(i<len){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
                buff.push(s[i]);
                
            }
            else if(s[i]==')'){
                if(buff.empty()){return false;}
                else if(buff.top()=='('){buff.pop();}
                else{return false;}
            }
            else if(s[i]==']'){
                if(buff.empty()){return false;}
                else if(buff.top()=='['){buff.pop();}
                else{return false;}
            }
            else if(s[i]=='}'){
                if(buff.empty()){return false;}
                else if(buff.top()=='{'){buff.pop();}
                else{return false;}
            }
            i++;
        }
        if(buff.empty()) return true;
        else return false;

    }
};


/*

*/
