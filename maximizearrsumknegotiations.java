// A Java program to maximize array 
// sum after k negations. 
public class MaximizeSum { 

// function to maximize array 
// sum after k negations. 
static void maxSumAfterNegation(int[] a,int k){ 
		
		int minPos = Integer.MAX_VALUE, sum = 0, index = -1; 
		
		for(int i = 0; i < a.length; i++){ 
			
			// Do k negations by removing a minimum element k times 
			if(k < 0){ 
				break; 
			} 
			
			if(a[i] < 0){ 
				a[i]=-a[i]; 
				k--; 
			} 
			
			if(a[i] < minPos && a[i] > -1){ 
				minPos = a[i]; 
				index = i; 
			} 
				// Compute sum of all elements 
			sum+=a[i]; 
		} 
		
		for(int i = k; i > 0; i--){ 
			a[index]=-a[index]; 
		} 
		
		/*for(int i:a){ 
			sum+=i; 
		}*/
		
		sum+=(2*a[index]); 
		
		System.out.print(sum); 
	} 
	
	//Driver code 
	public static void main(String[] args) { 
		// TODO Auto-generated method stub 

		int[] a= {-2, 0, 5, -1, 2} ; 
			MaximizeSum.maxSumAfterNegation(a, 4); 
	
	} 

} 
