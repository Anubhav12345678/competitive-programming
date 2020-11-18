import java.util.*;
import java.io.*;

public class Solution {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        
        Scanner sc=new Scanner(System.in);
        
        int n=sc.nextInt();
        int m=sc.nextInt();
        
        int[][]A=new int[n][m];
        
        for(int i=0;i<A.length;i++) {
            for(int j=0;j<A[0].length;j++) {
                
                A[i][j]=sc.nextInt();
                
            }
        }
        
        System.out.println(GetAns(n, m, A));

    }
    
    private static int GetAns(int rows, int cols, int[][]A) {
        
        int[][]rowSum=new int[rows][cols];
        int[][]colSum=new int[rows][cols];
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++)
            {
                if(i==0 && j==0)
                {
                    rowSum[i][j]=A[i][j];
                    colSum[i][j]=A[i][j];
                }
                else if(i==0)
                {
                    rowSum[i][j]=rowSum[i][j-1]+A[i][j];
                    colSum[i][j]=A[i][j];
                }
                else if(j==0)
                {
                    rowSum[i][j]=A[i][j];
                    colSum[i][j]=colSum[i-1][j]+A[i][j];
                }
                else
                {
                    rowSum[i][j]=rowSum[i][j-1]+A[i][j];
                    colSum[i][j]=colSum[i-1][j]+A[i][j];
                }
            }
        
        }
        
        int ans=Integer.MIN_VALUE;
        
        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++)
            {
                for(int length=1;i+length-1<rows && j+length-1<cols;length++)
                {
                    if(length==1)
                    {
                        ans=Math.max(ans, A[i][j]);
                        
                    }
                    else
                    {
                        int xOne=i;
                        int xTwo=i+length-1;
                        int yOne=j;
                        int yTwo=j+length-1;
                        
                        int side1=rowSum[xTwo][yTwo]-rowSum[xTwo][yOne];
                        int side2=rowSum[xOne][yTwo]-rowSum[xOne][yOne];
                        
                        int side3=colSum[xTwo][yTwo]-colSum[xOne][yTwo];
                        int side4=colSum[xTwo][yOne]-colSum[xOne][yOne];
                        
                        int t=side1+side2+side3+side4+A[i][j]-A[xTwo][yTwo];
                        
                        ans=Math.max(ans,t);
                        
                    }
                }
            }
        }
        
        if(ans==Integer.MIN_VALUE)
        ans=-1;
        
        return ans;
        
    }

}