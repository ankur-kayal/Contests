#include <algorithm>
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

    vector<vector<vector<int64_t>>> adj(N);

    for(int i=1;i<N;i++) {
        int64_t u, v, w, c;
        cin >> u >> v >> w >> c;
        --u, --v;
        adj[u].push_back({v, w, c});
        adj[v].push_back({u, w, c});
    }
    vector<vector<int64_t>> edge_contributions;
    vector<int64_t> leaf_count(N);
    auto dfs = y_combinator([&](auto dfs, int node, int par) -> void {
        if(adj[node].size() == 1 && node != 0) {
            leaf_count[node] = 1;
            return;
        }
        for(auto edge: adj[node]) {
            int64_t child = edge[0];
            int64_t weight = edge[1];
            int64_t cost = edge[2];
            if(child != par) {
                dfs(child, node);
                edge_contributions.push_back({weight, leaf_count[child], cost});
                leaf_count[node] += leaf_count[child];
            }
        }
    });

    dfs(0, -1);
    vector<int64_t> order1, order2;

    int64_t path_sum = 0;
    for(auto edge : edge_contributions) {
        int64_t weight = edge[0];
        int64_t count = edge[1];
        int64_t cost = edge[2];
        path_sum += weight * count;
        if(cost == 1) {
            while(weight != 0){
                order1.push_back(((weight + 1) / 2) * count);
                weight/=2;
            }
        } else {
            while(weight != 0){
                order2.push_back(((weight + 1) / 2) * count);
                weight/=2;
            }
        }
    }
    sort(order1.rbegin(), order1.rend());
    sort(order2.rbegin(), order2.rend());

    vector<int64_t> prefix1 = {0}, prefix2={0};
    for(auto u: order1) {
        prefix1.push_back(prefix1.back() + u);
    }

    for(auto u: order2) {
        prefix2.push_back(prefix2.back() + u);
    }

    if(path_sum <= S) {
        cout << 0 << '\n';
        return;
    }

    int64_t best = 1e18;

    for(int i=0;i<prefix1.size();i++) {
        int64_t cost = i;

        int64_t needed = path_sum - S - prefix1[i];
        if(needed <= 0) {
            best = min(best, cost);
            continue;
        }
        if(prefix2.back() < needed) continue;
        
        cost = cost + (lower_bound(prefix2.begin(), prefix2.end(), needed) - prefix2.begin()) * 2;
        best = min(best, cost);
    }

    cout << best << '\n';    
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}