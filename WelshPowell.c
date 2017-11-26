//Trabalho feito por Kevin Mitchell Spiller

#include <stdio.h>
#include <string.h>

#define V 11
#define C 5

int grau[V];
int cor[V];
int ordem[V];

void inicializa(){
	int i;
	for(i = 0; i < V; i++){
		grau[i] = 0;
		ordem[i] = 0;
		cor[i] = 0;
	}
}

void sort(){ //ordenação
	int aux;
	for( int i=0; i < V; i++ ){
		for( int j = V - 1; j > i; j-- ){
			if( grau[ordem[j]] > grau[ordem[j-1]] ){
			aux = ordem[j];
			ordem[j] = ordem[j-1];
			ordem[j-1] = aux;
			}
		}
	}
}

void contaOrdem(int grafo [V][V]){//função para contar a ordem dos vertices a serem coloridos
	int i,j;
	inicializa();
	for(i = 0; i < V; i++){
		grau[i] = 0;
	}
	for(i = 0; i < V; i++){
		ordem[i] = i;
	}

	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			if(grafo[i][j] == 1) grau[i] ++;
		}
	}
	sort();
}

void printaWelsh(){
	printf("Vértices ordenados por grau:\n\n");
	for(int i = 0; i < V; i++){
		printf("Grau do V %d: %d - Cor: %d\n", ordem[i], grau[ordem[i]], cor[ordem[i]]);
	}
}

void welshPowell(int grafo [V][V]){
	int i,j,k,l = 0;
	int vcor[C];
	contaOrdem(grafo);
	for(i = 0; i < V; i++){ //percorre a ordem dos vetores
		l = ordem[i];
		memset (vcor,0,sizeof(vcor));
		for(j = 0; j < V; j++){ //percorre as adjacencias
			/*verifica a cor do vizinho
				para saber se pode ou não colori-lo com a mesma cor*/
			if(grafo[l][j] == 1 && cor[j] != 0){
				vcor[cor[j]] = 1;
			}
		}
		k = 1;
		while(cor[l] == 0){
			if(vcor[k] == 0){
				cor[l] = k;
			}
			k++;
		}
	}
	printaWelsh();
}


int main(){
	//matriz de adjacencia do grafo
	int grafo[V][V] = {{0,1,0,0,0,0,0,1,0,0,0},
										 {1,0,0,1,0,0,0,0,0,0,0},
										 {0,0,0,1,0,0,0,0,0,0,0},
										 {0,1,1,0,0,0,0,0,1,0,1},
										 {0,0,0,0,0,1,0,0,0,0,1},
										 {0,0,0,0,1,0,1,0,0,0,0},
										 {0,0,0,0,0,1,0,1,0,0,1},
										 {1,0,0,0,0,0,1,0,1,1,1},
										 {0,0,0,1,0,0,0,1,0,1,0},
										 {0,0,0,0,0,0,0,1,1,0,1},
										 {0,0,0,1,1,0,1,1,0,1,0}};

	welshPowell(grafo);

	return 0;
}
