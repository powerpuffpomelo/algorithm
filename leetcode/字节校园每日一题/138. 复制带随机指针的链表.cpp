// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_map<Node*, Node*> ori2cpy;
    Node* copyRandomList(Node* head) {
        auto dummy = new Node(0), pre = dummy;
        auto p = head;
        ori2cpy[nullptr] = nullptr;
        while(p){
            auto q = new Node(p->val);
            ori2cpy[p] = q;
            pre = pre->next = q;
            p = p->next;
        }
        p = head;
        auto q = dummy->next;
        while(p){
            q->random = ori2cpy[p->random];
            p = p->next;
            q = q->next;
        }
        return dummy->next;
    }
};