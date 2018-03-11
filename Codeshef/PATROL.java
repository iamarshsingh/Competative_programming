import java.util.Scanner;
class Try {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t=scan.nextInt();
        while((t--)>0){
            double u,v,x,time;
            u=scan.nextDouble();
            v=scan.nextDouble();
            x=scan.nextDouble();
            time=(x/(u+v));
            System.out.println(time);
        }
        
    }
    
} 
