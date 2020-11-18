#include <stdio.h>

int main() {
	//code
	int t;
	scanf("%d\n",&t);
	
	while(t--){
	    
	    int n;
	    scanf("%d",&n);
	    
	    int a[n];
	    for(int i=0;i<n;i++)
	        scanf("%d",a+i);
	    
	    int i = 0;
	    int j = n - 1;
	    int cnt = 0;
	    while(i<=j){
	        
	        if(a[i] == a[j]){
	            i++;
	            j--;
	        }
	        else{
	            //printf("i=%d j=%d a[i]=%d a[j]=%d cnt=%d\n",i,j,a[i],a[j],cnt);
	            while(i<j){
	                
	                if(a[i] < a[j]){
	                   a[i+1] += a[i];
	                   i++;
	                }
	                else{
	                    a[j-1] += a[j];
	                    j--;   
	                }
	                cnt++;
	                //printf("\ti=%d j=%d a[i]=%d a[j]=%d cnt=%d\n",i,j,a[i],a[j],cnt);
	                if(a[i] == a[j])
	                    break;
	            }
	        }
	    }
	    
	    printf("%d\n",cnt);
	}
	return 0;
}