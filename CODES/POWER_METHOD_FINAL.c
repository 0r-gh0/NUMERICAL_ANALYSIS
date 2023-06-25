#include<stdio.h>
#include<math.h>
double Normalize(double a[], int n)
{
	double sum = 0;
	for(int j = 1; j <= n; j++)
    {
        sum += a[j]*a[j];
	}
	return sqrt(sum);
}

double FrobNorm(double a[],double b[], int n)
{
	double sum = 0;
	for(int j = 1; j <= n; j++)
    {
        sum += (a[j] - b[j]) * (a[j] - b[j]) ;
	}
	return sqrt(sum);
}

int main()
{
	int i, j, k, n, MAX_ITER;
    double q_n[20], q_n1[20], q_0[20], A[20][20], temp[20], eps, sum, norm;
    printf("PLEASE ENTER THE NUMBER OF EQUATIONS :  \t");
    scanf("%d",&n);
    printf("\nPLEASE ENTER THE ERROR OF TOLERENCE :  \t");
    scanf("%lf",&eps);
    printf("\nPLEASE ENTER MAXIMUM ITERATIONS :  \t");
    scanf("%d",&MAX_ITER);
    
    printf("\nPLEASE ENTER THE ELEMENTS OF THE MATRIX ROW-WISE : \n\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("PLEASE ENTER THE ELEMENT OF ROW %d AND COLUMN %d : ", i, j);
            scanf("%lf",&A[i][j]);
        }
        printf("\n");
    }
    printf("SO THE MATRIX BECOMES :  \n\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            printf("%lf\t",A[i][j]);
        }
        printf("\n");
    }
    
    printf("\nPLEASE ENTER THE INITIAL VALUES (q_0) :  \n\n");
	for(j = 1; j <= n; j++)
    {
        printf("x[%d] = \t",j);
        scanf("%lf",&q_n1[j]);
	}
	norm = Normalize( q_n1 , n );
	for(j = 1; j <= n; j++)
    {
        q_n[j] = q_n1[j] / (double) norm;
	}
	
	printf("%lf", norm);
	for(j = 1; j <= n; j++)
    {
        printf("x[%d] = %lf\t",j,q_n[j]);
	}
	
	for(i = 1; i <= MAX_ITER; i++)
	{
		for(j = 1; j <= n; j++)
    	{
    		q_n1[j] = q_n[j]; 
		}
		
		for(int k = 1; k <= n; k++)
    	{
			temp[k] = 0; 
    		for(int l = 1; l <= n; l++)
    		{
    			temp[k] += A[k][l] * q_n[l];
			} 
		}
		
		printf("\n\n\n");
		
		for(j = 1; j <= n; j++)
    	{
        	printf("x[%d] = %lf\n",j,temp[j]);
		}
		
		for(j = 1; j <= n; j++)
    	{
    		q_n[j] = temp[k]; 
		}
		
		norm = Normalize( q_n , n );
		
		for(j = 1; j <= n; j++)
    	{
        	q_n[j] = q_n[j] / (double) norm;
		}
		
		printf("\n\n\n");
		
		for(j = 1; j <= n; j++)
    	{
        	printf("x[%d] = %lf\n",j,temp[j]);
		}
		
		
		printf("\n\n%lf \t %lf\n\n", Normalize( q_n , n ),Normalize( q_n1 , n ));
		
		double frob = FrobNorm(q_n,q_n1,n);
		if( frob < eps )
		{
			printf("\nERROR  OF TOLERENCE REACHED, NO FURTHER ITERATIONS ARE NEEDED.\n");
			break;
		}
	}
	
	
	return 0;
	
}
	