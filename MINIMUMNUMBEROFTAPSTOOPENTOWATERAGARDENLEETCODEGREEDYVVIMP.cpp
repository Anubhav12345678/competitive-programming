class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jump((n+1),0);
        int i,j,k,m;
        for(i=0;i<ranges.size();i++){
            int l =  max(0,i-ranges[i]);
            int r = min(n,i+ranges[i]);
            jump[l] = max(jump[l],r-l);
        }
        
        int curend=0,curfar=0, cnt=0;
        for(i=0;i<jump.size()-1;i++){
            if(i>curfar) return -1;
            curfar = max(curfar,i+jump[i]);
            if(curend==i){
                curend=curfar;
                cnt++;
            }
        }
        
        if(curfar<n) return -1;
        return cnt;
    }
};
/*

There is a one-dimensional garden on the x-axis. The garden starts at the point 0 and ends at the point n. (i.e The length 
of the garden is n).

There are n + 1 taps located at points [0, 1, ..., n] in the garden.

Given an integer n and an integer array ranges of length n + 1 where ranges[i] (0-indexed) means the i-th tap can water the area
 [i - ranges[i], i + ranges[i]] if it was open.

Return the minimum number of taps that should be open to water the whole garden, If the garden cannot be watered return -1.

*/