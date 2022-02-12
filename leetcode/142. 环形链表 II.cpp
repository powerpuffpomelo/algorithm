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
    ListNode *detectCycle(ListNode *head) {
        auto first = head, second = head;
        while(second){
            first = first->next;
            second = second->next;
            if(!second) return nullptr;
            second = second->next;
            if(first == second){
                second = head;
                while(first != second){
                    first = first->next;
                    second = second->next;
                }
                return first;
            }
        }
        return nullptr;
    }
};