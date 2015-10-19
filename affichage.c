#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

int arbitrary (int min, int max)
{
     return (int) rand()% max + min;
}

int** malloc_2D_array (int line, int col)
{
    int i;
    int** arr;

    arr = (int**) malloc(line * sizeof(int*));
    if  (arr == NULL)
    {
        printf("Mémoire insuffisante !\n -- Arrêt du programme --");
        exit(0);
    }
    for (i = 0; i < line; i++)
    {
       arr[i] = (int*) malloc(col * sizeof(int));
    }

    return arr;
}

/**
 * Initialisation de la grille
 * Les mûrs sont placé aux indices paires
 */
void init_grid (int** laby, int max_line, int max_col)
{
    int col, line;
    int cell_num=1;
    int rand_num; 
    
    for (line = 0; line < max_line; line++){
        for (col = 0; col < max_col; col++){
            if (line%2 == 0 || col%2 == 0){
                // 0 = "#" for walls
                laby[line][col] = 0;        
            }else{
                laby[line][col] = cell_num++;
            }
        }
    }
}

void create_labyrinthe (int** laby,int max_line, int max_col)
{
    int finish = 0;
    int alea_line = 0;
    int alea_col = 0;
    int min_cell = 1;
    int max_cell = (max_line -1) * (max_col - 1) / 4;

    init_grid(laby, max_line, max_col);
    /*
    while (!finish)
    {
        alea_line = arbitrary(min_cell + 2, max_cell - 2);
        alea_col = arbitrary(min_cell + 2, max_cell - 2);

        if (alea_line %2 != 0 && alea_col %2 != 0)
        {

        }

        if (alea_col %2 != 0)
        {
            alea_col += 1;
        }
        
        printf("%d -- %d\n", alea_line, alea_col);

        finish = 1;
        
    }*/
}

void print_2D_array(int** arr, int max_line, int max_col)
{
    int col, line, rand_num;
    int cell_max =  max_line * max_col /4;

    for (line = 0; line < max_line; line++){
        for (col = 0; col < max_col; col++){
            printf("\t%d", arr[line][col]);
        }
        printf("\n");
    }
}
