#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*	Grupo 9:
	Allan R Clementino - RA: 2163187
	Projeto final: Jogo 2048.
*/

// -------------inicialização e atualização--------------
void FirstNumber(int MBase[4][4]); //Adiciona dois números(2 ou 4), em duas posições aleatórias da matriz.
void AddNumber(int MBase[4][4]); //Adiciona um número(2 ou 4).
// ----------------------Movimentos----------------------
// As funções abaixo somam e movem todas os números para a uma dirção da matriz.
void TeclaW(int MBase[4][4]); //Soma e move os números para cima;
void TeclaA(int MBase[4][4]); //Soma e move os números para esquerda;
void TeclaS(int MBase[4][4]); //Soma e move os números para baixo;
void TeclaD(int MBase[4][4]); //Soma e move os números para direita.

void Backup(int MBase[4][4]);	// Armazena a matriz após o último movimento realizado.

void FirstNumber(int MBase[4][4]){	// Adiciona 2 nºs aleatórios, no início do jogo.
	int l = 0, c;
	
	printf("\e[H\e[2J"); // Limpa a tela do terminal.
	srand(time(NULL)); 	// Capta um momento do tempo que é utilizado na randomização.
	
	while(l < 2){  // Quantidade de números a ser gerados.
		MBase[rand()%4][rand()%4] = 2+(rand()%2*2); // Números iniciais em posições aleatórias.
		l++;
	}

	for(l = 0; l < 4; l++){	// Utilizado para imprimir a Matriz na tela.
		printf("|");
    	for(c = 0; c < 4; c++)
    	    printf("%4i|", MBase[l][c]);
    	printf("\n");
    }
}

void AddNumber(int MBase[4][4]){	// Adiciona 1 nº aleatório, depois de cada comando.
	int l = 0, c = 0, i = 0, MAux1[16], MAux2[16];
	
	for(l = 0; l < 4; l++){		// O for percorre a matriz por linha.
    	for(c = 0; c < 4; c++){	// O for percorre a matriz por coluna.
    		if(!MBase[l][c]){	// O if verifica se a posição da matriz é igual a zero.
    			MAux1[i] = l;	// Se a verificação é verdadeira a matriz auxiliar 1 quarda o valor da linha.
    			MAux2[i] = c;	// o mesmo ocorre com a matriz auxiliar 2, ela armazena o valor da coluna.
    			i++;
			}
   	}
   }

	srand(time(NULL)); 
	i = rand()%i; // randomiza um valor de 0 a i-1, que sera as posições dos vetores MAux1 e MAux2, uma posição onde o valor é zero.
	MBase[MAux1[i]][MAux2[i]] = 2+(rand()%2*2); // Adiciona um número randomico 2 ou 4, na posição determinada.

	for(l = 0; l < 4; l++){ // Utilizado para imprimir a Matriz na tela.
		printf("|");
    	for(c = 0; c < 4; c++)
    	    printf("%4i|", MBase[l][c]);
    	printf("\n");
    }
}

void TeclaW(int MBase[4][4]){ 
	for(int c = 0; c < 4; c++){
		for(int i = 0; i < 4; i++){
			for(int l = i+1; l < 4; l++){
				if(!MBase[l][c])
					continue;
				if(MBase[i][c] != MBase[l][c])
					break;
				MBase[i][c] *= 2;
				MBase[l][c] = 0;
				break;
			}
		}
		
		for(int i = 0; i < 3; i++){
			for(int l = 0; l < 3; l++){
				if(!MBase[l][c]){
					MBase[l][c] = MBase[l+1][c];
					MBase[l+1][c] = 0;
				}
			}
		}
	}
	AddNumber(MBase);
}

void TeclaA(int MBase[4][4]){ //Joga tudo para a esquerda.
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

void TeclaS(int MBase[4][4]){ //Joga tudo para baixo.
	for(int c = 0; c < 4; c++){
		for(int i = 3; i > 0; i--){
			for(int l = i-1; l >= 0; l--){
				if(!MBase[l][c])
					continue;
				if(MBase[i][c] != MBase[l][c])
					break;
				MBase[i][c] *= 2;
				MBase[l][c] = 0;
				break;
			}
		}
		
		for(int i = 0; i < 4; i++){
			for(int l = 3; l > 0; l--){
				if(!MBase[l][c]){
					MBase[l][c] = MBase[l-1][c];
					MBase[l-1][c] = 0;
				}
			}
		}
	}
	AddNumber(MBase);
}

void TeclaD(int MBase[4][4]){ //Joga tudo para a direita.
	for(int l = 0; l < 4; l++){
		for(int i = 3; i > 0; i--){
			for(int c = i-1; c >= 0; c--){
				if(!MBase[l][c])
					continue;
				if(MBase[l][i] != MBase[l][c])
					break;
				MBase[l][i] *= 2;
				MBase[l][c] = 0;
				break;
			}
		}
		
		for(int i = 0; i < 4; i++){
			for(int c = 3; c > 0; c--){
				if(!MBase[l][c]){
					MBase[l][c] = MBase[l][c-1];
					MBase[l][c-1] = 0;
				}
			}
		}
	}
	AddNumber(MBase);
}

void Backup(int MBase[4][4]){	// Armazena a matriz após o último movimento realizado.
	int MBackup[4][4] = {};
	
	for(int l = 0; l < 4; l++){ 	// O for percorre a matriz por linha.
    	for(int c = 0; c < 4; c++){	// O for percorre a matriz por coluna.
    		if(!MBase[l][c]) 	// O if verifica se a posição da matriz é igual a zero.
    			continue;	  	// Se a verificação for verdaeira, pulamos esta etapa do laço.
    		else										// Se a verificação for falsa, então,
    			MBackup[l][c] = MBase[l][c];	// A matriz backup recebe a informação da matriz base.
    	}
   }
}

int main(){
	int MBase[4][4] = {{0,0,0,0},
							 {0,0,0,0},
							 {0,0,0,0},
							 {0,0,0,0}}, cont = 0;
	char op;

	FirstNumber(MBase);
	setbuf(stdin, NULL);
	
	do{
		scanf("%c", &op);
		switch(op){	case 'w':
						case 'W':{	printf("\e[H\e[2J");
										TeclaW(MBase);
										break;
									}
						case 'a':
						case 'A':{	printf("\e[H\e[2J");
										TeclaA(MBase);
										break;
									}
						case 's':
						case 'S':{	printf("\e[H\e[2J");
										TeclaS(MBase);
										break;
									}
						case 'd':
						case 'D':{	printf("\e[H\e[2J");
										TeclaD(MBase);
										break;
									}
						default: break;
					}
	}while(cont<1);
}
