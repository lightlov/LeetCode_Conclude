/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (29.56%)
 * Total Accepted:    209.3K
 * Total Submissions: 707.6K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if(matrix.size()==0) return res;
        
        spiralOrder(res,matrix,0,0,matrix.size(),matrix[0].size());
        return res;

    }
private:
    void spiralOrder(vector<int> &res,vector<vector<int>>& matrix,int row,int clum,int m,int n){
        if(row>=m||clum>=n) return ;
        int i;
        int j;
        for(j=clum;j<n;j++){
            res.push_back(matrix[row][j]);
        }
        if(m-row==1) return;
        for(i=row+1;i<m;i++){
            res.push_back(matrix[i][n-1]);
        }
        
        
        for(j=n-2;j>=clum;--j){
            res.push_back(matrix[m-1][j]);
        }
        
        if(n-clum==1) return;

        for(i=m-2;i>=row+1;--i){
            res.push_back(matrix[i][clum]);
        }

        spiralOrder(res,matrix,row+1,clum+1,m-1,n-1);


    }
};

