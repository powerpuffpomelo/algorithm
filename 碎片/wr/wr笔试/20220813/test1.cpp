// you can use includes, for example:
#include <bits/stdc++.h>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    double sum = 0;
    priority_queue<double> q;
    for(auto x : A){
        sum += x;
        q.push(x);
    }
    double sub = sum / 2, temp = 0;
    int ans = 0;
    while(temp < sub){
        auto t = q.top();
        temp += t / 2;
        q.pop();
        q.push(t / 2);
        ans++;
    }
    return ans;
}
