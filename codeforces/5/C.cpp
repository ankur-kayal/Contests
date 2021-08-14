#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

void run_cases() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> cnt(n + 1);

    vector<pair<char, int>> st;
    st.push_back({'#', -1});
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            st.emplace_back(s[i], i);
        } else {
            if(st.back().first == '(') {
                int top = st.back().second;
                st.pop_back();
                cnt[i - st.back().second]++;
            } else {
                st.emplace_back(')', i);
            }
        }
    }

    for(int i = n; i >= 0; i--) {
        if(cnt[i] > 0) {
            cout << i << " " << cnt[i] << '\n';
            return;
        }
    }   

    cout << "0 1";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);

    int tests = 1;
    // cin >> tests;

    for(int test = 1;test <= tests;test++) {
        run_cases();
    }
}