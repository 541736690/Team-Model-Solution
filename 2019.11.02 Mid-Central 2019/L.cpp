//
// Created by 54173 on 11/2/2019.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string s;
string current;
vector<int> V;

int convert(string s)
{
    int res = 0;
    for (int i=0; i<s.size(); i++)
    {
        res<<=1;
        if (s[i]=='u')
            res++;
    }
    return res;
}

bool punctuation(char c)
{
    if ('0'<=c and c<='9')
        return false;
    if ('a'<=c and c<='z')
        return false;
    if ('A'<=c and c<='Z')
        return false;

    if (c==' ')
        return false;

    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    while (cin >> s)
    {
        bool valid = true;
        for (int i=0; i<s.size(); i++)
            if (s[i]!='u' and s[i]!='m' and !punctuation(s[i])) {
                valid = false;
                break;
            }
        if (!valid)
            continue;

        for (int i=0; i<s.size(); i++){

            if (punctuation(s[i]))
                continue;

            current+=s[i];
            if (current.size()==7)
            {
                V.push_back(convert(current));
                current="";
            }
        }
    }


    for (int v: V)
        cout << (char) v;


    return 0;
}

