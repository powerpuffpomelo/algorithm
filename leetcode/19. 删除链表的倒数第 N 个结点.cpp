// ###################################################### 版本2 ###################################################### //
// 计算节点数量
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(-1);
        dummy->next = head;
        int num = 0;
        for(auto p = head; p; p = p->next) num++;
        auto p = dummy;
        for(int i = 0; i < num - n; i++) p = p->next;
        p->next = p->next->next;
        return dummy->next;
    }
};

// ###################################################### 版本1 ###################################################### //
// 双指针
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        auto a = dummy, b = dummy;
        for(int i = 0; i < n; i++) b = b->next;
        while(b->next){
            a = a->next;
            b = b->next;
        }
        a->next = a->next->next;
        return dummy->next;
    }
};