//
// Created by 54173 on 11/6/2019.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

#define ld long double
using namespace std;
const ld eps = 1e-10;

struct pt
{
    ld x,y;
} o,p1,p2;

struct line
{
    ld a,b,c;
};

pt subtract(pt a,pt b)
{
    return {a.x-b.x,a.y-b.y};
}

line make_line(pt a,pt b)
{
    pt u = subtract(a,b);
    pt n = {-u.y,u.x};
    return {n.x,n.y,a.x*n.x+a.y*n.y};
}

line make_perp(pt a,line d)
{
    pt u = {d.a,d.b};
    pt n = {-u.y,u.x};
    return {n.x,n.y,a.x*n.x+a.y*n.y};
}

pt intersection(line d1,line d2)
{
    ld D = d1.a*d2.b-d1.b*d2.a;
    ld Dx = d1.c*d2.b-d1.b*d2.c;
    ld Dy = d1.a*d2.c-d1.c*d2.a;

    if (abs(D)<=eps)
        return {nan(" "),nan(" ")};

    return {Dx/D,Dy/D};
}

ld dist(pt a,pt b)
{
    return hypot(a.x-b.x,a.y-b.y);
}

bool between(ld a,ld b,ld c)
{
    return (min(a,c)-eps<=b and b<=max(a,c)+eps);
}

bool between(pt a,pt b,pt c)
{
    return between(a.x,b.x,c.x) and between(a.y,b.y,c.y);
}

ld distPtToSeg(pt p,pt a,pt b)
{
    line d1 = make_line(a,b);
    line d2 = make_perp(p,d1);

    pt I = intersection(d1,d2);

    if (!isnan(I.x) and between(a,I,b))
        return dist(p,I);

    return min(dist(p,a),dist(p,b));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin >> o.x >> o.y >> p1.x >> p1.y >> p2.x >> p2.y;
    ld res = 1e10;

    res = min(res,distPtToSeg(o,{p1.x,p1.y},{p1.x,p2.y}));
    res = min(res,distPtToSeg(o,{p1.x,p2.y},{p2.x,p2.y}));
    res = min(res,distPtToSeg(o,{p2.x,p2.y},{p2.x,p1.y}));
    res = min(res,distPtToSeg(o,{p2.x,p1.y},{p1.x,p1.y}));

    cout << setprecision(3) << fixed << res;
}
