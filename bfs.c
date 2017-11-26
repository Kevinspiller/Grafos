#include <stdio.h>
#include <string.h>

#define INF 9999
#define V 21

int ant[V]; //vetor de vertices anteriores
int dist[V]; //vetor de distancias dos vertices

void bfs(int grafo[V][V],int origem, int dest){
	int i, fila[V], inicio = 0, final = 0, j;;
	memset (ant,-1,sizeof(ant));// inicializa vetores anteriores com -1
	memset (dist,0x7f,sizeof(dist));// inicializa distancia dos vetores como infinito

	dist[origem] = 0;//distancia do origem é igual a 0
	fila[final++] = origem;

	while(inicio <= final){
		origem = fila[inicio++];
		for (i = 0; i < V; i++){//percorre afinal de encontrar um vertice vizinho
			if( grafo[origem][i] > 0 && dist[i] > dist[origem] + 1 ){
        /*verifica se existe uma ligação entre os vertices
				verifica se a distancia e menor do que a existente
				*/
				ant[i] = origem;
				dist[i] = dist[origem] + 1; //atualiza distancia
				fila[++final] = i;
			}
		}
	}//printfs para printar a resposta com vertice, v_anterior ,distancia, comprimento e backtracking
  origem = 0;
  dest = 20;

	printf("vertice  v_Anterior  dist");
	for(j = 0; j < V; j++){
    printf("\n%d \t\t%d  \t%d",j,ant[j], dist[j]);
   }

  printf("\n\n");
  printf("\nDistância de %d ate %d é: %d\n", origem, dest, dist[dest]-dist[origem]);
  printf("\n\n");
  printf("Caminho backtracking: ");
  j = dest;
	printf("%d ",j);
	while(j != origem){
		printf("-> %d ",ant[j]);
		j = ant[j];
	}
}

int main(void){

int grafo[V][V] = {
						{0,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0},
						{1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,1,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0},
						{0,0,1,1,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1},
						{1,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0},
						{0,0,0,1,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,1,0,1,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,1},
						{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1},
						{0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1,1,0}
						};

    bfs(grafo,0,20);

return 0;
}
