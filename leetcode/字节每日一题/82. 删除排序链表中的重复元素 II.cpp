// ###################################################### 版本2 ###################################################### //
// 更简单的写法
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode();
        dummy->next = head;
        auto p = dummy;
        while(p->next){
            auto q = p->next;
            while(q && q->val == p->next->val) q = q->next;
            if(q == p->next->next){
                p = p->next;
            }else{
                p->next = q;
            }
        }
        return dummy->next;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode();
        dummy->next = head;
        auto pre = dummy, cur = head;
        while(cur){
            auto p = cur->next;
            while(p && p->val == cur->val) p = p->next;
            if(p == cur->next){
                pre = cur;
                cur = cur->next;
            }else{
                cur = p;
                pre->next = p;
            }
        }
        return dummy->next;
    }
};

