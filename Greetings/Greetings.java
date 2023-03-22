import java.util.*;

public class Greetings{
  public static void main(String args[]){
    Scanner scan = new Scanner(System.in);
    String input = scan.nextLine();
    String result = "";
    for(int i = 0; i < input.length(); i++){
      if(input.charAt(i) == 'e'){
        result += "ee";
      }
      else{
        result += input.charAt(i);
      }
    }
    System.out.println(result);
    scan.close();
  }
}
