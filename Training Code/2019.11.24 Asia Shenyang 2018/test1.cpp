#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = (int)1e7 + 50;

int find(int x) {
    int res = 0;
    int j = (int)sqrt(x + 5);
    for(int i = 1; i * i <= x; i++) {
        while(j * j + i * i > x) j--;
        if(j * j + i * i == x) res++;
    }
    return res;
}

vector<P> p[N];

int main() {
    ll res = 0, mx = 0;
    for(int i = 1; i <= (int)1e7; i++) {
        ll cur = find(i);
        res += cur;
        mx = max(cur, mx);
        if(i % 10000 == 0) cout << res << " " << mx << endl;
    }
}