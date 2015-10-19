#ifndef affichage
#define affichage 
/* affichage.c */
int arbitrary(int min, int max);
int **malloc_2D_array(int line, int col);
void init_grid(int **laby, int max_line, int max_col);
void create_labyrinthe(int **laby, int max_line, int max_col);
void print_2D_array(int **arr, int max_line, int max_col);

#endif
