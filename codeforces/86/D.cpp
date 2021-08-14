#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

int block;

struct Query {
    int64_t l, r, id;

    Query() {}

    Query(int64_t _l, int64_t _r, int64_t _id) : l(_l), r(_r), id(_id) {}

    bool operator < (Query &other) {
        return make_pair(l / block, r) < make_pair(other.l / block, other.r);
    }
};

void run_cases() {
    int N, T;
    cin >> N >> T;

    block = sqrtl(N);

    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t maxA = *max_element(A.begin(), A.end());

    vector<int64_t> K(maxA + 1);

    int64_t ans = 0;
    vector<Query> queries;
    vector<int64_t> answers(T);

    for(int i = 0; i < T; i++) {
        int l, r;
        cin >> l >> r;
        --l;
        queries.push_back(Query(l, r, i));
    }

    sort(queries.begin(), queries.end());

    int global_left = 0, global_right = 0;

    auto add_element = [&](int64_t element) {
        ans -= (K[element] * K[element] * element);
        K[element]++;
        ans += (K[element] * K[element] * element);
    };

    auto delete_element = [&](int64_t element) {
        ans -= (K[element] * K[element] * element);
        K[element]--;
        ans += (K[element] * K[element] * element);
    };

    for(Query q: queries) {

        while(global_left < q.l) {
            delete_element(A[global_left]);
            global_left++;
        }

        while(global_left > q.l) {
            global_left--;
            add_element(A[global_left]);
        }

        while(global_right < q.r) {
            add_element(A[global_right]);
            global_right++;
        }

        while(global_right > q.r) {
            global_right--;
            delete_element(A[global_right]);
        }

        answers[q.id] = ans;
    }

    for(auto u: answers) {
        cout << u << '\n';
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