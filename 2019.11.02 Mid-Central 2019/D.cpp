//
// Created by 54173 on 11/2/2019.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <iterator>
#include <iomanip>
#define ld long double
using namespace std;
const int maxn = 10000;
const ld pi = 4.0*atan(1.0);
//const ld eps = 1e-10;
int n;
ld x[maxn+1],y[maxn+1],r[maxn+1];
ld b,d;
map<ld,int> M;

ld sqr(ld x)
{
    return x*x;
}

ld distance(ld x1,ld y1,ld x2,ld y2)
{
    return hypot(x1-x2,y1-y2);
}
ld distanceSquare(ld x1,ld y1,ld x2,ld y2)
{
    return sqr(x1-x2)+sqr(y1-y2);
}

ld standardize(ld x)
{
    if (x<0)
        x+=2*pi;
    else
        if (x>=2*pi)
            x-=2*pi;
    return x;
}

void addRange(ld x,ld y)
{
    x = standardize(x);
    y = standardize(y);

    if (x<y)
    {
        M[x]++;
        M[y]--;
    }
    else
    {
        M[x]++;
        M[0]++;
        M[2*pi]--;
        M[y]--;
    }
}

ld maxDis(ld h,ld a)
{
    return sqrt(h*h-a*a);
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> x[i] >> y[i] >> r[i];
    cin >> b >> d;

    if (abs(d)<=1e-10)
    {
        cout << "1.000000000000";
        return 0;
    }

    for (int i=1; i<=n; i++)
        r[i]+=b;

    for (int i=1; i<=n; i++)
    {
        ld dist = distance(0,0,x[i],y[i]);
        ld distSqr = distanceSquare(0,0,x[i],y[i]);

        if (maxDis(dist,r[i])<d)
        {
            ld diff = asin(r[i]/dist);
            ld angle = atan2(y[i],x[i]);
            addRange(angle-diff,angle+diff);
        }
        else
            if (dist-r[i]<d)
            {
                ld diff = acos((sqr(d)+distSqr-sqr(r[i]))/(2.0*d*dist));
                ld angle = atan2(y[i],x[i]);
                addRange(angle-diff,angle+diff);
            }
    }

    ld acc = 0;
    for (auto it=next(M.begin(),1); it!=M.end(); it++)
        (*it).second += (*prev(it,1)).second;

    for (auto it=M.begin(); next(it,1)!=M.end(); it++)
    {
        if ((*it).second>0)
            acc+=(*next(it,1)).first-(*it).first;
    }

    cout << setprecision(10) << fixed << 1.0-acc/(2*pi);



    return 0;
}

