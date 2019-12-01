#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
pair<int, ull> f[300001];

const int base1 = 37;
const int base2 = 41;
const int mod1 = (int )(1e9 + 7);

char str[300001];
int mul1[300001];
ull mul2[300001];
int vis[300001];
pair<int, ull> a[300001];
pair<int, ull> operator + (const pair<int, ull>& x, int d) {
    return make_pair((1LL * x.first * base1 + d) % mod1, x.second * base2 + d);
}

pair<int, ull> hsh(int x, int y) {
    return make_pair((f[y].first - 1LL * f[x - 1].first * mul1[y - x + 1] % mod1 + mod1) % mod1,
                     (f[y].second - f[x - 1].second * mul2[y - x + 1]));
}

int main( ) {
    scanf("%s", str + 1);
    int n = (int )strlen(str + 1);
    mul1[0] = 1;
    mul2[0] = 1;
    for (int i = 1; i <= n; i ++) {
        mul1[i] = 1LL * mul1[i - 1] * base1 % mod1;
        mul2[i] = mul2[i - 1] * base2;
    }

    f[0] = make_pair(0, 0);
    for (int i = 1; i <= n; i ++)
        f[i] = f[i - 1] + (str[i] - 'a' + 1);

    int ansx = 0, ansy = 1;
    for (int i = 1; i <= n; i ++) {
        int tmp = str[i] - 'a' + 1;
        if (vis[tmp]) {
            int st = vis[tmp], ed = i - 1;
            cout << st << " " << ed << endl;

            int len = ed - st + 1;
            int l = 1, r = min(len - 1, n - ed);
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (hsh(st, st + mid - 1) == hsh(ed + 1, ed + mid)) l = mid + 1;
                else r = mid - 1;
            }


            int sz = len + r;
            int x = sz, y = len;
            int get = __gcd(x, y);
            x /= get, y /= get;
            if (1LL * x * ansy > 1LL * ansx * y) {
                ansx = x;
                ansy = y;
                printf("%d/%d\n", ansx, ansy);
            }
        }
        vis[tmp] = i;
    }

    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n / i; j ++) {
            int st = (j - 1) * i + 1, ed = j * i;
            a[j] = hsh(st, ed);
        }
        int mx = 0;
        int m = n / i;
        for (int j = 1; j <= m; j ++) {
            int tmp = j;
            while (tmp <= m && a[j] == a[tmp]) ++ tmp;
            -- tmp;

            int st = (j - 1) * i + 1, ed = j * i;
            int l = 1, r = min(st - 1, i - 1);
            int cnt = (tmp - j + 1) * i;

            while (l <= r) {
                int mid = (l + r) >> 1;
                if (hsh(ed - mid + 1, ed) == hsh(st - mid, st - 1)) l = mid + 1;
                else r = mid - 1;
            }
            cnt += r;

            st = (tmp - 1) * i + 1, ed = tmp * i;
            l = 1, r = min(i - 1, n - ed);
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (hsh(st, st + mid - 1) == hsh(ed + 1, ed + mid)) l = mid + 1;
                else r = mid - 1;
            }
            cnt += r;

            if (cnt > mx) mx = cnt;
            j = tmp;
        }
        int x = mx, y = i;
        int tmp = __gcd(x, y);
        x /= tmp, y /= tmp;
        if (1LL * x * ansy > 1LL * ansx * y) {
            ansx = x;
            ansy = y;
        }
    }
    printf("%d/%d\n", ansx, ansy);
    return 0;
}