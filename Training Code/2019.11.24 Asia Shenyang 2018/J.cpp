//
// Created by 54173 on 11/24/2019.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#define int long long

using namespace std;
const int maxn = 1000;
int n;
string s;
string type1,type2;
string variable;
string size;
map<string,int> M;
int res;

void init()
{
    M["bool"] = 1;
    M["char"] = 1;
    M["int"] = 4;
    M["long long"] = 8;
    M["__int128"] = 16;
    M["float"] = 4;
    M["double"] = 8;
    M["long double"] = 16;
}

void solve()
{
    res = 0;
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> type1;
        if (type1=="long")
        {
            cin >> type2;
            type1+=" "+type2;
        }

        cin >> variable;

        size = "";
        bool flag = false;
        for (int i=0; i<variable.size(); i++)
        {
            if (variable[i]=='[')
            {
                flag=true;
            }
            else
            if (variable[i]==']')
                flag = false;
            else
                if (flag)
                size+=variable[i];
        }

        int nsize = 0;
        if (size=="")
            nsize = 1;
        else
            nsize = stoll(size);

        //cerr << type1 << ' ' << nsize << '\n';
        res+=nsize*M[type1];
    }

    cout << res/1024+(res%1024!=0) << '\n';
}

main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    init();
    int t;
    cin >> t;
    for (int i=1; i<=t; i++)
    {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}

