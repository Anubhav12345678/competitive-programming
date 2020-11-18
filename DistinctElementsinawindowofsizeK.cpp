vector<int> Solution::dNums(vector<int> &A, int B) {
      assert(B<=A.size());
    int n=A.size();
    vector<int> ret;
    unordered_map <int, int> m;
    for(int i=0; i<n; i++){
        //increase key
        m[A[i]]++;
        if(i-B+1>=0){

            //decrease key
            ret.push_back(m.size());
            m[A[i-B+1]]--;

            //remove if count becomes 0
            if(m[A[i-B+1]]==0)m.erase(A[i-B+1]);
        }
    }
    return ret;
}
    