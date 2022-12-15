// ###################################################### 版本2 ###################################################### //
// 
class Solution {
public:
    unordered_map<string, int> cnt;
    typedef pair<int, string> pis;
    vector<pis> heap;
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(auto s : words) cnt[s]++;
        for(auto [s, i] : cnt) heap.push_back({i, s});
        auto cmp = [](pis a, pis b){                          // 匿名函数
            if(a.first != b.first) return a.first < b.first;
            return a.second > b.second;
        };
        make_heap(heap.begin(), heap.end(), cmp);
        vector<string> ans;
        while(k--){
            ans.push_back(heap[0].second);
            pop_heap(heap.begin(), heap.end(), cmp);
            heap.pop_back();
        }
        return ans;
    }
};

// ###################################################### 版本1 ###################################################### //
// 我的初版
class Solution {
public:
    unordered_map<string, int> idx_map;
    struct node{
        int freq;
        string str;
        node(int _f, string _s): freq(_f), str(_s) {}
    }*nodes[510];
    static bool cmp(node* a, node* b){
        if(a->freq != b->freq) return a->freq > b->freq;
        else return a->str < b->str;
    }
    int idx = 0;
    vector<string> topKFrequent(vector<string>& words, int k) {
        for(auto s : words){
            if(!idx_map.count(s)){
                idx_map[s] = idx;
                nodes[idx++] = new node(1, s);
            }else{
                nodes[idx_map[s]]->freq++;
            }
        }
        sort(nodes, nodes + idx, cmp);
        vector<string> ans;
        for(int i = 0; i < k; i++) ans.push_back(nodes[i]->str);
        return ans;
    }
};