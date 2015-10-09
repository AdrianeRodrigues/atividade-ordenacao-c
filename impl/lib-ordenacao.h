void selection_sort_cpf_candidato(campos cp[]){
	int i=0, j=0, pos_menor,count_trocas = 0;
	campos cp_aux;
        
	for (i = 0; i < MIN; i++){
		pos_menor = i;
		for (j=i+1; j < MIN; j++){
			if (cp[j].cpfdocandidato < cp[pos_menor].cpfdocandidato){
						          
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


void bubble_sort_cpf_candidato(campos cp[]){
	int i, j, trocou = 1,count_trocas = 0;
	campos cp_aux;
	for(i = 0; i < 100 && trocou==1; i++){
		trocou = 0;
		for(j = 0; j <( MIN - (i + 1)); j++){
			if (cp[j].cpfdocandidato > cp[j+1].cpfdocandidato){
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


void insert_sort_cpf_candidato(campos cp[]){
	int i, j, count_trocas = 0;
	campos cp_aux;
        
	for (i = 1; i <MIN; i++){
		cp_aux = cp[i];
		for (j = (i-1);(j >= 0) && (cp[j].cpfdocandidato>cp_aux.cpfdocandidato); j--){
			cp[j+1] = cp[j];
			 count_trocas++;
		}
		cp[j+1] = cp_aux;
		 count_trocas++;	
	}
	printf("Total operação dominante: trocas = %d\n", count_trocas);
}

void partition_cpf_candidato(campos cp[], int lb, int ub, int *j){
	int down, up;
	campos cp_aux, temp;
	cp_aux = cp[lb];
	up = ub;
	down = lb;
	while(down < up){
		while(cp[down].cpfdocandidato <= cp_aux.cpfdocandidato && down < ub){
			down++;
		}
		while(cp[up].cpfdocandidato > cp_aux.cpfdocandidato){
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

int quicksort_cpf_candidato(campos cp[], int lb, int ub){

    int j = -1;
	int i =0;
    if(lb >= ub)
        return count_trocas_sort;                     

    partition_cpf_candidato(cp, lb, ub, &j); 
	quicksort_cpf_candidato(cp, lb, j-1);          
	quicksort_cpf_candidato(cp, j+1, ub);
	       
	
}

int busca_binaria(campos cp[], int chave, int tamanho){
	int inicio, fim, meio, achou;
	campos *achado;
	achou = 0;
	inicio = 0; 
	fim = tamanho - 1;
	meio = (inicio + fim) / 2;
	
	while(inicio <= fim && !achou){
		if( cp[meio].cpfdocandidato == chave){
			achou = 1;
		}else{
			if (chave < cp[meio].cpfdocandidato){
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

void selection_sort_char(campos cp[]){
	int i=0, j=0, pos_menor;
	int count_trocas = 0;
	campos cp_aux;    
	for (i = 0; i < MIN; i++){
		pos_menor = i;
		for (j=i+1; j < MIN; j++){
			if (strcmp(cp[j].tipodespesa,cp[pos_menor].tipodespesa)==(-1)){      
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

void bubble_sort_char(campos cp[]){
	int i, j, trocou = 1;
	campos cp_aux;
	int count_trocas = 0;
	for(i = 0; i < MIN && trocou==1; i++){
		trocou = 0;
		for(j = 0; j <( MIN - (i + 1)); j++){
			if (strcmp(cp[j].tipodespesa,cp[j+1].tipodespesa)==(1)){
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

void insert_sort_char(campos cp[]){
	int i, j;
	campos cp_aux;
	for (i = 1; i <MIN; i++){
		cp_aux = cp[i];
		for (j = (i-1);(j >= 0) &&(strcmp(cp[j].tipodespesa,cp_aux.tipodespesa)==(1)); j--){
			cp[j+1] = cp[j];
		}
		cp[j+1] = cp_aux;
	}
}

void partition_char(campos cp[], int lb, int ub, int *j){
	int down, up;
	campos cp_aux, temp;
	cp_aux = cp[lb];
	up = ub;
	down = lb;
	while(down < up){
		while((strcmp(cp[down].tipodespesa,cp_aux.tipodespesa)<=0) && down < ub){
			down++;
		}
		while(strcmp(cp[up].tipodespesa,cp_aux.tipodespesa)==1){
			up--;
		}
		if (down < up){
			temp = cp[down];
			cp[down] = cp[up];
			cp[up] = temp;
		}
	}
	cp[lb] = cp[up];
	cp[up] = cp_aux;
	*j = up;
}

void quicksort_char(campos cp[], int lb, int ub){

    int j = -1;
	int i =0;
    if(lb >= ub)
        return;                     

    partition_char(cp, lb, ub, &j); 
	quicksort_char(cp, lb, j-1);          
	quicksort_char(cp, j+1, ub);	
}

int busca_binaria_char(campos cp[], char *chave, int tamanho){
	int inicio, fim, meio, achou;
	campos *achado;
	achou = 0;
	inicio=0; 
	fim = tamanho-1;
	meio = (inicio + fim) / 2;
	
	while(inicio <= fim && !achou){
		if(strcmp(cp[meio].tipodespesa,chave) == 1){
			achou = 1;
		}else{
			if (strcmp(cp[meio].tipodespesa,chave) != 1){
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
