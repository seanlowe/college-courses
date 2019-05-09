package cold.puter_science;

import java.util.Scanner;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 * @author sean
 */
public class ColdPuter_scienceTest {
    @Test
    public void testSolver() {
        //System.out.println("solver");
        int length = 0;
        Scanner sc = null;
        int expResult = 0;
        int result = ColdPuter_science.solver(length, sc); // if there is no input, it should do nothing
        assertEquals(expResult, result);
    }

    @Test
    public void testPrint_answer() {
        //System.out.println("print_answer");
        int x = 0;
        Boolean failed = false;
        try {
            ColdPuter_science.print_answer(x);
        } catch (Exception e) {
            failed = true;
            fail("Should not have thrown an exception;");
        }
        if (!failed) { assertEquals(0, 0); /* no exceptions were thrown! Yay! */ }
        
    }
    
}
