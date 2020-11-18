#include <stdio.h>
#include <algorithm>
using namespace std;
int n,i,a[100500],rez,l;
int main()
{
    scanf("%d%d",&n,&l);
    for (i = 0; i < n; i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    rez = 2*max(a[0],l-a[n-1]);
    for (i = 0; i < n-1; i++)
        rez = max(rez, a[i+1]-a[i]);
    printf("%.10f\n",rez/2.);
    return 0;
}
/*
Vanya walks late at night along a straight street of length l, lit by n lanterns. Consider the coordinate system with the
 beginning of the street corresponding to the point 0, and its end corresponding to the point l. Then the i-th lantern is 
 at the point a i. The lantern lights all points of the street that are at the distance of at most d from it, where d is 
 some positive number, common for all lanterns.

Vanya wonders: what is the minimum light radius d should the lanterns have to light the whole street?

*/