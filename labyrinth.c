#include <stdio.h>
#include <time.h>
#include <stdlib.h> 

/**
 * \brief Génère un nombre aléatoire borné
 * \param min Borne minimum
 * \param max Borne minimum
 */
int rand_ab (int min, int max)
{
     return (int) rand()% max + min;
}

void get_size (int* max_line, int* max_col)
{
    char buff[100];
    
    printf("Veuillez entrer la taille du labyrinthe\n");
    
    printf("Nombre de lignes ?\n");
    scanf("%s", buff);
    *max_line= (int) strtol(buff, NULL, 10);
      
    printf("Nombre de colonnes ?\n");
    scanf("%s", buff);
    *max_col= (int) strtol(buff, NULL, 10);

    if (*max_line%2 ==0)
    {
        *max_line += 1;
    }

    if(*max_col %2 ==0)
    {
        *max_col += 1;
    }
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
    
    for (line = 0; line < max_line; line++){
        for (col = 0; col < max_col; col++){
            if (line%2 == 0 || col%2 == 0){
                /* 0 = "#" for walls */
                laby[line][col] = 0;        
            }else{
                laby[line][col] = cell_num++;
            }
        }
    }
}

void create_labyrinth (int** laby,int max_line, int max_col)
{
    int i, j, k;
    int search_value;
    int value;
    int vertical_wall; /* Boolean  */
    int line = 0;
    int col = 0;
    int min_cell = 1;
    /*int max_cell = (max_line -1) * (max_col - 1) / 4;*/
    int finish = (max_line/2) * (max_col /2) -1;
    init_grid(laby, max_line, max_col);
    
    for(i = 0; i< finish; i++)
    {

        do{
            line = rand_ab(min_cell, max_line -2);
            col = rand_ab(min_cell, max_col -2);
            
            vertical_wall = col %2;

            if (vertical_wall)
            {
                value = laby[line-1][col];
                search_value = laby[line+1][col];
            }
            else
            {
                value = laby[line][col-1];
                search_value = laby[line][col+1];
            }
   
    
         } while(   (line %2 == 0 && col %2 == 0) 
                || (line %2 != 0 && col %2 != 0)
                || laby[line][col] !=0 
                || value == search_value);
        /* tant que ce n'est pas un mur ... */
        
        
        laby[line][col] = value;

        for (j = 0; j<max_line ; j++)
        {
            for (k=0 ; k<max_col ; k++)
            {
                if (laby[j][k] == search_value)
                {
                    laby[j][k] = value;
                }
            }
        }

        laby[1][0] = -1;
        laby[max_line-2][max_col-1] = value;
    }
}

void print_2D_array(int** arr, int max_line, int max_col)
{
    int col, line;
    printf("\n");
    for (line = 0; line < max_line; line++){
        for (col = 0; col < max_col; col++){
            if(arr[line][col] == 0)
                printf("#");
            else if (arr[line][col] == -1)
                printf("o");
            else
                printf(" ");
        }
        printf("\n");
    }
}

/**
 * \brief Libère l'allocation mémoire du tableau 2D
 * \param arr le tableau contenant le carré
 * \param line le nombre de ligne dans le carré
 *
 */
void free_2D_array(int** arr, int line)
{
    int i;

    for (i = 0; i< line; i++)
    {
        free(arr[i]);
    }
    free(arr);
}

