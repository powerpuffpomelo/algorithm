/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ###################################################### 版本1 ###################################################### //
// 确定不重复才加进来
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode *h = new ListNode(0);
        auto pre = h, cur = head;
        while(cur){
            if(cur->next && cur->next->val == cur->val){
                int v = cur->val;
                while(cur && cur->val == v) cur = cur->next;
            }else{
                pre = pre->next = cur;
                cur = cur->next;
                pre->next = nullptr;
            }
        }
        return h->next;
    }
};

// ###################################################### 版本2 ###################################################### //
// 先加进来再看要不要删
class Solution {
public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode *h = new ListNode(-1);
        h->next = head;
        auto p = h;
        while(p->next){
            auto q = p->next;
            while(q && q->val == p->next->val) q = q->next;
            if(p->next->next == q) p = p->next;
            else p ->next = q;
        }
        return h->next;
    }
};