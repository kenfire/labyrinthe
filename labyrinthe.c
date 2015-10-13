#include <stdio.h>
#include "affichage.h"

int main(void)
{
    const int MAX_LINE = 9;
    const int MAX_RAW = 23;
  
    /* Setting random seed (once and for all) */
    srand(time(NULL));

    print_labyrinthe(9,23);
    return 0;
}
