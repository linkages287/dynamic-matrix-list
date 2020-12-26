#include <stdio.h>
#include <stdlib.h>
#include "helper.h"

int main() 
{

        struct mat *dim = (struct mat *)malloc(sizeof(struct mat)); // alloca lo spazio per salvare i dati dimensione matrice
        
        node ** v_list = crea_matrice_lista("data.dat", dim);

        print_list_vect(v_list,*dim);

        check_matrix_list(v_list, dim);

        // CON MATRICI--------------------------------------------------------------
        printf ("-------------------------matrix--------------------------------------\n");

        int ** mat = crea_matrice("data.dat", dim);

        print_matrix(mat,*dim); // dim viene passata come ref, viene modificata

        check_perm_matrix(mat , *dim); // controllo delle permutazioni nella matrice

        return 0;
}