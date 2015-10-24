#include <stdio.h>
#include "affichage.h"

#define MAX_LINE 5
#define MAX_COL 11

int main(void)
{
    int** laby;
    /* Setting random seed (once and for all) */
    srand(time(NULL));
    if (!(MAX_LINE %2) || !(MAX_COL %2))
    {  
        printf("Nombre de ligne et de colonne doit être impaire !\n");
        printf("MAX_LINE = %d, MAX_LINE = %d\n", MAX_LINE, MAX_COL);
        return 0;
    }
    laby = malloc_2D_array(MAX_LINE, MAX_COL);
    create_labyrinthe (laby, MAX_LINE, MAX_COL);
    print_2D_array(laby, MAX_LINE, MAX_COL);
    free_2D_array(laby, MAX_LINE);
    return 0;
}
