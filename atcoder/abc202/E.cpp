#include <bits/stdc++.h>
using namespace std;

#define nl '\n'


//----------------------------------- DEBUG -----------------------------------
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

//----------------------------------- END DEBUG --------------------------------

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
    if (pow == 0) {
        return 0;
    }
    int hpow = 1 << (pow-1);
    int seg = (x < hpow) ? (
        (y < hpow) ? 0 : 3
    ) : (
        (y < hpow) ? 1 : 2
    );
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2*pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}
 
struct Query {
    int l, r, idx, val;
    int64_t ord;

    Query() {}

    Query(int _l, int _r, int _idx, int _val) {
        l = _l;
        r = _r;
        idx = _idx;
        val = _val;
        ord = gilbertOrder(l, r, 21, 0);
    }
};
 
inline bool operator<(const Query &a, const Query &b) {
    return a.ord < b.ord;
}


void run_cases() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for(int i=1;i<N;i++) {
        int parent;
        cin >> parent;
        --parent;
        adj[i].push_back(parent);
        adj[parent].push_back(i);
    }

    vector<int> in(N), out(N), depth(N), euler;
    int timer = 0;

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        in[node] = timer++;

        euler.push_back(node);

        for(int child: adj[node]) {
            if(child != par) {
                depth[child] = depth[node] + 1;
                dfs(child, node);
            }
        }

        euler.push_back(node);
        out[node] = timer++;
    };

    dfs(0, -1);

    debug() << imie(euler);
    debug() << imie(depth);
    debug() << imie(in) imie(out);

    for(auto &u: euler) {
        u = depth[u];
    }

    debug() << imie(euler);

    int Q;
    cin >> Q;
    vector<Query> query(Q);
    for(int i=0;i<Q;i++) {
        int u, d;
        cin >> u >> d;
        --u;
        int l = in[u];
        int r = out[u];
        query[i] = Query(l, r, i, d);
    }
 
    sort(query.begin(), query.end());

    vector<int> answers(Q, 0);
    vector<int> cnt(N, 0);
 
    auto add = [&](int64_t val) -> void {
        cnt[val]++;
    };
 
    auto sub = [&](int64_t val) -> void {
        cnt[val]--;
    };
 
    int l = query[0].l, r = query[0].l - 1;
    for(auto u: query) {
        while(r < u.r) {
            r++, add(euler[r]);
        }
        while(l > u.l) {
            l--, add(euler[l]);
        }
        while(r > u.r) {
            sub(euler[r]), r--;
        }
        while(l < u.l) {
            sub(euler[l]), l++;
        }
        answers[u.idx] = cnt[u.val];
    }
 
    for(auto u: answers) {
        cout << u / 2 << nl;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}