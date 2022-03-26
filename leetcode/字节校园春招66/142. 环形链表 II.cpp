// ###################################################### 版本1 ###################################################### //
// 快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto first = head, second = head;
        while(first){
            first = first->next;
            second = second->next;
            if(!first) return nullptr;
            first = first->next;
            if(first == second){
                first = head;
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

// ###################################################### 版本2 ###################################################### //
// 快慢指针
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        auto first = head, second = head;
        while(first && first->next){
            first = first->next->next;
            second = second->next;
            if(first == second) break;
        }
        if(first && first->next){
            first = head;
            while(first != second){
                first = first->next;
                second = second->next;
            }
            return first;
        }else return nullptr;
    }
};