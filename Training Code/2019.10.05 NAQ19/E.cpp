#include <bits/stdc++.h>
using namespace std;

const int N = (int)3e5 + 50;
int v[N], len[N];

struct Trie {
    static const int B = 26, M = (int)1e5 + 50;

    int next[M][B], fail[M], end[M];
    int failto[M];
    int id[M];
    int root, L;

    int newnode(){
        for(int i = 0; i < B; i++) next[L][i] = -1;
        id[L] = -1;
        failto[L] = -1;
        end[L++] = 0;
        return L - 1;
    }

    void init() {
        L = 0;
        root = newnode();
    }

    void insert(const string &buf, int idx) {
        int now = root;
        for(char c : buf) {
            if(next[now][c - 'A'] == -1) next[now][c - 'A'] = newnode();
            now = next[now][c - 'A'];
        }
        end[now]++;
        if(id[now] == -1 || v[id[now]] < v[idx]) id[now] = idx;
    }

    void build() {
        queue<int> Q;
        fail[root] = root;
        for(int i = 0; i < B; i++) {
            if(next[root][i] == -1) next[root][i] = root;
            else {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while(!Q.empty()) {
            int now = Q.front();
            Q.pop();
            for(int i = 0; i < B; i++) {
                if(next[now][i] == -1) next[now][i] = next[fail[now]][i];
                else {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    int get_fail_to(int v) {
        if(failto[v] != -1) return failto[v];
        if(v == 0) return failto[v] = 0;
        if(!end[fail[v]]) return failto[v] = get_fail_to(fail[v]);
        else return failto[v] = fail[v];
    }
} trie;


int n;
string fs[N], s[N];
int dp[N], pv[N];
string mes;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    trie.init();
    for(int i = 0; i < n; i++) {
        cin >> fs[i];
        for(char c : fs[i]) {
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                v[i]++;
                continue;
            }
            s[i].push_back(c);
        }
        len[i] = s[i].length();
        trie.insert(s[i], i);
    }
    trie.build();
    int cur_st = 0;
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    cin >> mes;
    int mlen = mes.length();
    mes = " " + mes;

    for(int i = 1; i <= mlen; i++) {
        cur_st = trie.next[cur_st][mes[i] - 'A'];
        int cur = cur_st;
        if(!trie.end[cur]) cur = trie.get_fail_to(cur);
        while(cur != 0) {
            int id = trie.id[cur];
            if(dp[i - len[id]] != -1 && dp[i - len[id]] + v[id] > dp[i]) {
                dp[i] = dp[i - len[id]] + v[id];
                pv[i] = id;
            }
            cur = trie.get_fail_to(cur);
        }
    }
    int cur = mlen;
    vector<int> res;
    while(cur != 0) {
        res.push_back(pv[cur]);
        cur -= len[pv[cur]];
    }
    reverse(res.begin(), res.end());
    for(int id : res) {
        cout << fs[id] << " ";
    }
    cout << endl;

}