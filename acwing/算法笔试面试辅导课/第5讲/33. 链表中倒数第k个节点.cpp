/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// ###################################################### 版本1 ###################################################### //
// 双指针
class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        auto ans = pListHead, p = pListHead;
        while(k--){
            if(p) p = p -> next;
            else return nullptr;
        }
        while(p){
            p = p -> next;
            ans = ans -> next;
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
class Solution {
public:
    ListNode* findKthToTail(ListNode* pListHead, int k) {
        int n = 0;
        for(auto p = pListHead; p; p = p -> next) n++;
        if(n < k) return nullptr;
        auto p = pListHead;
        for(int i = 0; i < n - k; i++) p = p -> next;
        return p;
    }
};