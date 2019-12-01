#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define X first
#define Y second
const int maxn = 1e3 + 5;

int n, m;
char s[maxn][maxn];
int sx,sy;
int row[maxn];
pii pos[30];
vector<int> have[maxn];
char ans[maxn][maxn];

void paint(int r1, int c1, int r2, int c2, char val) {
    for(int i=r1;i<=r2;i++) {
        for(int j=c1;j<=c2;j++) {
            if(ans[i][j]=='.') ans[i][j] = val-'A'+'a';
        }
    }
}

void solve(int r1, int c1, int r2, int c2) {
    //printf("solve %d %d %d %d\n",r1,c1,r2,c2);
    if(r1>r2 || c1>c2) return ;
    int low = 0;
    for(int x=r1;x<=r2;x++) {
        have[x].clear();
        for(int y=c1;y<=c2;y++) {
            if(s[x][y]!='.') {
                have[x].push_back(y);
                low = x;
                //printf("LOW = %d\n",x);
            }
        }
    }
    if(low==0) assert(0);

    int lrow = r1-1;
    for(int x=r1;x<=r2;x++) {
        int lcol = c1-1;
        for(int i=0;i<have[x].size();i++) {
            int y = have[x][i];
            if(i == have[x].size()-1) {
                //printf("YAY %c\n",s[x][y]);
                if(low == x) paint(lrow+1,lcol+1,r2,c2,s[x][y]);
                else paint(lrow+1,lcol+1,x,c2,s[x][y]);
            }
            else {
                if(low == x) paint(lrow+1,lcol+1,r2,y,s[x][y]);
                else paint(lrow+1,lcol+1,x,y,s[x][y]);
            }
            lcol = y;
        }
        if(!have[x].empty()) lrow = x;
    }
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf(" %s",s[i] + 1);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(s[i][j] == 'A') {
                sx = i;
                sy = j;
            }
            if(s[i][j] != '.') pos[s[i][j]-'A'] = {i, j};
            ans[i][j] = s[i][j];
        }
    }

    int mx = -1;
    pair<pii, pii> wow;
    for(int r1=sx;r1>=1;r1--) {
        for(int r2=sx;r2<=n;r2++) {
            int c1 = 1, c2 = m;
            for(int c=1;c<26;c++) {
                if(r1<=pos[c].X && pos[c].X<=r2) {
                    if(pos[c].Y<=sy) {
                        c1 = max(c1, pos[c].Y+1);
                    }
                    if(sy<=pos[c].Y) {
                        c2 = min(c2, pos[c].Y-1);
                    }
                }
            }
            if(c1<=c2 && (r2-r1+1)*(c2-c1+1) > mx) {
                mx = (r2-r1+1) * (c2-c1+1);
                wow = {{r1, r2}, {c1, c2}};
            }
        }
    }

    //printf("wow = %d %d %d %d\n",wow.X.X,wow.X.Y,wow.Y.X,wow.Y.Y);
    int r1 = wow.X.X, r2 = wow.X.Y, c1 = wow.Y.X, c2 = wow.Y.Y;

    solve(1,1,r1-1,m);
    solve(r2+1,1,n,m);
    solve(r1,1,r2,c1-1);
    solve(r1,c2+1,r2,m);
    solve(r1,c1,r2,c2);

    for(int i=1;i<=n;i++) {
        printf("%s\n",ans[i]+1);
    }
}