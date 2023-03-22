import java.util.*;

public class GrassSeed{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    Double costOfSeed = scan.nextDouble();
    Double total = 0.0;
    Integer numOfLawns = scan.nextInt();
    for(int i = 0; i < numOfLawns; i++){
      Double width = scan.nextDouble();
      Double length = scan.nextDouble();
      total += (width * length);
    }
    total *= costOfSeed;
    System.out.println(total);
    scan.close();
  }
}
