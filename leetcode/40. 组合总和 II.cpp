// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    vector<vector<int>> ans;
    int n;
    void dfs(vector<int>& candidates, int target, int u, vector<int>& vec){
        if(target == 0){        // 注意顺序！target==0要放在判断u>=n之前，否则可能错过 选最后一个数的正确答案
            ans.push_back(vec);
            return;
        }
        if(u >= n || target < 0) return;
        int x = candidates[u];
        // 不放当前数
        int k = u + 1;
        while(k < n && candidates[k] == x) k++;  // 控制答案不能重复，要放的话就可着前边的放，不放的话就跳到下一个数。（比如一共有五个2，但只需要两个2，就取前两个）
        dfs(candidates, target, k, vec);
        // 放当前数
        vec.push_back(x);
        dfs(candidates, target - x, u + 1, vec);
        vec.pop_back();
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dfs(candidates, target, 0, vec);
        return ans;
    }
};