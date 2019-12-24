#include<bits/stdc++.h>
using namespace std;

int n,m;
char s[20][505];
int good[505];
int ans;

void f(int x, int cnt) {
    if(x == m+1) {
        // printf("cnt = %d: ",cnt);
        // for(int i=0;i<n;i++) printf(" %d",good[i]);
        // printf("\n");
        int bad = 0;
        for(int i=0;i<n;i++) if(good[i] == 0) bad = 1;
        if(!bad) ans = min(ans, cnt);
        return ;
    }
    f(x+1, cnt);
    for(int i=0;i<n;i++) good[i] += s[x][i] - '0';
    f(x+1, cnt+1);
    for(int i=0;i<n;i++) good[i] -= s[x][i] - '0';
}

void solve(int tnum) {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf(" %s",s[i]);
    ans = m+1;
    f(1,0);
    if(ans == m+1) printf("-1\n");
    else printf("%d\n",ans);
}

int main() {
    int tnum; scanf("%d",&tnum);
    for(int i=1;i<=tnum;i++) solve(i);
}