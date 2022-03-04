// ###################################################### 版本2 ###################################################### //
// 轻巧写法
#include <bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
int has_pa[N];
vector<int> children[N];

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int pa, ch;
        cin >> pa >> ch;
        has_pa[ch] = true;
        children[pa].push_back(ch);
    }
    int root;
    for(int i = 1; i < N; i++){
        if(!has_pa[i] && children[i].size()){
            root = i;
            cout << root << endl;
            break;
        }
    }
    int mm = 1;
    for(int i = 2; i < N; i++){
        if(children[i].size() > children[mm].size()) mm = i;
    }
    cout << mm << endl;
    sort(children[mm].begin(), children[mm].end());
    for(int x : children[mm]) cout << x << ' ';
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// 我的初版
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
struct node{
    int num;
    vector<node*> children;
    node(int _num): num(_num) {}
}*nodes[N];
bool is_root[N];
int n, m;
unordered_map<int, int> num2id;
int id = 0;

int find_root(){
    for(int i = 0; i < n; i++){
        if(is_root[i]) return i;
    }
}

int find_most_children(){
    int ret = 0, mm = 0;
    for(int i = 0; i < n; i++){
        if((int)nodes[i]->children.size() > mm){
            ret = i, mm = nodes[i]->children.size();
        }
    }
    return ret;
}

int main(){
    cin >> n >> m;
    fill(is_root, is_root + N, true);
    while(m--){
        int x, y;
        cin >> x >> y;
        if(!num2id.count(x)){
            num2id[x] = id;
            nodes[id++] = new node(x);
        }
        if(!num2id.count(y)){
            num2id[y] = id;
            nodes[id++] = new node(y);
        }
        int xid = num2id[x], yid = num2id[y];
        nodes[xid]->children.push_back(nodes[yid]);
        is_root[yid] = false;
    }
    int root_id = find_root();
    cout << nodes[root_id]->num << endl;
    int most_children_id = find_most_children();
    cout << nodes[most_children_id]->num << endl;
    vector<int> vv;
    for(auto x : nodes[most_children_id]->children){
        vv.push_back(x->num);
    }
    sort(vv.begin(), vv.end());
    for(int x : vv) cout << x << ' ';
    return 0;
}

