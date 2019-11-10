#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define X first
#define Y second
const int maxn = 2e5 + 5;
const int inf = 1e9;

int n, k;
int a[maxn];
pii seg[maxn*4];
int last[maxn];
set<int> wow;
vector<int> place[maxn];

void build(int pos, int l, int r) {
    if(l==r) {
        seg[pos] = {a[l], l};
        return ;
    }
    int mid = (l+r)/2;
    build(pos<<1,l,mid); build(pos<<1|1,mid+1,r);
    seg[pos] = min(seg[pos<<1], seg[pos<<1|1]);
}

void update(int pos, int l, int r, int x) {
    if(l>r || r<x || x<l) return ;
    if(l==r) {
        seg[pos] = {inf, x};
        return ;
    }
    int mid = (l+r)/2;
    update(pos<<1,l,mid,x); update(pos<<1|1,mid+1,r,x);
    seg[pos] = min(seg[pos<<1], seg[pos<<1|1]);
}

pii query(int pos, int l, int r, int x, int y) {
    if(l>r || r<x || y<l) return {inf, inf};
    if(l==r) return seg[pos];
    int mid = (l+r)/2;
    return min(query(pos<<1,l,mid,x,y), query(pos<<1|1,mid+1,r,x,y));
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        last[a[i]] = i;
        place[a[i]].push_back(i);
    }
    build(1,1,n);
    for(int i=1;i<=k;i++) wow.insert(last[i]);
    int cur = 0;
    for(int tt=1;tt<=k;tt++) {
        int low = *wow.begin();
        pii tmp = query(1,1,n,cur+1,low);
        int x = tmp.first, i = tmp.second;
        printf("%d ",x);
        for(auto t : place[x]) update(1,1,n,t);
        cur = i;
        wow.erase(last[x]);
    }
}