#include<bits/stdc++.h>
using namespace std;

const int maxn = 1005;

int n,l,k;
char s[maxn];

int cnt[30];
int res[maxn][maxn];

int main() {
    scanf("%d%d%d %s",&n,&l,&k,s);

    for(int i=0;i<n*l;i++) cnt[s[i]-'a']++;

    for(int id=1;id<=n;id++) {
        for(int i=0;i<l;i++) {
            res[id][i] = -1;
        }
    }

    int want = k;
    for(int x=0;x<l;x++) {
        int sum = 0, good;
        for(int i=0;i<26;i++) {
            sum += cnt[i];
            if(sum >= want) {
                good = i;
                break;
            }
        }
        printf("good = %c (%d)\n",good+'a',want);
        int wow = min(cnt[good], want);
        int cur = good;
        for(int id=k;id>k-want;id--) {
            while(cnt[cur] == 0) cur--;
            printf("\tput %d %d: %c\n",id,x,cur+'a');
            res[id][x] = cur;
            cnt[cur]--;
        }
        want = wow;
    }

    int cur = 0;
    for(int id=1;id<=n;id++) {
        for(int i=0;i<l;i++) {
            if(res[id][i] == -1) {
                while(cnt[cur]==0) cur++;
                res[id][i] = cur;
                cnt[cur]--;
            }
        }
    }

    for(int id=1;id<=n;id++) {
        for(int i=0;i<l;i++) {
            printf("%c",res[id][i] + 'a');
        }
        printf("\n");
    }
}