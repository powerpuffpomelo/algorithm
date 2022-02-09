/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        auto i = l1, j = l2;
        ListNode *h = new ListNode(0), *t = h;
        while(i && j){
            if(i->val <= j->val){
                t = t->next = i;
                i = i -> next;
            }else{
                t = t->next = j;
                j = j->next;
            }
        }
        if(i) t->next = i;
        else t->next = j;
        return h->next;
    }
};

// ###################################################### 版本1 ###################################################### //
// yxc
class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;
        while (l1 != NULL && l2 != NULL) {
            if (l1 -> val < l2 -> val) {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = (l1 != NULL ? l1 : l2);
        return dummy -> next;
    }
};
