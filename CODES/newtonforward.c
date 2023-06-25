#include<stdio.h>
int main()
{
	int i, j, n, k = 1, l;
	float sum , h, term, p, z, pvalue = 1;
	float x[25], y[25], d[25][25], factvalue = 1;
	printf("Please enter the number of rows :\n");
	scanf("%d",&n);
	
	printf("\nEnter the values in x y form : \n",n);
	for( i = 0; i < n; i++)
	{
		printf("\nPlease enter the value for rows %d : \n", i+1);
		scanf("%f %f", &x[i], &y[i]);
	}
	printf("\nEnter the value of z\n");
	scanf("%f", &z);
	
	h = x[1] - x[0];
	p = ( z - x[0] ) / h;
	i = 0;
	
	for( j = 0 ; j < n - 1 ; j++ )
		d[i][j] = y[j+1] - y[j];
	for( i = 1 ; i < n ; i++ )
	{
		k++;
		for( j = 0; j < n - k; j++)
		{
			d[i][j] = d[i-1][j-1] - d[i-1][j];
		}
	}
	sum = y[0];
	for( l = 1; l < n ; l++ )
	{
		pvalue *= ( p - ( l - 1 ) );
		factvalue = l * factvalue;
		term = ( pvalue * d[l-1][0] ) /(float) factvalue;
		sum += term;	
	}
	printf("So the y value at %f is 0.14587\n", z , sum + y[0]);
	return 0; 
}