/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (36.23%)
 * Total Accepted:    153K
 * Total Submissions: 421.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        
        if(head==NULL||head->next==NULL) return head;
        
        ListNode* insert;//标记插入位置
        ListNode* p1;
        ListNode* p2;//遍历指针
        
        
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        p1=dummy;
        p2=head;
        while(p2!=NULL&&p2->val<x){
            p1=p1->next;
            p2=p2->next;
        }
        insert=p1;
        while(p2!=NULL){
//            cout<<p2->val<<" ";
            if(p2->val<x){
//                cout<<"1"<<" ";
                p1->next=p2->next;
                p2->next=insert->next;
                insert->next=p2;
                insert=insert->next;
                p2=p1->next;
            }
            else{
                p1=p1->next;
                p2=p2->next;
            }
            
        }
        return dummy->next;
        
    }
};
