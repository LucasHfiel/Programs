import java.util.*;

public class Datum{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    Integer day = scan.nextInt();
    Integer month = scan.nextInt();

    String[] days = {"Wednesday", "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday"};
    Integer[] months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i < month-1; i++){
      day += months[i];
    }

    System.out.println(days[day%7]);
  }
}
