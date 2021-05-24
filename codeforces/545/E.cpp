#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

struct Edge {
    int to, idx;
    int64_t weight;

    Edge() : to(), idx(), weight() {}
    Edge(int _to, int _idx, int64_t _weight) : to(_to), idx(_idx), weight(_weight) {}
};

const int64_t INF = 2e18;

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


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

void run_cases() {
    int N, M;
    cin >> N >> M;
    vector<vector<Edge>> adj(N);

    for(int i=1;i<=M;i++) {
        int u, v;
        int64_t weight;
        cin >> u >> v >> weight;
        --u, --v;
        adj[u].push_back(Edge(v, i, weight));
        adj[v].push_back(Edge(u, i, weight));
    }

    vector<pair<int64_t, int64_t>> values(N);  // id, weight

    int start;
    cin >> start;
    --start;

    // Do djikstra
    set<pair<int64_t, int64_t>> pq; // weight, node_id
    for(int i=0;i<N;i++) {
        values[i] = {-1, INF};
    }

    values[start] = {-1, 0};

    for(int i=0;i<N;i++) {
        pq.insert({values[i].second, i});
    }

    debug() << imie(pq);

    vector<pair<int64_t, int64_t>> chosen(N);

    while(!pq.empty()) {
        auto [current_weight, node_id] = *pq.begin();
        pq.erase(pq.begin());

        for(Edge e: adj[node_id]) {
            if(current_weight + e.weight <= values[e.to].second) {
                pq.erase(pq.find({values[e.to].second, e.to}));
                values[e.to] = {e.idx, current_weight + e.weight};
                chosen[e.to] = {e.idx, e.weight};
                pq.insert({values[e.to].second, e.to});
            }
        }
        debug() << imie(pq);
    }


    int64_t total_weight = 0;
    vector<int> chosen_edges;

    for(int i=0;i<N;i++) {
        if(i != start) {
            chosen_edges.push_back(chosen[i].first);
            total_weight += chosen[i].second;
        }
    }

    cout << total_weight << '\n';
    output_vector(chosen_edges);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}