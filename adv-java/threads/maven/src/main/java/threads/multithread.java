package threads;

import java.util.logging.*;

public class multithread extends Thread {
    public void run() {
        try {
            System.out.println("Thread " + Thread.currentThread().getId() + " is running.");
        } catch (Exception e) {
            System.out.println("some exception or some shit");
        }
    }

    public void waitTillFinish() {
        try {
            System.out.println("Thread " + Thread.currentThread().getId() + " was joined.");
            join();
        } catch (InterruptedException e) {
            Logger.getLogger(multithread.class.getName()).log(Level.SEVERE, null, e);
        }
    }
}