/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (32.82%)
 * Total Accepted:    338.3K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* l1=NULL;
        ListNode* l2;
        ListNode* l3;
        int len=lists.size();
        if(len==0){return l1;}
        l1=lists[0];
        if(len==1){return l1;}
        int i;
        int j=len-1;
        while(j>0){
            i=0;
            while(i<j){
                l1=lists[i];
                l2=lists[j];
                l3=mergeTwoLists(l1,l2);
                lists[i]=l3;
                i++;
                j--;
            }
        }
        return lists[0];
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(-1), *cur = res;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                cur = cur->next;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                cur = cur->next;
                l2 = l2->next;
            }
        }
        if(l1) {
            cur->next = l1;
        }
        if(l2) {
            cur->next = l2;
        }
        return res->next;
    }
};
