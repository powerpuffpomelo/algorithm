// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    const int N = 1e5 + 10;
    struct robot{
        int id, pos, health;
        char dir;
        robot(int _id, int _pos, int _health, char _dir){
            id = _id, pos = _pos, health = _health, dir = _dir;
        }
    };
    static bool cmp_pos(robot* a, robot* b){
        return a->pos < b->pos;
    }
    static bool cmp_id(robot* a, robot* b){
        return a->id < b->id;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<robot*> robots;
        for(int i = 0; i < n; i++){
            auto rob = new robot(i, positions[i], healths[i], directions[i]);
            robots.push_back(rob);
        }
        sort(robots.begin(), robots.end(), cmp_pos);
        stack<robot*> stk;
        for(int i = 0; i < n; i++){
            // cout << robots[i]->pos << ' ' << robots[i]->health << ' ' << robots[i]->dir << endl;
            bool died = false;
            if(robots[i]->dir == 'L'){
                while(stk.size() && stk.top()->dir == 'R' && !died){
                    if(robots[i]->health > stk.top()->health){
                        stk.pop();
                        robots[i]->health --;
                    }else if(robots[i]->health < stk.top()->health){
                        stk.top()->health --;
                        died = true;
                    }else{
                        stk.pop();
                        died = true;
                    }
                }
            }
            if(!died) stk.push(robots[i]);
        }
        vector<robot*> temp;
        while(stk.size()){
            temp.push_back(stk.top());
            stk.pop();
        }
        sort(temp.begin(), temp.end(), cmp_id);
        vector<int> ans;
        for(auto r : temp) ans.push_back(r->health);
        return ans;
    }
};