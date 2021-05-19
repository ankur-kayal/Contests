#include <bits/stdc++.h>
using namespace std;

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

void run_cases() {
    int64_t N, S;
    cin >> N >> S;

    vector<vector<pair<int64_t,int64_t>>> adj(N);

    for(int i=1;i<N;i++) {
        int64_t u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    vector<pair<int64_t,int64_t>> edge_contributions;
    vector<int64_t> leaf_count(N);
    auto dfs = y_combinator([&](auto dfs, int node, int par) -> void {
        if(adj[node].size() == 1 && node != 0) {
            leaf_count[node] = 1;
            return;
        }
        for(auto [child, weight]: adj[node]) {
            if(child != par) {
                dfs(child, node);
                edge_contributions.push_back({weight, leaf_count[child]});
                leaf_count[node] += leaf_count[child];
            }
        }
    });

    dfs(0, -1);
    multiset<vector<int64_t>> order;

    int64_t path_sum = 0;
    for(auto [weight, count] : edge_contributions) {
        path_sum += weight * count;
        order.insert({((weight + 1) / 2) * count, weight, count});
    }

    int moves = 0;
    while(path_sum > S) {
        vector<int64_t> modify = *prev(order.end());
        order.erase(prev(order.end()));
        path_sum -= modify[0];
        modify[1] /= 2;
        modify[0] = ((modify[1] + 1) / 2) * modify[2];
        order.insert(modify);
        moves++;
    }
    cout << moves << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}