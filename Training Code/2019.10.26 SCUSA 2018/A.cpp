//
// Created by 54173 on 10/26/2019.
//
#include<bits/stdc++.h>
using namespace std;

#define ll long long

int f(ll sz, ll x, ll y) {
    //printf("f %lld : %lld %lld\n",sz,x,y);
    if(sz == 1) return 0;

    if(x<sz && y<sz/2) return f(sz/2,x,y);
    if(x<sz/2 && y<sz) return f(sz/2,x,y);

    if(sz/2<=x && x<sz+sz/2 && sz/2<=y && y<sz) return f(sz/2,x-sz/2,y-sz/2);
    if(sz/2<=x && x<sz && sz/2<=y && y<sz+sz/2) return f(sz/2,x-sz/2,y-sz/2);

    if(x<sz) return f(sz/2,2*sz-1-y,x) + 1;

    return f(sz/2,y,2*sz-1-x) - 1;
}

void solve(int tnum) {
    ll x, y; scanf("%lld%lld",&x,&y);
    printf("%d\n",((f((1LL<<61),x,y))%4 + 4)%4);
}

int main() {
    int tnum; scanf("%d",&tnum);
    for(int i=1;i<=tnum;i++) solve(i);
}