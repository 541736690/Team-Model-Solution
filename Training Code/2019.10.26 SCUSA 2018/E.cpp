//
// Created by 54173 on 10/26/2019.
//
#include<bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 5;

int n;
double x[maxn], y[maxn], r[maxn];
vector<pair<double,pair<int,int>>> e;
int head[maxn];

int findhead(int x) {
    if(head[x] == x) return x;
    return head[x] = findhead(head[x]);
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);

    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            double dis = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])) - r[i] - r[j];
            e.push_back({dis, {i,j}});
        }
    }
    sort(e.begin(),e.end());
    for(int i=1;i<=n;i++) head[i] = i;
    double ans = 0;
    for(auto tmp : e) {
        int u = tmp.second.first, v = tmp.second.second;
        if(findhead(u)!=findhead(v)) {
            head[findhead(u)] = findhead(v);
            ans += tmp.first;
        }
    }
    printf("%.10lf",ans);
}

