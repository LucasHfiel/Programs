import java.util.*;

public class TwoStones{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    Integer input = scan.nextInt();
    if(input % 2 == 0){
      System.out.println("Bob");
    }
    else{
      System.out.println("Alice");
    }
    scan.close();
  }
}
