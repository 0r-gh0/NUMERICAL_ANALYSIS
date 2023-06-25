#include<stdio.h>
#include<math.h>
double norm(double a[], int n)
{
	double sum = 0;
	for(int j = 1; j <= n; j++)
    {
        sum += a[j]*a[j];
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
        for(j = 1; j <= n+1; j++)
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
        scanf("%lf",&q_0[j]);
        q_n1[20] = q_0[20]
	}
	// Check
	for(j = 1; j <= n; j++)
    {
        q_n[j] = q_n1[j] / (double) norm(q_n1[j]); //Check
	}
	
	for(i = 1; i <= MAX_ITER; i++)
	{
		for(j = 1; j <= n; j++)
    	{
    		q_n[j] = q_n1[j]; 
		}
		
		for(int k = 1; k <= n; k++)
    	{ 
    		for(int l = 1; l <= n; l++)
    		{
    			temp[l] = a[k][l] * q_n[l];
			} 
		}
		
		double tmp = norm(q_n[l]);
		
		for(int l = 1; l <= n; l++)
    	{
   			q_n[l] = temp[l]; //mightbe wrong check again
		}
		
		for(int l = 1; l <= n; l++)
    	{
        	q_n[l] = q_n[l] / tmp;
		}
		
		
		if()
	}
    
    return 0;
}