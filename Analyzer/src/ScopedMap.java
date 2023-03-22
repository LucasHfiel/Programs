/** A ScopedMap is similar to a Map, but with nested scopes. */
import java.util.HashMap;
import java.util.Map;
public class ScopedMap<K,V> {

	private Map<Integer, Map<K,V>> map = new HashMap<Integer, Map<K,V>>();
	private int currentLevel; // Key for the map
	
    /** makes a ScopedMap that maps no keys to values and is set to the global scope (nesting level 0) */
    public ScopedMap(){
    	currentLevel = 0;
    	HashMap<K,V> newMap = new HashMap<K,V>();
    	map.put(currentLevel, newMap);
    }

    /** sets the ScopedMap to a new scope nested inside the previous one;
        the nesting level increases by one */
    public void enterScope(){
        currentLevel++;
        map.put(currentLevel, new HashMap<K,V>());
    }

    /** exits from the current scope back to the containing one;
        the nesting level, which must have been positive, decreases by one */
    public void exitScope(){
        map.remove(currentLevel);
        currentLevel--;
    }

    /** puts the key/value pair in at the current scope;
        if the key is already in at the current nesting level,
        the new value replaces the old one;
        neither the key nor the value may be null */
    public void put(K key, V value) {
    	Map<K,V> input = map.get(currentLevel);
    	input.put(key, value);
    	map.put(currentLevel, input);
    }

    /** gets the value corresponding to the key, at the innermost scope for which there is one;
        if there is none, returns null */
    public V get(K key) {
    	Integer checker = currentLevel;
        while(checker >= 0) {
        	Map<K,V> current = map.get(checker); 
        	if((current.get(key)) != null) {
        		return current.get(key);
        	}
        	checker--;
        }
    	return null;
    }
    
    /** returns true if the key has a value at the current scope (ignoring surrounding ones) */
    public boolean isLocal(K key) {
    	Map<K,V> current = map.get(currentLevel);
        if(current.get(key) != null) {
        	return true;
        }
    	return false;
    }
    
    /** returns the current nesting level */
    public int getNestingLevel() {
    	return currentLevel;
    }
}
