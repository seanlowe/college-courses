package easiest2;

import java.util.Scanner;

/**
 * @author sean
 */
public class Easiest2 {    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String N, NM; int N_sum, Ni, NM_sum, M;
        while (sc.hasNext()) {
            M = 11;
            NM_sum = -999; N_sum = 0;
            N = sc.next();
            Ni = Integer.parseInt(N);
            if (Ni == 0) { NM_sum = N_sum; }
            while (NM_sum != N_sum) {
                NM_sum = 0; N_sum = 0;
                for (int i = 0; i < N.length(); i++) { N_sum += Integer.parseInt(String.valueOf(N.charAt(i))); }
                NM = String.valueOf(Ni * M);
                for (int i = 0; i < NM.length(); i++) { NM_sum += Integer.parseInt(String.valueOf(NM.charAt(i))); }
                if (NM_sum != N_sum) { M++; }
                else { System.out.println(M); }
            }
        }
    }
}
