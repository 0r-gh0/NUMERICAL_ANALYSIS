#include<stdio.h>
float deriV(float x, float y)
{
	return((x - y)/(x + y));
}
float RK(float x0, float y0, float x, float h)
{
	int n = (int)((x - x0) / h);

	float k1, k2, k3, k4, k5;

	float y = y0;
	for (int i=1; i<=n; i++)
	{
		k1 = h*deriV(x0, y);
		k2 = h*deriV(x0 + 0.5*h, y + 0.5*k1);
		k3 = h*deriV(x0 + 0.5*h, y + 0.5*k2);
		k4 = h*deriV(x0 + h, y + k3);

		y = y + (1.0/6.0)*(k1 + 2*k2 + 2*k3 + k4);;

		x0 = x0 + h;
	}

	return y;
}

int main()
{
	float x0 , y , x , h;
	printf("Please enter the Values of x0 , y , x , h : \n");
	scanf("%f %f %f %f",&x0,&y,&x,&h);
	printf("\nThe value of y at x is : %f",RK(x0, y, x, h));
	return 0;
}
