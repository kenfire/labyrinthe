#include <stdio.h>
#include <time.h>

int random(int min, int max)
{
    srand(time(NULL));
    return (int) rand()%max + min;
}

void create_labyrinthe(int max_line, int max_col, int arr[max_line][max_col])
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

void print_labyrinthe(int max_line, int max_col)
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
