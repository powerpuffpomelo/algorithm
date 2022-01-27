// ###################################################### 版本1 ###################################################### //
// 巧妙思路：快指针一次走两步，慢指针一次走一步；如果二者相遇说明有环；此时慢指针回到起点，两指针一次走一步会在环初始处相遇
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
    ListNode *entryNodeOfLoop(ListNode *head) {
        ListNode *first = head, *second = head;
        while(second){
            first = first -> next;
            second = second -> next;
            if(second) second = second -> next;
            else return 0;
            if(first == second){
                first = head;
                while(first != second){
                    first = first -> next;
                    second = second -> next;
                }
                return first;
            }
        }
        return 0;  // return 0; 和 return nullptr; 是一样的
    }
};

// ###################################################### 版本2 ###################################################### //
// 哈希表
class Solution {
    unordered_map<ListNode*, int> hash;
public:
    ListNode *entryNodeOfLoop(ListNode *head) {
        int vis = 1;
        for(auto p = head; p; p = p -> next){
            if(hash[p]) return p;
            else hash[p] = 1;
        }
        return 0;
    }
};