#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

struct Node{
  char info;
  struct Node* Left;
  struct Node* Right;
};

typedef struct Node simpul;
simpul *root, *P, *Q[30], *R, *current;
char X;

void inisialisasi(){
  root = NULL;
  P = NULL;
}

void buatsimpul(char X){
  P = (simpul*) malloc(sizeof(simpul));
  if(P != NULL){
    P->info = X;
    P->Left = NULL;
    P->Right = NULL;
  }
}

void buatsimpulakar(){
  if(root == NULL){
    if(P != NULL){
      root = P;
      P->Left = NULL;
      P->Right = NULL;
    }
    else{
      cout << "Simpul belum dibuat" << endl;
    }
  }
  else{
    cout << "Pohon Sudah Ada !!!" << endl;
  }
}

void innserturutnomer(char input[6]){
  int i, j, flag;
  char X;
  flag = 0;
  i = 1;
  j = 1;
  Q[i] = root;
  while(flag == 0 && j < 6){
    X = input[j-1];
    if(X != '0'){
      buatsimpul(X);
      current = Q[i];
      current->Left = P;
      j++;
      Q[j] = P;
    }
    else{
      flag = 1;
      j++;
      Q[j] = NULL;
    }
    if(flag == 0){
      X = input[j-1];
      if(X != '0'){
        buatsimpul(X);
        current->Right = P;
        j++;
        Q[j] = P;
      }
    }
    else{
      flag = 1;
      j++;
      Q[j] = NULL;
    }
    i++;
  }
}

void bacaurutnomer(){
  int i, j, n, counter;
  i = 1;
  j = 1;
  n = 1;
  counter = 0;
  int level = 0;
  while (Q[i] != NULL){
    current = Q[i];
    if(i == 1){
      cout << endl;
      cout << "Level " << level << endl;
    }
    cout<<current -> info <<" - ";
    counter++;
	if(counter == n){
		level++;
		cout<<"Level " << level <<" " <<endl;
	}
    if(counter == n){
      cout << endl;
      counter = 0;
      n = n * 2;
    }
    if(current->Left != NULL){
      j++;
      Q[i] = current->Left;
    }
    if(current->Right != NULL){
      j++;
      Q[i] = current->Right;
    }
    i++;
  }
}

int main(){
  char root = 'R';
  char daun[6] = {'S', 'U', 'V', 'W', 'Y', 'Z'};
  inisialisasi();
  buatsimpul(root);
  buatsimpulakar();
  innserturutnomer(daun);
  bacaurutnomer();
  return 0;
}