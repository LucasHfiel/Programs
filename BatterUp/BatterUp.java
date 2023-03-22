import java.util.*;

public class BatterUp{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    Integer atBats = scan.nextInt();
    Integer success = atBats;
    Integer total = 0;
    for(int i = 0; i < atBats; i++){
      Integer current = scan.nextInt();
      if(current == -1){
        success--;
      }
      else{
        total += current;
      }
    }
    Double slugger = (double) total / success;
    System.out.println(slugger);
    scan.close();
  }
}
