#include "uteis.h"
#include "lib-ordenacao.h"
#include "lib-ordenacao-seq-candidato.h"
#include "lib-ordenacao-cnpj-fornecedor.h"

void ordenacao_selectsort(campos cp[], FILE *);
void ordenacao_booblesort(campos cp[], FILE *);
void ordenacao_insertsort(campos cp[], FILE *);
void ordenacao_quicksort(campos cp[], FILE *);

int main(int argc, char const *argv[])
{
	FILE *arq, *saida, *analise;
     arq = fopen("DespesasCandidatos.txt","r");
     saida = fopen("saida.txt", "w");
     analise = fopen("../analise-com-um-cento.txt", "w");
    int i,ch;
    int qtn = MAX;

	fseek(arq,393,SEEK_SET);

	campos *cadastros = malloc(sizeof(campos) * qtn);
	CHAR *leitura = malloc(sizeof(CHAR)*qtn);

    printf("lendo arquivo ...\n");
    fseek(arq,393,SEEK_SET);
    for(i=0;i<MAX-1;i++){
        fscanf(arq,"%*c%[^\"]s",cadastros[i].dataehora);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].sequencialcandidatoC);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].uf);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].numeroue);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].municipio);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].siglapartido);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].numerocandidato);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].cargo);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].nomecandidato);
        fscanf(arq,"%*3c%[^\"]s",leitura[i].cpfcandidatoC);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].tipododocumento);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].numerododocumento);
        fscanf(arq,"%*3c%[^\"]s",leitura[i].cnpjfornecedorC);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].nomedofornecedor);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].nomereceitafornecedor);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].codsetoreconomicofornecedor);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].setoreconomicofornecedor);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].datadadespesa);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].valordespesa);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].tipodespesa);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].descricaodadespesa);
        fscanf(arq,"%*2c");
    }
    
    for(i=0;i<MAX-1;i++){
       	cadastros[i].cpfdocandidato = atof(leitura[i].cpfcandidatoC);
       	cadastros[i].cpfcnpjdofornecedor = atof(leitura[i].cnpjfornecedorC);
        cadastros[i].sequencialcandidato = atof(cadastros[i].sequencialcandidatoC);   	
	}	
	free(leitura);
  	printf("Leitura feita com sucesso\n");
    
    //ordenacao_selectsort(cadastros, analise);
    //ordenacao_booblesort(cadastros, analise);
    //ordenacao_insertsort(cadastros,analise);
    ordenacao_quicksort(cadastros, analise);

    printf("salvando ordanacao do arquivo saida.txt\n");
    w_saida(cadastros, saida);
	printf("arquivo saida.txt OK\n");
    
    printf("ENCERRANDO PROGRAMA\n");
	fclose(arq);
    fclose(saida);
    fclose(analise);
    free(cadastros);

    printf("----------------------FIM----------------------\n");
    return 0;
}

void ordenacao_selectsort(campos cp[], FILE *analisar){
    int tempo_inicio, tempo_final;
    //fseek(analisar, 0, SEEK_END);
    printf("iniciando metodo de ordenacao...\n");
    //fprintf(analisar, ".................select sort.....................\n");
    //fprintf(analisar, ".................select sort char.....................\n");
    //fprintf(analisar, ".................select sort sequencial candidato.....................\n");
    fprintf(analisar, ".................select sort cnpj fornecedor.....................\n");
    tempo_inicio = time(NULL);
    //selection_sort(cp);
    //selection_sort_char(cp);
    //selection_sort_seq_candidato(cp);
    selection_sort_cnpj_fornecedor(cp);
    tempo_final = time(NULL);
    fprintf(analisar, "Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    fprintf(analisar, "FIM ORDENACAO\n-----------------------------------------------------------------------------\n\n");
}

void ordenacao_booblesort(campos cp[], FILE *analisar){
    int tempo_inicio, tempo_final;
    //fseek(analisar, 0L, SEEK_END);
    printf("iniciando metodo de ordenacao...\n");
    //fprintf(analisar, ".................booble sort.......................\n");
    //fprintf(analisar, ".................booble sort char.......................\n");
    //fprintf(analisar, ".................booble sort sequencial candidato.......................\n");
    fprintf(analisar, ".................booble sort cnpj fornecedor.......................\n");
    tempo_inicio = time(NULL);
    //bubble_sort(cp);
    //bubble_sort_char(cp);
    //bubble_sort_seq_candidato(cp);
    bubble_sort_cnpj_fornecedor(cp);
    tempo_final = time(NULL);
    fprintf(analisar, "Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    fprintf(analisar, "FIM ORDENACAO\n-----------------------------------------------------------------------------\n\n");
}

void ordenacao_insertsort(campos cp[], FILE *analisar){
    int tempo_inicio, tempo_final;
    printf("iniciando metodo de ordenacao...\n");
    //fprintf(analisar, "..................insert sort.........................\n");
    //fprintf(analisar, "..................insert sort char.........................\n");
    //fprintf(analisar, "..................insert sort sequencial candidato.........................\n");
    fprintf(analisar, "..................insert sort cnpj fornecedor.........................\n");
    tempo_inicio = time(NULL);
    //insert_sort(cp);
    //insert_sort_char(cp);
    //insert_sort_seq_candidato(cp);
    insert_sort_cnpj_fornecedor(cp);
    tempo_final = time(NULL);
    fprintf(analisar, "Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    fprintf(analisar, "FIM ORDENACAO\n-----------------------------------------------------------------------------\n\n");
}

void ordenacao_quicksort(campos cp[], FILE *analisar){
    int tempo_inicio, tempo_final;
    printf("iniciando metodo de ordenacao...\n");
    //fprintf(analisar, "---------------Quick Sort--------------------\n");
    //fprintf(analisar, "---------------Quick Sort char--------------------\n");
    //fprintf(analisar, "---------------Quick Sort sequencial candidato--------------------\n");
    fprintf(analisar, "---------------Quick Sort cnpj fornecedor--------------------\n");
    tempo_inicio = time(NULL);
    //quicksort(cp,0,MAX-1);
    //quicksort_char(cp, 0, MAX-1);
    //quicksort_seq_candidato(cp,0,MAX-1);
    quicksort_cnpj_fornecedor(cp, 0, MAX-1);
    tempo_final = time(NULL);
    fprintf(analisar, "Tempo: %f\n", difftime(tempo_inicio, tempo_final));    
    fprintf(analisar, "FIM ORDENACAO\n-----------------------------------------------------------------------------\n\n");
}