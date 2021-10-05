#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*	Grupo 9:
	Allan R Clementino - RA: 2163187
	Mairon L Slusarz   - RA: 2163330
	Matheus M Gomes    - RA: 2165171
	Ruan L M Afinovicz - RA: 1858386
	Projeto final: Jogo 2048.
*/

void FirstNumber(int MBase[4][4]);
void AddNumber(int MBase[4][4]);
void TeclaA(int MBase[4][4]);

void main(){
	int MBase[4][4] = {
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
	};
	char op;

	FirstNumber(MBase);
	setbuf(stdin, NULL);
	scanf("%c", &op);
	switch(op)
		case 'a':
			TeclaA(MBase);
}

void FirstNumber(int MBase[4][4]){					// Adiciona 2 nºs aleatórios, no início do jogo.
	int l = 0, c;
	
	srand(time(NULL));
	
	while(l < 2){
		MBase[rand()%4][rand()%4] = 2+(rand()%2*2);
		l++;
	}
	
	for(l = 0; l < 4; l++){
    	for(c = 0; c < 4; c++)
    	    printf("%i  ", MBase[l][c]);
    	printf("\n");
    }
}

void AddNumber(int MBase[4][4]){						// Adiciona 1 nº aleatório, depois de cada comando.
	int l = 0, c;
	
	srand(time(NULL));
		
	while(l < 1){
		if(MBase[rand()%4][rand()%4] == 0){
			MBase[rand()%4][rand()%4] = 2+(rand()%2*2);
			l++;
		}
	}
	
	for(l = 0; l < 4; l++){
    	for(c = 0; c < 4; c++)
    	    printf("%i  ", MBase[l][c]);
    	printf("\n");
    }
}

void TeclaA(int MBase[4][4]){							// Nesta parte é percorrido o vetor, somando e organizando a direita da tela.
	for(int l = 0; l < 4; l++){
		for(int i = 0; i < 4; i++){
			for(int c = i+1; c < 4; c++){
				if(!MBase[l][c])
					continue;
				if(MBase[l][i] != MBase[l][c])
					break;
				MBase[l][i] *= 2;
				MBase[l][c] = 0;
				break;
			}
		}
		
		for(int i = 0; i < 3; i++){
			for(int c = 0; c < 3; c++){
				if(!MBase[l][c]){
					MBase[l][c] = MBase[l][c+1];
					MBase[l][c+1] = 0;
				}
			}
		}
	}
	AddNumber(MBase);
}
