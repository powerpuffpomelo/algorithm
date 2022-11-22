// ###################################################### 版本1 ###################################################### //
// 我的初版
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
    static bool cmp(ListNode* a, ListNode* b){
        return a->val < b->val;
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> vec;
        for(auto p = head; p; p = p->next) vec.push_back(p);
        sort(vec.begin(), vec.end(), cmp);
        auto dummy = new ListNode(0), pre = dummy;
        for(auto p : vec){
            pre = pre->next = p;
            p->next = nullptr;
        }
        return dummy->next;
    }
};