//
// Created by 54173 on 10/19/2019.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#define mp make_pair
#define ii pair<int,int>
#define iii pair<int,ii>

using namespace std;
const int maxP = 1000;
const int maxL = 1000;
int p;
int a[maxP+1];
int pattAB[10][10],pattAC[10][10],pattBC[10][10];
bool validAB[10][10],validAC[10][10],validBC[10][10];
int cntAB[10][10],cntAC[10][10],cntBC[10][10];
int firstOccAB[10][10],firstOccBC[10][10],firstOccAC[10][10];
int currentA,currentN,currentB,currentM,currentC;

iii mp(int x,int y,int z)
{
    return {x,{y,z}};
}

void update(int patt[][10], bool valid[][10], int cnt[][10],int firstOcc[][10],int a,int b,int c,int occ)
{
    if (patt[a][b]==-1)
    {
        patt[a][b] = c;
        valid[a][b] = true;
        cnt[a][b] = 1;
        firstOcc[a][b] = occ;
    }
    else
    {
        if (patt[a][b]==c)
            cnt[a][b]++;
        else
        {
            if (patt[a][b]!=c)
                valid[a][b] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> p;
    for (int i=1; i<=p; i++)
        cin >> a[i];
    int limit = p/40+1;
    if (p%40!=0)
        limit++;

    currentA = -1;

    for (int i=2; i<=maxL; i++)
    {
        for (int n=1; n<i; n++)
        {
            int m = i-n;
            memset(cntAB,0,sizeof(cntAB));
            memset(pattAB,-1,sizeof(pattAB));
            memset(validAB,0,sizeof(validAB));
            memset(cntBC,0,sizeof(cntBC));
            memset(pattBC,-1,sizeof(pattBC));
            memset(validBC,0,sizeof(validBC));
            memset(cntAC,0,sizeof(cntAC));
            memset(pattAC,-1,sizeof(pattAC));
            memset(validAC,0,sizeof(validAC));
            memset(firstOccAB,0,sizeof(firstOccAB));
            memset(firstOccBC,0,sizeof(firstOccBC));
            memset(firstOccAC,0,sizeof(firstOccAC));

            for (int i=1; i+n+m<=p; i++)
            {
                update(pattAB,validAB,cntAB,firstOccAB,a[i],a[i+n],a[i+n+m],i);
                update(pattAC,validAC,cntAC,firstOccAC,a[i],a[i+n+m],a[i+n],i);
                update(pattBC,validBC,cntBC,firstOccBC,a[i+n],a[i+n+m],a[i],i);
            }

            for (int j=0; j<=9; j++)
                for (int k=0; k<=9; k++) {
                    if (validAB[j][k] and cntAB[j][k] >= limit) {
                        {
                            int l = pattAB[j][k];
                            if (validBC[k][l] and cntBC[k][l] >= limit and validAC[j][l] and cntAC[j][l] >= limit) {
                                if (currentA == -1) {
                                    currentA = firstOccAB[j][k];
                                    currentN = n;
                                    currentB = k;
                                    currentM = m;
                                    currentC = pattAB[j][k];
                                } else if (mp(currentA, currentN, currentM) > mp(firstOccAB[j][k], n, m)) {
                                    currentA = firstOccAB[j][k];
                                    currentN = n;
                                    currentB = k;
                                    currentM = m;
                                    currentC = pattAB[j][k];
                                }
                            }
                        }
                    }
                }
        }
    }

    if (currentA==-1)
        cout << "random sequence";
    else
        cout << "triple correlation " << a[currentA] << '(' << currentN << ')' << currentB << '('
        << currentM << ')' << currentC << " found";

    return 0;
}
