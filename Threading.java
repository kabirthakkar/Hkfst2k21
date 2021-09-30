import java.util.*;

class ThreadA extends Thread {
    
    private String name;

    ThreadA(){}

    ThreadA(String obj) {   // overrid. constructor
        obj = name;
    }   

    @Override
    public void run() {
        while (true) {
            System.out.println("Thread A");
            try {
                ThreadA.sleep(1500);
            }
            catch (InterruptedException e) {
                System.out.println("interrupted A");
            }
        }
    }
}

class ThreadB extends Thread {

    @Override
    public void run() {
        while(true) {
            System.out.println("Thread B");
            
            try {
                ThreadB.sleep(1000);
            } catch (InterruptedException e) {
                System.out.println("interrupted B");
            }
        }
    }
}

public class Threading {
    public static void main(String[] args) {
        var a = new ThreadA();
        var b = new ThreadB();

        a.start();
        b.start();

        var sysIn = new Scanner(System.in);
        String obj;

        while ((obj = sysIn.next()) != "x");
        
        sysIn.close();
        if ("x".equals(obj)) {
            a.interrupt();
            b.interrupt();
        }
    }
}
