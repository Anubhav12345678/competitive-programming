import java.util.*;
public class solve{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i1=0;i1<n;i1++){
            
        int[] a1 = new int[5];
        int[] a2 = new int[5];
            a1[0] = sc.nextInt();
            a2[0] = sc.nextInt();
            a1[1] = sc.nextInt();
            a2[1] = sc.nextInt();
            a1[2] = sc.nextInt();
            a2[2] = sc.nextInt();
            a1[3] = sc.nextInt();
            a2[3] = sc.nextInt();
            a1[4] = sc.nextInt();
            a2[4] = sc.nextInt();
            int pos =-1;
            for(int i=0;i<5;i++){
                int cx=0;int cy=0;
                for(int j=0;j<5;j++){
                    if(a1[i] == a1[j]){
                        cx++;
                    }
                    if(a2[i] == a2[j]){
                        cy++;
                    }
                }   
                if( cx==3 && cy == 3){
                    pos = i;
                }
            }int res =0;int res2=0;
            if(pos != -1){
                for(int i = 0;i<5;i++){
                    if(a1[i] == a1[pos]+1){
                        res++;
                    }
                    else if(a1[i] == a1[pos]-1){
                        res++;
                    }
                    else if(a2[i] == a2[pos]-1 || a2[i] == a2[pos]-2){
                        res++;
                    }
                    else if(a2[i] == a2[pos]+1 || a2[i] == a2[pos]+2){
                        res++;
                    }
                }
                for(int i = 0;i<5;i++){
                    if(a2[i] == a2[pos]+1){
                        res2++;
                    }
                    else if(a2[i] == a2[pos]-1){
                        res2++;
                    }
                    else if(a1[i] == a1[pos]-1 || a1[i] == a1[pos]-2){
                        res2++;
                    }
                    else if(a1[i] == a1[pos]+1 || a1[i] == a1[pos]+2){
                        res2++;
                    }
                }
                
            }
            if(res == 4 || res2 == 4){
                System.out.println("Yes");
            }
            else{
                System.out.println("No");
            }
        }
    }
}