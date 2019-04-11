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
public class SkateboardTest {
    
    public SkateboardTest() {
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

    @Test
    public void testIsMoving() {
        System.out.println("isMoving");
        Skateboard instance = new Skateboard();
        boolean expResult = false;
        boolean result = instance.isMoving();
        assertEquals(expResult, result);
    }

    @Test
    public void testIsGreased() {
        System.out.println("isGreased");
        Skateboard instance = new Skateboard();
        boolean expResult = false;
        boolean result = instance.isGreased();
        assertEquals(expResult, result);
    }

    @Test
    public void testGrease() {
        System.out.println("grease");
        Skateboard instance = new Skateboard();
        instance.grease();
        boolean expResult = true;
        boolean result = instance.isGreased();
        assertEquals(expResult, result);
    }

    @Test
    public void testKickOff() {
        System.out.println("kickOff");
        Skateboard instance = new Skateboard();
        boolean expResult = false;
        boolean result = true;
        try {
            instance.kickOff();
        } catch (IllegalArgumentException e) {
            result = false;
        }
        assertEquals(expResult, result);
        
    }

    @Test
    public void testTailGrind() {
        System.out.println("tailGrind");
        Skateboard instance = new Skateboard();
        boolean expResult = false;
        boolean result = true;
        try {
            instance.tailGrind();
        } catch (IllegalArgumentException e) {
            result = false;
        }
        assertEquals(expResult, result);
    }
    
}