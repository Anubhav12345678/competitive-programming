struct ele
{
    int val;
    int ind;
};
bool comp(struct ele a,struct ele b)
{
    return a.val<b.val;
}
int Solution::maximumGap(const vector<int> &A) {
    if (A.size() == 0) return -1;
            if (A.size() == 1) return 0;
            vector<pair<int, int> > toSort; 
            for (int i = 0; i < A.size(); i++) {
                toSort.push_back(make_pair(A[i], i));
            }
            sort(toSort.begin(), toSort.end());
            int len = toSort.size();
            int maxIndex = toSort[len - 1].second;
            int ans = 0;
            for (int i = len - 2; i >= 0; i--) {
                ans = max(ans, maxIndex - toSort[i].second);
                maxIndex = max(maxIndex, toSort[i].second);
            }
            return ans;
}
    