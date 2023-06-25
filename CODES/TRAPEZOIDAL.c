#include<stdio.h>
#include<math.h>
float function(float x)
{
	return sin(x)*x*x*x; 
}

int main()
{
	FILE *fp;
	int i,n;
    float x0,xn,h,y[20],x[20],ans = 0;
    fp = fopen("TRAPEZOIDAL.txt","w");
    fprintf(fp,"::TRAPEZOIDAL's RULE:: \n\nGIVEN FUNCTION IS sin(x)*x*x*x\n\n");
    printf("\n Please Enter the values of x0, xn and n :\n");
	scanf("%f %f %d", &x0, &xn, &n);
	h = ( xn - x0 ) / (float) n;
    printf("\n Refined value of n and h are: %d %f\n", n, h);
    fprintf(fp,"x_0 = %f, x_n = %f, N = %d, h = %f\n\n", x0, xn, n, h);
    for(i=0; i<=n; i++)
    {
        x[i]=x0+i*h;
        y[i]=function(x[i]);
        printf("\n%f %f\n",x[i],y[i]);
        fprintf(fp,"%d. x[%d] = %f, y[%d] = %f\n\n", i+1, i, x[i], i, y[i]);
    }
    for(i=1; i<n; i++)
    {
    	ans += y[i];
	}
	float ANS = 0.5*h*(y[0] + y[n] + 2*ans);
	printf("\nANSWER = %f\n", ANS);
	printf("\nPLEASE CHECK THE TRAPEZOIDAL.txt FILE FOR DETAILED SOLUTION");
	fprintf(fp,"\nSo,the approximated integral after N = %d iterations is : %f", n, ANS);
	fclose(fp);
    return 0;
} 