#include <stdio.h>
#define V 7
#define INF 9999

/* Função criada para encontrar o vértice com a distância de menor valor,
do conjunto de par de vértices ainda não inclusos nos caminhos menores
*/
int distanciaMin(int dist[], int v_abertos[]){

    //Inicializa para infinito
    int min = INF;
    int indice_min = 0;

    for (int v = 0; v < V; v++){
        if (v_abertos[v] == 0 && dist[v] <= min){
            min = dist[v], indice_min = v;
        }
    }
    return indice_min;
}

/*Função para imprimir o menor caminho da origem até o destino
usando o vetor dos antecessores*/
void imprimeCaminho(int pai[], int j){

    //Caso j seja a origem
    if (pai[j]==-1)
        return;

    imprimeCaminho(pai, pai[j]);

    printf("%d ", j);
}

/* Função para imprimir o vetor das distância e caminho entre
o vértice origem e restantes*/
void imprimeMatriz(int dist[], int n, int pai[]){

    int origem = 0;;
    printf("Vértice\t  \tDistância  \tCaminho");

    for (int i = 0; i < V; i++){
        printf("\n%d -> %d \t\t%d\t\t%d ", origem, i, dist[i], origem);
        imprimeCaminho(pai, i);
    }
}

// Função do dijkstra a partir de um vértice origem e um vértice destino
void dijkstra(int grafo[V][V], int origem, int dest){

    /* vetor de saida, dist[i] terá a menor distância
    entre origem ate i*/
    int dist[V];

    /* v_abertos[i] será verdadeiro se vértice i está incluido no menor caminho
    ou menor distância entre origem e i foi finalizada*/
    int v_abertos[V];

    // Vetor do pai para armazenar o pai de cada vertice visitado
    int pai[V];

    // Inicializa todas distâncias como infinito e v_abertos[] como falso
    for (int i = 0; i < V; i++){
        pai[0] = -1;
        dist[i] = INF;
        v_abertos[i] = 0;
    }

    // Distância do vértice origem a si mesmo é sempre 0
    dist[origem] = 0;

    // Encontra o menor caminho entre todos vértices
    for (int count = 0; count < V-1; count++){
        /*Pega o vértice de distância mínima do conjunto de vértices
           ainda não processados. u é sempre igual a origem na primeira
           iteração.*/
        int u = distanciaMin(dist, v_abertos);

        // Marca o vértice pego como processado
        v_abertos[u] = 1;

        /* Atualiza valor da distancia dos vértices adjacentes do vértice
        pego.*/
        for (int v = 0; v < V; v++)

             /*Atualiza dist[v] somente se não está em v_abertos, existe uma
             aresta de u para v, e o peso total do caminho da origem para v
             através de u é menor que o valor atual de dist[v].*/
            if (!v_abertos[v] && grafo[u][v] && dist[u] + grafo[u][v] < dist[v]){
                pai[v]  = u;
                dist[v] = dist[u] + grafo[u][v];
            }
    }

    //imprime o vetor de distâncias e caminho
    imprimeMatriz(dist, V, pai);
    //imprime o caminho mais curto de A até G
    printf("\nO caminho mais curto de %d->%d é: %d\n",origem,dest,dist[dest]);
}

int main(){

    int grafo[V][V] = {{0, 7, 0, 5, 0, 0, 0}, //a
                       {7, 0, 8, 9, 7, 0, 0}, //b
                       {0, 8, 0, 0, 5, 0, 0}, //c
                       {5, 9, 0, 0, 15, 6, 0}, //d
                       {0, 7, 5, 9, 0, 8, 9}, //e
                       {0, 0, 0, 6, 8, 0, 11}, //f
                       {0, 0, 0, 0, 9, 11, 0}, //g
                      };

    dijkstra(grafo, 0,6);

    return 0;
}
