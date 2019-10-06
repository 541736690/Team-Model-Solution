//
// Created by 54173 on 10/5/2019.
//
#include<bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
const int oo = (int) 1e9 + 99;

int n;
int v1[maxn+1],d1[maxn+1];
int v2[maxn+1],d2[maxn+1];
int p[2][7][maxn+1];
int dayFactor[7] = {0,1,2,3,2,1,0};
int l[2][7][maxn*5];
int r[2][7][maxn*5];
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

void initArray() {
    for (int i=0; i<7; i++) {
        int currentDay = 0;
        for (int j = i; j < n; j++) {
            p[0][i][j] = v1[j] + d1[j] * dayFactor[currentDay];
            p[1][i][j] = v2[j] + d2[j] * dayFactor[currentDay];
            currentDay = (currentDay + 1) % 7;
        }
        /*for(int j=i;j<n;j++) printf("%d ",p[0][i][j]);
        printf("\n");
        for(int j=i;j<n;j++) printf("%d ",p[0][i][j]);
        printf("-----\n");*/
    }
}

void merge(node& res,node& left,node& right) {
    res.maxi = max(left.maxi,right.maxi);
    res.mini = min(left.mini,right.mini);
    res.maxDiff = max(left.maxDiff,right.maxDiff);
    res.maxDiff = max(res.maxDiff,right.maxi-left.mini);
}

void initIT(int id1,int id2,int i,int x,int y) {
    l[id1][id2][i] = x;
    r[id1][id2][i] = y;
    if (x==y)
    {
        it[id1][id2][i].maxi = p[id1][id2][x];
        it[id1][id2][i].mini = p[id1][id2][x];
        it[id1][id2][i].maxDiff = 0;
        //printf("(%d, %d) [%d, %d] = {%d, %d, %d}\n",id1,id2,x,y,it[id1][id2][i].maxi,it[id1][id2][i].mini,it[id1][id2][i].maxDiff);
    }
    else
    {
        int m = (x+y)/2;
        initIT(id1,id2,i<<1,x,m);
        initIT(id1,id2,(i<<1)+1,m+1,y);
        merge(it[id1][id2][i],it[id1][id2][i<<1],it[id1][id2][(i<<1)+1]);
        //printf("(%d, %d) [%d, %d] = {%d, %d, %d}\n",id1,id2,x,y,it[id1][id2][i].maxi,it[id1][id2][i].mini,it[id1][id2][i].maxDiff);
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
    for (int i=0; i<n; i++)
        cin >> v1[i] >> d1[i];
    for(int i=0;i<n;i++) {
        v2[i] = v1[n-1-i];
        d2[i] = d1[n-1-i];
    }

    initArray();

    for (int i=0; i<2; i++) {
        for (int j = 0; j < 7; j++)
            initIT(i, j, 1, 0, n-1);
    }


    int q;
    cin >> q;
    for (int i=1; i<=q; i++)
    {
        int s,t;
        cin >> s >> t;
        s--; t--;
        if (s<=t)
        {
            //printf("ask %d %d %d %d\n",0,s%7,s,t);
            cout << max(0,getIT(0,s%7,1,s,t).maxDiff) << '\n';
        }
        else
        {
            s = n-1-s;
            t = n-1-t;
            //printf("ask %d %d %d %d\n",1,s%7,s,t);
            cout << max(0,getIT(1,s%7,1,s,t).maxDiff) << '\n';
        }
    }

    return 0;
}

