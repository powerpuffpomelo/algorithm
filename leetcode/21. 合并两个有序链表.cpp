// ###################################################### 版本1 ###################################################### //
// 迭代
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        ListNode *i = list1, *j = list2;
        while(i && j){
            if(i->val <= j-> val){
                cur = cur->next = i;
                i = i->next;
            }else{
                cur = cur->next = j;
                j = j->next;
            }
        }
        cur->next = i ? i : j;
        return dummy->next;
    }
};

// ###################################################### 版本2 ###################################################### //
// 递归 空间复杂度也是O(n + m)，因为需要调用函数消耗栈空间
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2) return list1 ? list1 : list2;
        if(list1->val < list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }else{
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};