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

const int64_t INF = 1e17;

void run_cases() {
    int N, M;
    cin >> N >> M;

    vector<int64_t> start(3), finish(3);

    start[0] = 0, finish[0] = M + 1;
    cin >> start[1] >> start[2] >> finish[1] >> finish[2];
    vector<vector<int64_t>> teleportation(M, vector<int64_t>(3));

    for(int i=1;i<=M;i++) {
        cin >> teleportation[i-1][1] >> teleportation[i-1][2];
        teleportation[i-1][0] = i;
    }   

    debug() << imie(teleportation);

    vector<vector<pair<int64_t, int64_t>>> adj(M + 2);

    sort(teleportation.begin(), teleportation.end(), [&](vector<int64_t> a, vector<int64_t> b) {
        return a[1] < b[1];
    });


    auto add_edge = [&](int64_t u, int64_t v, int64_t cost) -> void {
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    };

    for(int i=0;i<M-1;i++) {
        int u = teleportation[i][0];
        int v = teleportation[i+1][0];
        int64_t cost = abs(teleportation[i][1] - teleportation[i + 1][1]);
        add_edge(u, v, cost);
    }

    sort(teleportation.begin(), teleportation.end(), [&](vector<int64_t> a, vector<int64_t> b) {
        return a[2] < b[2];
    });


    for(int i=0;i<M-1;i++) {
        int u = teleportation[i][0];
        int v = teleportation[i+1][0];
        int64_t cost = abs(teleportation[i][2] - teleportation[i + 1][2]);
        add_edge(u, v, cost);
    }

    for(int i=0;i<M;i++) {
        int u = start[0];
        int v = teleportation[i][0];
        int64_t cost = min(abs(start[1] - teleportation[i][1]) , abs(start[2] - teleportation[i][2]));
        add_edge(u, v, cost);
    }

    for(int i=0;i<M;i++) {
        int u = finish[0];
        int v = teleportation[i][0];
        int64_t cost = abs(finish[1] - teleportation[i][1]) + abs(finish[2] - teleportation[i][2]);
        add_edge(u, v, cost);
    }

    add_edge(start[0], finish[0], abs(start[1] - finish[1]) + abs(start[2] - finish[2]));

    debug() << imie(adj);


    vector<int64_t> dists(M + 2, INF);
    set<pair<int64_t, int64_t>> pq; // first is weight, second is the node
    vector<bool> vis(M + 2, false);

    vis[0] = true;
    dists[0] = 0;
    for(int i=0;i<M+2;i++) {
        pq.insert({dists[i], i});
    }
    // return;


    while(!pq.empty()) {
        auto [current_weight, current_node] = *pq.begin();
        pq.erase(pq.begin());


        for(auto [child, weight] : adj[current_node]) {
            if(current_weight + weight < dists[child]) {
                pq.erase(pq.find({dists[child], child}));
                dists[child] = current_weight + weight;
                pq.insert({dists[child], child});
            }
        }
    }

    cout << dists[M + 1] << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}