import java.util.Scanner;

public class Analyzer {
	
	/**
	 * Construct an Analyzer.
	 */
	public Analyzer(){
		
	}

	/**
	 * Analyze a block and return it with indentation and scope info.
	 * @param input the block to analyze
	 */
	public String analyze(String input) {
		StringBuilder sb = new StringBuilder("");
		Scanner scan = new Scanner(input);
		ScopedMap<String, Integer> scope = new ScopedMap<String, Integer>();
		Integer declareCounter = 1; // Counts the number of declarations for the declaration number
		Boolean beginPrior = false; // Checks if the statement is a begin statement 
		Boolean isEnd = false; // Checks if an end call has been made (no more begin calls can be made after
							   // because it would be more than 1 block inside a block)
		
		// Checks to make sure the first call is begin
		String item = scan.next();
		Integer level = scope.getNestingLevel();
		if(!(item.equals("begin"))) {
			throw new IllegalArgumentException("You cannot declare anything before a begin statement");
		}
		else {
			scope.enterScope();
			sb.append(item + "\n");
			beginPrior = true;
		}
		
		while(scan.hasNext()) { // Scanner block checking each string
			item = scan.next();
			level = scope.getNestingLevel();
			
			// Creates the spacing before the next section of the string
			if((level == 1 && item.equals("end"))){ // Checks if the item is the last end statement
				scope.exitScope();
				sb.append(item + "\n");
				break;
			}
			else {
				while(level > 0) {
					sb.append("  ");
					level--;
				}
			}
			
			// Checks which function call is being called
			if(item.equals("begin")) {
				if(beginPrior == true) {
					throw new IllegalArgumentException("You cannot have begin statements next to each other");
				}
				else if(isEnd == true) {
					throw new IllegalArgumentException("You cannot have begin statements after end statements");
				}
				scope.enterScope();
				sb.append(item);
				beginPrior = true;
			}
			else if(item.equals("pass")) {
				sb.append(item);
				beginPrior = false;
			}
			else if(item.equals("end")) {
				sb.delete(sb.length() - 3, sb.length() - 1); //deletes white space in front of an end statement
				scope.exitScope();
				sb.append(item);
				beginPrior = false;
				isEnd = true;
			}
			else if(item.equals("declare")) {
				String var = scan.next();
				if(var.equals("use") || var.equals("declare") || var.equals("pass") || var.equals("begin") || var.equals("end")){
					throw new IllegalArgumentException("Cannot call this after a declare statement");
				}
				sb.append(item + " " + var);
				if(scope.isLocal(var) == true) {
					sb.append(" {illegal redeclaration}");
				}
				else{
					scope.put(var, declareCounter);
					sb.append(" {declaration " + declareCounter + "}");
					declareCounter++;
				}
				beginPrior = false;
			}
			else if(item.equals("use")) {
				String var = scan.next(); // Key
				if(var.equals("use") || var.equals("declare") || var.equals("pass") || var.equals("begin") || var.equals("end")){
					throw new IllegalArgumentException("Cannot call this after a use statement");
				}
				Integer value = scope.get(var); // Value -> Declaration Number
				sb.append(item + " " + var);
				if(value == null) {
					sb.append(" {illegal undeclared use}");
				}
				else {
					sb.append(" {references declaration " + scope.get(var) + "}");
				}
				beginPrior = false;
			}
			else { // not a valid input / syntax error
				throw new IllegalArgumentException("Not a valid input");
			}
			sb.append("\n");
		}
		scan.close();
		return sb.toString();
	}

}
