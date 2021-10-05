#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int menu_jogo(int *dif){
    int n, op[3] = {3,4,4};
    
    do{ system("clear");
        printf("Escolha um nível de dificuldade:\n");
        printf("(1)Fácil\n(2)Díficil\n(3)Teste\n");
        scanf("%i", &n);
        setbuf(stdin, NULL);
    }while(n < 1 || n > 3);
    *dif = n;
    return op[n-1];
}

int liberar(int *aposta, int *sorteio, int *qtdacertospc, int *qtdacertospe){
    free(aposta);
    free(sorteio);
    free(qtdacertospc);
    free(qtdacertospe);
}
        
int printela(int *sorteio, int n){
    for(int i = 0; i < n; i++)
        printf("%i", sorteio[i]);
    printf("\n");
}

int *alocar(int n){
    int *senha = (int*) malloc (n * sizeof(int));
    for(int i = 0; i < n; i++)
        senha[i] = 0;
    return senha;
}

void ler_senha(int *aposta, int n){
    for(int i = 0; i < n; i++){
        scanf("%i", &aposta[i]);
        if(aposta[i] >= 0 && aposta[i] <= 9)
            continue;
        else{
            printf("Valor incorreto!");
            --i;
        }
    }
}

void sorteia_valores(int *sorteio, int n){
    srand(time(NULL));
    for(int i = 0 ; i < n ; i++){
        sorteio[i] = rand() % 10;
        for(int j = 0; j < i ; j++){
            if(sorteio[j] == sorteio[i]){
                i--;
                break;
            }
        }
    }
}

void compara_senha(int *senha, int *senhausuario, int *qtdacertospc, int *qtdacertospe, int dificuldade){
    *qtdacertospc = 0;
    *qtdacertospe = 0;
    for(int i = 0; i < dificuldade; i++){
        for(int j = 0; j < dificuldade; j++){
            if(senha[i] == senhausuario[j])
                i == j ? (*qtdacertospc)++:(*qtdacertospe)++;
        }
    }
    printf("%i %i\n", *qtdacertospc, *qtdacertospe);
}

void main(){
    int n, dif, *aposta, *sorteio, *qtdacertospc, *qtdacertospe;

    do{ n = menu_jogo(&dif);
        aposta = alocar(n);
        sorteio = alocar(n);
        qtdacertospc = alocar(1);
        qtdacertospe = alocar(1);
        switch(dif){
            case 1:{    system("clear");
                        int i = 0, j = 1;
                        sorteia_valores(sorteio, n);
                        do{ printf("%i tentativa\n", j);
                            ler_senha(aposta, n);
                            compara_senha(sorteio,aposta,qtdacertospc,qtdacertospe,n);
                            *qtdacertospc == n ? i = 1,printf("Você acertou em %i tentativas!\n", j):j++;
                        }while(i == 0);
            }break;
            case 2:{    system("clear");
                        int i = 0, j = 1;
                        sorteia_valores(sorteio, n);
                        do{ printf("%i tentativa\n", j);
                            ler_senha(aposta, n);
                            compara_senha(sorteio,aposta,qtdacertospc,qtdacertospe,n);
                            *qtdacertospc == n ? i = 1,printf("Você acertou em %i tentativas!\n", j):j++;
                        }while(i == 0);
            }break;
            case 3:{    system("clear");
                        int i = 0, j = 1;
                        sorteia_valores(sorteio, n);
                        printela(sorteio, n);
                        do{ printf("%i tentativa\n", j);
                            ler_senha(aposta, n);
                            compara_senha(sorteio,aposta,qtdacertospc,qtdacertospe,n);
                            *qtdacertospc == n ? i = 1,printf("Você acertou em %i tentativas!\n", j):j++;
                        }while(i == 0);
            }break;
            default:break;
        }
        liberar(aposta,sorteio,qtdacertospc,qtdacertospe);
        printf("Gostaria de jogar novamente amiguinho?\n(1)Sim\n(2)Não\n");
        do{ scanf("%i", &n);
            setbuf(stdin, NULL);
            if(n == 2){
                printf("Até mais!\n");
                return;
            }
        }while(n != 1);
    }while(n == 1);
}
