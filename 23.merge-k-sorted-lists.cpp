/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (43.25%)
 * Total Accepted:    13.9K
 * Total Submissions: 32.1K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
/*
method1:使用合并双链表相似的算法,不过由于链表长度不一,空链表的判断较为复杂
method2:调用mergeTwoLists,当lists的大小为0,返回空链表,为1,返回lists[1]
>=2,则令l1=lists[0],l2=lists[i],i=1,2,...,lists.size()-1,循环调用
l1=mergeTwoLists(l1,l2)
method3:当lists.size>=2时,令l1=lists[i],l2=lists[j],j=lists.size-1;
while(j>0){
    i=0;
    while(i<j){
        l3=mergeTwoLists(l1,l2);
        lists[i]=l3;
        i++;
        j--;
    }
}
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
        for(int i=1;i<len;i++){
            
            l2=lists[i];
            l3=mergeTwoLists(l1,l2);
            l1=l3;
        }
        return l1;
    }

/*    ListNode* mergeKLists(vector<ListNode*>& lists) {
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
    */
    
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
