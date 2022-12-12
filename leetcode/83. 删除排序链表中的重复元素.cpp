// ###################################################### 版本2 ###################################################### //
// 只需要构建一个指针就可
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        auto p = head;
        while(p->next){
            if(p->val == p->next->val) p->next = p->next->next;
            else p = p->next;
        }
        return head;
    }
};

// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        auto dummy = new ListNode(-110), p = head, q = head;
        dummy->next = p;
        while(p){
            q = p;
            while(q && q->val == p->val) q = q->next;
            p = p->next = q;
        }
        return dummy->next;
    }
};