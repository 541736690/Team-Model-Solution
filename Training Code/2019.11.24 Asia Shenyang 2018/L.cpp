//
// Created by 54173 on 11/24/2019.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <vector>
#include <map>
#include <iterator>
#include <set>
#define ld long double
#define ii pair<ld,ld>
#define X first
#define Y second
using namespace std;
const ld eps = 1e-20;
const ld pi = 4.0*atan(1.0);
const int maxn = 100;
int n;
ld R;
ld x[maxn+1],y[maxn+1],r[maxn+1];
map<ld,int> del;
set<ld> okpts;

void deleteInterval(ld x,ld y)
{
    while (x>2*pi)
    {
        x-=2*pi;
        y-=2*pi;
    }

    do
    {
        del[x]++;
        del[y]--;
        x+=2*pi;
        y+=2*pi;
    }
    while (x<=8*pi);
}

void addCriticalPoint(ld x)
{
    ld cp = x;
    while (cp>pi)
        cp-=pi;
    do
    {
        del[cp]+=0;
        cp+=pi;
    }
    while (cp<=8*pi);
}

bool ok(map<ld,int> ::iterator it)
{
    if (it!=del.begin()) {
        if ((*prev(it,1)).second==0)
            return true;
    }
    else
        return true;

    if ((*it).second==0)
        return true;

    return false;
}

ld dist(ii a,ii b)
{
    return hypot(a.X-b.X,a.Y-b.Y);
}
ld dist(ld a,ld b)
{
    return R*dist(ii(cos(a),sin(a)),ii(cos(b),sin(b)));
}
ld sqr(ld x)
{
    return x*x;
}

ld distSquare(ii a,ii b)
{
    return sqr(a.X-b.X)+sqr(a.Y-b.Y);
}

void solve()
{
    del.clear();
    cin >> n >> R;

    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i] >> r[i];

        ld d = dist(ii(x[i],y[i]),ii(0,0));
        ld d2 = distSquare(ii(x[i],y[i]),ii(0,0));
        ld baseAngle = atan2(y[i],x[i]);
        if (d+r[i]<R) {
            // do nothing
        }
        else if (d<=R+r[i])
        {
            ld cosBase = (-sqr(r[i])+sqr(R)+d2)/(2.0*R*d);
            ld deltaAngle = abs(acos(cosBase));
            // calculate angle
            deleteInterval(baseAngle-deltaAngle, baseAngle+deltaAngle);
            addCriticalPoint(baseAngle);
            addCriticalPoint(baseAngle-deltaAngle);
            addCriticalPoint(baseAngle+deltaAngle);
        }
    }


    for (auto it=next(del.begin(),1); it!=del.end(); it++)
        (*it).second+=(*prev(it,1)).second;

    ld res = 0;

    okpts.clear();
    for (auto it=del.begin(); it!=del.end(); it++)
        if (ok(it))
            okpts.insert((*it).first);


        auto pt = okpts.lower_bound(2*pi);
        for (auto it=pt; (*it)<=4*pi; it++)
        {
            auto jt=okpts.lower_bound((*it)+pi);

            res = max(res,dist(*it,*jt));

            if (jt!=okpts.begin())
            {
                jt--;
                res = max(res,dist(*it,*jt));
            }
        }
    /*for (auto it=del.lower_bound(2*pi); (*it).first<=4*pi; it++)
    {
        for (auto jt=del.lower_bound(2*pi); (*jt).first<=4*pi; jt++)
            if (ok(it) and ok(jt)){
                //cout << (*it).first << ' ' << (*jt).first << ' ' << dist((*it).first,(*jt).first) << '\n';
                res = max(res,dist((*it).first,(*jt).first));
            }
    }*/

    cout << setprecision(20) << fixed << res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin >> t;
    for (int i=1; i<=t; i++) {
        cout << "Case #" << i << ": ";
        solve();
        cout << '\n';
    }

}

