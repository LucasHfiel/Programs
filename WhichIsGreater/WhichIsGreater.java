import java.util.*;

public class WhichIsGreater{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);

    int first = scan.nextInt();
    int second = scan.nextInt();
    if(first > second){
      System.out.println("1");
    }
    else{
      System.out.println("0");
    }
    scan.close();
  }
}
