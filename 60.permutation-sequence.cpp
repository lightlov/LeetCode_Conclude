/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (32.20%)
 * Total Accepted:    129K
 * Total Submissions: 400K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */
/*
method 1:
调用getnext函数，getnext函数返回当前串的下一个串，函数调用k次就能得到答案。复杂度较高

method2：
选数法：第k个字符串是从下标为1开始，等同于下标从0开始的第k-1个数字。
而当第一个数字选定之后，有(n-1)!个数字，因此将（k-1）/((n-1)!)就是当前选择数字的下标，比如n=3，k=2，选取第1个数字，（k-1）/(n-1)!=0,则选取s[0]=1;
(k-1)%(n-1)!=1, 1/(n-2)!=1/1=1，选取s[1],此时s中有s[0]=2,s[1]=3,所以选3，以此类推
*/
class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        string res;
        int divid=1;
        
        for(int i=1;i<=n;i++){
            str.push_back('0'+i);
            divid*=i;
        }
        
        int l=k-1;
        
        int i;
        
        while(n!=0){
            divid=divid/n;
            
            if(l==0) break;
 
            i=l/divid;
            l=l%divid;
            res.push_back(str[i]);
            str.erase(str.begin()+i);
            n--;
        }
        
        for(i=0;i<str.size();i++){
            res.push_back(str[i]);
        }
        
        return res;
        
    }
    

};

