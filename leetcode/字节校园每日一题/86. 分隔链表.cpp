// ###################################################### 版本2 ###################################################### //
// 妙啊
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto lh = new ListNode(-1), rh = new ListNode(-1);
        auto lt = lh, rt = rh;
        for(auto p = head; p; p = p->next){
            if(p->val < x) lt = lt->next = p;
            else rt = rt->next = p;
        }
        lt->next = rh->next;
        rt->next = 0;
        return lh->next;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        auto d1 = new ListNode(0), d2 = new ListNode(0);
        auto r1 = d1, r2 = d2;
        auto p = head;
        while(p){
            auto ne = p->next;
            if(p->val < x){
                p->next = r1->next;
                r1 = r1->next = p;
            }else{
                p->next = r2->next;
                r2 = r2->next = p;
            }
            p = ne;
        }
        r1->next = d2->next;
        return d1->next;
    }
};