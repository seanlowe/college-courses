/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package skateboard;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author sean
 */
public class PoweredSkateboardTest extends SkateboardTest {
    
    public PoweredSkateboardTest() {
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
     * Test of isCharged method, of class PoweredSkateboard.
     */
    @Test
    public void testIsCharged() {
        System.out.println("isCharged");
        PoweredSkateboard instance = new PoweredSkateboard();
        boolean expResult = false;
        boolean result = instance.isCharged();
        assertEquals(expResult, result);
    }

    /**
     * Test of charge method, of class PoweredSkateboard.
     */
    @Test
    public void testCharge() {
        System.out.println("charge");
        PoweredSkateboard instance = new PoweredSkateboard();
        instance.charge();
        boolean expResult = true;
        boolean result = instance.isCharged();
        assertEquals(expResult, result);
    }

    /**
     * Test of ActivateBoost method, of class PoweredSkateboard.
     */
    @Test
    public void testActivateBoost() {
        System.out.println("ActivateBoost");
        PoweredSkateboard instance = new PoweredSkateboard();
        instance.ActivateBoost();
        boolean expResult = false;
        boolean result = instance.isMoving();
        assertEquals(expResult, result);
    }
    
}
