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

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();  // 链表个数
        ListNode* ans = new ListNode;
        ListNode* rear = ans;
        while(true){
            int min_temp = 1e4 + 10, min_idx = -1;
            bool have_remain = false;
            for(int i = 0; i < n; i++){
                if(lists[i] != nullptr && lists[i] -> val < min_temp){
                    min_temp = lists[i] -> val;
                    min_idx = i;
                    have_remain = true;
                }
            }
            if(have_remain == false) break;
            // 删除
            lists[min_idx] = lists[min_idx] -> next;
            // 插入
            ListNode* mm = new ListNode;
            mm -> val = min_temp;
            rear -> next = mm;
            rear = mm;
        }
        ans = ans -> next;
        return ans;
    }
};