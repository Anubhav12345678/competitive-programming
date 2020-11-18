class Solution {
public:
    /*

Given an array arr that represents a permutation of numbers from 1 to n. You have a binary string of size n
 that initially has all its bits set to zero.

At each step i (assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position 
arr[i] is set to 1. You are given an integer m and you need to find the latest step at which there exists 
a group of ones of length m. A group of ones is a contiguous substring of 1s such that it cannot be extended in either direction.

Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.

 

Example 1:

Input: arr = [3,5,1,2,4], m = 1
Output: 4
Explanation:
Step 1: "00100", groups: ["1"]
Step 2: "00101", groups: ["1", "1"]
Step 3: "10101", groups: ["1", "1", "1"]
Step 4: "11101", groups: ["111", "1"]
Step 5: "11111", groups: ["11111"]
The latest step at which there exists a group of size 1 is step 4.


    */
    static const int maxn=100005;
    int par[maxn],sz[maxn],b[maxn];
    int find(int x) {
        return x==par[x]?x:par[x]=find(par[x]);
    }
    int cnt[maxn];
    void merge(int x,int y) {
        int a=find(x),b=find(y);
        if(a!=b) {
            cnt[sz[a]]--;
            cnt[sz[b]]--;
            par[a]=b;
            sz[b]+=sz[a];
            cnt[sz[b]]++;
        }
    }
    
    int findLatestStep(vector<int>& a, int m) {
        int n=a.size();
        for(int i=1;i<=n;++i) par[i]=i,sz[i]=1;
        int ret=0,tp=1;
        for(int i:a) {
            b[i]=1;
            cnt[1]++;
            if(b[i-1]) {
                merge(i,i-1);
            }
            if(b[i+1]) {
                merge(i,i+1);
            }
            if(cnt[m]) ret=tp;
            ++tp;
        }
        if(!ret) return -1;
        return ret;
    }
};