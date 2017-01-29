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
import java.lang.Math;

public class NR {


    public static void main(String args[]){
        Scanner sc  = new Scanner(System.in);
        int deg,x,ip;
        System.out.println("Input Degree");
        deg = sc.nextInt();                                              //  input degree of fn
        int[] fn = new int[deg+1];                                      // building array of coeffecients
        System.out.println("Input " + (deg+1) + " Coeffecients");       // Making Array of Coeffecients for fn
        for(x = 0; x<fn.length; x++ ){
            fn[x] = sc.nextInt();
        }


        System.out.println("Enter value of x");
        ip = sc.nextInt();
        System.out.printf("\nDerivative at %d is %f\n\n", ip, diff(fn,deg,1));

        double e = 9999999;
        double cur,next = 10,count=0;
        System.out.print("Input initial suppossition:  ");
        cur = sc.nextInt();
        System.out.printf("Function value for %f is %f \n", cur,fvalue(fn,cur));

        while(e > 0.0000001 || count < 2000){
            next = cur - (fvalue(fn,cur)/diff(fn,deg,cur));
            e = next-cur;
            cur = next;
            count++;
            
        }
     System.out.printf("Nearest encountered ROOT is %f\nERROR - %f\n",next,e);
    }

    public static void printPoly(int[] fn){
        for(int i = 0; i<fn.length; i++){
            if(fn[i]!=0&&i!=(fn.length-1)&&fn[i]>0)
                System.out.printf("%dX^%d+",fn[i],(fn.length-1-i));
            else System.out.printf("%d\n",fn[i]);
        }
    }

    public static double diff(int[] function,int degree, double point){
        
        if(function.length==0)return 0;
        int i;
        double x=0;
        int[] diffr = new int[degree];
        for(i = 0; i<diffr.length; i++){
            diffr[i] = function[i]*(function.length-1-i);
            x+=diffr[i];
        }
        
        return fvalue(diffr,point);                 // return differential for function value at double no point
    }

    public static double fvalue(int[] fun,  double a){
        int i;
        double fv=0;
        for(i = 0; i<fun.length; i++){
            fv = fv + fun[i]*Math.pow(a,fun.length-1-i);
        }
        return fv;                  // returning function value at no. a
    }

    //  printing array
    public static void printArray(int[] a){
        for(int i = 0;i<a.length;i++)
            System.out.printf("%d ", a[i]);


    }


}
