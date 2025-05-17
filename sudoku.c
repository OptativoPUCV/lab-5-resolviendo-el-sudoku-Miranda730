#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"


typedef struct{
   int sudo[9][9];
}Node;

Node* createNode(){
  Node* n=(Node*) malloc(sizeof(Node));
  return n;
}

Node* copy(Node* n){
    Node* new=(Node*) malloc(sizeof(Node));
    *new = *n;
    return new;
}

Node* read_file (char* file_name){
  Node* n = createNode();
  FILE* file = fopen (file_name, "r");
  int i,j;
  for(i=0;i<9;i++){
       for(j=0;j<9;j++){
          if(!fscanf (file, "%d", &n->sudo[i][j]))
            printf("failed to read data!");
       }
  }

  fclose (file);
  return n;
}

void print_node(Node* n){
    int i,j;
    for(i=0;i<9;i++){
       for(j=0;j<9;j++)
          printf("%d ", n->sudo[i][j]);
       printf("\n");
    }
    printf("\n");
}

int is_valid(Node* n){
  int arreglo1[10];
  int arreglo2[10];
  int arreglo3[10];
  for(int k = 0 ; k < 9 ; k++){
    for(int p=0;p<9;p++){
      arreglo1[p] = 0;
      arreglo2[p] = 0;
      arreglo3[p] = 0;
      int numFila = n->sudo[k][p];
      if(numFila != 0){
        if(arreglo1[numFila] == 1)return 0;
        arreglo1[numFila] = 1;
      }
      int numCol = n->sudo[p][k];
      if(numCol != 0){
        if(arreglo2[numCol] == 1)return 0;
        arreglo2[numCol] = 1;
      }
      int i=3*(k/3) + (p/3) ;
      int j=3*(k%3) + (p%3) ;
      int numMatriz = n->sudo[i][j];
      if(numMatriz != 0){
        if(arreglo3[numMatriz] == 1)return 0;
        arreglo3[numMatriz] = 1;
      }
    }
  }
  return 1;
}


List* get_adj_nodes(Node* n){
    List* list=createList();
    if(n == NULL) return list;

    for(int i = 0 ; i < 9 ; i++)
      for(int j = 0 ; j < 9 ; j++)
      {
        if(n->sudo[i][j] == 0){
          for(int k = 1 ; k <= 9 ; k++){
            Node* newNode = copy(n);
            newNode->sudo[i][j] = k;
            pushBack(list, newNode);
          }
          return list;
        }
      }

    return list;
}


int is_final(Node* n){
    return 0;
}

Node* DFS(Node* initial, int* cont){
  return NULL;
}



/*
int main( int argc, char *argv[] ){

  Node* initial= read_file("s12a.txt");;

  int cont=0;
  Node* final = DFS(initial, &cont);
  printf("iterations:%d\n",cont);
  print_node(final);

  return 0;
}*/