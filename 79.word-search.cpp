/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (30.33%)
 * Total Accepted:    252.8K
 * Total Submissions: 831.5K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 */
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()==0) return false;
        if(board[0].size()==0) return false;
        if(word.size()>board.size()*board[0].size()) return false;
        
        vector<bool> ss(board[0].size(),false);
        vector<vector<bool>> table(board.size(),ss);
    
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    
                    if(exist(board,word,i,j,0,table)) return true;
                } 
            }
        }
        
        return false;
    }
    
private:
    bool exist(vector<vector<char>>& board, string word,int i,int j,int k,vector<vector<bool>>& table){
        //从location的位置寻找单词word
        if(k>=word.size()) return true;
        if(i<0||i>=board.size()||j<0||j>=board[0].size()) return false;
        if(board[i][j]!=word[k]) return false;
        if(table[i][j]) return false;
        table[i][j]=true;
        bool res=exist(board,word,i-1,j,k+1,table)||
            exist(board,word,i,j+1,k+1,table)||
            exist(board,word,i+1,j,k+1,table)||
            exist(board,word,i,j-1,k+1,table);
        table[i][j]=false;
        return res;
    }
};
