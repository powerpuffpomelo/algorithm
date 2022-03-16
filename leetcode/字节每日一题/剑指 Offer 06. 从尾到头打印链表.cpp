// ###################################################### 版本1 ###################################################### //
// 递归
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        if(!head) return {};
        vector<int> a = reversePrint(head->next);
        a.push_back(head->val);
        return a;
    }
};

// ###################################################### 版本2 ###################################################### //
// 栈
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        stack<int> stk;
        while(head){
            stk.push(head->val);
            head = head->next;
        }
        vector<int> ans;
        while(stk.size()){
            ans.push_back(stk.top());
            stk.pop();
        }
        return ans;
    }
};