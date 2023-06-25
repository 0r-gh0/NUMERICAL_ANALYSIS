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
    float x0,xn,h,y[20],x[20],ans_ODD = 0,ans_EVEN = 0;
    fp = fopen("SIMPSON.txt","w");
    fprintf(fp,"::SIMPSON's 1/3rd RULE:: \n\nGIVEN FUNCTION IS sin(x)*x*x*x\n\n");
    printf("\n Please Enter x0, xn and Even number of n:\n\n");
	scanf("%f %f %d", &x0, &xn, &n);
	h = ( xn - x0 ) / (float) n;
	fprintf(fp,"x_0 = %f, x_n = %f, N = %d, h = %f\n\n", x0, xn, n, h);
    printf("\nSO THE DATA POINTS ARE\n");
    for(i=0; i<=n; i++)
    {
        x[i] = x0+i*h;
        y[i] = function(x[i]);
        printf("\n%f %f\n",x[i],y[i]);
        fprintf(fp,"%d. x[%d] = %f, y[%d] = %f\n\n", i+1, i, x[i], i, y[i]);
    }
	for(i = 1; i < n; i++)
    {
        if( i%2 == 1 )
        {
            ans_ODD += y[i];
        }
        else
        {
            ans_EVEN += y[i];
        }
    }
    float ANS = (h/3)*(y[0] + y[n] + 4*ans_ODD + 2*ans_EVEN);
	printf("\nANSWER = %f\n", ANS);
	printf("\nPLEASE CHECK THE SIMPSON.txt FILE FOR DETAILED SOLUTION");
	fprintf(fp,"So, the approximated integral after N = %d iterations is : %f", n, ANS);
	fclose(fp);
    return 0;
} 