#include<stdio.h>
int main()
{
    double x[100],y[100],a,s=1,t=1,k=0;
    int n,i,j,d=1;
    printf("Please enter the value of N :");
    scanf("%d",&n);
    printf("\nPlease enter the respective values of the variables x and y: \n");
    for(i=0; i<n; i++)
    {
        scanf ("%lf",&x[i]);
        scanf("%lf",&y[i]);
    }
    printf("\n\n The table you entered is as follows :\n\n");
    for(i=0; i<n; i++)
    {
        printf("%lf\t%lf",x[i],y[i]);
        printf("\n");
    }
        printf(" \nPlease enter the value of the x to find the corresponding value of y :\n");
        scanf("%lf",&a);
        for(i=0; i<n; i++)
        {
            s=1;
            t=1;
            for(j=0; j<n; j++)
            {
                if(j!=i)
                {
                    s=s*(a-x[j]);
                    t=t*(x[i]-x[j]);
                }
            }
            k=k+((s/t)*y[i]);
        }
        printf("\n\nSo, the corresponding value of the variable y is: %f",k);
        return 0;
        
}