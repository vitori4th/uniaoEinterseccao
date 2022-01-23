/* Faça uma função que recebe como parâmetro 2 vetores de inteiros representando conjuntos
de números inteiros, e devolve um outro vetor com o resultado da união dos dois conjuntos.
O vetor resultante deve ser alocado dinâmicamente. a função também deve retornar o tamanho do 
conjunto resultante */

#include<stdio.h>
#include<stdlib.h>

int * iniciaVetor( int n){
	int * v= (int *) malloc(n* sizeof(int));
	return v;
}

int * uniao(int v1[], int n1, int v2[],  int n2, int *nC){
	int i,j,k;
	int x=n1+n2;
	
	int *U= (int *)malloc(n1* sizeof(int));
	
	for(i=0;i<n1;i++){
		U[i]=v1[i];
	}

	for(j=0;j<n2;j++){
		U[i]=v2[j];
		i++;
	}
	
	for(i=0;i<x;i++){
		for(j=i+1;j<x;j++){
			if(U[i]==U[j]){
				for(k=j;k<x-1;k++){
					U[k]=U[k+1];
				}
					x--;
			}
		}
	}
	*nC=x;
	return U;
}

void imprimeConjunto(int *C, int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d\n",C[i]);
	}

}

void liberaConjunto(int *C){
	free(C);
}

int * interseccao(int v1[], int n1, int v2[],  int n2, int *nD){
	*nD=n1+n2;
	int p=0, i,j;
	int *I=(int*) malloc(*nD *sizeof(int));
	
	for(i=0;i<*nD;i++){
		for(j=0;j<*nD;j++){
		if(v1[i]==v2[j]){
		I[p]=v1[i];
		p++;
		}else{
		*nD=*nD-1;
		}
		}
	}
	
	return I;
}

int main(int argc, char * argv[]){
  int* A;
  int* B;
  int* C;
  int* D;
  int nA, nB, nC, nD, aux,i,j;
  
  //inicializando e lendo o conjunto A
  scanf("%d", &nA);
  A = iniciaVetor(nA);
  for(i = 0; i < nA; i++){
    scanf("%d", &aux);
    A[i] = aux;
  }
  
  //inicializando e lendo o conjunto B
  scanf("%d", &nB);
  B = iniciaVetor(nB);
  for(j = 0; j < nB; j++){
    scanf("%d", &aux);
    B[j] = aux;
  }
  
  //calcula e imprime a uniao e a interseccao
  C = uniao(A, nA, B, nB, &nC);
  imprimeConjunto(C, nC);
  
  D = interseccao(A, nA, B, nB, &nD);
  imprimeConjunto(D, nD);
  
  //libera a memoria dos 4 vetores
  liberaConjunto(A); 
  liberaConjunto(B); 
  liberaConjunto(C); 
  liberaConjunto(D); 

  return 0;
}
