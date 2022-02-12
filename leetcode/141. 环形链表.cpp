/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto first = head, second = head;
        while(second){
            first = first->next;
            second = second->next;
            if(!second) return false;
            second = second->next;
            if(first == second) return true;
        }
        return false;
    }
};