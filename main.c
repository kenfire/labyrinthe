#include <stdio.h>
#include "labyrinth.h"
#include "menu.h"

#define MAX_LINE 9
#define MAX_COL 23

int main(void)
{
    int** laby;
    int opt;
    int max_line, max_col;
    /* Setting random seed (once and for all) */
    srand(time(NULL));
    if (!(MAX_LINE %2) || !(MAX_COL %2))
    {  
        printf("Nombre de ligne et de colonne doit être impaire !\n");
        printf("MAX_LINE = %d, MAX_LINE = %d\n", MAX_LINE, MAX_COL);
        return 0;
    }
    
    print_menu();
    opt = chose_menu();
    
    if (opt == 1)
    {
        get_size(&max_line, &max_col);
        laby = malloc_2D_array(max_line, max_col);
        create_labyrinth (laby, max_line, max_col);
        print_2D_array(laby, max_line, max_col);
        free_2D_array(laby, max_line);
    }
    else if (opt == 4)
    {
       return 0; 
    }
    return 0;
}
