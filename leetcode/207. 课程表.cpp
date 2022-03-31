class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses);
        vector<int> ind(numCourses);
        for(auto& e : prerequisites){
            g[e[1]].push_back(e[0]);
            ind[e[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!ind[i]) q.push(i);
        }
        int cnt = 0;
        while(q.size()){
            auto t = q.front();
            q.pop();
            cnt++;
            for(int x : g[t]){
                if(--ind[x] == 0) q.push(x);
            }
        }
        return cnt == numCourses;
    }
};