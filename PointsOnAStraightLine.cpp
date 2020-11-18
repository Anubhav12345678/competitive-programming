int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    int n=A.size();
    // // int m=B.size();
    // if(n!=m)
    // return 0;
    int i,j,k,maxpoint=INT_MIN;
    map<pair<int,int>,int> m;
    if(n<2)
    return n;
    int overlap,vertical,curmax;
    for(i=0;i<n;i++)
    {
        overlap=curmax=vertical=0;
        for(j=i+1;j<n;j++)
        {
            if(A[i]==A[j]&&B[i]==B[j])
            overlap++;
            else if(A[i]==A[j])
            vertical++;
            else
            {
                int xdiff = A[j]-A[i];
                int ydiff = B[j]-B[i];
                int res = __gcd(xdiff,ydiff);
                xdiff/=res;
                ydiff/=res;
                auto it = m.find(make_pair(xdiff,ydiff));
                if(it!=m.end())
                it->second++;
                else
                m.insert(make_pair((make_pair(xdiff,ydiff)),1));
                it= m.find(make_pair(xdiff,ydiff));
                curmax = max(curmax,it->second);
            }
            curmax = max(curmax,vertical);
        }
        maxpoint = max(maxpoint,curmax+overlap+1);
        m.clear();
    }
    return maxpoint;
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
}
// me
int gcd(int a, int b) {
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.size() < 3) return points.size();

        int res = 0;

        for (int i1 = 0; i1 < points.size()-1; ++i1) {
            int duplicate = 0;
            unordered_map<string,int> mydict;
            for (int i2 = i1+1; i2 < points.size(); ++i2) {

                int dx = points[i1][0] - points[i2][0];
                int dy = points[i1][1] - points[i2][1];

                if (dx == 0 && dy == 0) ++duplicate;
                else if (dx == 0) ++mydict["vertical"];
                else if (dy == 0) ++mydict["horizontal"];
                else {
                    int temp = abs(gcd(dy,dx));
                    if (dy < 0) temp *= -1;
                    ++mydict[to_string(dy/temp)+to_string(dx/temp)];
                }
            }
            
            res = max(res,duplicate);
            for (auto i : mydict)
                res = max(res,i.second+duplicate);
        }
            
        return res + 1;
    }
};