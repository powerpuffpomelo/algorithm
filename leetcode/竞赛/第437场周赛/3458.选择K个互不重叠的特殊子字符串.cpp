// ###################################################### 版本1 ###################################################### //
class Solution {
    public:
        bool maxSubstringLength(string s, int k) {
            int n = s.size();
            vector<int> pos[26];  // 记录每个字母对应的开始和结束位置
            for(int i = 0; i < s.size(); i++){
                int c = s[i] - 'a';
                pos[c].push_back(i);
            }
            typedef pair<int, int> pii;
            vector<pii> vec;
            for(int i = 0; i < 26; i++){
                if(!pos[i].size()) continue;
                int l = pos[i][0], r = pos[i].back();
                bool flag = true;
                while(flag){  // 检查子串内的其它字母 是否复合特殊子串要求，不符合的话要更新范围
                    flag = false;
                    for(int j = 0; j < 26; j++){
                        int c = upper_bound(pos[j].begin(), pos[j].end(), r) - lower_bound(pos[j].begin(), pos[j].end(), l);
                        if(c > 0 && c < pos[j].size()){
                            flag = true;
                            l = min(l, pos[j][0]), r = max(r, pos[j].back());
                        }
                    }
                }
                if(!(l == 0 && r == n - 1)) vec.push_back({r, l}); // 如果合规（不是整个字符串），就把该子串加进来
            }
            sort(vec.begin(), vec.end());
            int R = -1, ret = 0;
            for(auto p : vec){  // 计算，有多少无重叠区间
                if(p.second > R){
                    R = p.first;
                    ret++;
                }
            }
            return ret >= k;
        }
    };