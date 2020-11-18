#include <bits/stdc++.h>
using namespace std;
int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
	    int n=0,c=0;
	    long int j=0;
	    char s[10000];
	    int h[26]={0};
	    scanf("%s",s);
	    while(s[j]!='\0'){
	    	// cout<<"h["<<s[j]-'a'<<"] = "<<h[s[j]-'a']<<endl;
	        h[s[j]-'a'] = (h[s[j]-'a']+1)%2;
	        // cout<<"h["<<s[j]-'a'<<"] = "<<h[s[j]-'a']<<endl;
	        j++;
	    }
	    for(j=0;j<26;j++){
	        if(h[j]==1){
	            c++;
	        }
	    }
	    // cout<<"c = "<<c<<endl;
	    if(c==2||c==1||c==3){
	        printf("DPS\n");
	    }
	    else{
	        printf("!DPS\n");
	    }
	}
	return 0;
}

