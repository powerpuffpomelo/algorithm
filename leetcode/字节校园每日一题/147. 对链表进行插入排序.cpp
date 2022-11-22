// ###################################################### 版本3 ###################################################### //
// 链表插入排序
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        auto dummy = new ListNode(-1);  // 新建一个链表
        for(auto p = head; p; ){  // 每次从原链表中取出一个元素，插入新链表
            auto cur = dummy, next = p->next;
            while(cur->next && cur->next->val <= p->val) cur = cur->next;  // 新链表从前往后寻找插入位置
            p->next = cur->next;
            cur->next = p;
            p = next;
        }
        return dummy->next;
    }
};

// ###################################################### 版本2 ###################################################### //
// 借助vector插入排序
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> vec;
        for(auto p = head; p; p = p->next){
            vec.push_back(p);
        }
        for(int i = 1; i < vec.size(); i++){
            int j = i;
            while(j > 0 && vec[j]->val < vec[j - 1]->val){
                swap(vec[j], vec[j - 1]);
                j--;
            }
        }
        for(int i = 0; i < vec.size(); i++){
            if(i < vec.size() - 1) vec[i]->next = vec[i + 1];
            else vec[i]->next = nullptr;
        }
        return vec[0];
    }
};

// ###################################################### 版本1 ###################################################### //
// 偷懒，非插入排序
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
    static bool cmp(ListNode* a, ListNode* b){
        return a->val < b->val;
    }
    ListNode* insertionSortList(ListNode* head) {
        vector<ListNode*> vec;
        for(auto p = head; p; p = p->next) vec.push_back(p);
        sort(vec.begin(), vec.end(), cmp);
        auto dummy = new ListNode(0), pre = dummy;
        for(auto p : vec){
            pre = pre->next = p;
            p->next = nullptr;
        }
        return dummy->next;
    }
};