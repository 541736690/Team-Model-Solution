#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n = 6;
int mp[N][N];
int m;
int ans = N;
int lx[N], rx[N], ly[N], ry[N];

bool move(int v, int d) {
    if(lx[v] == rx[v]) {
        int i = lx[v];
        if(d > 0) {
            int j = ry[v];
            if(j == 5 || mp[i][j + 1] != 0) return false;
            mp[i][++ry[v]] = v;
            mp[i][ly[v]++] = 0;
        }
        else {
            int j = ly[v];
            if(j == 0 || mp[i][j-1] != 0) return false;
            mp[i][--ly[v]] = v;
            mp[i][ry[v]--] = 0;
        }
    }
    else {
        assert(ly[v] == ry[v]);
        int j = ly[v];
        if(d > 0) {
            int i = rx[v];
            if(i == 5 || mp[i+1][j] != 0) return false;
            mp[++rx[v]][j] = v;
            mp[lx[v]++][j] = 0;
        }
        else {
            int i = lx[v];
            if(i == 0 || mp[i-1][j] != 0) return false;
            mp[--lx[v]][j] = v;
            mp[rx[v]--][j] = 0;
        }
    }
    return true;
}

void dfs(int rem) {
//    cout << rem << ": " << endl;
//    for(int i = 0; i < n; i++) {
//        for(int j = 0; j < n; j++) cout << mp[i][j] << " ";
//        cout << endl;
//    }
    if(5 - ry[1] > rem) return ;
    if(ry[1] == 5) {
        ans = min(ans, 10 - rem);
        return ;
    }
    if(5 - ry[1] == rem) {
        if(move(1, 1)) {
            dfs(rem - 1);
            assert(move(1, -1));
        }
        return ;
    }
    for(int i = 1; i <= m; i++) {
        if(move(i, 1)) {
            dfs(rem - 1);
            assert(move(i, -1));
        }
        if(move(i, -1)) {
            dfs(rem - 1);
            assert(move(i, 1));
        }
    }
}

int main() {
    fill(lx, lx + N, N);
    fill(ly, ly + N, N);
    fill(rx, rx + N, -1);
    fill(ry, ry + N, -1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int c;
            cin >> c;
            mp[i][j] = c;
            m = max(c, m);
            lx[c] = min(lx[c], i);
            rx[c] = max(rx[c], i);
            ly[c] = min(ly[c], j);
            ry[c] = max(ry[c], j);
        }
    }
    if(lx[1] != 2 || rx[1] != 2) return cout << -1 << endl, 0;
    dfs(8);
    cout << (ans == N ? -1 : ans) << endl;
}