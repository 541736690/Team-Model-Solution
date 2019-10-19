//
// Created by 54173 on 10/19/2019.
//
#include<bits/stdc++.h>
using namespace std;

char s[1005][100];
int p[1005], pos[1005];
int sz1, sz2;

bool cmp(int x, int y) {
    return strcmp(s[x], s[y]) < 0;
}

void init() {
    for(int x=1;x<=999;x++) {
        int val = x;
        int sz = -1;
        while(val != 0) {
            if(val >= 900) {
                s[x][++sz] = 'C';
                s[x][++sz] = 'M';
                val -= 900;
            }
            else if(val >= 800) {
                s[x][++sz] = 'D';
                s[x][++sz] = 'C';
                s[x][++sz] = 'C';
                s[x][++sz] = 'C';
                val -= 800;
            }
            else if(val >= 700) {
                s[x][++sz] = 'D';
                s[x][++sz] = 'C';
                s[x][++sz] = 'C';
                val -= 700;
            }
            else if(val >= 600) {
                s[x][++sz] = 'D';
                s[x][++sz] = 'C';
                val -= 600;
            }
            else if(val >= 500) {
                s[x][++sz] = 'D';
                val -= 500;
            }
            else if(val >= 400) {
                s[x][++sz] = 'C';
                s[x][++sz] = 'D';
                val -= 400;
            }
            else if(val >= 300) {
                s[x][++sz] = 'C';
                s[x][++sz] = 'C';
                s[x][++sz] = 'C';
                val -= 300;
            }
            else if(val >= 200) {
                s[x][++sz] = 'C';
                s[x][++sz] = 'C';
                val -= 200;
            }
            else if(val >= 100) {
                s[x][++sz] = 'C';
                val -= 100;
            }
            else if(val >= 90) {
                s[x][++sz] = 'X';
                s[x][++sz] = 'C';
                val -= 90;
            }
            else if(val >= 80) {
                s[x][++sz] = 'L';
                s[x][++sz] = 'X';
                s[x][++sz] = 'X';
                s[x][++sz] = 'X';
                val -= 80;
            }
            else if(val >= 70) {
                s[x][++sz] = 'L';
                s[x][++sz] = 'X';
                s[x][++sz] = 'X';
                val -= 70;
            }
            else if(val >= 60) {
                s[x][++sz] = 'L';
                s[x][++sz] = 'X';
                val -= 60;
            }
            else if(val >= 50) {
                s[x][++sz] = 'L';
                val -= 50;
            }
            else if(val >= 40) {
                s[x][++sz] = 'X';
                s[x][++sz] = 'L';
                val -= 40;
            }
            else if(val >= 30) {
                s[x][++sz] = 'X';
                s[x][++sz] = 'X';
                s[x][++sz] = 'X';
                val -= 30;
            }
            else if(val >= 20) {
                s[x][++sz] = 'X';
                s[x][++sz] = 'X';
                val -= 20;
            }
            else if(val >= 10) {
                s[x][++sz] = 'X';
                val -= 10;
            }
            else if(val >= 9) {
                s[x][++sz] = 'I';
                s[x][++sz] = 'X';
                val -= 9;
            }
            else if(val >= 8) {
                s[x][++sz] = 'V';
                s[x][++sz] = 'I';
                s[x][++sz] = 'I';
                s[x][++sz] = 'I';
                val -= 8;
            }
            else if(val >= 7) {
                s[x][++sz] = 'V';
                s[x][++sz] = 'I';
                s[x][++sz] = 'I';
                val -= 7;
            }
            else if(val >= 6) {
                s[x][++sz] = 'V';
                s[x][++sz] = 'I';
                val -= 6;
            }
            else if(val >= 5) {
                s[x][++sz] = 'V';
                val -= 5;
            }
            else if(val >= 4) {
                s[x][++sz] = 'I';
                s[x][++sz] = 'V';
                val -= 4;
            }
            else if(val >= 3) {
                s[x][++sz] = 'I';
                s[x][++sz] = 'I';
                s[x][++sz] = 'I';
                val -= 3;
            }
            else if(val >= 2) {
                s[x][++sz] = 'I';
                s[x][++sz] = 'I';
                val -= 2;
            }
            else if(val >= 1) {
                s[x][++sz] = 'I';
                val -= 1;
            }
        }
        //printf("%d: %s\n",x,s[x]);
    }
    s[1000][0] = 'M';

    for(int i=1;i<=1000;i++) p[i] = i;
    sort(&p[1],&p[1001],cmp);
    for(int i=1;i<=1000;i++) pos[p[i]] = i;//, printf("%d ",p[i]);
    //printf("\n----\n");
    sz1 = pos[1000];
    sz2 = 1000 - pos[1000];
}

int solve(int x, int l, int r) {
    if(x==0) return l;
    if(x>1000) return solve(x-1000, l+sz1, r-sz2);
    if(pos[x] <= pos[1000]) return l + pos[x];
    return r - (1000-pos[x]+1);
}

int main() {
    init();
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        int x; scanf("%d",&x);
        printf("%d\n",solve(x,0,0));
    }
}
