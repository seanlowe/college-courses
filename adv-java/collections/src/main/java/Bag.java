/*
Write an implementation for data structure Bag as a Java class, which is similar to a set,
but it may contain several instances of the same member. For example, {'to', 'be', 'or', 'not', 'to', 'be'}
is a bag of words, which is equal to {'be', 'be', 'not', 'or', 'to', 'to'}
(since order of members is insignificant), but is unequal to {'be', 'not', 'or', 'to'}
(since the number of instances is significant). Adding (removing) a member increases (decreases)
the number of instances in the bag by one.
The member is deleted from the bag when it has no instances . . .
*/

import java.util.ArrayList;

/**
 * @author sslowe
 */

public class Bag {
    private ArrayList<String> contents = new ArrayList<String> ();

    public boolean contains(String entry) {
        for (String e : this.contents) {
            if (entry.equals(e)) return true;
        }
        return false;
    }

    public int countOf(String entry) {
        int count = 0;
        for (String e : this.contents) {
            if (entry.equals(e)) count++;
        }
        return count;
    }

    public int length() {
        int index = 0;
        for (String e : this.contents) {
            index++;
        }
        return index;
    }

    public void add(String entry) {
        contents.add(entry);
    }

    public void add(String[] entries) {
        for (int i = 0; i < entries.length; i++) {
            this.contents.add(entries[i]);
        }
    }

    // delete all occurrences of an entry
    public void delete(String entry) {
        this.contents.removeIf(s -> s.equals(entry));
    }

    // remove first occurrence of an entry
    public void erase(String entry) {
        this.contents.remove(entry);
    }

    // remove everything
    public void clean() {
        this.contents.clear();
    }
}