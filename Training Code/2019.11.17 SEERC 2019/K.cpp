//
// Created by 54173 on 11/17/2019.
//
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;
const int maxn = 500;
int n,m,p;
char a[maxn+1][maxn+1][maxn+1];

bool sunlightReach[maxn+1][maxn+1][maxn+1][6];

short gravityFall[maxn+1][maxn+1][maxn+1][6];

struct direction
{
    int x,y,z;
} sunlight[6];

struct state
{
    int x,y,z,t;
};

queue<state> Q;



void init()
{
    sunlight[0] = {1,0,0};
    sunlight[1] = {-1,0,0};
    sunlight[2] = {0,1,0};
    sunlight[3] = {0,-1,0};
    sunlight[4] = {0,0,1};
    sunlight[5] = {0,0,-1};
}

int minRangeForX(int id)
{
    if (sunlight[id].x==-1)
        return p;
    else
        return 1;
}

int maxRangeForX(int id)
{
    if (sunlight[id].x==1)
        return 1;
    else
        return p;
}

int minRangeForY(int id)
{
    if (sunlight[id].y==-1)
        return n;
    else
        return 1;
}

int maxRangeForY(int id)
{
    if (sunlight[id].y==1)
        return 1;
    else
        return n;
}

int minRangeForZ(int id)
{
    if (sunlight[id].z==-1)
        return m;
    else
        return 1;
}

int maxRangeForZ(int id)
{
    if (sunlight[id].z==1)
        return 1;
    else
        return m;
}

bool isEmptyBlock(int x,int y,int z)
{
    return (a[x][y][z]!='*');
}

bool isEmptyBlock(state s)
{
    return isEmptyBlock(s.x,s.y,s.z);
}

void emptyQueue()
{
    while (!Q.empty())
        Q.pop();
}
void initQueueForSunlight(int id)
{
    for (int x=minRangeForX(id); x<=maxRangeForX(id); x++)
        for (int y=minRangeForY(id); y<=maxRangeForY(id); y++)
            for (int z=minRangeForZ(id); z<=maxRangeForZ(id); z++)
                if (isEmptyBlock(x,y,z)) {
                    Q.push({x, y, z, id});
                    sunlightReach[x][y][z][id] = true;
                }
}

state nextState(state current,direction direction)
{
    return {current.x+direction.x,current.y+direction.y,current.z+direction.z,current.t};
}

bool between(int x,int y,int z)
{
    return min(x,z)<=y and y<=max(x,z);
}

bool validState(state current)
{
    return between(1,current.x,p) and between(1,current.y,n) and between(1,current.z,m);
}

void bfsSunlight(int id)
{
    emptyQueue();
    initQueueForSunlight(id);

    do
    {
        state p = Q.front();
        state next = nextState(p,sunlight[id]);

        if (validState(next) and isEmptyBlock(next))
        {
            if (!sunlightReach[next.x][next.y][next.z][next.t])
            {
                sunlightReach[next.x][next.y][next.z][next.t] = true;
                Q.push(next);
            }
        }
    }
    while (!Q.empty());
}


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> n >> m >> p;

    for (int i=1; i<=p; i++) for (int j=1; j<=n; j++) for (int k=1; k<=m; k++)
        cin >> a[i][j][k];

    memset(sunlightReach,false,sizeof(sunlightReach));
    for (int i=0; i<6; i++)
        bfsSunlight(i);








    return 0;
}

