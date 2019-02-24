/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (52.24%)
 * Total Accepted:    42.6K
 * Total Submissions: 81.5K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
static const auto __ = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return nullptr;
}();
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* res;
        ListNode* s1=l1;
        ListNode* s2=l2;
        if(s1==NULL){return l2;}
        if(s2==NULL){return l1;}
        if(s1==NULL&&s2==NULL){return l1;}
        if(s1->val<=s2->val){
            ListNode* s3=new ListNode(s1->val);
            //s3->val=s1->val;
            //s3->next=NULL;
            res=s3;
            s1=s1->next;
        }
        else{
            ListNode* s3=new ListNode(s2->val);
            //s3->val=s2->val;
            //s3->next=NULL;
            res=s3;
            s2=s2->next;
        }
        ListNode* rcv=res;
        while(s1!=NULL&&s2!=NULL){
            if(s1->val<=s2->val){
                ListNode* s3=new ListNode(s1->val);
                //s3->val=s1->val;
                //s3->next=NULL;
                rcv->next=s3;
                s1=s1->next;
                rcv=rcv->next;
            }
            else{
                ListNode* s3=new ListNode(s2->val);
                //s3->val=s2->val;
                s3->next=NULL;
                rcv->next=s3;
                s2=s2->next;
                rcv=rcv->next;
            }

        }
        ListNode* l3;
        if(s1==NULL){l3=s2;}
        else{l3=s1;}
        while(l3!=NULL){
            ListNode* s3=new ListNode(l3->val);
                //s3->val=s->val;
                //s3->next=NULL;
                rcv->next=s3;
                l3=l3->next;
                rcv=rcv->next;
        }
        return res;
    }
};
