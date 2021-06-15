#include "tp1.h"

void preencheMatriz(int** matriz, int tamMatriz, int* origens, int* destinos, int* valores){
    for(int i=0; i<tamMatriz; i++){
            matriz[origens[i]-1][destinos[i]-1] = valores[i];
    }
}

char* obterSubstring(char* string, int inicio, int fim){
    char *newString = (char*) malloc(((fim - inicio) +1) * sizeof(char));
    strncpy(newString, string + inicio, ((fim - inicio) +1));
    return newString;
}

void dividirString(char* string, int* origem, int* destino, int* valor){
    int espacos=0, iDestino=0, iValor=0, fimString=0;
    for(int i=0; i<20; i++){
        if(string[i]==' ' && espacos==0){
            *origem = atoi(obterSubstring(string, 0, i-1));
            iDestino = i+1;
            espacos++;
        }else if(string[i]==' ' && espacos==1){
            *destino = atoi(obterSubstring(string, iDestino, i-1));
            iValor = i+1;
            espacos++;
        }else if(string[i]=='\0' && espacos==2){
            *valor = atoi(obterSubstring(string, iValor, i-1));
        }
    }
}

void imprimeMatriz(int** matriz, int linhas, int colunas){
    for(int i = 0; i<linhas; i++){
        for(int j = 0; j<colunas; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void zeraMatriz(int** matriz, int linhas, int colunas){
    for(int i = 0; i< linhas; i++){
        for(int j = 0; j<colunas; j++){
            matriz[i][j] = 0;
        }
    }
}

int menu(int **matriz, int totalVertices, int totalArestas){
    printf("\nMENU:\n\n1-Sumario\n2-Grau de vertice\n3-Sucessores de vertice\n4-Antecessores de vertice\n0-SAIR\n\nDigite uma opcao: ");
    int opcao, vertice;;
    scanf("%d", &opcao);
    switch (opcao)
    {
    case 1:
        sumario(matriz, totalVertices, totalArestas);
        return 1;
        break;
    case 2:
        printf("\nDigite um vertice: ");
        
        scanf("%d", &vertice);
        grauVertice(matriz, totalVertices, vertice);
        return 1;
        break;
    case 3:
        printf("\nDigite um vertice: ");
        scanf("%d", &vertice);
        sucessores(matriz, totalVertices, vertice);
        return 1;
        break;
    case 4:
        printf("\nDigite um vertice: ");
        scanf("%d", &vertice);
        antecessores(matriz, totalVertices, vertice);
        return 1;
        break;
    case 0:
        printf("\nentrou 0\n");
        return 0;
        break;
    
    default:
        break;
    }
}

void grauVertice(int **matriz, int totalVertices, int vertice){
    if(vertice>totalVertices){ 
        printf("\nVertice invalido\n");
        return;
    }
    int entrada=0, saida=0;
    for(int i=0; i<totalVertices; i++){
        if(matriz[i][vertice-1]!=0) entrada++;
        if(matriz[vertice-1][i]!=0) saida++;
    }
    printf("\nGrau de entrada: %d, Grau de saida: %d\n", entrada, saida);
}

void sumario(int** matriz, int totalVertices, int totalArestas){
    float densidade = (float)totalArestas/(totalVertices*(totalVertices-1));
    printf("Numero de Vertices: %d, Numero de Arestas: %d, Densidade: %.4f", totalVertices, totalArestas, densidade);
}
void sucessores(int **matriz, int totalVertices, int vertice){
    if(vertice>totalVertices){ 
        printf("\nVertice invalido\n");
        return;
    }
    printf("\nSucessores: ");
    for(int i=0; i<totalVertices; i++){
        if(matriz[vertice-1][i]!=0) printf("%d ", i+1); 
    }
    printf("\n");
}
void antecessores(int **matriz, int totalVertices, int vertice){
    if(vertice>totalVertices){ 
        printf("\nVertice invalido\n");
        return;
    }
    printf("\nAntecessores: ");
    for(int i=0; i<totalVertices; i++){
        if(matriz[i][vertice-1]!=0) printf("%d ", i+1); 
    }
    printf("\n");
}