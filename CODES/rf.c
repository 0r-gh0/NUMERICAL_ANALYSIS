#include <stdio.h>
#include <math.h>
double function(double x)
{
	return cos(x) - x*exp(x);
}
double regulaFalsi(double a, double b, double eps, int i, int n, FILE *fp)
{
	i = i + 1;
	double x = (a*function(b) - b*function(a))/ (function(b) - function(a));
	fprintf(fp,"Iteration = %d || A = %f || B = %f || x = %f || F(x) = %f,\n", i, a, b, x, function(x));
	if( fabs(function(x)) >= eps && i < n )
    {
		if( function(a)*function(x) < 0.0 )
    	{
			regulaFalsi(a,x,eps,i,n,fp);
    		
		}
		else
		{
			regulaFalsi(x,b,eps,i,n,fp);
			
		}
	}
	else
	{
    	fprintf(fp,"\n ITERATIONS = %d ||\t ROOT = %f ||\t F(X) = %f ", i, x, function(x));
    	fclose(fp);
	    printf("\nPLEASE SEE FILE 'regulaFalsi.txt' FOR RESULTS\n\n");
    	printf("Computation terminated. Please check the output file");
		return 0;
	}
}
int main()
{
	double    a , b , eps ;
    int      i = 0 , n ;
    FILE     *fp;
    fp = fopen("regulaFalsi.txt","w");
    printf("Please enter end points of the interval (a,b) :\n");
    scanf("%lf %lf",&a , &b);
    printf("\nPlease enter the number of maximum iterations :\n");
    scanf("%d",&n);
    printf("\nPlease enter the error of tolerance :\n");
    scanf("%lf",&eps);
    fprintf(fp,"A = %f, B = %f, N = %d,", a, b, n);
    fprintf(fp,"EPILON = %E\n\n", eps);
    regulaFalsi(a,b,eps,i,n,fp);
}