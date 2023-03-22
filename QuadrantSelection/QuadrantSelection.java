import java.util.*;

public class QuadrantSelection{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);

    Integer x = scan.nextInt();
    Integer y = scan.nextInt();
    if(x > 0 && y > 0){
        System.out.println("1");
    }
    else if(x > 0 && y < 0){
        System.out.println("4");
    }
    else if(x < 0 && y > 0){
        System.out.println("2");
    }
    else if(x < 0 && y < 0){
        System.out.println("3");
    }
  }
}
