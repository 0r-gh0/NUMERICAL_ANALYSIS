#include<stdio.h>
#include<math.h>
#include<conio.h>
#define f(x,y) 2 - exp(-4*y) -2*x
int main()
{
 float x0, y0, xn, h, yn, slope;
 int i, n;
 printf("Enter Initial Condition\n");
 printf("x0 = ");
 scanf("%f", &x0);
 printf("y0 = ");
 scanf("%f", &y0);
 printf("Enter the point xn = ");
 scanf("%f", &xn);
 printf("Enter number of steps: ");
 scanf("%d", &n);

 
 h = (xn-x0)/n;

 printf("\nx0\t\ty0\t\tslope\t\tyn\n");
 printf("------------------------------------------------------------------------\n");
 for(i=0; i < n; i++)
 {
  slope = f(x0, y0);
  yn = y0 + h * slope;
  printf("%f\t%f\t%f\t%f\n",x0,y0,slope,yn);
  y0 = yn;
  x0 = x0+h;
 }
 printf("\nValue of y at x = %f is %f",xn, yn);

 getch();
}
