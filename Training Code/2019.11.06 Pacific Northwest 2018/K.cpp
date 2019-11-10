//
// Created by 54173 on 11/6/2019.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>
#include <string>
#define ld long double
using namespace std;
const ld eps = 1e-10;

string s;
int r1,r2;
int mask;

int S[1<<10];

ld dpMax[1<<10][7][7];
ld dpMin[1<<10][7][7];

int traceMax,traceMin;

int setbit(int x,int n)
{
    return x|(1<<n);
}

int getbit(int x,int n)
{
    return (x>>n) & 1;
}

string toString(int mask)
{
    string res = "";
    for (int i=1; i<=9; i++) {
        if (getbit(mask, i))
            res += to_string(i);
    }

    return res;
}

bool isSubset(int x,int y)
{
    return ((x&y)==x);
}

int sum(int mask)
{
    if (S[mask]!=-1)
        return S[mask];

    S[mask] = 0;

    for (int i=0; i<10; i++) {
        if (getbit(mask, i))
            S[mask] += i;
    }

    return S[mask];
}

ld calMax(int x,int y,int z,bool save = false)
{
    if (dpMax[x][y][z]>=-eps)
        return dpMax[x][y][z];

    dpMax[x][y][z] = 0;

    bool noSubset = true;
    for (int i=0; i<(1<<10); i++)
    {
        if (isSubset(i,x) and sum(i)==y+z)
        {
            noSubset = false;
            ld sum = 0;
            for (int n1=1; n1<=6; n1++) {
                for (int n2 = 1; n2 <= 6; n2++)
                    sum += calMax(x ^ i, n1, n2);
            }

            dpMax[x][y][z] = max(dpMax[x][y][z],sum);

            if (save and abs(dpMax[x][y][z]-sum)<eps)
                traceMax = i;
        }
    }

    if (noSubset)
    {
        for (int i=0; i<10; i++)
            if (getbit(x,i))
                dpMax[x][y][z]=dpMax[x][y][z]*10.0+(ld) i;
    }
    else
        dpMax[x][y][z]*=(1.0/36.0);

    return dpMax[x][y][z];
}

ld calMin(int x,int y,int z,bool save = false)
{
    if (dpMin[x][y][z]>=-eps)
        return dpMin[x][y][z];

    dpMin[x][y][z] = 1e10;

    bool noSubset = true;
    for (int i=0; i<(1<<10); i++)
    {
        if (isSubset(i,x) and sum(i)==y+z)
        {
            noSubset = false;
            ld sum = 0;
            for (int n1=1; n1<=6; n1++) {
                for (int n2 = 1; n2 <= 6; n2++)
                    sum += calMin(x ^ i, n1, n2);
            }

            dpMin[x][y][z] = min(dpMin[x][y][z],sum);

            if (save and abs(dpMin[x][y][z]-sum)<eps)
                traceMin = i;
        }
    }

    if (noSubset)
    {
        dpMin[x][y][z] = 0;
        for (int i=0; i<10; i++)
            if (getbit(x,i))
                dpMin[x][y][z]=dpMin[x][y][z]*10.0+(ld) i;
    }
    else
        dpMin[x][y][z]*=(1.0/36.0);

    return dpMin[x][y][z];
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s >> r1 >> r2;

    for (int i=0; i<(int) s.size(); i++)
        mask=setbit(mask,s[i]-'0');

    for (int i=0; i<(1<<10); i++) {
        for (int j = 1; j <= 6; j++) {
            for (int z = 1; z <= 6; z++) {
                dpMax[i][j][z] = -1;
                dpMin[i][j][z] = -1;
            }
        }
    }

    memset(S,-1,sizeof(S));

    ld resMax = calMax(mask,r1,r2,true);
    ld resMin = calMin(mask,r1,r2,true);

    cout << setprecision(0) << fixed;

    if (traceMin==0)
        cout << -1;
    else
    {
        for (int i=1; i<10; i++)
            if (getbit(traceMin,i))
                cout << i;
    }

    cout << ' ';
    cout << setprecision(5) << fixed;
    cout << resMin;

    cout << '\n';
    cout << setprecision(0) << fixed;

    if (traceMax==0)
        cout << -1;
    else
    {
        for (int i=1; i<10; i++)
            if (getbit(traceMax,i))
                cout << i;
    }

    cout << ' ';

    cout << setprecision(5) << fixed;

    cout << resMax;
    return 0;
}

