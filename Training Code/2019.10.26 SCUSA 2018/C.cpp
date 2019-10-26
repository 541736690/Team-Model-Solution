#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1e3 + 5;
const ll mod = 1e9 + 7;

struct hs {
    ll hsh[4];
    hs(ll a = 0, ll b = 0, ll c = 0, ll d = 0) {
        hsh[0] = a;
        hsh[1] = b;
        hsh[2] = c;
        hsh[3] = d;
    }
    bool operator == (const hs other) const {
        for(int i=0;i<4;i++) if(hsh[i]!=other.hsh[i]) return false;
        return true;
    }
    bool operator < (const hs other) const {
        for(int i=0;i<4;i++) if(hsh[i]!=other.hsh[i]) return hsh[i]<other.hsh[i];
        return false;
    }
};

int n;
char a[maxn], b[maxn];

ll hello[4] = {101, 131, 173, 919};
ll pw[4][30];
set<hs> have;

hs add(hs x, int y) {
    hs ret = hs(0,0,0,0);
    for(int i=0;i<4;i++) ret.hsh[i] = ((x.hsh[i]+pw[i][y])%mod + mod)%mod;
    return ret;
}

void solve(int tnum) {
    scanf(" %s %s",a+1,b+1);
    n = strlen(a+1);

    have.clear();

    for(int x=1;x<=n;x++) {
        hs hsh = hs(0,0,0,0);
        for(int y=x;y<=n;y++) {
            hsh = add(hsh, b[y]-'a');
            have.insert(hsh);
        }
    }

    int ans = 0, st = 0, ft = 0;
    for(int x=1;x<=n;x++) {
        hs hsh = hs(0,0,0,0);
        for(int y=x;y<=n;y++) {
            hsh = add(hsh, a[y]-'a');
            if(have.find(hsh) != have.end()) {
                if(y-x+1>ans) {
                    ans = y-x+1;
                    st = x; ft = y;
                }
            }
        }
    }

    if(ans==0) printf("NONE\n");
    else {
        for(int i=st;i<=ft;i++) printf("%c",a[i]);
        printf("\n");
    }
}

int main() {
    for(int k=0;k<4;k++) {
        pw[k][0] = 1LL;
        for (int i = 1; i <= 30; i++) pw[k][i] = ((pw[k][i - 1] * hello[k])%mod + mod)%mod;
    }
    int tnum; scanf("%d",&tnum);
    for(int i=1;i<=tnum;i++) solve(i);
}