// ###################################################### 版本3 ###################################################### //
// trie树，结构体指针
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
string op, str;
int n;

struct node{
    int cnt;
    node* children[26];
    node(){
        cnt = 0;
        for(int i = 0; i < 26; i++) children[i] = nullptr;
    }
}*root;

void insert(string str){
    node *p = root;
    for(char c : str){
        int u = c - 'a';
        if(!p->children[u]) p->children[u] = new node();
        p = p->children[u];
    }
    (p->cnt)++;
}

int query(string str){
    node *p = root;
    for(char c : str){
        int u = c - 'a';
        if(!p->children[u]) return 0;
        p = p->children[u];
    }
    return p->cnt;
}

int main(){
    cin >> n;
    root = new node();
    while(n--){
        cin >> op >> str;
        if(op == "I") insert(str);
        else cout << query(str) << endl;
    }
    return 0;
}

// ###################################################### 版本1 ###################################################### //
// trie树，数组模拟
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int trie[N][26], cnt[N], idx = 0;  // 下标是0的点，即是根节点又是空节点
int n;
char op[2], str[N];

void insert(char *str){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!trie[p][u]) trie[p][u] = ++idx;
        p = trie[p][u];
    }
    cnt[p]++;
}

int query(char *str){
    int p = 0;
    for(int i = 0; str[i]; i++){
        int u = str[i] - 'a';
        if(!trie[p][u]) return 0;
        p = trie[p][u];
    }
    return cnt[p];
}

int main(){
    cin >> n;
    while(n--){
        cin >> op >> str;
        if(*op == 'I') insert(str);
        else if(*op == 'Q') cout << query(str) << endl;
    }
    return 0;
}

// ###################################################### 版本2 ###################################################### //
// 哈希表
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int n;
string op, str;
unordered_map<string, int> cnt;

int main(){
    cin >> n;
    while(n--){
        cin >> op >> str;
        if(op == "I") cnt[str]++;
        else cout << cnt[str] << endl;
    }
    return 0;
}