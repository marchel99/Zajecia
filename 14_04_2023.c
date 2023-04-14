#include <stdio.h>

void swap(int a, int b)
{
int temp;
temp =a;
a=b;
b=temp;


a=b; 
b=a;

}

int main()
{
    int a = 2;
    int b = 3;
    swap(a,b);
    printf("a:%d b:%d",a,b);

    return 0;
}
