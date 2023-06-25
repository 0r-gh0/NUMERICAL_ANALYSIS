#include<stdio.h>

int* findAverage(int marks[])
{
    return marks;
}


int main()
{
    float avg;
    int marks[] = {99, 90, 96, 93, 95};
    printf("%d ", findAverage(marks)[1]);
    return 0;
}
