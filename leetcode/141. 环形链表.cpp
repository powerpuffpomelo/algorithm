// ###################################################### 版本3 ###################################################### //
// 快慢指针
class Solution {
public:
    bool hasCycle(ListNode *head) {
        auto first = head, second = head;
        while(first && first->next){
            first = first->next->next;
            second = second->next;
            if(first == second) return true;
        }
        return false;
    }
};

// ###################################################### 版本2 ###################################################### //
// 快慢指针
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

// ###################################################### 版本1 ###################################################### //
// 哈希
class Solution {
public:
    unordered_set<ListNode*> se;
    bool hasCycle(ListNode *head) {
        while(head){
            if(se.count(head)) return true;
            se.insert(head);
            head = head->next;
        }
        return false;
    }
};

