#include<stdio.h>

float ProdutoPorSoma(float a, int b)
{
    float soma = 0;
    for(int i=0; i < b; soma += a, i++);
    return soma;
}

int Fatorial(int n)
{
    int f;
    if(n==0 || n==1)
	return 1;
    else
    {
	for(f = 1; n > 1; n = n - 1)
	    f = f * n;

    return f;
    }
}

void main()
{
    float y, pi = 3.141592;
    scanf("%f", &y);

    y=y*pi/180;
    printf("%f", y);
}
