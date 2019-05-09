package cold.puter_science;

import java.util.*;

/**
 * @author sean
 */
public class ColdPuter_science {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c = Integer.parseInt(sc.next());
        int x = solver(c, sc);
        print_answer(x);
    }
    
    public static int solver(int length, Scanner sc) {
        int x = 0;
        for (int i = 0; i < length; i++) {
            if (Integer.parseInt(sc.next()) < 0) {
                x++;
            }
        }
        return x;
    }
    
    public static void print_answer(int x) {
        System.out.println(x);
    }
}