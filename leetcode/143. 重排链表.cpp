// ###################################################### 版本2 ###################################################### //
// 非递归
class Solution {
public:
    void reorderList(ListNode* head) {
        int n = 0;
        for(auto p = head; p; p = p->next) n++;
        auto mid = head;
        for(int i = 0; i < (n + 1) / 2 - 1; i++) mid = mid->next;
        auto a = mid, b = a->next;
        while(b){
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        if(n % 2) mid->next = nullptr;
        else mid->next->next = nullptr;
        auto p = head, q = a;
        for(int i = 0; i < (n - 1) / 2; i++){
            auto r = q->next;
            q->next = p->next;
            p->next = q;
            p = q->next;
            q = r;
        }
    }
};

// ###################################################### 版本1 ###################################################### //
// 递归
class Solution {
public:
    ListNode* reorder(ListNode* head){
        if(!head || !head->next || !head->next->next) return head;
        auto c = head, d = c->next;
        while(d->next){
            c = d, d = d->next;
        }
        auto b = head->next;
        head->next = d;
        c->next = nullptr;
        d->next = reorder(b);
        return head;
    }
    void reorderList(ListNode* head) {
        reorder(head);
    }
};