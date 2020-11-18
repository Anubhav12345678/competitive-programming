class Solution {
public:
    string toHex(int num) {
        
        if(num==0)
            return "0";
         map<int, char> m = {{0,'0'},{1,'1'},{2,'2'},{3,'3'},{4,'4'},{5,'5'},{6,'6'},{7,'7'},{8,'8'},{9,'9'},{10,'a'},{11,'b'},{12,'c'},{13,'d'},{14,'e'},{15,'f'}};
        if(num>0)
        {
            string res="";
            while(num>0)
            {
                res=m[num%16]+res;
                num/=16;
            }
            return res;
        }
        else
        {
            int rd = (num&1);
            num>>=1;
            u_int n = ( long long int) num;
            n<<=1;
            if(rd)
                n+=1;
            string res="";
            while(n>0)
            {
                res=m[n%16]+res;
                n/=16;
            }
            return res;
            
            // int rd = (n&1);
            
        }
    }
};