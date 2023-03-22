import java.util.*;

public class R2{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    Integer first = scan.nextInt();
    Integer middle = scan.nextInt();
    middle += (middle-first);
    System.out.println(middle);
    scan.close();
  }
}
