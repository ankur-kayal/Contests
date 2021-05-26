#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    int N;
    cin >> N;
    vector<vector<int>> adj(N);
    for(int i=1;i<N;i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int root = 0;
    vector<double> probability(N, 1);
    
    double expected_value = 0;

    function<void(int,int)> dfs = [&](int node, int par) -> void {
        double children_count = adj[node].size() - 1;
        if(node == root) {
            children_count++;
        }

        for(int child: adj[node]) {
            if(child != par) {
                expected_value += probability[node] / children_count;
                probability[child] = probability[node] / children_count;
                dfs(child, node);
            }
        }
    };

    dfs(0, -1);

    cout << setprecision(15) << fixed << expected_value;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}