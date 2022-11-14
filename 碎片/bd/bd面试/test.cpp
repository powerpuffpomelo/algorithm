
input 1->2->3->3->4->4->5 处理后为 1->2->5.

head,   val, next

ListNode* func(ListNode* head){
    auto dummy = new ListNode(-1);
    dummy->next = head;
    auto pre = dummy;
    while(pre){
        auto cur = pre->next;
        while(cur && cur->next && cur->next->val == cur->val){
            auto x = cur->val;
            while(cur && cur->val == x) cur = cur->next;   // 这里cur忘判断是否存在了。。。
        }
        pre = pre->next = cur;
    }
    return dummy->next;
}

#============================================#
nums = [0,0,0,1,0,1,1,0], K = 3
翻转 A[0],A[1],A[2]: A变成 [1,1,1,1,0,1,1,0]
翻转 A[4],A[5],A[6]: A变成 [1,1,1,1,1,0,0,0]
翻转 A[5],A[6],A[7]: A变成 [1,1,1,1,1,1,1,1]
00010001
00011111
11111111  
// 线性遍历即可

string str, end;
typedef pair<string, int> psi;
unordered_set<string> vis;  
int n;

void change(string& temp, int i, int k){
    int j = i;
    while(k--){
        if(temp[j] == '1') temp[j] = '0';
        if(temp[j] == '0') temp[j] = '1';
        j++;
    }
}

int bfs(int k){
    queue<psi> q;
    q.push({str, 0});
    vis.insert(str);
    if(str == end) return 0;
    while(q.size()){
        auto t = q.front();
        q.pop();
        string temp = t.first;
        int cnt = t.second;
        for(int i = 0; i + k - 1 < n; i++){
            change(temp, i, k);
            if(!vis.count(temp)){
                vis.insert(temp);
                q.push(temp, cnt + 1);
                if(temp == end) return cnt + 1;
            }
            change(temp, i, k);
        }
    }
    return -1;
}

int func(vector<int>& nums, int k){
    n = nums.size();
    for(auto x : nums){
        str += '0' + x;
        end += '1';
    }
    return bfs(k);
}























