/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 *
 * https://leetcode.com/problems/candy/description/
 *
 * algorithms
 * Hard (27.77%)
 * Total Accepted:    98.6K
 * Total Submissions: 353K
 * Testcase Example:  '[1,0,2]'
 *
 * There are N children standing in a line. Each child is assigned a rating
 * value.
 * 
 * You are giving candies to these children subjected to the following
 * requirements:
 * 
 * 
 * Each child must have at least one candy.
 * Children with a higher rating get more candies than their neighbors.
 * 
 * 
 * What is the minimum candies you must give?
 * 
 * Example 1:
 * 
 * 
 * Input: [1,0,2]
 * Output: 5
 * Explanation: You can allocate to the first, second and third child with 2,
 * 1, 2 candies respectively.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1,2,2]
 * Output: 4
 * Explanation: You can allocate to the first, second and third child with 1,
 * 2, 1 candies respectively.
 * ⁠            The third child gets 1 candy because it satisfies the above two
 * conditions.
 * 
 * 
 */

/* 超时
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> candy_num(ratings.size(),0);
        
        for(int i=0;i<ratings.size();i++){
            if(i==0) {candy_num[i]=1;continue;}
            
            if(ratings[i]>ratings[i-1]){
                candy_num[i]=candy_num[i-1]+1;
            }
            else if(ratings[i]==ratings[i-1]){
                candy_num[i]=1;
            }
            else{
                if(candy_num[i-1]==1){
                    candy_num[i]=1;
                    for(int j=i-1;j>=0;j--){
                        if(ratings[j]>ratings[j+1]&&candy_num[j]==candy_num[j+1]) candy_num[j]++;
                        else break;
                    }
                }
                else{
                    candy_num[i]=1;
                }
            }
            
        }
        
        int res=0;
        for(int i=0;i<candy_num.size();i++){
            cout<<candy_num[i]<<" ";
            res+=candy_num[i];
        }
        
        return res;
    }
};
*/

class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==0) return 0;
        
        int n=ratings.size();
        vector<int> dp(n,0);
        dp[0]=1;
        
        int index=0;
        int pre_candy=1;
        int index_candy=1;
        
        for(int i=1;i<ratings.size();i++){
            
            //至少分发一个糖果
            dp[i]=dp[i-1]+1;
            
            if(ratings[i]>ratings[i-1]){
                dp[i]+=pre_candy;
                pre_candy++;
                index_candy=pre_candy;
                index=i;
            }
            
            else if(ratings[i]==ratings[i-1]){
                pre_candy=1;
                index=i;
                index_candy=1;
            }
            else{
                pre_candy=1;
                dp[i]=i-index<index_candy?dp[i]+i-index-1:dp[i]+i-index;
            }
            
        }
        
        
        
        
        return dp[n-1];
    }
};

