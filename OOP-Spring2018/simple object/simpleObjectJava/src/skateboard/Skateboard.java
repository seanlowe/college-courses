package skateboard;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author sean
 */


public class Skateboard {
    protected boolean moving;
    protected boolean greased;
    
    public boolean isMoving() {
        if (moving == false) {
            return false;
        } else if (moving == true) {
            return true;
        }
        throw new IllegalStateException();
    }
    
    public boolean isGreased() {
        if (greased == false) {
            return false;
        } else if (greased == true) {
            return true;
        }
        throw new IllegalStateException();
    }
    
    public void grease() {
        greased = true;
    }
    
    public void kickOff() {
        if (isGreased() == true) {
            moving = true;
        } else {
            throw new IllegalArgumentException("Wheels must be greased before board can be ridden.");
        }
    }
    
    public void tailGrind() {
        if (isMoving() == true) {
            moving = false;
        } else {
            throw new IllegalArgumentException("You must be moving to perform a tail grind.");
        }
    }
            
}