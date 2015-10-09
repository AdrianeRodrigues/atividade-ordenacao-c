#include "uteis.h"
#include "lib-ordenacao.h"
#include "lib-ordenacao-cnpj-fornecedor.h"
#include "lib-ordenacao-seq-candidato.h"

void leitura_arquivo(FILE *, campos *, CHAR *);
void ordenacao_cpf_candidato(FILE *, campos *, CHAR *);
void ordenacao_fornecedor(FILE *, campos *, CHAR *);
void ordenacao_seq_candidato(FILE *, campos *, CHAR *);
void ordenacao_tipo_despesa(FILE *, campos *, CHAR *);

int main(){
    FILE *arq;
    arq = fopen("DespesasCandidatos.txt","r");

    if(arq ==NULL){
        printf("Nao foi possivel ler o arquivo!\n");
        return -1;
    }
    
    fseek(arq,393,SEEK_SET);

    campos *cadastros = malloc(sizeof(campos) * MIN);
    CHAR *leitura = malloc(sizeof(CHAR)* MIN);
    
    printf("lendo arquivo ...");
    printf("\nDEMONSTRACAO DOS METODOS DE ORDENACAO\n");

   fseek(arq,393,SEEK_SET);

   printf("\n\n\tORDENACAO POR CPF DO CANDICATO!\n");
   ordenacao_cpf_candidato(arq, cadastros, leitura);
   printf("\n\n\tORDENACAO POR CPF/CNPJ DO FORNECEDOR!\n");
   ordenacao_fornecedor(arq, cadastros, leitura);
   printf("\n\n\tORDENACAO POR SEQUENCIAL DO CANDIDATO!\n");
   ordenacao_seq_candidato(arq, cadastros, leitura);
   printf("\n\n\tORDENACAO POR TIPO DE DESPESA!\n");
   ordenacao_tipo_despesa(arq, cadastros, leitura);
    
    printf("\n\nENCERRANDO PROGRAMA...\n\n");
    fclose(arq);
    printf("----------------------FIM----------------------\n");
    free(cadastros);
    free(leitura);
    return 0;
}

void leitura_arquivo(FILE *arq, campos *cadastros, CHAR *leitura){
    int i = 0;
    for(i=0;i<MIN;i++){
        fscanf(arq,"%*c%[^\"]s",cadastros[i].dataehora);
        fscanf(arq,"%*3c%[^\"]s",leitura[i].sequencialcandidatoC);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].uf);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].numeroue);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].municipio);
        fscanf(arq,"%*3c%[^\"]s",cadastros[i].siglapartido);
        fscanf(arq,"%*3c%[^\"]s",leitura[i].numerocandidatoC);
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
    for(i=0;i<MIN;i++){
        cadastros[i].cpfdocandidato = atof(leitura[i].cpfcandidatoC);
        cadastros[i].cpfcnpjdofornecedor = atof(leitura[i].cnpjfornecedorC);
        cadastros[i].numerocandidato= atof(leitura[i].numerocandidatoC);
        cadastros[i].sequencialcandidato = atof(leitura[i].sequencialcandidatoC);   
    }
}

void ordenacao_cpf_candidato(FILE *arq, campos *cadastros, CHAR *leitura){
    int i, count_trocas=0,tempo_inicio=0, tempo_final=0;
    leitura_arquivo(arq, cadastros, leitura);
    printf("Leitura feita com sucesso\n");
    printf("iniciando metodo de ordenacao...\n");
    printf("\n.................SELECT SORT.....................\n");
    tempo_inicio = time(NULL);
    selection_sort_cpf_candidato(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
        
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n.................BUBBLE SORT.......................\n");
    tempo_inicio = time(NULL);
    bubble_sort_cpf_candidato(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n..................INSERT SORT.........................\n");
    insert_sort_cpf_candidato(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n---------------QUICK SORT--------------------\n");
    tempo_inicio = time(NULL);
    count_trocas_sort=quicksort_cpf_candidato(cadastros,0,MIN); 
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));     
    printf("Total operacao dominante: trocas = %d\n",count_trocas_sort);
}

void ordenacao_fornecedor(FILE *arq, campos *cadastros, CHAR *leitura){
    int i, count_trocas=0,tempo_inicio=0, tempo_final=0;

    leitura_arquivo(arq, cadastros, leitura);

    printf("Leitura feita com sucesso\n");
    printf("iniciando metodo de ordenacao...\n");
            
    printf("\n.................SELECT SORT.....................\n");
    tempo_inicio = time(NULL);
    selection_sort_cnpj_fornecedor(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
        
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n.................BUBBLE SORT.......................\n");
    tempo_inicio = time(NULL);
    bubble_sort_cnpj_fornecedor(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
   
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n..................INSERT SORT.........................\n");
    insert_sort_cnpj_fornecedor(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n---------------QUICK SORT--------------------\n");
    tempo_inicio = time(NULL);
    count_trocas_sort = 0;
    count_trocas_sort=quicksort_cnpj_fornecedor(cadastros,0,MIN); /// o meu pc nao roda o quik a 1% ele nao aguenta :(, e eu tmb não consegui contar as trocas sem usar uma varivel global
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));     
    printf("Total operacao dominante: trocas = %d\n",count_trocas_sort);
}

void ordenacao_seq_candidato(FILE *arq, campos *cadastros, CHAR *leitura){
    int i, count_trocas=0,tempo_inicio=0, tempo_final=0;

    leitura_arquivo(arq, cadastros, leitura);
    printf("Leitura feita com sucesso\n");
    printf("iniciando metodo de ordenacao...\n");
            
    printf("\n.................SELECT SORT.....................\n");
    tempo_inicio = time(NULL);
    selection_sort_seq_candidato(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
        
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n.................BUBBLE SORT.......................\n");
    tempo_inicio = time(NULL);
    bubble_sort_seq_candidato(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
   
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n..................INSERT SORT.........................\n");
    insert_sort_seq_candidato(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n---------------QUICK SORT--------------------\n");
    tempo_inicio = time(NULL);
    count_trocas_sort = 0;
    count_trocas_sort=quicksort_seq_candidato(cadastros,0,MIN); /// o meu pc nao roda o quik a 1% ele nao aguenta :(, e eu tmb não consegui contar as trocas sem usar uma varivel global
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));     
    printf("Total operacao dominante: trocas = %d\n",count_trocas_sort);
}

void ordenacao_tipo_despesa(FILE *arq, campos *cadastros, CHAR *leitura){
    int i, count_trocas=0,tempo_inicio=0, tempo_final=0;
    leitura_arquivo(arq, cadastros, leitura);
    printf("Leitura feita com sucesso\n");
    printf("iniciando metodo de ordenacao...\n");
    printf("\n.................SELECT SORT.....................\n");
    tempo_inicio = time(NULL);
    selection_sort_char(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
        
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n.................BUBBLE SORT.......................\n");
    tempo_inicio = time(NULL);
    bubble_sort_char(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n..................INSERT SORT.........................\n");
    insert_sort_char(cadastros);
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));
    
    /*
    //tempo de espera muito grande, não foi possivel obter o resultado
    leitura_arquivo(arq, cadastros, leitura);
    printf("\n---------------QUICK SORT--------------------\n");
    tempo_inicio = time(NULL);
    count_trocas_sort=quicksort_char(cadastros,0,100); 
    tempo_final = time(NULL);
    printf("Tempo: %f\n", difftime(tempo_final, tempo_inicio));     
    printf("Total operacao dominante: trocas = %d\n",count_trocas_sort);*/
}