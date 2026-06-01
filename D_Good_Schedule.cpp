#include <iostream>
using namespace std;
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int multTestQ;
  cin >> multTestQ;
  for (int test = 0; test < multTestQ; ++test) {
    int n;
    cin >> n;
    vector<int> a(n + 2), b(n + 2);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    vector<vector<int>> pos_sync(n + 2), mis_pos(n + 2);
    for (int i = 1; i <= n; ++i) {
      if (a[i] == b[i]) {
        pos_sync[a[i]].push_back(i);
      } else {
        mis_pos[a[i]].push_back(i);
        mis_pos[b[i]].push_back(i);
      }
    }
    // no need to sort, already in order
    map<long long, int> memo;
    auto get_first_mismatch = [&](auto&& self, int init_k, int init_sp) -> int {
      if (init_k > n) return n + 1;
      long long init_key = 1LL * init_k * (n + 2LL) + init_sp;
      if (memo.count(init_key)) return memo[init_key];
      vector<long long> path;
      int cur_k = init_k;
      int cur_sp = init_sp;
      int final_res = n + 1;
      while (cur_k <= n) {
        long long ckey = 1LL * cur_k * (n + 2LL) + cur_sp;
        if (memo.count(ckey)) {
          final_res = memo[ckey];
          break;
        }
        path.push_back(ckey);
        // q
        auto& syn = pos_sync[cur_k];
        auto it = lower_bound(syn.begin(), syn.end(), cur_sp + 1);
        int q = (it != syn.end() ? *it : n + 2);
        // mis
        auto& ml = mis_pos[cur_k];
        auto itm = lower_bound(ml.begin(), ml.end(), cur_sp + 1);
        int misv = (itm != ml.end() ? *itm : n + 2);
        if (q <= n && misv >= q) {
          // advance
          cur_sp = q;
          cur_k++;
        } else {
          final_res = (misv <= n ? misv : n + 1);
          break;
        }
      }
      if (cur_k > n) {
        final_res = n + 1;
      }
      for (auto pk : path) {
        memo[pk] = final_res;
      }
      return final_res;
    };
    // precompute for k=1
    vector<int> next_mis1(n + 2, n + 1);
    {
      auto& ml = mis_pos[1];
      int ptr = 0;
      for (int i = 1; i <= n; ++i) {
        while (ptr < (int)ml.size() && ml[ptr] < i) ++ptr;
        if (ptr < (int)ml.size()) {
          next_mis1[i] = ml[ptr];
        }
      }
    }
    vector<int> next_sync_1(n + 2, n + 1);
    {
      auto& s1 = pos_sync[1];
      int ptr = 0;
      for (int i = 1; i <= n; ++i) {
        while (ptr < (int)s1.size() && s1[ptr] < i) ++ptr;
        if (ptr < (int)s1.size()) {
          next_sync_1[i] = s1[ptr];
        }
      }
    }
    map<int, int> fixed_for_sync;
    auto& s1 = pos_sync[1];
    for (int s : s1) {
      fixed_for_sync[s] = get_first_mismatch(get_first_mismatch, 2, s);
    }
    long long answer = 0;
    for (int L = 1; L <= n; ++L) {
      int q = next_sync_1[L];
      int varr = next_mis1[L];
      int max_st = (q <= n ? q : n + 1);
      if (varr >= max_st) varr = n + 1;
      int fixd = (q > n ? n + 1 : fixed_for_sync[q]);
      int M = min(varr, fixd);
      if (M > n + 1) M = n + 1;
      long long num = (M > L ? (long long)M - L : 0LL);
      if (M == n + 1) num = (long long)(n + 1) - L;  // wait, already handled since M=n+1 >L, M-L =n+1 -L
      answer += num;
    }
    cout << answer << '\n';
  }
  return 0;
}