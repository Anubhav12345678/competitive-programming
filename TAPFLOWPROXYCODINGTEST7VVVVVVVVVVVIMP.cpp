#include <bits/stdc++.h>
using namespace std;
#include<vector>
 
int main(){
    int n, t;
    std::cin >> n >> t;
 
    std::vector<std::vector<double>> arr(n+1, std::vector<double>(n+1, 0.0));
     // let's assume max volume of a vessel is 1
    // add 1 to the volume of the top vessel at every timestep
    while(t--){
        arr[1][1] += 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=i; j++){
                if(arr[i][j]>1.0 && i<n){
                    // add surplus and then reset the vessel volume to 1
                    arr[i+1][j] += (arr[i][j]-1)/2.0;
                    arr[i+1][j+1] += (arr[i][j]-1)/2.0;
                    arr[i][j]=1;
                }
            }
        }
    }
 
    int ans=0;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            if(arr[i][j]>=1)
                ans++;
    std::cout << ans << std::endl;
    return 0;
}
/*
An A-structure is an arrangement of items such that the first level has one object and every other level below it has one more than the number of objects in the level above it.

A tap has been opened up above an A-structure of U-shaped vessels. The tap outputs water at a constant capacity.

Each second, the output of the tap is equal to the volume of one U-shaped vessel. If the vessel is already full, but there is some water flowing in it, then it pours over the edge of the vessel and is equally distributed over the two vessels standing under.

If the overflowed vessel is at the bottom level, then the water pours on the ground. You need to find out the number of completely full vessels if the tap is stopped in t seconds. The number of levels will also be provided to you as n.

For the purposes of this problem:

All the objects are arranged symmetrically along the horizontal axis.
Assume that all levels are equally spaced.
Water flows symmetrically over both the edges of the vessel
Sample view of an A-Structure with n=3 and at a time t=2 after the tap has been opened:


*/