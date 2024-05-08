// ###################################################### 版本1 ###################################################### //
#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;
int n;
struct Segment{   // 每条扫描线
    double x, y1, y2;
    int k;  // k=1代表岛屿来了；k=-1代表岛屿走了
    bool operator< (const Segment &t)const{
        return x < t.x;
    }
}seg[N * 2];
struct Node{
    int l, r, cnt;  // cnt代表这条线段中覆盖了多少个矩形岛屿。（但如果没有cnt，也不代表没有岛屿，cnt只是方便计算len的）
    double len;  // len代表这条线段中，有岛屿覆盖的长度。
}tr[N * 8];  // 有2N个y值，2N个点对应的线段树大小是8N
vector<double> ys;

int find(double y){  // 离散化，浮点数y映射为整数id。
    return lower_bound(ys.begin(), ys.end(), y) - ys.begin();
}

void build(int u, int l, int r){
    tr[u] = {l, r, 0, 0};
    if(l < r){
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
    }
}

void pushup(int u){
    if(tr[u].cnt) tr[u].len = ys[tr[u].r + 1] - ys[tr[u].l];
    else if(tr[u].l < tr[u].r) tr[u].len = tr[u << 1].len + tr[u << 1 | 1].len;
    else tr[u].len = 0;
}

void modify(int u, int l, int r, int k){  // 在线段树中，modify整数id 代表 modify从id到id+1这一条线段
    if(tr[u].l >= l && tr[u].r <= r){
        tr[u].cnt += k;
        pushup(u);
    }else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(l <= mid) modify(u << 1, l, r, k);
        if(r > mid) modify(u << 1 | 1, l, r, k);
        pushup(u);
    }
}

int main(){
    int T = 1;
    while(cin >> n, n){
        ys.clear();
        for(int i = 0, j = 0; i < n; i++){
            double x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            seg[j++] = {x1, y1, y2, 1};
            seg[j++] = {x2, y1, y2, -1};
            ys.push_back(y1);
            ys.push_back(y2);
        }
        sort(seg, seg + n * 2);
        sort(ys.begin(), ys.end());
        ys.erase(unique(ys.begin(), ys.end()), ys.end());
        build(1, 0, ys.size() - 2);
        double ans = 0;
        for(int i = 0; i < n * 2; i++){
            if(i) ans += tr[1].len * (seg[i].x - seg[i - 1].x);
            modify(1, find(seg[i].y1), find(seg[i].y2) - 1, seg[i].k);
        }
        printf("Test case #%d\n", T++);
        printf("Total explored area: %.2f\n\n", ans);
    }
    return 0;
}