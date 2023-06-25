#include <stdio.h>
#include <math.h>
float function(float s)
{
	return exp(-s)*(3.2*sin(s)-0.5*cos(s));
}
float bisect(float a, float b, float eps, int i, int n, FILE *fp)
{
	i = i + 1;
	float x = ( a + b )/2.0f;
	fprintf(fp,"Iteration = %d \t:: A = %f \t:: B = %f \t:: Midpoint = %f \t:: F(x) = %f,\n", i, a, b, x, function(x));
	if( fabs(function(x)) >= eps && i < n )
    {
		if( function(a)*function(x) < 0.0 )
    	{
			bisect(a,x,eps,i,n,fp);
    		
		}
		else
		{
			bisect(x,b,eps,i,n,fp);
			
		}
	}
	else
	{
    	fprintf(fp,"\n ITERATIONS = %d \t::\t ROOT = %f \t::\t F(X) = %f ", i, x, function(x));
    	fclose(fp);
	    printf("\nPLEASE SEE FILE 'bisection.txt' FOR RESULTS\n\n");
    	printf("Computation terminated. Please check the output file");
		return 0;
	}
}
int main()
{
	float    a , b , eps ;
    int      i = 0 , n ;
    FILE     *fp;
    fp = fopen("bisection.txt","w");
    printf("Please enter end points of the interval (a,b) :\n");
    scanf("%f %f",&a , &b);
    printf("\nPlease enter the number of maximum iterations :\n");
    scanf("%d",&n);
    printf("\nPlease enter the error of tolerance :\n");
    scanf("%E",&eps);
    fprintf(fp,"A = %f, B = %f, N = %d,", a, b, n);
    fprintf(fp,"EPILON = %E\n\n", eps);
    bisect(a,b,eps,i,n,fp);
}