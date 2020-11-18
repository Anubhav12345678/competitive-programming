// Find the total area covered by two rectilinear rectangles in a 2D plane.

// Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

// Rectangle Area
// 223 leetcode
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A>=G||C<=E||D<=F||B>=H)
            return (C-A)*(D-B)+(G-E)*(H-F);
        else
        {
            vector<int> f,l;
            f.push_back(A);
            f.push_back(C);
            f.push_back(E);
            f.push_back(G);
            l.push_back(B);
            l.push_back(D);
            l.push_back(H);
            l.push_back(F);
            sort(f.begin(),f.end());
            sort(l.begin(),l.end());
            long long int p = -((f[2]-f[1])*(l[2]-l[1]))+(C-A)*(D-B)+(G-E)*(H-F);
            return (int) p;
            
            
            
            
        }
    }
};