// ###################################################### 版本3 ###################################################### //
// 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto dummy = new ListNode(0), cur = dummy;
        int t = 0;
        while(l1 || l2 || t){
            auto p = new ListNode(t);
            if(l1) p->val += l1->val, l1 = l1->next;
            if(l2) p->val += l2->val, l2 = l2->next;
            t = p->val / 10;
            p->val %= 10;
            cur = cur->next = p;
        }
        return dummy->next;
    }
};

// ###################################################### 版本1 ###################################################### //
// 非常优雅！不用考虑哪个链表更长，只要算出来数就可以
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode *res = new ListNode(-1);   //添加虚拟头结点，简化边界情况的判断
        ListNode *cur = res;
        int carry = 0;  //表示进位
        while (l1 || l2) 
        {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry) cur->next = new ListNode(1); //如果最高位有进位，则需在最前面补1.
        return res->next;   //返回真正的头结点
    }
};

// ###################################################### 版本2 ###################################################### //
// 我的初版
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int rem = 0;
        auto i = l1, j = l2;
        auto dummy = new ListNode(0), pre = dummy;
        while(i && j){
            int t = i->val + j->val + rem;
            auto cur = new ListNode(t % 10);
            rem = t / 10;
            pre = pre->next = cur;
            i = i->next, j = j->next;
        }
        if(i) pre->next = i;
        else pre->next = j;
        if(rem){
            if(pre->next){
                pre = pre->next;
                pre->val += rem;
                while(pre->val >= 10){
                    rem = 1;
                    pre->val -= 10;
                    if(pre->next) pre->next->val++;
                    else pre->next = new ListNode(1);
                    pre = pre->next;
                }
            }else{
                pre->next = new ListNode(1);
            }
            
        }
        
        return dummy->next;
    }
};