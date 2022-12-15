class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ind(n + 1), outd(n + 1);
        for(auto v : trust){
            ind[v[1]]++;
            outd[v[0]]++;
        }
        int ans = -1;
        for(int i = 1; i <= n; i++){
            if(ind[i] == n - 1 && outd[i] == 0){
                if(ans == -1) ans = i;
                else return -1;
            }
        }
        return ans;
    }
};