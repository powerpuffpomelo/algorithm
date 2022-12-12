// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> ma;
        int pos = 0;
        for(auto p = head; p; p = p->next){
            if(!ma.count(p)) ma[p] = pos++;
            else return p;
        }
        return nullptr;
    }
};