#include <bits/stdc++.h>
using namespace std;

const int inf = 1e9;

int n, m;
int a[255][255];
int ex, ey;

map<int,int> cnt;

vector<pair<int,int>> way[255][255];
pair<int,int> dp[255][255];
queue<pair<int,int>> q;
pair<int,int> track[255][255];

int main() {
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            scanf("%d", &a[i][j]);
            cnt[a[i][j]]++;
        }
    }
    scanf("%d%d",&ex,&ey);

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(a[i][j]>=0) {
                int l = j;
                while(j+1<=m && a[i][j+1]==a[i][j]) j++;
                if(j-l+1 != cnt[a[i][j]]) continue;
                if(j+1<=m) way[i][j+1].push_back({i, l});
                if(l-1>=1) way[i][l-1].push_back({i, j});
            }
        }
    }

    for(int j=1;j<=m;j++) {
        for(int i=1;i<=n;i++) {
            if(a[i][j]>=0) {
                int l = i;
                while(i+1<=n && a[i+1][j]==a[i][j]) i++;
                if(i-l+1 != cnt[a[i][j]]) continue;
                if(i+1<=n) way[i+1][j].push_back({l, j});
                if(l-1>=1) way[l-1][j].push_back({i, j});
            }
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            dp[i][j] = {inf, inf};
            if(a[i][j] == -1) {
                dp[i][j] = {0, inf};
                q.push({i, j});
            }
        }
    }
    while(!q.empty()) {
        int x = q.front().first, y = q.front().second;
        //printf("q %d %d: %d %d\n",x,y,dp[x][y].first,dp[x][y].second);
        q.pop();
        for(auto tmp : way[x][y]) {
            int xx = tmp.first, yy = tmp.second;
            if(dp[xx][yy] > make_pair(dp[x][y].first + 1, a[x][y])) {
                dp[xx][yy] = {dp[x][y].first + 1, a[x][y]};
                track[xx][yy] = {x, y};
                q.push({xx,yy});
            }
        }
    }

    if(dp[ex][ey].first == inf) printf("impossible");
    else {
        vector<int> ans;
        while(a[ex][ey] != -1) {
            ans.push_back(a[ex][ey]);
            auto tmp = track[ex][ey];
            ex = tmp.first; ey = tmp.second;
        }
        reverse(ans.begin(),ans.end());
        for(auto t : ans) printf("%d ",t);
    }
}