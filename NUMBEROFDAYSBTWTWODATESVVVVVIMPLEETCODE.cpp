class Solution {
    int x[100]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int get(string date)
    {
        int y=0,m=0,d=0,i,ans=0;
        for(i=0;i<4;i++)y=y*10+date[i]-'0';
        for(i=5;i<7;i++)m=m*10+date[i]-'0';
        for(i=8;i<10;i++)d=d*10+date[i]-'0';
        for(i=0;i<y;i++)if(i%400==0||i%4==0&&i%100)ans+=366;
        else ans+=365;
        if(y%400==0||y%4==0&&y%100)x[2]=29;
        else x[2]=28;
        for(i=1;i<m;i++)ans+=x[i];
        ans+=d;
        return ans;
    }
public:
    int daysBetweenDates(string date1, string date2) {
        return abs(get(date1)-get(date2));
    }
};