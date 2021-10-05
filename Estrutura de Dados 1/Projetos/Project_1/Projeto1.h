// Funções para a biblioteca

int menu_jogo(int *dif);
/* Recebe como parâmetro uma informação.
 * Um número que determina a dificuldade escolhida.
 */

int liberar(int *aposta, int *sorteio, int *qtdacertospc, int *qtdacertospe);
/* Recebe as variáveis alocadas dinamicamente.
 * Liberar os espaços alocados.
 */

int printela(int *sorteio, int n);
/* Recebe como parâmetro duas informações.
 * 1º a senha sorteada e 2º a quantidade de digitos contidos na senha.
 */

int *alocar(int n);

