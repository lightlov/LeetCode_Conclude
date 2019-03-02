/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (45.45%)
 * Total Accepted:    209.3K
 * Total Submissions: 459.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> len(m);
        for(int i=0;i<m;i++){
            len[i].resize(n);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) len[i][j]=grid[i][j];
                else if(i==0&&j!=0) len[i][j]=grid[i][j]+len[i][j-1];
                else if(i!=0&&j==0) len[i][j]=grid[i][j]+len[i-1][j];
                else{
                    len[i][j]=grid[i][j]+min(len[i][j-1],len[i-1][j]);
                }
            }
        }
       
        return len[m-1][n-1];
    }
};

