//
// Created by 54173 on 10/19/2019.
//
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 5000 + 5;

int n,m,clue;
char s[55][55];
pair<int,int> pos[maxn];
ll sum[maxn][2];
int len[maxn][2];
int down[55][55], across[55][55];
int used[maxn][2];

bool valid(int x, int y) {
    if(x<1 || y<1 || x>n || y>m || s[x][y]=='#') return false;
    return true;
}

void compute(int id, int type) {
    int x = pos[id].first, y = pos[id].second;
    int sz = len[id][type];
    sum[id][type] = 0;
    //down
    if(type == 0) {
        for(int i=0;i<sz;i++) {
            if(s[x+i][y]!='.') sum[id][type] += sz-i;
        }
    }
    else {
        for(int i=0;i<sz;i++) {
            if(s[x][y+i]!='.') sum[id][type] += sz-i;
        }
    }
    //printf("sum %d %d = %lld\n",id,type,sum[id][type]);
}

ll wow(int x) {
    return (ll)x*(x+1)/2;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf(" %s",s[i]+1);

    //indexing
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i][j]=='#') continue;
            if(!valid(i-1,j) || !valid(i,j-1)) {
                clue++;
                int id = clue;
                pos[id] = {i, j};
                sum[id][0] = sum[id][1] = -1;
                //down
                if(!valid(i-1,j)) {
                    int x = i;
                    while(valid(x+1,j)) x++;
                    for(int k=i;k<=x;k++) down[k][j] = id;
                    len[id][0] = x-i+1;
                    compute(id,0);
                }
                //across
                if(!valid(i,j-1)) {
                    int x = j;
                    while(valid(i,x+1)) x++;
                    for(int k=j;k<=x;k++) across[i][k] = id;
                    len[id][1] = x-j+1;
                    compute(id,1);
                }
            }
        }
    }

    //return 0;

    //solve
    while(1) {
        int id = 0, type = 0;
        for(int t=1;t>=0;t--) {
            for(int x=1;x<=clue;x++) {
                if(sum[x][t]==-1) continue;
                if(used[x][t]) continue;
                if(id == 0 || sum[x][t] * wow(len[id][type]) > sum[id][type] * wow(len[x][t])) {
                    id = x;
                    type = t;
                }
            }
        }
        if(id == 0 && type == 0) break;
        if(sum[id][type] == wow(len[id][type])) {
            used[id][type] = 1;
            continue;
        }
        if(type==0) printf("%dD\n",id);
        else printf("%dA\n",id);

        //printf("sum = %lld  wow = %lld\n",sum[id][type],wow(len[id][type]));

        int x = pos[id].first, y = pos[id].second;
        int sz = len[id][type];

        //fill
        //down
        if(type == 0) {
            for(int i=0;i<sz;i++) s[x+i][y] = 'A';
        }
            //across
        else {
            for(int i=0;i<sz;i++) s[x][y+i] = 'A';
        }

        //update
        compute(id,type);
        //down
        if(type == 0) {
            for(int i=0;i<sz;i++) if(across[x+i][y]) compute(across[x+i][y], 1);
        }
            //across
        else {
            for(int i=0;i<sz;i++) if(down[x][y+i]) compute(down[x][y+i], 0);
        }

    }
}
