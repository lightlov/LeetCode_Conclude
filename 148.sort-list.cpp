/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (34.03%)
 * Total Accepted:    172.7K
 * Total Submissions: 505.5K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
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
    ListNode* sortList(ListNode* head) {
        
        if(head==nullptr||head->next==nullptr) return head;
        
        ListNode* middle=FindMiddle(head);
        ListNode* head2=middle->next;
        middle->next=nullptr;
        ListNode* l1=sortList(head);
        ListNode* l2=sortList(head2);
        
        return mergeList(l1,l2);
        
        return head;
    }
    
private:
    ListNode* mergeList(ListNode *head1,ListNode *head2){
        ListNode* dummy=new ListNode(0);
        dummy->next=head1;
        ListNode *p1=dummy;
        ListNode *p2=head2;
        while(p2!=nullptr){
            if(p1->next==nullptr){p1->next=p2;break;}
            if(p2->val<p1->next->val){
                ListNode* temp=p2;
                p2=p2->next;
                temp->next=p1->next;
                p1->next=temp;
            }
            else{
                p1=p1->next;
            }
        }
        
        
        
        
        return dummy->next;
    }
    
    ListNode* FindMiddle(ListNode* head){
        
        if(head==nullptr) return nullptr;
        ListNode* fast=head->next;
        ListNode* slow=head;
        
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
};
