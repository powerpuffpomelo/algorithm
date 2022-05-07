// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    queue<string> q;
    unordered_set<string> se;
    unordered_map<string, int> dist;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string s : wordList) se.insert(s);
        q.push(beginWord);
        dist[beginWord] = 1;
        while(q.size()){
            auto t = q.front();
            q.pop();
            string r = t;
            for(int i = 0; i < t.size(); i++){
                t = r;
                for(char c = 'a'; c <= 'z'; c++){
                    if(r[i] != c){
                        t[i] = c;
                        if(se.count(t) && !dist.count(t)){
                            dist[t] = dist[r] + 1;
                            if(t == endWord) return dist[t];
                            q.push(t);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    queue<string> q;
    unordered_map<string, int> dist;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string s : wordList) dist[s] = -1;
        q.push(beginWord);
        dist[beginWord] = 0;
        while(q.size()){
            auto t = q.front();
            q.pop();
            if(t == endWord) return dist[t] + 1;
            for(int i = 0; i < t.size(); i++){
                string temp = t;
                for(int j = 0; j < 25; j++){
                    if(temp[i] == 'z') temp[i] = 'a';
                    else temp[i] += 1;
                    if(dist[temp] == -1){
                        q.push(temp);
                        dist[temp] = dist[t] + 1;
                    }
                }
            }
        }
        return 0;
    }
};