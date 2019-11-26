//
// Created by 54173 on 11/17/2019.
//
#include <iostream>
#include <cstdio>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

string s;
int cnt['z'+1];
char dominance;
set<char> S;
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    bool case1 = true;
    for (int i=0; i<s.size(); i++)
    {
        cnt[s[i]]++;
        if (cnt[s[i]]>s.size()/2)
        {
            case1 = false;
            dominance = s[i];
        }
        S.insert(s[i]);
    }

    if (case1)
    {
        sort(s.begin(),s.end());
        cout << "YES\n";
        cout << s;
        return 0;
    }

    if (S.size()>=3)
    {
        cout << "YES\n";
        S.erase(dominance);

        for (int i=1; i<=s.size()/2; i++)
            cout << dominance;

        char nextChar = *S.begin();
        S.erase(S.begin());
        for (int i=1; i<=cnt[nextChar]; i++)
            cout << nextChar;

        for (int i=1; i<=cnt[dominance]-s.size()/2; i++)
            cout << dominance;

        for (char nextChar : S)
        {
            for (int i=1; i<=cnt[nextChar]; i++)
                cout << nextChar;
        }

        return 0;
    }

    if (S.size()==1)
    {
        cout << "NO\n";
        return 0;
    }

    if (S.size()==2)
    {
        S.erase(dominance);
        char other = *S.begin();

        if (cnt[other]>2)
        {
            cout << "YES\n";
            for (int i=1; i<=s.size()/2; i++)
                cout << dominance;
            cout << other;
            for (int i=1; i<=cnt[dominance]-s.size()/2; i++)
                cout << dominance;
            for (int i=1; i<=cnt[other]-1; i++)
                cout << other;

            return 0;
        }

        if (cnt[other]==1)
        {
            cout << "NO\n";
            return 0;
        }

        if (cnt[other]==2)
        {
            cout << "NO\n";
            return 0;
        }
    }

    return 0;
}

