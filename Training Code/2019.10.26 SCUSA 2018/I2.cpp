//
// Created by 54173 on 10/26/2019.
//
#include<bits/stdc++.h>
using namespace std;

struct node {
    int a,b;
    pair<int,pair<int,pair<int,int>>> t;
    node(int _a = 0, int _b = 0, pair<int,pair<int,pair<int,int>>> _t = {0, {0, {0,0}}}) {
        a = _a;
        b = _b;
        t = _t;
    }
    bool operator < (node x) const {
        if(a!=x.a) return a < x.a;
        if(b!=x.b) return b < x.b;
        if(t!=x.t) return t < x.t;
        return false;
    }
};

int n;
map<node,int> mp;

pair<int,pair<int,pair<int,int>>> wow(int a, int b, int c, int d) {
    pair<int,pair<int,pair<int,int>>> t1 = {a,{b,{c,d}}};
    pair<int,pair<int,pair<int,int>>> t2 = {b,{c,{d,a}}};
    pair<int,pair<int,pair<int,int>>> t3 = {c,{d,{a,b}}};
    pair<int,pair<int,pair<int,int>>> t4 = {d,{a,{b,c}}};
    pair<int,pair<int,pair<int,int>>> t = min(min(t1,t2), min(t3,t4));
    //printf("wow %d %d %d %d = %d %d %d %d\n",a,b,c,d,t.first,t.second.first,t.second.second.first,t.second.second.second);
    return t;
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int a,b,c,d,e,f; scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        if(mp.find(node(a,b,wow(c,f,d,e))) != mp.end()) mp[node(a,b,wow(c,f,d,e))]++;
        else if(mp.find(node(b,a,wow(f,c,e,d))) != mp.end()) mp[node(b,a,wow(f,c,e,d))]++;
        else if(mp.find(node(c,d,wow(f,a,e,b))) != mp.end()) mp[node(c,d,wow(f,a,e,b))]++;
        else if(mp.find(node(d,c,wow(f,b,e,a))) != mp.end()) mp[node(d,c,wow(f,b,e,a))]++;
        else if(mp.find(node(e,f,wow(c,a,d,b))) != mp.end()) mp[node(e,f,wow(c,a,d,b))]++;
        else if(mp.find(node(f,e,wow(c,b,d,a))) != mp.end()) mp[node(f,e,wow(c,b,d,a))]++;
        else mp[node(a,b,wow(c,f,d,e))]++;
        //for(auto tmp : mp) printf("\t%d\n",tmp.second);
    }
    int ans = 0;
    for(auto tmp : mp) ans = max(ans, tmp.second);
    printf("%d",ans);
}
