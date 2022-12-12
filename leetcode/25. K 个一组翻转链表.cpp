// ###################################################### 版本2 ###################################################### //
// 递归
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto p = head;
        for(int i = 0; i < k - 1 && p; i++) p = p->next;   // for循环中间的条件变量，几个条件不能用逗号, 要用 && 
        if(!p) return head; 
        p = p->next;  // 注意题中条件是，不满k个，所以要先落在k个以内
        ListNode *pre = nullptr, *cur = head;
        while(cur != p){
            auto next = cur->next;
            cur->next = pre;
            pre = cur, cur = next;
        }
        head->next = reverseKGroup(p, k);
        return pre;
    }
};

// ###################################################### 版本1 ###################################################### //
// 迭代
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto dummy = new ListNode();
        dummy->next = head;
        for(auto p = dummy;;){
            auto q = p;
            for(int i = 0; i < k && q; i++) q = q->next;
            if(!q) break;
            auto a = p->next, b = a->next;
            for(int i = 0; i < k - 1; i++){
                auto next = b->next;
                b->next = a;
                a = b, b = next;
            }
            auto temp = p->next;
            p->next = a;
            temp->next = b;
            p = temp;
        }
        return dummy->next;
    }
};