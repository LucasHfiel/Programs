import java.util.*;

public class TriangleArea{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);

    Integer base = scan.nextInt();
    Integer height = scan.nextInt();
    if((base * height) % 2 == 0){
      Integer area = (base * height) / 2;
      System.out.println(area);
    }
    else{
      Double area = (base * height)/2.0;
      System.out.println(area);
    }
    scan.close();
  }
}
