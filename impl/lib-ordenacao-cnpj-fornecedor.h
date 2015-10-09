void selection_sort_cnpj_fornecedor(campos cp[]){
	int i = 0, j = 0, pos_menor, count_trocas = 0;
	campos cp_aux;
	for (i = 0; i < MIN; i++){
		pos_menor = i;
		for (j=i+1; j < MIN; j++){
			if (cp[j].cpfcnpjdofornecedor < cp[pos_menor].cpfcnpjdofornecedor){
				pos_menor = j;
			}
		}
		cp_aux = cp[i];
		cp[i] = cp[pos_menor];
		cp[pos_menor] = cp_aux;
		count_trocas++;
	}
	printf("Total operação dominante: trocas = %d\n", count_trocas);
}

void bubble_sort_cnpj_fornecedor(campos cp[]){
	int i, j, trocou = 1, count_trocas = 0;
	campos cp_aux;
	for(i = 0; i < MIN && trocou==1; i++){
		trocou = 0;
		for(j = 0; j < (MIN - (i + 1)); j++){
			if (cp[j].cpfcnpjdofornecedor > cp[j+1].cpfcnpjdofornecedor){
				cp_aux = cp[j];
				cp[j] = cp[j+1];
				cp[j+1] = cp_aux;
				trocou = 1;
				count_trocas++;
			}
		}
	}
	printf("Total operação dominante: trocas = %d\n", count_trocas);
}

void insert_sort_cnpj_fornecedor(campos cp[]){
	int i, j, count_trocas = 0;
	campos cp_aux;
	for (i = 1; i < MIN; i++){
		cp_aux = cp[i];
		for (j = (i-1);(j >= 0) && (cp[j].cpfcnpjdofornecedor>cp_aux.cpfcnpjdofornecedor); j--){
			cp[j+1] = cp[j];
		}
		cp[j+1] = cp_aux;
	}
	printf("Total operação dominante: trocas = %d\n", count_trocas);
}

void partition_cnpj_fornecedor(campos cp[], int lb, int ub, int *j){
	int down, up;
	campos cp_aux, temp;
	cp_aux = cp[lb];
	up = ub;
	down = lb;

	while(down < up){
		while(cp[down].cpfcnpjdofornecedor <= cp_aux.cpfcnpjdofornecedor && down < ub){
			down++;
		}
		while(cp[up].cpfcnpjdofornecedor > cp_aux.cpfcnpjdofornecedor){
			up--;
		}
		if (down < up){
			temp = cp[down];
			cp[down] = cp[up];
			cp[up] = temp;
			count_trocas_sort++;
		}
	}
	cp[lb] = cp[up];
	cp[up] = cp_aux;
	*j = up;
}

int quicksort_cnpj_fornecedor(campos cp[], int lb, int ub){
	int j = -1;
    if(lb >= ub)
        return count_trocas_sort;                
    partition_cnpj_fornecedor(cp, lb, ub, &j);      
	quicksort_cnpj_fornecedor(cp, lb, j-1);          
	quicksort_cnpj_fornecedor(cp, j+1, ub);
}

int busca_binaria_cnpj_fornecedor(campos cp[], long chave, int tamanho){
	int inicio, fim, meio, achou;
	campos *achado;
	achou = 0;
	inicio = 0; 
	fim = tamanho - 1;
	meio = (inicio + fim) / 2;
	
	while(inicio <= fim && !achou){
		if( cp[meio].cpfcnpjdofornecedor == chave){
			achou = 1;
		}else{
			if (chave < cp[meio].cpfcnpjdofornecedor){
				fim = meio - 1;
			}else{
				inicio = meio + 1;
			}
			meio = (inicio + fim) / 2;
		}
	}
	if(achou){
		return meio;
	}else
		return -1;
}