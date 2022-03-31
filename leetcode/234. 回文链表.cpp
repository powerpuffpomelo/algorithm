// ###################################################### 版本3 ###################################################### //
// 空间复杂度O(1)，翻转链表后半段，但本题不能改动链表，所以判断完之后还要翻转回原来的样子
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        int n = 0;
        for(auto p = head; p; p = p->next) n++;
        auto a = head;
        for(int i = 0; i < (n + 1) / 2 - 1; i++) a = a->next;
        auto b = a->next;
        while(b){
            auto next = b->next;
            b->next = a;
            a = b, b = next;
        }
        auto tail = a;
        b = head;
        bool ans = true;
        for(int i = 0; i < n / 2; i++){
            if(a->val != b->val){
                ans = false;
                break;
            }
            a = a->next;
            b = b->next;
        }
        a = 0, b = tail;
        for(int i = 0; i < n / 2; i++){
            auto next = b->next;
            b->next = a;
            a = b, b = next;
        }
        return ans;
    }
};

// ###################################################### 版本2 ###################################################### //
// 字符记录，因为每个节点内都是个位数，但空间复杂度也是O(n)
class Solution {
public:
    string a, b;
    bool isPalindrome(ListNode* head) {
        while(head){
            a += head->val + '0';
            head = head->next;
        }
        b = a;
        reverse(b.begin(), b.end());
        return a == b;
    }
};

// ###################################################### 版本1 ###################################################### //
// 空间复杂度O(n)，额外开数组记录
class Solution {
public:
    vector<int> a, b;
    bool isPalindrome(ListNode* head) {
        while(head){
            a.push_back(head->val);
            head = head->next;
        }
        b = a;
        reverse(b.begin(), b.end());
        for(int i = 0; i < a.size(); i++){
            if(a[i] != b[i]) return false;
        }
        return true;
    }
};