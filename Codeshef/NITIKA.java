import java.util.Scanner;
 
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner scan = new Scanner(System.in);
        int T;
        T = Integer.parseInt(scan.nextLine().toString());
        String name,ans="";
        int i=1;
        
        
        do{
            name = scan.nextLine();
            String ch;
            int spaces=0, spass=0, strpass=0;
            
          for(int j=0;j<=(name.length()-1);j++){
              ch=name.substring(j,j+1);
              if(ch.equals(" ")){
                  spaces++;
              }
          }
 
          for(int j=0 ; j<=(name.length()-1) ; j++){
              ch=name.substring(j,j+1);
              
              if(spaces==0){
                  if(j==0)ans = ans +ch.toUpperCase();
                  else ans = ans + ch.toLowerCase();
              }
              
              else if(spaces==1){
                  
                  if(j==0){
                      ans = ans +ch.toUpperCase();
                      ans = ans+". ";
                  }
                  
                  if(spass==1){
                      
                      if(strpass!=0){
                          ans = ans+ch.toLowerCase();
                      }
                      
                      if(strpass==0){
                          ans = ans+ch.toUpperCase();
                          strpass++;
                      }
                      
                  }
                  
                  
                  if(ch.equals(" ")){
                      spass=1;
                  }
                  
              }
              
              else if(spaces==2){
                  if(j==0){
                      ans = ans +ch.toUpperCase();
                      ans = ans+". ";
                  }
                  
                  if(spass==1){
                      
                      if(strpass==0){
                          ans = ans +ch.toUpperCase();
                          ans = ans+". ";
                          strpass++;
                      }
                      
                    }
                  
                  if(spass==2){
                      if(strpass>1){
                          ans = ans+ch.toLowerCase();
                      }
                      if(strpass==1){
                          ans = ans+ch.toUpperCase();
                          strpass++;
                      }
                      
                  }
                  
                  if(ch.equals(" ")){
                      spass++;
                  }
                  
              }
              
          }
           ans = ans+"\n";
         
          i++;  
        }
        while(i<=T);
         System.out.println(ans);
	}
}
