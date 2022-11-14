// ###################################################### 版本3 ###################################################### //
// 归并排序，因为O(1)空间复杂度所以不能自顶向下递归，而要自底向上
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        auto dummy = new ListNode(0);
        dummy->next = head;
        int n = 0;
        for(auto p = head; p; p = p->next) n++;
        for(int i = 1; i < n; i *= 2){  // 每个有序链的长度
            auto cur = dummy;
            for(int j = 1; j + i <= n; j += i * 2){  // 每次归并的起点
                auto p = cur->next, q = p;
                for(int k = 0; k < i; k++) q = q->next;
                int x = 0, y = 0;
                while(x < i && y < i && p && q){
                    if(p->val <= q->val) cur = cur->next = p, p = p->next, x++;
                    else cur = cur->next = q, q = q->next, y++;
                }
                while(x < i && p) cur = cur->next = p, p = p->next, x++;
                while(y < i && q) cur = cur->next = q, q = q->next, y++;
                cur->next = q;
            }
        }
        return dummy->next;
    }
};

// ###################################################### 版本2 ###################################################### //
// 节点排序，依次修改指针，O(n)空间复杂度
class Solution {
public:
    static bool cmp(ListNode* a, ListNode* b){
        return a->val < b->val;
    }
    ListNode* sortList(ListNode* head) {
        auto dummy = new ListNode(0);
        vector<ListNode*> vv;
        while(head){
            vv.push_back(head);
            head = head->next;
        }
        sort(vv.begin(), vv.end(), cmp);
        auto cur = dummy;
        for(auto p : vv){
            cur = cur->next = p;
        }
        cur->next = nullptr;
        return dummy->next;
    }
};

// ###################################################### 版本1 ###################################################### //
// 最简单的方法，修改值
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        vector<int> vv;
        for(auto p = head; p; p = p->next) vv.push_back(p->val);
        sort(vv.begin(), vv.end());
        int i = 0;
        for(auto p = head; p; p = p->next, i++) p->val = vv[i];
        return head;
    }
};