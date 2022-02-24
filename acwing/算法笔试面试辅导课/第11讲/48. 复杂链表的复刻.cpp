// ###################################################### 版本2 ###################################################### //
// 哈希, 更简单的思路，时间O(n), 空间O(n)
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        unordered_map<ListNode*, ListNode*> hashh;
        hashh[nullptr] = nullptr;
        for(ListNode *p = head; p; p = p->next){
            hashh[p] = new ListNode(p->val);
        }
        for(ListNode *p = head; p; p = p->next){
            hashh[p]->next = hashh[p->next];
            hashh[p]->random = hashh[p->random];
        }
        return hashh[head];
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版, 时间O(n), 空间O(n)
/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        if(!head) return nullptr;
        ListNode *ans_head = new ListNode(head->val);
        ListNode *p = head, *q = ans_head;
        for(; p->next; p = p->next){
            q->next = new ListNode(p->next->val);
            q = q->next;
        }
        p = head, q = ans_head;
        ListNode *findp, *findq;
        for(; p; p = p->next, q = q->next){
            auto r = p->random;
            if(!r){
                q->random = nullptr;
                continue;
            }
            findp = head, findq = ans_head;
            while(findp != r){
                findp = findp->next;
                findq = findq->next;
            }
            q->random = findq;
        }
        return ans_head;
    }
};

// ###################################################### 版本3 ###################################################### //
// 奇特思路，在每个点后添加一个复制
class Solution {
public:
    ListNode *copyRandomList(ListNode *head) {
        if(!head) return head;
        for(auto p = head; p;){
            ListNode *nn = new ListNode(p->val);
            ListNode *next = p->next;
            p->next = nn, nn->next = next;
            p = next;
        }
        for(auto p = head; p;){
            if(p->random){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        auto dummy = new ListNode(-1);
        for(auto p = head, q = dummy; p;){
            q = q->next = p->next;
            p = p->next = p->next->next;
        }
        return dummy->next;
    }
};