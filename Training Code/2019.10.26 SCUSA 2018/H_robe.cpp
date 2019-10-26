//
// Created by 54173 on 10/26/2019.
//

#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#define ld long double

using namespace std;
const int maxn = 100000;
const ld pi = 4.0*atan(1.0);
const ld eps = 1e-10;
int n,k;
struct pt
{
    ld x,y;
} p[maxn+1];

vector<pair<ld,ld> > ranges;

ld sqr(ld x)
{
    return x*x;
}
ld distanceSquare(pt p)
{
    return sqr(p.x)+sqr(p.y);
}

ld distance(pt p)
{
    return hypot(p.y,p.x);
}

ld standardize(ld angle)
{
    while (angle<0)
        angle+=2*pi;
    while (angle>2*pi)
        angle-=2*pi;
    return angle;
}

bool between(ld x,ld y,ld z)
{
    return min(x,z)-eps<=y and y<=max(x,z)+eps;
}

pair<ld,ld> make_range(ld l,ld r)
{
    while (l<0)
    {
        l+=2*pi;
        r+=2*pi;
    }

    while (r>4*pi)
    {
        l-=2*pi;
        r-=2*pi;
    }

    return make_pair(l,r);
}

bool validForRanges(ld l,ld r)
{
    return between(0,l,4*pi) and between(0,r,4*pi);
}

void add_range(ld l, ld r,bool debug = false,int index = 0)
{
    pair<ld,ld> firstRange = make_range(l,r);
    ranges.push_back(firstRange);

    /*if (debug)
    {
        cout << index << ' ';
        cout << firstRange.first << ' ' << firstRange.second << ' ';
        cout << firstRange.first+2*pi << ' ' << firstRange.second+2*pi << '\n';
    }*/


    firstRange.first+=2*pi;
    firstRange.second+=2*pi;
    if (validForRanges(firstRange.first,firstRange.second))
        ranges.push_back(firstRange);
}

bool inCircle(pt p,ld r)
{
    return distanceSquare(p)<=sqr(r);
}

map<ld,int> M;

bool check(ld r)
{
    ranges.clear();
    for (int i=1; i<=n; i++)
        if (inCircle(p[i],2*r))
        {
            ld d = distance(p[i]);
            ld delta = acos(d/r*0.5);
            ld angle = atan2(p[i].y,p[i].x);

            add_range(angle-delta,angle+delta);
        }

    /*for (pair<ld,ld> range: ranges)
        cout << range.first << ' ' << range.second << '\n';
    cout << '\n';*/

    M.clear();

    for (pair<ld,ld> range: ranges)
    {
        M[range.first]++;
        M[range.second+eps]--;
    }

    int cnt = 0;
    for (auto it=M.begin(); it!=M.end(); it++)
    {
        cnt+=(*it).second;
        if (cnt>=k)
            return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++)
        cin >> p[i].x >> p[i].y;

    ld dau = 0, cuoi = 1e8;

    do
    {
        ld giua=(dau+cuoi)*0.5;
        if (check(giua))
            cuoi = giua-eps;
        else
            dau = giua+eps;
    }
    while (dau + eps < cuoi);

    if (dau>=1e8)
        cout << -1;
    else
        cout << setprecision(10) << fixed << dau << '\n';

    return 0;
}

