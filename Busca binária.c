#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *v;
    
    int tamanho_vetor; 

    int i; 
    
    int valor;
    
    int pesquisa;

    int encontrado = 1;

    int inicio, meio, fim;
    
    printf("Digite um tamanho para o vetor: ");
    
    scanf("%d", &tamanho_vetor);
    
    v = (int *) malloc(tamanho_vetor * sizeof(int));

    if (v == NULL)
    {

       printf("Problema ao alocar vetor!");
       return(1);      
       
    }
    else
    {

        for (i = 0; i < tamanho_vetor; i++)
        {
            printf("Digite a posicao %d do vetor: ", i);
            scanf("%d", &valor);
            v[i] = valor;
        }

        printf("Digite o elemento que deseja pesquisa no vetor: ");
        scanf("%d", &pesquisa);

        inicio = 0;
        fim = tamanho_vetor - 1;
        
        while (inicio <= fim)
        {
              
              meio = (inicio + fim) / 2;

              if (pesquisa == v[meio])
              {
                 encontrado = 0;
                 break;
              }
              
              else if (pesquisa < v[meio])
              {
                 fim = meio - 1;
                 continue;
              }

              else if(pesquisa > v[meio])
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
        
        if (encontrado == 0){
           printf("Elemento %d encontrado! Posicao: %d - Valor: %d", pesquisa, meio, v[meio]);                      
        } else {
           printf("Elemento %d nao encontrado!", pesquisa);
        }

        return (0);
        
    }
    
}
