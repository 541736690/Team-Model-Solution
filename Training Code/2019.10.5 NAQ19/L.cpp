//
// Created by 54173 on 10/5/2019.
//
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
const int maxn = 100000;
const int oo = (int) 1e9+10;
int n;
int v[maxn+1],d[maxn+1];
int p[2][7][maxn+1];
int dayFactor[7] = {0,1,2,3,2,1,0};
int l[2][7][maxn*5],r[2][7][maxn*5];
struct node
{
    int maxi;
    int mini;
    int maxDiff;

    string toString()
    {
        return to_string(maxi)+" "+to_string(mini)+" "+to_string(maxDiff);
    }
} it[2][7][maxn*5];

void initArray()
{
    for (int i=0; i<7; i++) {
        int currentDay = i;
        int startingDay = i;
        for (int j = 1; j <= n; j++) {
            p[0][startingDay][j] = v[j] + d[j] * dayFactor[currentDay];
            currentDay = (currentDay + 1) % 7;
        }
    }

    for (int i=0; i<7; i++)
    {
        int currentDay = i;
        int startingDay = i;
        for (int j=n; j>=1; j--)
        {
            p[1][startingDay][n-j+1] = v[j] + d[j]*dayFactor[currentDay];
            currentDay = (currentDay+1)%7;
        }
    }
}

void merge(node& res,node& left,node& right)
{
    res.maxi = max(left.maxi,right.maxi);
    res.mini = min(left.mini,right.mini);
    res.maxDiff = max(left.maxDiff,right.maxDiff);
    res.maxDiff = max(res.maxDiff,right.maxi-left.mini);
}

void initIT(int id1,int id2,int i,int x,int y)
{
    l[id1][id2][i] = x;
    r[id1][id2][i] = y;
    if (x==y)
    {
        it[id1][id2][i].maxi = p[id1][id2][x];
        it[id1][id2][i].mini = p[id1][id2][x];
        it[id1][id2][i].maxDiff = 0;
    }
    else
    {
        int m = (x+y)/2;
        initIT(id1,id2,i<<1,x,m);
        initIT(id1,id2,(i<<1)+1,m+1,y);
        merge(it[id1][id2][i],it[id1][id2][i<<1],it[id1][id2][(i<<1)+1]);
    }
}

void printIT(int id1,int id2,int i)
{
    cout << l[id1][id2][i] << ' ' << r[id1][id2][i] << ' ' << it[id1][id2][i].toString() << '\n';
    if (l[id1][id2][i]!=r[id1][id2][i])
    {
        printIT(id1,id2,i<<1);
        printIT(id1,id2,(i<<1)+1);
    }

}

node getIT(int id1,int id2,int i,int x,int y)
{
    if (y<l[id1][id2][i] or x>r[id1][id2][i])
        return {-oo,oo,0};

    if (x<=l[id1][id2][i] and r[id1][id2][i]<=y)
        return it[id1][id2][i];

    node resLeft = getIT(id1,id2,i<<1,x,y);
    node resRight = getIT(id1,id2,(i<<1)+1,x,y);

    node res;
    merge(res,resLeft,resRight);

    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> v[i] >> d[i];

    initArray();
    for (int i=0; i<2; i++)
        for (int j=0; j<7; j++)
        {
            cout << i << ' ' << j << '\n';
            for (int z=1; z<=n; z++)
                cout << p[i][j][z] << ' ';
            cout << '\n';
        }

    for (int i=0; i<2; i++) {
        for (int j = 0; j < 7; j++)
            initIT(i, j, 1, 1, n);
    }


    int q;
    cin >> q;
    for (int i=1; i<=q; i++)
    {
        int s,t;
        cin >> s >> t;
        if (s<=t)
        {
            int startDayFrom1 = (14-(s-1)+7*maxn)%7;
            int version = 0;

            //cout << startDayFrom1 << ' ' << version << ' ' << s << ' ' << t << '\n';
            cout << getIT(version,startDayFrom1,1,s,t).maxDiff << '\n';
        }
        else
        {
            int version = 1;
            int startDayFromN = (14-(n-s)+7*maxn)%7;
            //cout << startDayFromN << ' ' << version << ' ' << s << ' ' << t << '\n';
            cout << getIT(version,startDayFromN,1,n-s+1,n-t+1).maxDiff << '\n';
        }
    }

    //printIT(0,0,1);

    return 0;
}

