// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for(int s : stones) q.push(s);
        while(q.size() > 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            if(abs(a - b)) q.push(abs(a - b));
        }
        if(q.size()) return q.top();
        else return 0;
    }
};