#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 8

#pragma pack(1)

typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};
int compara(const void *e1, const void *e2)
{
	return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8);
}

void intercala (char *arq1, char *arq2, int proximo){
        Endereco ea, eb;
        FILE *saida,*a,*b;
        char nomeArquivo [20];

        sprintf(nomeArquivo,"cep_%03d.dat", proximo);
        a = fopen(arq1,"r");
        b = fopen(arq2,"r");
        saida = fopen(nomeArquivo,"w");
        fread(&ea,sizeof(Endereco),1,a);
        fread(&eb,sizeof(Endereco),1,b);

        while(!feof(a) && !feof(b)){

            if(compara(&ea,&eb)<0){
                fwrite(&ea,sizeof(Endereco),1,saida);
                fread(&ea,sizeof(Endereco),1,a);
            }else{
                fwrite(&eb,sizeof(Endereco),1,saida);
                fread(&eb,sizeof(Endereco),1,b);
            }
        }

        while(!feof(a)){
            fwrite(&ea,sizeof(Endereco),1,saida);
            fread(&ea,sizeof(Endereco),1,a);		
        }
        while(!feof(b)){
            fwrite(&eb,sizeof(Endereco),1,saida);
            fread(&eb,sizeof(Endereco),1,b);		
        }
        
        fclose(a);
        remove(arq1);
        fclose(b);
        remove(arq2);
        fclose(saida);
    }

int main(int argc, char**argv){
	FILE *f, *saida;
	Endereco *e;
	long posicao, qtd, divisao;

	f = fopen("cep.dat","r");
	fseek(f,0,SEEK_END);
	posicao = ftell(f);
	qtd = posicao/sizeof(Endereco);
	divisao = qtd/N;
    rewind(f);

    for (int i = 1; i <= N; i++){

        char nomeArquivo[20];
        // Para resolver o impasse de números quebrados
        if(i==N){
            divisao += qtd%N;
        }

        e = (Endereco*) malloc(divisao*sizeof(Endereco));

        
        if(fread(e,sizeof(Endereco),divisao,f) == divisao){
            printf("Lido = OK\n");
        }
        qsort(e,divisao,sizeof(Endereco),compara);
        printf("Ordenado = OK\n");
        sprintf(nomeArquivo,"cep_%03d.dat",i);
        saida = fopen(nomeArquivo,"w");
        fwrite(e,sizeof(Endereco),divisao,saida);
        fclose(saida);
        printf("Escrito = OK\n ----");
        free(e);
    }
	fclose(f);

    // Intercalação
    int atual=1 , proximo= N+1; 
    while (atual != proximo-1){
        char arq1[20], arq2[20];
        sprintf(arq1, "cep_%03d.dat",atual);
        sprintf(arq2, "cep_%03d.dat",atual+1);
        intercala(arq1,arq2,proximo);
        atual += 2;
        proximo += 1;
    }

    // Renomeando

    char arqOrdenado[20];
    sprintf(arqOrdenado, "cep_%03d.dat", proximo-1);
    rename(arqOrdenado, "cep_finalizado.dat");
	return 0;

}

