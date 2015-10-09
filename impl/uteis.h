#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 1066111//100%
//#define MAX 10611//1%

typedef struct{
    long cpfdocandidato,cpfcnpjdofornecedor, sequencialcandidato;
    char dataehora[50],sequencialcandidatoC[50],uf[10],numeroue[35],municipio[45],siglapartido[30],numerocandidato[30],cargo[45],nomecandidato[70],
	tipododocumento[50],numerododocumento[30],nomedofornecedor[100],nomereceitafornecedor[100],
    codsetoreconomicofornecedor[50],setoreconomicofornecedor[70],datadadespesa[31],valordespesa[40],tipodespesa[200],descricaodadespesa[350];

}campos;

typedef struct{
	char cpfcandidatoC[30],cnpjfornecedorC[30];
}CHAR;

void w_saida(campos cadastros[], FILE *s){
	int i;
	 for(i=0;i<MAX-1;i++){
		fprintf(s,"Data e hora: %s\n",cadastros[i].dataehora);
		fprintf(s,"Sequencial Candidato: %s\n",cadastros[i].sequencialcandidatoC);
		fprintf(s,"UF: %s\n",cadastros[i].uf);
		fprintf(s,"Numero UE:%s\n",cadastros[i].numeroue);
		fprintf(s,"Municipio: %s\n",cadastros[i].municipio);
		fprintf(s,"Sigla Partido:%s\n",cadastros[i].siglapartido);
		fprintf(s,"Numero candidato:%s\n",cadastros[i].numerocandidato);
		fprintf(s,"Cargo:%s\n",cadastros[i].cargo);
		fprintf(s,"Nome candidato:%s\n",cadastros[i].nomecandidato);
		fprintf(s,"CPF do candidato:%2.f\n",cadastros[i].cpfdocandidato);
		fprintf(s,"Tipo do documento:%s\n",cadastros[i].tipododocumento);
		fprintf(s,"Numero do documento:%s\n",cadastros[i].numerododocumento);
		fprintf(s,"CPF/CNPJ do fornecedor:%2.f\n",cadastros[i].cpfcnpjdofornecedor);
		fprintf(s,"Nome do fornecedor: %s\n",cadastros[i].nomedofornecedor);
		fprintf(s,"Nome Receita Fornecedor: %s\n",cadastros[i].nomereceitafornecedor);
		fprintf(s,"Cod setor economico fornecedor: %s\n",cadastros[i].codsetoreconomicofornecedor);
		fprintf(s,"Setor economico fornecedor: %s\n",cadastros[i].setoreconomicofornecedor);
		fprintf(s,"Data da despesa: %s\n",cadastros[i].datadadespesa);
		fprintf(s,"Valor despesa:%s\n",cadastros[i].valordespesa);
		fprintf(s,"Tipo despesa:%s\n",cadastros[i].tipodespesa);
		fprintf(s,"Descricao da despesa:%s\n",cadastros[i].descricaodadespesa);
		fprintf(s,"\n");
		fprintf(s,"**************************************************************************************\n");
    }
	
}

void mostra_dados(campos cadastros[],int i){
		printf("Data e hora: %s\n",cadastros[i].dataehora);
		printf("Sequencial Candidato: %s\n",cadastros[i].sequencialcandidatoC);
		printf("UF: %s\n",cadastros[i].uf);
		printf("Numero UE:%s\n",cadastros[i].numeroue);
		printf("Municipio: %s\n",cadastros[i].municipio);
		printf("Sigla Partido:%s\n",cadastros[i].siglapartido);
		printf("Numero candidato:%s\n",cadastros[i].numerocandidato);
		printf("Cargo:%s\n",cadastros[i].cargo);
		printf("Nome candidato:%s\n",cadastros[i].nomecandidato);
		printf("CPF do candidato:%2.f\n",cadastros[i].cpfdocandidato);
		printf("Tipo do documento:%s\n",cadastros[i].tipododocumento);
		printf("Numero do documento:%s\n",cadastros[i].numerododocumento);
		printf("CPF/CNPJ do fornecedor:%2.f\n",cadastros[i].cpfcnpjdofornecedor);
		printf("Nome do fornecedor: %s\n",cadastros[i].nomedofornecedor);
		printf("Nome Receita Fornecedor: %s\n",cadastros[i].nomereceitafornecedor);
		printf("Cod setor economico fornecedor: %s\n",cadastros[i].codsetoreconomicofornecedor);
		printf("Setor economico fornecedor: %s\n",cadastros[i].setoreconomicofornecedor);
		printf("Data da despesa: %s\n",cadastros[i].datadadespesa);
		printf("Valor despesa:%s\n",cadastros[i].valordespesa);
		printf("Tipo despesa:%s\n",cadastros[i].tipodespesa);
		printf("Descricao da despesa:%s\n",cadastros[i].descricaodadespesa);
		printf("\n");
		printf("********************************************************************************************\n");
        printf("\n");
	
}