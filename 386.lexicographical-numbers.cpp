/*
 * @lc app=leetcode id=386 lang=cpp
 *
 * [386] Lexicographical Numbers
 *
 * https://leetcode.com/problems/lexicographical-numbers/description/
 *
 * algorithms
 * Medium (44.86%)
 * Total Accepted:    37.6K
 * Total Submissions: 83.6K
 * Testcase Example:  '13'
 *
 * Given an integer n, return 1 - n in lexicographical order.
 * 
 * For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
 * 
 * Please optimize your algorithm to use less time and space. The input size
 * may be as large as 5,000,000.
 * 
 */
bool cmp(int a,int b){
    return to_string(a)<to_string(b);
}

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i=1;i<=n;i++){
            res.push_back(i);
        }
        
        sort(res.begin(),res.end(),cmp);
        return res;
    }
};

