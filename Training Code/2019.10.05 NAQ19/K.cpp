//
// Created by 54173 on 10/5/2019.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#define ll long long
using namespace std;
const int maxn = 1000000;
string s;
vector<int> V['z'+1];
int vt['z'+1];
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> s;
    for (int i=0; i<s.size(); i++)
        V[s[i]].push_back(i);

    ll res = 0;
    for (int i=0; i<s.size(); i++)
    {
        int nex = 0;
        if (vt[s[i]]==V[s[i]].size()-1)
            nex = maxn;
        else
            nex = V[s[i]][vt[s[i]]+1];

        for (char j='a'; j<='z'; j++) {
            if (V[j].size()==0)
                continue;
            if (V[s[i]][vt[s[i]]] < V[j][vt[j]] and V[j][vt[j]] < nex)
                res++;
        }

        vt[s[i]]++;
    }

    cout << res << '\n';
    return 0;
}