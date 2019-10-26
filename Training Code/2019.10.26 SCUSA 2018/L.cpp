//
// Created by 54173 on 10/26/2019.
//
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int maxn = 50000;
int n;
int g[maxn+1];
char type[maxn+1];

int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> g[i] >> type[i];




    return 0;
}

