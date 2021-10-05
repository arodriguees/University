// Programa representa a conjectura de Goldbach, qualquer número par, maior que 2, pode ser escrito como a soma de dois números primos.
// Allan Rodrigues e Gabriela Scaramal

#include <stdio.h>

int main()
{
	int num, a, p, p1, p2, dv1, dv2, flag=0;
	
	for(a=1; a<15 ; a++)
	{
		printf("Informe o valor:\n");
			scanf("%i", &num);
		if(num>2 && num%2 == 0)
		{
			flag=0;
			for(p1=2 ; p1<num && flag==0 ; p1++)
			{
				dv1=0;
				dv2=0;				
				for(p=1 ; p<=p1 ; p++)
				{
					if(p1 % p == 0)
						dv1++;
				}
				if(dv1 == 2)
				{
					p2=num-p1;
					for(p=1 ; p<=p2 ; p++)
					{
						if(p2 % p == 0)
							dv2++;
					}
					if(dv2 == 2)
					{
						printf("%i + %i = %i.\n", p1, p2, num);
						flag=1;
					}
				}
			}
		}
		else
			p--;
	}
}
