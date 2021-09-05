#include <stdio.h>
#include <stdlib.h>

int main(){
    
    /* Ponteiro para o vetor que ira ser alocado */
    int *v; 
    
    /* Tamanho do vetor a ser alocado */
    int tamanho_vetor; 
    
    /* Variavel de controle dos loops */
    int i; 
    
    /* Variavel que ira conter o valor temporario da posicao do vetor */
    int valor;
    
    /* Variavel que ira conter o elemento a ser pesquisado no vetor */
    int pesquisa;
    
    /* Variavel de controle de pesquisa, identifica se o elemento foi encontrado */
    int encontrado = 1;
    
    /* Variaveis de controle do vetor durante a pesquisa binaria */
    int inicio, meio, fim;
    
    /* Escreve uma mensagem pedindo o tamanho do vetor */
    printf("Digite um tamanho para o vetor: ");
    
    /* Recebe o tamanho do vetor */
    scanf("%d", &tamanho_vetor);
    
    /* Aloca o espaco de memoria do vetor */
    v = (int *) malloc(tamanho_vetor * sizeof(int));
    
    /* Verifica se houve erro na alocacao de memoria */
    if (v == NULL)
    {
       
       /* Exibe a mensagem de erro */
       printf("Problema ao alocar vetor!");
       return(1);      
       
    }
    else
    {
       
        /* Alimentacao do vetor */ 
        for (i = 0; i < tamanho_vetor; i++)
        {
            printf("Digite a posicao %d do vetor: ", i);
            scanf("%d", &valor);
            v[i] = valor;
        }
        
        /* Recebe o valor a ser pesquisado no vetor */
        printf("Digite o elemento que deseja pesquisa no vetor: ");
        scanf("%d", &pesquisa);
        
        /* Define o inicio e o fim do vetor. (Fim do vetor: seu_tamanho - 1 */
        inicio = 0;
        fim = tamanho_vetor - 1;
        
        /* Loop que ira realizar a pesquisa binaria */
        while (inicio <= fim)
        {
              
              /* Obtem o meio do vetor */
              meio = (inicio + fim) / 2;
              
              /* Verifica se o elemento foi encontrado */
              if (pesquisa == v[meio])
              {
                 encontrado = 0;
                 break;
              }
              
              /**
              * Se a pesquisa for menor que o meio do vetor, 
              * entao o fim do vetor sera o meio atual -1
              */
              else if (pesquisa < v[meio])
              {
                 fim = meio - 1;
                 continue;
              }
              
              /**
              * Se a pesquisa for maior que o meio do vetor, entao a pesquisa
              * comecara a partir do meio atual atual do vetor 
              */
              else if(pesquisa > v[meio])
              {
                 inicio = meio + 1;
                 continue;
              }
              
              /**
              * Caso nada seja encontrado, define o controle_pesquisa = 1
              */
              else
              {
                 encontrado = 1;
                 break;
              }
              
        }
        
        /**
        * Verifica a variavel que indica se o elemento foi encontrado ou nao.
        * Se for 0, o elemento foi encontrado, caso contrario, o elemento nao foi
        * encontrado. Basta entao exibir as mensagens.
        */
        if (encontrado == 0){
           printf("Elemento %d encontrado! Posicao: %d - Valor: %d", pesquisa, meio, v[meio]);                      
        } else {
           printf("Elemento %d nao encontrado!", pesquisa);
        }

        return (0);
        
    }
    
}
