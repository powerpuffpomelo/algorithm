class Solution {
public:
    // 堆的比较函数需要传入结构体，重载()，返回大的在下 所以是小顶堆
    struct cmp{
        bool operator() (ListNode* a, ListNode* b){
            return a->val > b->val;
        } 
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
        for(auto p : lists){
            if(p) heap.push(p);
        }
        auto dummy = new ListNode(-1), cur = dummy;
        while(heap.size()){
            auto t = heap.top();
            heap.pop();
            cur = cur->next = t;
            if(t->next) heap.push(t->next);
        }
        return dummy->next;
    }
};