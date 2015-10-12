#include <stdio.h>
#include <time.h>

int random (int min, int max)
{
    srand(time(NULL));
    return (int) rand()%max + min;
}
/*
 * 
*/
void create_grid (int max_line, int max_col, int arr[max_line][max_col])
{
    int col, line;
    int cell_num=1;
    int rand_num; 
    
    for (line = 0; line < max_line; line++){
        for (col = 0; col < max_col; col++){
            if (line%2 == 0 || col%2 == 0){
                // 0 = "#" for walls
                arr[line][col] = 0;        
            }else{
                arr[line][col] = cell_num++;
            }
        }
    }
}

void create_labyrinthe (int max_line, int max_col, int arr[max_line][max_col])
{
    int finish = 0;
    int alea_line = 0;
    int alea_col = 0;
    int min_cell = 1;
    int max_cell = (max_line -1) * (max_col - 1) / 4;

    create_grid(max_line, max_col, arr);
    
    while (!finish)
    {
        alea_line = random(min_cell + 2, max_cell - 2);
        alea_col = random(min_cell + 2, max_cell - 2);
        
        if (alea_line %2 != 0)
        { 
            alea_line += 1;
        }

        if (alea_col %2 != 0)
        {
            alea_col += 1;
        }

        printf("%d -- %d\n", alea_line, alea_col);
        finish = 1;
    }
}
void print_labyrinthe (int max_line, int max_col)
{
    int col, line, rand_num;
    int cell_num=1;
    int arr[max_line][max_col];
    create_labyrinthe(max_line, max_col, arr);

    for (line = 0; line < max_line; line++){
        for (col = 0; col < max_col; col++){
            printf("%d, ", arr[line][col]);
        }
        printf("\n");
    }
    rand_num = random(1,cell_num-1);
    printf("%d", rand_num);
       
}
