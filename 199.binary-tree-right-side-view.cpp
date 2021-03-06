/*
 * @lc app=leetcode id=199 lang=cpp
 *
 * [199] Binary Tree Right Side View
 *
 * https://leetcode.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (46.69%)
 * Total Accepted:    152.9K
 * Total Submissions: 327.2K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * Given a binary tree, imagine yourself standing on the right side of it,
 * return the values of the nodes you can see ordered from top to bottom.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3,null,5,null,4]
 * Output: [1, 3, 4]
 * Explanation:
 * 
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        
        queue<TreeNode*> Q;
        TreeNode* temp;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            if(Q.front()==NULL&&Q.back()==NULL) break;
            temp=Q.front();
            Q.pop();
            if(temp==NULL) {
                Q.push(NULL);
                continue;
            }
            if(Q.front()==NULL) res.push_back(temp->val);
            if(temp->left!=NULL) Q.push(temp->left);
            if(temp->right!=NULL) Q.push(temp->right);



        }
        return res;

    }
};

