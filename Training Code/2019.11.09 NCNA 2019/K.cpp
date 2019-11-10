//
// Created by EHPC010 on 11/9/2019.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

#define ld long double
using namespace std;
const int maxn = 100000;
const ld pi = 4.0*atan(1.0);
const ld eps = 1e-10;

int n;
ld T[maxn+1],a[maxn+1],s[maxn+1];
struct critic
{
    ld pos;
    int id;
    int type;
};
vector<critic> V;

int ptLeft, ptRight,ptMid;
ld angleLeft,angleRight;

set<int> A,B; // A = above; B = below


ld sumTA,sumTB,sumAA,sumAB;
ld sumSA,sumSB;


ld delta[maxn+1];

bool cmp(critic x,critic y)
{
    return x.pos < y.pos;
}

bool equal(ld x,ld y)
{
    return (abs(x-y)<=eps);
}

ld modupi(ld x)
{
    if (x>=2*pi)
        x-=2*pi;
    if (x<0)
        x+=2*pi;
    return x;
}

void insertSetA(int id)
{
    if (!A.count(id))
    {
        A.insert(id);
        sumTA+=T[id];
        sumSA+=s[id];
        sumAA+=a[id];
    }
}

void insertSetB(int id)
{
    if (!B.count(id))
    {
        B.insert(id);
        sumTB+=T[id];
        sumSB+=s[id];
        sumAB+=a[id];
    }
}

void eraseSetA(int id)
{
    if (A.count(id))
    {
        A.erase(id);
        sumTA-=T[id];
        sumSA-=s[id];
    }
}

void eraseSetB(int id)
{
    if (B.count(id))
    {
        B.erase(id);
        sumTB-=T[id];
        sumSB-=s[id];
    }
}

void handleCriticalPoint(critic p)
{
    if (p.type==0)
    {
        eraseSetA(p.id);
        insertSetB(p.id);
    }

    if (p.type==1)
    {
        eraseSetB(p.id);
        insertSetA(p.id);
    }

    if (p.type==2)
        eraseSetB(p.id);

    if (p.type==3)
        eraseSetA(p.id);
}

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> T[i] >> s[i] >> a[i];


    for (int i=1; i<=n; i++)
    {
        V.push_back({a[i],i, 0}); // 0: change from above to below
        V.push_back({a[i]+2*pi, i,0});

        delta[i] = min(pi,T[i]/s[i]);
        if (a[i]-delta[i]<0)
            V.push_back({a[i] - delta[i], i, 2}); // 2 : end point left
        V.push_back({a[i] + delta[i], i, 3}); // 3 : end point right

        V.push_back({a[i]+2*pi-delta[i],i,2});
        if (a[i]+2*pi+delta[i]<=4*pi)
            V.push_back({a[i]+2*pi+delta[i],i,3});
    }

    sort(V.begin(),V.end(),cmp);


    ptLeft = 0;
    ptMid = 0;
    while (V[ptMid]<2*pi)
    {
        ptLeft = 0;
    }
    ptRight = -1;
    for (ptLeft=0; V[ptLeft].pos<2*pi; ptLeft++)
    {
        while (ptRight+1<(int) V.size() and V[ptRight+1].pos<V[ptLeft]-1)
        {

        }
    }

    return 0;
}