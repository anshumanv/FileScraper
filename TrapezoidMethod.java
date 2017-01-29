/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package ds;

/**
 *
 * @author Natsu  Dragneel
 */
import java.util.Scanner;
public class TrapezoidMethod {

    public static void main(String  args[]){
        Scanner sc  = new Scanner(System.in);
        int deg,x;

        System.out.println("Input Degree");
        deg = sc.nextInt();
                                                                        //  input degree of fn
        int[] fn = new int[deg+1];
        System.out.println("Input " + (deg+1) + " Coeffecients");       // Making Array of Coeffecients for fn
        for(x = 0; x<fn.length; x++ ){
            fn[x] = sc.nextInt();
        }

        System.out.println("Input lower limit and upper limit of integration");
        double a = sc.nextDouble();
        double b = sc.nextDouble();

        System.out.println("Input no of partitions");
        int n = sc.nextInt();

        double h = (b-a)/n;

        double temp=0,y=a;
        while(y<=b){
            //boundary cases
        if(n==0)temp+=fvalue(fn,a);
        else if(n==fn.length)temp+=fvalue(fn,b);

        else{
                temp+=2*(fvalue(fn,y));
            }
        
        System.out.printf("y is %f  fvalue at %f is  %f and temp = %f\n",y,y,fvalue(fn,y),temp);
        y+=h;
        n--;
        }
         double area = Math.abs(temp*(h/2));
         System.out.printf("\n\nArea bounded by function from %f to %f is %f", a,b,area);
    }

    public static double fvalue(int[] fun,  double a){
        int i;
        double fv=0;
        for(i = 0; i<fun.length; i++){
            fv += fun[i]*Math.pow(a,fun.length-1-i);
        }
        return fv;                  // returning function value at no. a
    }

    //  printing array
    public static void printArray(int[] a){
        for(int i = 0;i<a.length;i++)
            System.out.printf("%d ", a[i]);
    }


}
