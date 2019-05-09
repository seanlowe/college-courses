package trik;

import java.util.Scanner;

/**
 * @author sean
 */
public class Trik {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str; int cp = 1;
        while(sc.hasNext()){
            str = sc.next();
            for (int i = 0; i < str.length(); i++) {
                switch (str.charAt(i)) {
                    case 'A':
                        if (cp == 1) { cp = 2; }
                        else if (cp == 2) { cp = 1; }
                        else if (cp == 3) { cp = 3; }
                       break;
                    case 'B':
                        if (cp == 1) { cp = 1; }
                        else if (cp == 2) { cp = 3; }
                        else if (cp == 3) { cp = 2; }
                        break;
                    case 'C':
                        if (cp == 1) { cp = 3; }
                        else if (cp == 2) { cp = 2; }
                        else if (cp == 3) { cp = 1; }
                        break;
                }
            }
            System.out.println(answer(str, 1));
        }
    }
  
    public static int answer(String str, Integer cp) {
        for (int i = 0; i < str.length(); i++) {
            switch (str.charAt(i)) {
                case 'A':
                    cp = (cp == 1) ? 2 : 1;
                    //if (cp == 1) { cp = 2; } //else if (cp == 2) { cp = 1; }
                    break;
                case 'B':
                    cp = (cp == 2) ? 3 : 2;
                    //if (cp == 2) { cp = 3; }  //else if (cp == 3) { cp = 2; }
                    break;
                case 'C':
                    cp = (cp == 1) ? 3 : 1;
                    //if (cp == 1) { cp = 3; } //else if (cp == 3) { cp = 1; }
                    break;
            }
        }
        return cp;
    }
}