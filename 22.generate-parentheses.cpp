/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (68.13%)
 * Total Accepted:    14.1K
 * Total Submissions: 20.7K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */
/*
method:
活用递归进行遍历,当l>n或者r>n或者r>l,则表示为无效字符串括号,直接返回不push_back
当l==r==n时,则代表所有括号放好且满足条件,push_back进vector中
若不满足以上条件,递归调用,先放左括号,l+1
再放右括号,r+1
*/
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generatebracket(res,"",0,0,n);
        return res;
    }
    void generatebracket(vector<string> &res, string str,int l,int r,int n){
        if(l>n||r>n||r>l){return ;}
        if(l==n&&r==n){res.push_back(str);return ;}
        generatebracket(res,str+'(',l+1,r,n);
        generatebracket(res,str+')',l,r+1,n);
    }
};
