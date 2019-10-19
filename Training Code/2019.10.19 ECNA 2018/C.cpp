//
// Created by 54173 on 10/19/2019.
//
#include<bits/stdc++.h>
using namespace std;

int n,m;
int val[2005];
char s[30];
int pos[2005][30];
int win[30][30];
int vis[30], cnt;

void dfs(int x) {
    vis[x] = 1; cnt++;
    for(int i=0;i<m;i++) {
        if(win[x][i] && !vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++) {
        scanf("%d %s",&val[i],s+1);
        for(int j=1;j<=m;j++) pos[i][s[j]-'A'] = j;//, printf("pos %d %c = %d\n",i,s[j],j);
    }

    for(int i=0;i<m;i++) {
        for(int j=i+1;j<m;j++) {
            int A = 0, B = 0;
            for(int x=1;x<=n;x++) {
                if(pos[x][i] < pos[x][j]) A += val[x];
                else B += val[x];
            }
            //printf("%c %c: %d %d\n",i+'A',j+'A',A,B);
            if(A > B) win[i][j] = 1;
            else win[j][i] = 1;
        }
    }

    for(int i=0;i<m;i++) {
        cnt = 0;
        memset(vis,0,sizeof(vis));
        dfs(i);
        if(cnt==m) printf("%c: can win\n",i+'A');
        else printf("%c: can't win\n",i+'A');
    }
}