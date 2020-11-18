#include<algorithm>
#include<cmath>
#include<vector>
#include<math.h>
#include<set>
#include<map>
#include<deque>
#include<queue>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <functional>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
#define  ll long long
#define  ull unsigned long long
#define  ul unsigned long
#define all(v) v.begin(),v.end()
#define sz(n) (int)n.size()
#define pb(s) push_back(s);
#define format(n) fixed<<setprecision(n)
#define finl "\n"
#define Dark_knight fast();
 
#define mod 1000000007
#define INF LLONG_MAX
#define PI 3.141592654
#define e exp(1)
#define clr(dp,n) memset(dp,n,sizeof dp)
#define ex(n) return cout<<n<<finl,0;
int dx[] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[] = { 0, 1, 0, -1, 1, -1, 1, -1 };
void fast(){
 
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
 
#ifdef ONLINE_JUDGE
    //freopen("alice.in ", "r", stdin);
 
    //freopen("little.out", "w", stdout);
#endif
#ifndef ONLINE_JUDGE
    //freopen("input.in", "r", stdin);
 
    // freopen("output.out", "w", stdout);
#endif
}
 
 
// You can do it ^_^
int main()
 
{
 
 Dark_knight
 
 
int n,taxi=0,count4=0,count3=0,count2=0,count1=0;
    cin>>n;
 
    if(n >=1 && n <= 100000)
    {
        for(int i=0;i<n;i++)
        {
            int num;
            cin>>num;
            if(num == 1)
            {
                ++count1;
            }
 
            else if(num == 2)
            {
                ++count2;
            }
 
            else if(num == 3)
            {
                ++count3;
            }
 
            else if(num == 4)
            {
                ++count4;
            }
        }
 
        taxi+=count4;
        count4=0;
 
        if(count2 % 2 == 0)
        {
            taxi+= count2 / 2;
            count2=0;
        }
 
        if(count1 == 0)
        {
            taxi+=count3;
            count3=0;
            if(count2>0 && count2 % 2 != 0)
            {
                if(count2 == 1)
                {
                    ++taxi;
                    count2=0;
                }
                else if(count2 > 1)
                {
                    taxi = taxi + ((count2-1)/2) + 1;
                    count2=0;
                }
            }
        }
 
        else
        {
            while(count3 > 0 && count1 > 0)
            {
                --count3;
                --count1;
                ++taxi;
            }
 
            if(count3 > 0)
            {
                taxi+=count3;
 
                if(count2>0 && count2 % 2 != 0)
                {
                    if(count2 == 1)
                    {
                        ++taxi;
                        count2=0;
                    }
                    else if(count2 > 1)
                    {
                        taxi = taxi + ((count2-1)/2) + 1;
                        count2=0;
                    }
                }
 
            }
 
            if(count1 > 0)
            {
                if(count2>0 && count2 % 2 != 0)
                {
                    if(count2 == 1)
                    {
                        --count2;
                        count1-=2;
                        ++taxi;
                        if(count1 > 0)
                        {
                            if(count1 > 4)
                            {
                                taxi += count1 / 4;
                                if(count1%4 != 0)
                                {
                                    ++taxi;
                                }
                                count1=0;
                            }
                            else if(count1 > 0 && count1 < 4)
                            {
                                ++taxi;
                                count1=0;
                            }
                        }
                        count2=0;
                    }
                    else if(count2 > 1)
                    {
                        taxi = taxi + ((count2-1)/2);
                        --count2;
                        count1-=2;
                        ++taxi;
                        if(count1 > 0)
                        {
                            if(count1 > 4)
                            {
                                taxi += count1 / 4;
                                if(count1%4 != 0)
                                {
                                    ++taxi;
                                }
                                count1=0;
                            }
                            else if(count1 > 0 && count1 < 4)
                            {
                                ++taxi;
                                count1=0;
                            }
                        }
                        count2=0;
 
                    }
                }
 
                if(count2 == 0)
                {
                     if(count1 > 0)
                        {
                            if(count1 >= 4)
                            {
                                taxi += count1 / 4;
                                if(count1%4 != 0)
                                {
                                    ++taxi;
                                }
                                count1=0;
                            }
                            else if(count1 > 0 && count1 < 4)
                            {
                                ++taxi;
                                count1=0;
                            }
                        }
 
                }
            }
 
            if(count1==0 && count3==0)
            {
                if(count2>0 && count2 % 2 != 0)
                {
                    if(count2 == 1)
                    {
                        ++taxi;
                        count2=0;
                    }
                    else if(count2 > 1)
                    {
                        taxi = taxi + ((count2-1)/2) + 1;
                        count2=0;
                    }
                }
            }
        }
        cout<<taxi<<endl;
    }
}
 