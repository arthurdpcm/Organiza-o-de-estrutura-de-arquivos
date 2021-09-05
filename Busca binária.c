#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *vetor;
    
    int tamanho_vetor; 

    int i; 
    
    int valor;
    
    int pesquisa;

    int encontrado = 1;

    int inicio, meio, fim;
    
    int erro = 1;

    printf("Digite um tamanho para o vetor: ");
    
    scanf("%d", &tamanho_vetor);
    
    vetor = (int *) malloc(tamanho_vetor * sizeof(int));

    if (vetor == NULL)
    {

       printf("Não foi possível alocar o vetor");
       return 1;      
       
    }else{
        printf("Digite a posicao 0 do vetor: ");
        scanf("%d", &valor);
        vetor[0] = valor;
        for (i = 1; i < tamanho_vetor; i++){

          
            printf("Digite a posicao %d do vetor: ", i);
            scanf("%d", &valor);
            vetor[i] = valor;

          if (vetor[i]<vetor[i-1]){
            printf("Tem que ser em ordem crescente para funcionar a busca binária.\n");
            erro = 1;
            break;
          }
          erro = 0;
        }
      if(erro != 1){
        printf("Digite o elemento que deseja pesquisa no vetor: ");
        scanf("%d", &pesquisa);
      }
        inicio = 0;
        fim = tamanho_vetor - 1;
        
        while (inicio <= fim)
        {
              
              meio = (inicio + fim) / 2;

              if (pesquisa == vetor[meio])
              {
                 encontrado = 0;
                 break;
              }
              
              else if (pesquisa < vetor[meio])
              {
                 fim = meio - 1;
                 continue;
              }

              else if(pesquisa > vetor[meio])
              {
                 inicio = meio + 1;
                 continue;
              }
              
              else
              {
                 encontrado = 1;
                 break;
              }
              
        }
        if(erro != 1){
          if (encontrado == 0){
            printf("Elemento %d encontrado na posicao %d do vetor.", pesquisa, meio);                      
          }else {
            printf("Elemento %d nao encontrado!", pesquisa);
          }
        }
    }
  
  return 0;
        
}
    

