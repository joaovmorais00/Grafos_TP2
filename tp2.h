#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void preencheMatriz(int** matriz, int numArestas, int* origens, int* destinos, int* valores);
char* obterSubstring(char* string, int inicio, int fim);
void dividirString(char* string, int* origem, int* destino, int* valor);
void imprimeMatriz(int** matriz, int linhas, int colunas);
int menu(int** matriz, int totalVertices, int totalArestas);
void sumario(int** matriz, int totalVertices, int totalArestas);
void grauVertice(int **matriz, int totalVertices, int vertice);
void sucessores(int **matriz, int totalVertices, int vertice);
void antecessores(int **matriz, int totalVertices, int vertice);