/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 *
 * https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description/
 *
 * algorithms
 * Medium (36.82%)
 * Total Accepted:    228K
 * Total Submissions: 619.2K
 * Testcase Example:  '{"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}'
 *
 * You are given a perfect binary tree where all leaves are on the same level,
 * and every parent has two children. The binary tree has the following
 * definition:
 * 
 * 
 * struct Node {
 * ⁠ int val;
 * ⁠ Node *left;
 * ⁠ Node *right;
 * ⁠ Node *next;
 * }
 * 
 * 
 * Populate each next pointer to point to its next right node. If there is no
 * next right node, the next pointer should be set to NULL.
 * 
 * Initially, all next pointers are set to NULL.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * 
 * 
 * Input:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
 * 
 * Output:
 * {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}
 * 
 * Explanation: Given the above perfect binary tree (Figure A), your function
 * should populate each next pointer to point to its next right node, just like
 * in Figure B.
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * You may only use constant extra space.
 * Recursive approach is fine, implicit stack space does not count as extra
 * space for this problem.
 * 
 * 
 */
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/

/*
方法一：层次遍历，在每一层结尾插入NULL，按照出队列顺序，将next指针填充
空间复杂度O（n），时间复杂度O（n）
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> Q;
        Node* p;
        Q.push(root);
        Q.push(NULL);
        while(!Q.empty()){
            if(Q.front()==NULL&&Q.back()==NULL) break;
            if(Q.front()==NULL) {
                Q.push(NULL);
                Q.pop();
            }
            else{
                cout<<Q.front()->val<<" ";
                if(Q.front()->left) Q.push(Q.front()->left);
                if(Q.front()->right) Q.push(Q.front()->right);
                p=Q.front();
                Q.pop();
                p->next=Q.front();
            }
        }
        return root;
    }
};

/*
方法二：递归，将每个节点的左子节点和右子节点相连接，
在将左子节点的右子节点和右子节点的左子节点链接，递归调用。
时间复杂度O（n），空间复杂度O(logn)
*/
class Solution {
public:
    Node* connect(Node* root) {
        connect(root,NULL);
        return root;
    }
    
    void connect(Node* root,Node* sabling){
        if(!root) return ;
        root->next=sabling;
        connect(root->left,root->right);
        if(sabling){
            connect(root->right,sabling->left);
        }
        else{
            connect(root->right,NULL);
        }
    }
};

