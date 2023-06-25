#include<stdio.h>
int main()
{
	double a,b,x[20],y[20],sum_x_2 = 0, sum_x = 0, sum_y = 0, sum_xy = 0;
	int n;
	printf("Enter the number of values \n");
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
	{
		printf("Please enter the value of X[%d] and Y[%d]\t",i+1,i+1);
		scanf("%lf\t%lf",&x[i],&y[i]);
		sum_x_2 += x[i]*x[i];
		sum_x += x[i];
		sum_y += y[i];
		sum_xy += x[i]*y[i];
	}
	b = (sum_x_2*sum_y - sum_x*sum_xy)/ (double) (n*sum_x_2 - (sum_x)*(sum_x));
	a = (n*sum_xy - sum_x*sum_y)/ (double) (n*sum_x_2 - (sum_x)*(sum_x));
	printf("\nSo, A = %lf and B = %lf are as follows\n",a,b);
	printf("OR Y = (%lf)*X + (%lf)",a,b);
	return 0;
}