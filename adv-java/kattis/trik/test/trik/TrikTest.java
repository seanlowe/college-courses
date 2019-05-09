package trik;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 * @author sean
 */
public class TrikTest {
    
    public TrikTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of main method, of class Trik.
     */
    @Test
    public void testMain() {
        System.out.println("main");
        String[] args = null;
        Trik.main(args);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }

    /**
     * Test of answer method, of class Trik.
     */
    @Test
    public void testAnswer() {
        System.out.println("answer");
        String str = "";
        Integer cp = null;
        Trik instance = null;
        int expResult = 0;
        int result = instance.answer(str, cp);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        fail("The test case is a prototype.");
    }
    
}
