#include<math.h>
#include<stdio.h>
double fun(double x,double y)
{
    return 2 - exp(-4*x) - 2*y;
}
main()
{
    double a,b,x,y,h,t,k;
    printf("\nEnter x0,y0,h,xn: ");
    scanf("%lf%lf%lf%lf",&a,&b,&h,&t);
    x=a;
    y=b;
    printf("\n  x\t  y\n");
    while(x<=t)
    {
        k=h*fun(x,y);
        y=y+k;
        x=x+h;
        printf("%lf\t%lf\n",x,y);
    }
}