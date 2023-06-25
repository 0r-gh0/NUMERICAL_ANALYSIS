#include <stdio.h>
#include <math.h>

void main()
{   
    int n;
    printf("Please enter the No. of points: ");
    scanf("%d", &n);

    float x[n+1], y[n+1];
    printf("Enter the x - y values:\n");
    for (int i = 1; i <= n; i++)
    {
        scanf("%f %f", &x[i], &y[i]);
    }

    // A matrix (Augmented Matrix - A | b )
    float a[4][5] = {0};
    
    for (int i = 1; i <= n; i++)
    {
        a[1][1] += 1;
        a[1][2] += x[i];
        a[1][3] += pow(x[i], 2);

        a[2][3] += pow(x[i], 3);
        a[3][3] += pow(x[i], 4);

        a[1][4] += y[i];
        a[2][4] += x[i] * y[i];
        a[3][4] += pow(x[i], 2) * y[i];
    }

    a[2][1] = a[1][2]; // Symmetric Matrix

    a[2][2] = a[1][3];
    a[3][1] = a[1][3];

    a[3][2] = a[2][3];


    // GAUSS ELIMINATION METHOD
    for (int i = 1; i <= 2; i++)
    {
        for (int r = (i + 1) ; r <= 3; r++)
        {
            float multiplier = a[r][i] / a[i][i];
            for (int c = 1; c <= 4; c++)
            {
                a[r][c] -= multiplier * a[i][c];
            }
        }
    }

    // Backward Substitution
    float solution[4];
    for (int r = 3; r >= 1; r--)
    {
        float sum = 0;
        for (int c = 3; c > r; c--)
        {
            sum += solution[c] * a[r][c];
        }
        solution[r] = (a[r][4] - sum) / a[r][r];
    }

    // printing the results
    printf("Quadratic Equation, y = a + bx + c*x^2 \n");
    printf("a = %f, b = %f, c = %f", solution[1], solution[2], solution[3]);
    
}