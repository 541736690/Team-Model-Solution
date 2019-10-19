//
// Created by 54173 on 10/19/2019.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#define ld long double
#define mp make_pair
#define X first
#define Y second
using namespace std;
const int maxn = 10000;
const int maxx = 20000;
const ld eps = 1e-6;
const ld pi = 4.0*atan(1.0);
int r,dx,dy,x,y;
ld p;

vector<int> Xline;
vector<int> Yline;
map<int,vector<int> > Xsect,Ysect;

struct pt
{
    ld x,y;
};

ld arcArea(ld angle,ld r)
{
    return 0.5*(angle*r*r - r*r*sin(angle));
}

ld between(ld a,ld b,ld c)
{
    return (a-eps<b and b<c+eps)
}

ld inRect(ld x1,ld y1,ld x2,ld y2,ld x3,ld y3)
{
    return (between(x1,x3,x2) and between(y1,y3,y2));
}

ld angle(pt A,pt B)
{
    ld res = atan2(A.y,A.x) - atan2(B.y,B.x);
    while (res<0)
        res+=2*pi;
    return min(res,2*pi-res);
}

pair<ld,ld> circleInter(ld x)
{
    if (r*r-x*x<0)
        return {nan(" "),nan(" ")};
    return {-sqrt(r*r-x*x),sqrt(r*r-x*x)};
}

ld  sqr(ld x)
{
    return x*x;
}

bool inCircle(ld x,ld y,ld r)
{
    return sqr(x)+sqr(y)<=sqr(r);
}

pt subtract(pt a,pt b)
{
    return {a.x-b.x,a.y-b.y};
}

ld calculateArea(vector<pt>& poly)
{
    if (poly.size()<=2)
        return 0;

    ld res = 0;
    for (int i=0; i<poly.size(); i++)
        res+=(poly[i].x*poly[(i+1)%poly.size()].y - poly[i].y * poly[(i+1)%poly.size()].x);

    return abs(res)*0.5;

}

ld midPointSmallArc(pt A,pt B)
{
    ld angle1 = atan2(A.y,A.x);
    ld angle2 = atan2(B.y,B.x);


}

ld areaInter(ld x1,ld y1,ld x2,ld y2)
{
    if (inCircle(x1,y1,r) and inCircle(x1,y2,r) and inCircle(x2,y1,r) and inCircle(x2,y2,r))
        return abs(x1-x2)*abs(y1-y2);

    pair<ld,ld> Iy1 = circleInter(x1);
    pair<ld,ld> Iy2 = circleInter(x2);
    pair<ld,ld> Ix1 = circleInter(y1);
    pair<ld,ld> Ix2 = circleInter(y2);


    vector<pt> poly;
    poly.clear();

    if (inCircle(x1,y1,r))
        poly.push_back({x1,y1});

    if (!isnan(Iy1.X))
    {
        if (inRect(x1,y1,x2,y2,x1,Iy1.X))
            poly.push_back({x1,Iy1.X});
        if (inRect(x1,y1,x2,y2,x1,Iy1.Y))
            poly.push_back({x1,Iy1.Y});
    }

    if (inCircle(x1,y2,r))
        poly.push_back({x1,y2});

    if (!isnan(Ix2.X))
    {
        if (inRect(x1,y1,x2,y2,Ix2.X,y2))
            poly.push_back({Ix2.X,y2});
        if (inRect(x1,y1,x2,y2,Ix2.Y,y2))
            poly.push_back({Ix2.Y,y2});
    }

    if (inCircle(x2,y2,r))
        poly.push_back({x2,y2});

    if (!isnan(Iy2.X))
    {
        if (inRect(x1,y1,x2,y2,x2,Iy2.X))
            poly.push_back({x2,Iy2.X});
        if (inRect(x1,y1,x2,y2,x2,Iy2.Y))
            poly.push_back({x2,Iy2.Y});
    }

    if (inCircle(x2,y1,r))
        poly.push_back({x2,y1});

    if (!isnan(Ix1.X))
    {
        if (inRect(x1,y1,x2,y2,Ix1.X,y1))
            poly.push_back({Ix1.X,y1});
        if (inRect(x1,y1,x2,y2,Ix1.Y,y1))
            poly.push_back({Ix1.Y,y1});
    }

    ld res = calculateArea(poly);

    for (int i=0; i<poly.size(); i++)
    {

    }


    return res;
}


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> r >> dx >> dy >> x >> y;
    for (int i=x; i<=maxx; i+=dx)
       Xline.push_back(i);

    for (int i=x-dx; i>=-maxx; i-=dx)
        Xline.push_back(i);


    for (int i=y; i<=maxx; i+=dy)
        Yline.push_back(i);

    for (int i=y-dy; i>=-maxx; i-=dy)
        Yline.push_back(i);

    sort(Xline.begin(),Xline.end());
    sort(Yline.begin(),Yline.end());

    for (int i=0; i+1<Xline.size(); i++)
        for (int j=0; j+1<Yline.size(); j++)
        {

        }


    return 0;
}

