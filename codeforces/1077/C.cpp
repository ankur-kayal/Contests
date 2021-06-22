#include <bits/stdc++.h>
#include <numeric>
using namespace std;

#define nl '\n'

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());
 
    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void run_cases() {
    int N;
    cin >> N;
    vector<int64_t> A(N);
    for(auto &u: A)
        cin >> u;

    int64_t sum = accumulate(A.begin(), A.end(), 0LL);

    map<int64_t, int64_t> cnt;

    for(auto u: A) {
        cnt[u]++;
    }

    vector<int> ans;
    for(int i = 0; i < N; i++) {
        int64_t modifiedSum = sum - A[i];
        cnt[A[i]]--;

        if(modifiedSum % 2 == 0) {
            int64_t midElement = modifiedSum / 2;
            if(cnt.count(midElement) && cnt[midElement] > 0) {
                ans.push_back(i);
            }
        }

        cnt[A[i]]++;
    }


    cout << ans.size() << '\n';
    output_vector(ans, 1);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}