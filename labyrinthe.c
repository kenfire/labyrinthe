#include <stdio.h>
#include "affichage.h"

#define MAX_LINE 5
#define MAX_COL 7 

int main(void)
{
    int** laby;
    /* Setting random seed (once and for all) */
    srand(time(NULL));
    
    laby = malloc_2D_array(MAX_LINE, MAX_COL);
    create_labyrinthe (laby, MAX_LINE, MAX_COL);
    print_2D_array(laby, MAX_LINE, MAX_COL);

    return 0;
}
