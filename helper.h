#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef char * stringa;

struct mat {

        int r;
        int c;

};


typedef struct node  {


        int tag; // pone un tag sul valore
        int val; // DATA payload contenuto 
        struct node * next; // putnatoto al prossimo nodo



} node ;

// la struttura mar *  viene modificata dal main è passata come ref
int ** crea_matrice (stringa, struct mat * );

// restituisce un vettore di liste , ogni elemento del vettore punta alla lista. 
node ** crea_matrice_lista (stringa, struct mat * ); 


// check tags contained in a list and reset after
void reset_tags(node *);

//check correspondent elemetn inside a list adn tag it
bool check_elem_with_list (node * , int );

// whole list with another list usging check_eleme_with_list
bool check_list_with_list(node * , node *);

//check whole matrix will use all the upper functions
void check_matrix_list (node ** , struct mat *);

// print matrix elements
void print_matrix(int ** m, struct mat );

// print list element
void print_list_vect(node ** m, struct mat );

// prende in input  l'elemento da controllare , il vettore da controllare ed il numeo di colonne
// dobbiamo passargli il vettore TAGS per la verifica di replicazione di scambio
bool check_elem_with_line ( int to_be_checked, int * vetor_tocheck, int n_col , int * tags);

//prende in input la 1 riga origine , la 2 riga da controllare , la lunghezza delle colonne
bool check_row_with_row (int * , int * , int );

//controllo matrice
void check_perm_matrix(int **, struct mat);




