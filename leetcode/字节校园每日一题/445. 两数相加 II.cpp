// ###################################################### 版本2 ###################################################### //
// 反转链表
class Solution {
public:
    ListNode* reverse(ListNode* head){
        auto a = head, b = head->next;
        while(b){
            auto c = b->next;
            b->next = a;
            a = b, b = c;
        }
        head->next = nullptr;
        return a;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto p = reverse(l1), q = reverse(l2);
        auto head = new ListNode(-1);
        for(int t = 0; p || q || t;){
            if(p) t += p->val, p = p->next;
            if(q) t += q->val, q = q->next;
            auto cur = new ListNode(t % 10);
            t /= 10;
            cur->next = head->next;
            head->next = cur;
        }
        return head->next;
    }
};

// ###################################################### 版本1 ###################################################### //
// 事先存储
class Solution {
public:
    vector<int> v1, v2, ans;
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto h1 = l1, h2 = l2;
        while(h1){
            v1.push_back(h1->val);
            h1 = h1->next;
        }
        while(h2){
            v2.push_back(h2->val);
            h2 = h2->next;
        }
        reverse(v1.begin(), v1.end());
        reverse(v2.begin(), v2.end());
        for(int i = 0, t = 0; i < v1.size() || i < v2.size() || t; i++){
            if(i < v1.size()) t += v1[i];
            if(i < v2.size()) t += v2[i];
            ans.push_back(t % 10);
            t /= 10;
        }
        reverse(ans.begin(), ans.end());
        auto dummy = new ListNode(0), p = dummy;
        for(auto x : ans){
            auto q = new ListNode(x);
            p = p->next = q;
        }
        return dummy->next;
    }
};