#ifndef affichage
#define affichage 

/* affichage.c */
int rand_ab(int min, int max);
int **malloc_2D_array(int line, int col);
void init_grid(int **laby, int max_line, int max_col);
void create_labyrinth(int **laby, int max_line, int max_col);
void print_2D_array(int **arr, int max_line, int max_col);
void free_2D_array(int **arr, int line);
#endif
