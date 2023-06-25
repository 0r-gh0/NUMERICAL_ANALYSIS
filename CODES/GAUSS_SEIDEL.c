#include<stdio.h>
#include<math.h>
int main()
{
	int i, j, k, n, MAX_ITER;
    double x_n[20], x_n1[20], A[20][20], eps, sum, norm;
    printf("PLEASE ENTER THE NUMBER OF EQUATIONS :  \t");
    scanf("%d",&n);
    printf("\nPLEASE ENTER THE ERROR OF TOLERENCE :  \t");
    scanf("%lf",&eps);
    printf("\nPLEASE ENTER MAXIMUM ITERATIONS :  \t");
    scanf("%d",&MAX_ITER);
    
    printf("\nPLEASE ENTER THE ELEMENTS OF THE MATRIX ROW-WISE : \n\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n+1; j++)
        {
            printf("PLEASE ENTER THE ELEMENT OF ROW %d AND COLUMN %d : ", i, j);
            scanf("%lf",&A[i][j]);
        }
        printf("\n");
    }
    printf("SO THE AUGUMENTED MATRIX BECOMES :  \n\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n+1; j++)
        {
            printf("%lf\t",A[i][j]);
        }
        printf("\n");
    }
    printf("\nPLEASE ENTER THE INITIAL VALUES :  \n\n");
   	for(j = 1; j <= n; j++)
    {
        printf("x[%d] = \t",j);
        scanf("%lf",&x_n[j]);
	}
	
	for(i = 1; i <= MAX_ITER; i++)
	{
		for(j = 1; j <= n; j++)
    	{
    		x_n1[j] = x_n[j]; // Copying the elements from succeding to precceding, matrix.
		}
		printf("\nITERATION : %d\n\n",i);
		for(j = 1; j <= n; j++)
		{
			sum = 0, norm = 0;
			printf("-------------------------------------------------------------------------\n");
			for(k = 1; k <= n; k++)
			{
				sum += A[j][k]*x_n[k];
			}
			x_n[j] = ( (double) 1/A[j][j] )*( A[j][n+1] + A[j][j]*x_n[j] - sum );
			printf("|| x_%d[%d] = %lf || \t--------->\t || x_%d[%d] = %lf ||\n", i-1, j, x_n1[j], i, j, x_n[j]);
			norm += pow(x_n[j] - x_n1[j],2); //DONE, to avoid initialising extra variables
			printf("-------------------------------------------------------------------------\n");
		}
		norm = (double) sqrt(norm);
		printf("\nSO, || X_%d - X_%d || = %lf\n", i - 1, i, norm);
		if(norm < eps)
		{
			printf("\nERROR  OF TOLERENCE REACHED, NO FURTHER ITERATIONS ARE NEEDED.\n");
			break;
		}
		printf("\nSINCE NORM IS GREATER THAN, THE ERROR OF TOLERENCE, CONTINUING TO THE NEXT STEP :: \n");
	}
	printf("\n:: ITERATIONS TERMINATED ::\n\nSO THE SOLUTION IS :: \n\n");
   	for(j = 1; j <= n; j++)
    {
        printf("x[%d] = %lf\n", j, x_n[j]);
	}
	return 0;
}