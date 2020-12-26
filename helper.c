#include "helper.h"


// le prime due righe della amtrice sono 
// le dimensioni della matrice stessa
int ** crea_matrice (stringa file, struct mat * dim )

{

            FILE *fp = fopen(file,"r");

            // read dim
            fscanf(fp,"%d %d", &dim->r, &dim->c );


            int ** mat= (int **)malloc(dim->r*sizeof(int *));

            for (int i=0;i<dim->r;i++) 

            {
                    mat[i] = (int *)malloc(dim->c*sizeof(int));

            }

            for (int j =0;j<dim->r;j++) {


                    for (int k =0; k<dim->c ; k++) 
                    {

                                int val = 0;

                                fscanf(fp,"%d", &val);

                                mat[j][k] = val;

                    }

            }


            fclose(fp); // chiudi il file

            return mat; // ritorna la matrice

}


node ** crea_matrice_lista (stringa file, struct mat * dim  ){

        FILE *fp = fopen(file,"r");

            // read dim
            fscanf(fp,"%d %d", &dim->r, &dim->c );

                // creo il vettore di strutture
            node ** str_vect= (node **)malloc(dim->r*sizeof(node *));

                // creo le liste nel vettore
            for (int i=0;i<dim->r;i++) 

            {
                    
                    str_vect[i] = (node *)malloc(sizeof(node)); // creo la testa

                    node * head_t = str_vect[i];

                    head_t->tag=0;

                    int val = 0;

                    fscanf(fp, "%d", &val);

                    head_t->val = val;
                   
                for(int k=0;k<dim->c-1;k++)

                        {

                                node *  new_node = (node *)malloc(sizeof(node));
                                
                                new_node->tag=0;

                                int val = 0 ;

                                fscanf(fp, "%d", &val);

                                new_node->val = val;

                                new_node->next=NULL; // set next pointer to null untill is made

                                head_t->next = new_node;
                                
                                head_t=head_t->next; // scorro i nodi

                        }
                       
                }


            fclose(fp); // chiudi il file

            return str_vect; // ritorna la matrice &str_vect[0]

}


bool check_elem_with_list (node * head, int to_be_cheched) 
{

                node * node_t = head;

                while (node_t!= NULL) {


                                if (node_t->val==to_be_cheched && node_t->tag==0) 
                                                {

                                                        node_t->tag=1; // set tag equal to 1

                                                        return true;

                                                }

                        node_t=node_t->next;


                }

                return false;



}       



bool check_list_with_list(node * src, node * dst) {


                node * node_t_s = src;
                node * node_t_d = dst;

                while (node_t_s!=NULL) 
                {

                        if (!check_elem_with_list(node_t_d,node_t_s->val)) { return false;}

                        node_t_s = node_t_s->next; // scorro la lista

                }

        return true;

}


void reset_tags(node * head){

        node * node_t = head;

        while (node_t!=NULL) {


                node_t->tag = 0;

                node_t=node_t->next;

        }

}



void check_matrix_list (node ** mat_list, struct mat * dim){



                for (int j = 0; j<dim->r-1;j++) {
                        
                                for (int k = j+1;k<dim->r;k++) 

                                {

                                      if ( check_list_with_list(mat_list[j], mat_list[k])) 
                                                {

                                                printf ("Le righe %d e %d sono permutazioni\n",j+1, k+1);

                                                }

                                        reset_tags(mat_list[k]);


                                }
                        
                        }




}

void print_list_vect(node ** m, struct mat dim ){

        for (int j=0;j<dim.r;j++) {

                node * head_t = m[j];

                while(head_t!=NULL)
                                {
                                        printf("%d\t",head_t->val);

                                        head_t = head_t->next;

                                }       

                printf("\n");

        }


}


void print_matrix(int ** m, struct mat mat_t) {

   

        for (int j=0;j<mat_t.r;j++) {

                for (int k=0;k<mat_t.c;k++) {

                       printf("%d\t",m[j][k]);


                }
                printf("\n");

        }
        
}


bool check_elem_with_line ( int elem, int *vet, int n_c , int * tags_v)  {

                for (int i = 0;i<n_c;i++ ) {

                                if(*vet == elem && tags_v[i]==0) 
                                        {

                                                tags_v[i] = 1; // TAG VECTOR TO 1
                                                return true;

                                        }

                                vet++;

                }

                return false;



}



bool check_row_with_row (int * p_v, int * s_v, int n_c ) 
{

    
  
        // creazione ed azzeramento vettore dinamico
        int * tags = (int *)calloc(n_c,(sizeof(int))); 


        for (int i =0; i<n_c;i++){
        
        if  (!check_elem_with_line( p_v[i] , s_v , n_c , tags))
                        {
                               
                            return false;
                                

                        } 
            

        }

                return true;
                    

}

void check_perm_matrix(int ** mat, struct mat dim)
{

 for (int r = 0;r<(dim.r-1);r++) {


                for (int r_i=r+1;r_i<dim.r;r_i++) {


                        if (check_row_with_row(*(mat+r) , *(mat+r_i) , dim.c )){

                                 printf ("le righe %d %d sono permutazioni\n", r+1,r_i+1 );
                        }

                }

        }



}