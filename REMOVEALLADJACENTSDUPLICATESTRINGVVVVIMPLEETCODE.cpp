class Solution {
public:
    string removeDuplicates(string S) {
        int n  =S.size();
        int i,j,k,l;
        if(n==0)
            return "";
        if(n==1)
            return S;
        if(n==2)
        {
            if(S[0]==S[1])
                return "";
            else
                return S;
        }
        while(1)
        {
        for(i=0;i<S.size()-1;i++)
            if(S[i]==S[i+1]) break;
            if(i==S.size()-1)
                break;
        if(i==S.size()-2)
            return S.substr(0,S.size()-2);
            if(i==S.size()-1)
                break;
            // cout<<"b4 "<<S<<endl;
            if(S.size()==2)
                {
                    if(S[0]==S[1])
                        return "";
                    else
                        return S;
                }
            string cpy=S;
            
          S = S.substr(0,i)+S.substr(i+2);
            if(cpy==S)
                return S;
            if(S.size()==2)
                {
                    if(S[0]==S[1])
                        return "";
                    else
                        return S;
                }
            // cout<<"af "<<S<<endl;
        }
        return S;
        // return S.substr(0,i)+removeDuplicates();
    }
};