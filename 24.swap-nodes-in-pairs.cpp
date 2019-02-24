/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (43.02%)
 * Total Accepted:    279.1K
 * Total Submissions: 648.7K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //cout<<"ss";
        ListNode* l1=NULL;
        ListNode* l2;
        ListNode* l3;
        ListNode* s;
        ListNode* res;
        l1=head;
        if(l1==NULL||l1->next==NULL){
            return l1;
        }
        l2=l1->next;
        
        res=l2;
        l1->next=l2->next;
        l2->next=l1;
        s=l1;
        l1=l1->next;
        //l2=l1->next;
        
        
        while(l1!=NULL){
            l2=l1->next;
            if(l2==NULL){break;}
            s->next=l2;
            l1->next=l2->next;
            l2->next=l1;
            
            s=l1;
            l1=s->next;
            //l2=l1->next;
        }
        
        
        return res;
    }
};
