#include<bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n,m,na,nb;
int a[maxn], b[maxn];
bool alast[maxn], blast[maxn], vis[maxn];
set<int> wowa, wowb;

vector<pair<int,int>> edge;

int head[maxn];

int findhead(int x) {
    if(head[x]!=x) return head[x] = findhead(head[x]);
    return x;
}

int main() {
    scanf("%d%d%d%d",&n,&m,&na,&nb);
    for(int i=1;i<=na;i++) scanf("%d",&a[i]);
    for(int i=1;i<=nb;i++) scanf("%d",&b[i]);

    for(int i=na;i>=1;i--) {
        if(vis[a[i]]) continue;
        alast[i] = 1;
        vis[a[i]] = 1;
    }

    for(int i=nb;i>=1;i--) {
        if(vis[b[i]]) continue;
        blast[i] = 1;
        vis[b[i]] = 1;
    }

    for(int i=1;i<=n+m;i++) {
        if(!vis[i]) {
            if(i<=n) wowa.insert(i);
            else wowb.insert(i);
        }
    }

    int x = 1, y = 1, la = 1, lb = n+1;
    for(int i=1;i<=n+m-2;i++) {
        if(!wowa.empty() && y<=nb) {
            int t = *wowa.begin(); wowa.erase(t);
            //printf("edge %d %d\n",t,b[y]);
            lb = b[y];
            edge.push_back({t,b[y]});
            if(blast[y]) wowb.insert(b[y]);
            y++;
        }
        else if(!wowb.empty() && x<=na) {
            int t = *wowb.begin(); wowb.erase(t);
            //printf("edge %d %d\n",t,a[x]);
            la = a[x];
            edge.push_back({t,a[x]});
            if(alast[x]) wowa.insert(a[x]);
            x++;
        }
        else if(!wowa.empty() && !wowb.empty()){
            int ta = *wowa.begin(); wowa.erase(ta);
            int tb = *wowb.begin(); wowb.erase(tb);
            //printf("edge %d %d\n",ta,tb);
            lb = tb;
            edge.push_back({ta,tb});
            wowa.erase(ta);
        }
        else {
            printf("No");
            return 0;
        }
    }

    edge.push_back({la,lb});

    if(x<=na || y<=nb) {
        printf("No");
        return 0;
    }

//    for(int i=1;i<=n+m;i++) head[i] = i;
//    for(auto tmp : edge) {
////        printf("%d %d\n",tmp.first,tmp.second);
//        head[findhead(tmp.first)] = findhead(tmp.second);
//
//    }
//
//    for(int i=2,j=1;i<=n + m;i++) {
//        if(findhead(i) != findhead(j)) {
//            printf("No");
//            return 0;
//        }
//    }


    printf("Yes\n");
    for(auto tmp : edge) {
        printf("%d %d\n",tmp.first,tmp.second);
    }

}