/*
You are given a string s, and an array of pairs of indices in the string pairs where pairs[i] = [a, b] 
indicates 2 indices(0-indexed) of the string.

You can swap the characters at any pair of indices in the given pairs any number of times.

Return the lexicographically smallest string that s can be changed to after using the swaps.

*/
class Solution {
public:
    int find(vector<int>& ds, int i) {
  return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
}
string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
  vector<int> ds(s.size(), -1);
  vector<vector<int>> m(s.size());
  for (auto& p : pairs) {
    auto i = find(ds, p[0]), j = find(ds, p[1]);
    if (i != j) 
        ds[j] = i;
  }
  for (auto i = 0; i < s.size(); ++i) 
      m[find(ds, i)].push_back(i);
  for (auto &ids : m) {
    string ss = "";
    for (auto id : ids) 
        ss += s[id];
    sort(begin(ss), end(ss));
    for (auto i = 0; i < ids.size(); ++i) 
        s[ids[i]] = ss[i];
  }
  return s;
}
};