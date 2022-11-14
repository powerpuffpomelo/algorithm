// you can use includes, for example:
// #include <algorithm>
#include <bits/stdc++.h>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int ans = INT_MAX;

int solution(vector<int> &A, int X, int Y) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    int n = A.size();
    for(int r = 0; r < Y; r++){  // 余数
        queue<int> q;
        int sum = 0;
        for(int i = 0; i * Y + r < n; i++){   // 第几组
            if(q.size() == X){
                sum -= q.front();
                q.pop();
            }
            int x = A[i * Y + r];
            q.push(x);
            sum += x;
            if(q.size() == X) ans = min(ans, sum);
        }
    }
    return ans;
}
