#include<stdio.h>
#include<math.h>
int main()
{
    int i, j, k, l, n;
    double x[10], A[20][20],c;
    printf("\nPLEASE ENTER THE NUMBER OF EQUATIONS :  ");
    scanf("%d",&n);
    printf("\nPLEASE ENTER THE ELEMENT OF THE MATRIX ROW-WISE : \n\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n+1; j++)
        {
            printf("PLEASE ENTER THE ELEMENT OF ROW %d AND COLUMN %d : ", i, j);
            scanf("%lf",&A[i][j]);
        }
        printf("\n");
    }
    printf("\nSO THE AUGUMENTED MATRIX BECOMES :  \n\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n+1; j++)
        {
            printf("%lf\t",A[i][j]);
        }
        printf("\n");
    }
    
    for(j=1 ; j <= n ; j++) 
    {
		int r, I;
		double largest = 0.0;
		for(r = j; r <= n; r++)
	    {
	        if(fabs(A[r][j]) > largest)
	        {
	        	largest = A[r][j];
				I = r;
			}
	    }
	    if(A[I][j] > 0.0)
	    {
		    for(l = 1; l <= n+1; l++)
		    {
		        double temp = A[I][l];
		        A[I][l] = A[j][l];
		        A[j][l] = temp;
		    }
		}
		else
		{
			for(l = 1; l <= n+1; l++)
		    {
		        double temp = A[I][l];
		        A[I][l] = A[j][l];
		        A[j][l] = -1*temp;
		    }
		}
		printf("\n :: AFTER PARTIAL PIVOTING (SWAPPING THE ROWS) :: \n\n");
		for(int m = 1; m <= n; m++)
	    {
	        for(int a = 1; a <= n+1; a++)
	        {
	            printf("%lf\t",A[m][a]);
	        }
	        printf("\n");
	    }
		
        for(i=1 ; i<=n ; i++)
        {
            if(i>j)
            {
                c = A[i][j] / (double) A[j][j];
                for(k = 1; k <= n+1; k++)
                {
                    A[i][k] = A[i][k] - c*A[j][k];
                }
            }
        }
        printf("\n :: MAKING THE GIVEN MATRIX UPPER TRIANGULAR... :: \n\n");
		for(int m = 1; m <= n; m++)
	    {
	        for(int a = 1; a <= n+1; a++)
	        {
	            printf("%lf\t",A[m][a]);
	        }
	        printf("\n");
	    }
    }
    
    printf("\n :: THE GIVEN MATRIX WAS MADE UPPER TRIANGULAR SUCCESSFULLY !!! :: \n");
    x[n] = A[n][n+1] /(double) A[n][n];
    for(i = n-1; i>=1; i--)
    {
        double sum = 0;
		for( j = i+1; j <= n; j++)
        {
            sum = sum + A[i][j]*x[j];
        }
        x[i] = ( A[i][n+1] - sum ) /(double) A[i][i];
    }
    
	printf("\nNOW APPLYING BACK- SUBSTITUTION METHOD WE GET :: \n");
    for(i = 1; i <= n; i++)
    {
        printf("\nx[%d] = %lf\t", i, x[i]);
    }
    return 0;
}