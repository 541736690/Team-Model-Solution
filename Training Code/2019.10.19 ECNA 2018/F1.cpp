//
// Created by 54173 on 10/19/2019.
//
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
const int INF = 22000;


int p;
int a[maxn];
int vis[3][12][12];
int cnt[12][12][12];

struct P {
    int x, n, y, m, z;

    void print_out() {
        printf("triple correlation %d(%d)%d(%d)%d found\n", a[x], n, a[y], m, a[z]);
    }
};

vector<P> res;



int main() {
    scanf("%d",&p);
    for(int i=1;i<=p;i++) scanf("%d",&a[i]);


    int lim = (int)(ceil((double)p / 40)) + 1;
    for(int n=1;n<=p;n++) {
        for(int m=1;m+n<=p;m++) {
            memset(vis, -1, sizeof(vis));
            memset(cnt, 0, sizeof(cnt));
            for(int x=1;x+m+n<=p;x++) {
                int y = x+n;
                int z = x+n+m;
                int A = a[x], B = a[y], C = a[z];
                //case 1 (AB)
                if(vis[0][A][B]==-1) vis[0][A][B] = C;
                else if(vis[0][A][B] != -1 && vis[0][A][B] != C) vis[0][A][B] = -INF;

                cnt[A][B][C]++;
                if(vis[1][A][C]==-1) vis[1][A][C] = B;
                else if(vis[1][A][C] != -1 && vis[1][A][C] != B) vis[1][A][C] = -INF;

                if(vis[2][B][C] ==-1) vis[2][B][C] = A;
                else if(vis[2][B][C] != -1 && vis[2][B][C] != A) vis[2][B][C] = -INF;
            }
            for(int x=1;x+m+n<=p;x++) {
                int y = x+n;
                int z = x+n+m;
                int A = a[x], B = a[y], C = a[z];

                if(vis[0][A][B] != -INF && vis[1][A][C] != -INF && vis[2][B][C] != -INF) {
                    if(cnt[A][B][C] >= lim) {
                        res.push_back({x, n, y, m, z});
                        cnt[A][B][C] = -1;
                    }
                }
            }
        }
    }
    if(res.empty()) {
        printf("random sequence\n");
        return 0;
    }
    int mn_x = INF;
    int mn_n = INF, mn_m = INF;
    int idx = 0;
    for(int i = 1; i < res.size(); i++) {
        P &p = res[i];
        if(p.x < mn_x || (p.x == mn_x && p.n < mn_n) || (p.x == mn_x && p.n == mn_n && p.m < mn_m)) {
            idx = i;
            mn_x = p.x;
            mn_n = p.n;
            mn_m = p.m;
        }
    }
    res[idx].print_out();


}
