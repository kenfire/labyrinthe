void print_labyrinthe()
{
    int raw,line;
    int max_raw = 23;
    int max_line = 9;

    for (line = 0; line < max_line; line++){
        for (raw = 0; raw < max_raw; raw++){
            if (line == 0 || line == max_line-1 || raw%2 == 0;){
                printf("#");        
            }else{
                printf(" ");
            }
        }
    }
}
