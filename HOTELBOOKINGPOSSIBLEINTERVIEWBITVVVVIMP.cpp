/*
A hotel manager has to process N advance bookings of rooms for the next season. His hotel has K rooms.
 Bookings contain an arrival date and a departure date. He wants to find out whether there are enough rooms 
 in the hotel to satisfy the demand. Write a program that solves this problem in time O(N log N) .





*/





bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int,int> >v;
    int n=arrive.size();
    for(int i=0;i<n;i++){
        v.push_back(make_pair(arrive[i],1));
        v.push_back(make_pair(depart[i],-1));
    }
    sort(v.begin(),v.end());
    int count=0;
    for(int i=0;i<2*n;i++){
        count+=v[i].second;
        if(count>K)
         return false;
    }
    return true;
}
