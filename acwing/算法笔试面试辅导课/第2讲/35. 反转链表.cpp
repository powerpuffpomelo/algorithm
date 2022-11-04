// ###################################################### 版本1 ###################################################### //
// 迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;
        while(cur){
            ListNode *ne = cur -> next;
            cur -> next = pre;
            pre = cur, cur = ne;
        }
        return pre;
    }
};

// ###################################################### 版本2 ###################################################### //
// 递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode *newhead = reverseList(head -> next);
        head -> next -> next = head;
        head -> next = nullptr;
        return newhead;
    }
};