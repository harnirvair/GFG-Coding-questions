/******************************************************************************

                            Online Java Compiler.
                Code, Compile, Run and Debug java program online.
Write your code in this editor and press "Run" button to execute it.

*******************************************************************************/

public class Main
{
	public static void main(String[] args) {
	    Printer print = new Printer();
	    Thread t1 = new Thread (new PrintOddEven(20, print, false));
	    Thread t2 = new Thread (new PrintOddEven(10, print, true));
	    t1.start();
	    t2.start();
	}
}
	 class PrintOddEven implements Runnable{
	    private int max;
	    private Printer print;
	    private boolean isEvenNumber;
	    PrintOddEven (int m, Printer print, boolean x){
	        this.max = m;
	        this.print = print;
	        this.isEvenNumber = x;
	    }
	    public void run(){
	        int number = isEvenNumber ? 2 : 1;
	        while(number < max){
	            if (isEvenNumber)
	            print.printEven(number);
	            else
	            print.printOdd(number);
	            number+=2;
	        }
	    }
	}
	
	
	 class Printer {
	    boolean isOdd = false;
	    synchronized void printEven(int num){
	        try { 
	        while(isOdd == false){
	            wait();
	        }
	        }catch(Exception E){
	            
	        }
	        System.out.println("Even :" +  num);
	        isOdd = false;
	        notifyAll();
	        
	    }
	    synchronized void printOdd (int num){
	        try {
	            while(isOdd == true){
	                wait();
	            }
	        }
	        catch(Exception E){}
	        System.out.println("Odd : " + num);
	        isOdd = true;
	        notifyAll();
	        
	    }
	}


