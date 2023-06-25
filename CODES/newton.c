#include<stdio.h>
#include<math.h>
double func(double x)
{
	return cos(x) - x*exp(x);
}

double derivFunc(double x)
{
	return -(sin(x) + exp(x)*(1+x));
}
float newtonRaphson(double x,int i,int n,double eps,FILE *fp)
{
	double h = func(x) / derivFunc(x);
	if ( fabs(h) >= eps && i < n )
	{
		i = i + 1;
		fprintf(fp,"\nIteration %d || x = %f || f(x) = %f || f'(x) = %f || h = %f\n",i,x,func(x),derivFunc(x),h);
		x = x - h;
		newtonRaphson(x,i,n,eps,fp);
	}
	else
	{
		fprintf(fp,"\nSo,the approximated root after %d iterations is : %f",i , x);
		fclose(fp);
		printf("\nPLEASE SEE FILE 'newton.txt' FOR RESULTS\n\n");
    	printf("Computation terminated. Please check the output file");
		return 0;
	}
}
int main()
{
	FILE *fp;
	double x_0, eps;
	int i = 0 , n ;
	fp = fopen("newton.txt","w");
	printf("Please enter the value of x_0 :\t");
	scanf("%lf",&x_0);
	printf("Please enter the maximum number of iterations :\t");
	scanf("%d",&n);
	printf("Please enter the error of tolerence :\t");
	scanf("%lf",&eps);
	fprintf(fp,"x_0 = %f, N = %d, EPSILON = %f,", x_0, n, eps);
	newtonRaphson(x_0,i,n,eps,fp);
	return 0;
}
