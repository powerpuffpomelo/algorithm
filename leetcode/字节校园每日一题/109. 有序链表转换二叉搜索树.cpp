// ###################################################### 版本1 ###################################################### //
// 
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return 0;
        int n = 0;
        for(auto p = head; p; p = p->next) n++;
        if(n == 1) return new TreeNode(head->val);
        auto a = head;
        for(int i = 0; i < n / 2 - 1; i++) a = a->next;
        auto root = new TreeNode(a->next->val);  // 奇数中间 偶数右
        root->right = sortedListToBST(a->next->next);
        a->next = nullptr;
        root->left = sortedListToBST(head);
        return root;
    }
};