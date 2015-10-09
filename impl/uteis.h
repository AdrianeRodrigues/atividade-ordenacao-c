#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

#define MAX 1066111//100%
#define MIN 10611//1%

typedef struct{
    double cpfdocandidato,cpfcnpjdofornecedor,numerocandidato,sequencialcandidato;
    char dataehora[50],uf[10],numeroue[35],municipio[45],siglapartido[30],cargo[45],nomecandidato[70],
	tipododocumento[50],numerododocumento[30],nomedofornecedor[100],nomereceitafornecedor[100],
    codsetoreconomicofornecedor[50],setoreconomicofornecedor[70],datadadespesa[31],valordespesa[40],tipodespesa[200],descricaodadespesa[350];

}campos;

typedef struct{
	char cpfcandidatoC[30],cnpjfornecedorC[30],numerocandidatoC[30],sequencialcandidatoC[50];
}CHAR;

int count_trocas_sort=0;