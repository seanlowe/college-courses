/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package skateboard;

/**
 *
 * @author sean
 */
public class PoweredSkateboard extends Skateboard{
    protected boolean charged;
    
    public boolean isCharged() {
        if (charged == false) {
            return false;
        } else if (charged == true) {
            return true;
        }
        throw new IllegalStateException();
    }
    
    public void charge() {
        charged = true;
    }
    
    public void ActivateBoost() {
        if (isCharged() == true) {
            moving = true;
        } else {
            moving = false;
        }
    }
}
