//
// Created by 54173 on 10/5/2019.
//
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
#define ld long double

ld sqr(ld x)
{
    return x*x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        ld w,g,h,r;
        cin >> w >> g >> h >> r;
        cout << setprecision(20) << fixed << sqrt(sqr(g-h)+sqr(w)) << ' ' << sqrt(sqr(g+h-2*r)+sqr(w)) << '\n';
    }

    return 0;
}