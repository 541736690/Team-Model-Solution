//
// Created by 54173 on 11/24/2019.
//
#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;

struct point {
    int x,y;
};

int n, q;
point p[maxn*2];
int wow[6005][6005];

vector<pair<int,int>> cir[10000005];

bool valid(int x, int y) {
    return 1<=x && x<=6000 && 1<=y && y<=6000 && wow[x][y];
}

void solve(int tnum) {
    printf("Case #%d:\n",tnum);
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++) {
        int val; scanf("%d%d%d",&p[i].x,&p[i].y,&val);
        wow[p[i].x][p[i].y] = val;
    }
    long long lastans = 0;
    while(q--) {
        int type; scanf("%d",&type);
        if(type == 1) {
            int x,y,val; scanf("%d%d%d",&x,&y,&val);
            x = (int)(((long long)x + lastans)%6000 + 1);
            y = (int)(((long long)y + lastans)%6000 + 1);
            n++;
            p[n].x = x;
            p[n].y = y;
            wow[p[n].x][p[n].y] = val;
            //printf("new point %d %d: %d\n",x,y,val);
        }
        else if(type == 2) {
            int x,y; scanf("%d%d",&x,&y);
            x = (int)(((long long)x + lastans)%6000 + 1);
            y = (int)(((long long)y + lastans)%6000 + 1);
            wow[x][y] = 0;
            //printf("delete %d %d\n",x,y);
        }
        else if(type == 3) {
            int x,y,k,val; scanf("%d%d%d%d",&x,&y,&k,&val);
            x = (int)(((long long)x + lastans)%6000 + 1);
            y = (int)(((long long)y + lastans)%6000 + 1);
            for(auto t : cir[k]) {
                int xx = x + t.first, yy = y + t.second;
                //printf("xx = %d yy = %d\n",xx,yy);
                if(valid(xx,yy)) {
                    wow[xx][yy] += val;
                }
            }
        }
        else {
            int x,y,k; scanf("%d%d%d",&x,&y,&k);
            x = (int)(((long long)x + lastans)%6000 + 1);
            y = (int)(((long long)y + lastans)%6000 + 1);
            //printf("query %d %d\n",x,y);
            long long ans = 0;
            for(auto t : cir[k]) {
                int xx = x + t.first, yy = y + t.second;
                //printf("xx = %d yy = %d\n",xx,yy);
                if(valid(xx,yy)) {
                    ans += wow[xx][yy];
                }
            }
            printf("%lld\n",ans);
            lastans = ans;
        }
    }
    for(int i=1;i<=n;i++) wow[p[i].x][p[i].y] = 0;
}

void init() {
    for(int x=0;x<=6000;x++) {
        for(int y=0;y<=6000;y++) {
            int d = x*x + y*y;
            if(d<=10000000) {
                cir[d].push_back({x,y});
                if(x!=0) cir[d].push_back({-x,y});
                if(y!=0) cir[d].push_back({x,-y});
                if(x!=0 && y!=0) cir[d].push_back({-x,-y});
            }
            else break;
        }
    }
}

int main() {
    init();
    int tnum; scanf("%d",&tnum);
    for(int i=1;i<=tnum;i++) solve(i);
}
