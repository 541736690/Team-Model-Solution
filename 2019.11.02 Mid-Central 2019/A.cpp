//
// Created by 54173 on 11/2/2019.
//


#include<bits/stdc++.h>
using namespace std;

int n;
char s[205];

int main() {
    scanf(" %s",s+1);
    n = strlen(s+1);
    int A = 0, B = 0;
    int tied = 0;
    for(int i=1;i<=n;i+=2) {
        if(s[i]=='A') {
            A += s[i+1]-'0';
        }
        else {
            B += s[i+1]-'0';
        }
        if(A==10 && B==10) tied = 1;
        if(A >= 11 && !tied) return !printf("A");
        if(A-B >=2 && tied) return !printf("A");
        if(B >= 11 && !tied) return !printf("B");
        if(B-A >=2 && tied) return !printf("B");
    }
}