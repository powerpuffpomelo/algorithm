// ###################################################### 版本2 ###################################################### //
// 空间复杂度 O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p = headA, q = headB;
        while(p != q){
            if(p) p = p->next;
            else p = headB;
            if(q) q = q->next;
            else q = headA;
        }
        return p;
    }
};

// ###################################################### 版本1 ###################################################### //
// 哈希
class Solution {
public:
    unordered_set<ListNode*> se;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for(auto p = headA; p; p = p->next) se.insert(p);
        for(auto p = headB; p; p = p->next){
            if(se.count(p)) return p;
        }
        return nullptr;
    }
};
