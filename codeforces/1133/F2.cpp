#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

void run_cases() {
    int n, m, D;
    cin >> n >> m >> D;

    vector<int> is_connected_to_1;
    vector<int> parent(n, -1);
    vector<vector<int>> adj(n);
    vector<int> deg(n, 0);
    vector<bool> vis(n, false);

    for(int i=1;i<=m;i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        if(u > v) {
            swap(u, v);
        }
        if(u == 0){
            is_connected_to_1.push_back(v);
        } 

        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    deg[0] = D;


    auto dfs = y_combinator([&](auto dfs, int node, int par) -> void {
        vis[node] = true;
        if(par != -1) {
            parent[node] = par;
        }
        for(auto child : adj[node]) {
            if(!vis[child]) {
                dfs(child, node);
                deg[node]--;
            }
        }
    });

    dfs(0, -1);


    if(deg[0] < 0) {
        cout << "NO\n";
    } else {
        if(deg[0] != 0) {
            for(auto node: is_connected_to_1) {
                if(parent[node] != 0) {
                    parent[node] = 0;
                    deg[0]--;
                }
                if(deg[0] == 0) {
                    break;
                }
            }
        }

        if(deg[0] != 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int i=0;i<n;i++) {
                if(parent[i] != -1) {
                    cout << i + 1 << " " << parent[i] + 1 << '\n';
                }
            }
        }
        
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