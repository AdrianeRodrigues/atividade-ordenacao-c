void selection_sort_seq_candidato(campos cp[]){
	int i = 0, j = 0, pos_menor, count_trocas = 0;
	campos cp_aux;
	
	for (i = 0; i < MAX; i++){
		pos_menor = i;
		for (j=i+1; j < MAX; j++){
			if (cp[j].sequencialcandidato < cp[pos_menor].sequencialcandidato){
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

void bubble_sort_seq_candidato(campos cp[]){
	int i, j, trocou = 1, count_trocas = 0;
	campos cp_aux;
	for(i = 0; i < MAX && trocou == 1; i++){
		trocou = 0;
		for(j = 0; j < (MAX - (i + 1)); j++){
			if (cp[j].sequencialcandidato > cp[j+1].sequencialcandidato){
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

void insert_sort_seq_candidato(campos cp[]){
	int i, j, count_trocas = 0;
	campos cp_aux;
	for (i = 1; i < MAX; i++)
	{
		cp_aux = cp[i];
		for (j = (i - 1);(j >= 0) && (cp[j].sequencialcandidato > cp_aux.sequencialcandidato); j--){
			cp[j+1] = cp[j];
		}
		cp[j+1] = cp_aux;
	}
	printf("Total operação dominante: trocas = %d\n", count_trocas);
}

void partition_seq_candidato(campos cp[], int lb, int ub, int *j){
	int down, up;
	campos cp_aux, temp;
	cp_aux = cp[lb];
	up = ub;
	down = lb;

	while(down < up){
		while(cp[down].sequencialcandidato <= cp_aux.sequencialcandidato && down < ub){
			down++;
		}
		while(cp[up].sequencialcandidato > cp_aux.sequencialcandidato){
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

void quicksort_seq_candidato(campos cp[], int lb, int ub){
	int j = -1;
    if(lb >= ub)
        return;                     
    partition_seq_candidato(cp, lb, ub, &j);      
	quicksort_seq_candidato(cp, lb, j-1);          
	quicksort_seq_candidato(cp, j+1, ub);
}

int busca_binaria_seq_candidato(campos cp[], int chave, int tamanho){
	int inicio, fim, meio, achou;
	campos *achado;
	achou = 0;
	inicio = 0; 
	fim = tamanho - 1;
	meio = (inicio + fim) / 2;
	
	while(inicio <= fim && !achou){
		if( cp[meio].sequencialcandidato == chave){
			achou = 1;
		}else{
			if (chave < cp[meio].sequencialcandidato){
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