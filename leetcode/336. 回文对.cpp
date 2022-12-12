// ###################################################### 版本2 ###################################################### //
// 字符串哈希
typedef unsigned long long ULL;

const int N = 310, P = 131;

ULL p[N];

class Solution {
public:
    vector<vector<ULL>> h1, h2;

    ULL get(vector<ULL>& h, int l, int r) {
        return h[r] - h[l - 1] * p[r - l + 1];
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {
        p[0] = 1;
        for (int i = 1; i < N; i ++ ) p[i] = p[i - 1] * P;

        for (int i = 0; i < words.size(); i ++ ) {
            int n = words[i].size();
            vector<ULL> a(1), b(1);
            for (int j = 1; j <= n; j ++ ) a.push_back(a.back() * P + words[i][j - 1]);
            for (int j = n; j; j -- ) b.push_back(b.back() * P + words[i][j - 1]);
            h1.push_back(a);
            h2.push_back(b);
        }

        unordered_map<ULL, int> hash;
        for (int i = 0; i < words.size(); i ++ )
            hash[get(h2[i], 1, words[i].size())] = i;

        vector<vector<int>> res;
        for (int i = 0; i < words.size(); i ++ ) {
            int n = words[i].size();
            for (int j = 0; j <= n; j ++ ) {
                auto left = get(h1[i], 1, j), right = get(h1[i], j + 1, n);
                if (right == get(h2[i], 1, n - j) && hash.count(left) && hash[left] != i) res.push_back({i, hash[left]});
                if (left == get(h2[i], n - j + 1, n) && hash.count(right) && hash[right] != i && words[i].size() != words[hash[right]].size())
                    res.push_back({hash[right], i});
            }
        }
        return res;
    }
};


// ###################################################### 版本1 ###################################################### //
// 哈希，O(n*L^2)，会超时
class Solution {
public:
    bool is_palindrome(string& str){
        for(int i = 0, j = str.size() - 1; i < j; i++, j--){
            if(str[i] != str[j]) return false;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> ma;
        for(int i = 0; i < words.size(); i++){
            auto w = words[i];
            reverse(w.begin(), w.end());
            ma[w] = i;
        }
        vector<vector<int>> ans;
        for(int i = 0; i < words.size(); i++){
            string w = words[i];
            // 对每个单词w，考虑其作为回文串中较长的部分，分别位于左侧、右侧 时的情况
            for(int j = 0; j <= w.size(); j++){
                string left = w.substr(0, j), right = w.substr(j);
                if(is_palindrome(right) && ma.count(left) && ma[left] != i) ans.push_back({i, ma[left]});
                if(j && is_palindrome(left) && ma.count(right) && ma[right] != i) ans.push_back({ma[right], i});
            }
        }
        return ans;
    }
};
