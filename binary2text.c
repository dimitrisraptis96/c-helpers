#include <stdio.h>
#include <stdlib.h>

#define IN      "./data/S1.bin"
#define OUT     "./data/out.txt"

// error handlers
#define HANDLE_NULL( a ) {if (a == NULL) { \
                            printf( "Open file failed in %s at line %d\n", \
                                    __FILE__, __LINE__ ); \
                            exit( EXIT_FAILURE );}}

#define HANDLE_EOF( a ) {if (a == EOF) { \
                            printf( "File reading failed in %s at line %d\n", \
                                    __FILE__, __LINE__ ); \
                            exit( EXIT_FAILURE );}}

int main(int argc, char **argv){
    int i, j, N, D, pos, number_elements;
    double *in;

    if (argc != 3) {
        printf("==============================================\n");
        printf("Usage: Binary file to txt.\n");
        printf("==============================================\n");
        printf("arg[1] = N    ==> number of points\n");
        printf("arg[2] = D    ==> point's dimensions\n");
        printf("\n\nExiting program..\n");
        exit(1);
      }

    N     = atoi(argv[1]);
    D     = atoi(argv[2]);

    FILE *finp, *fout;
    HANDLE_NULL( (finp = fopen(IN, "rb")) );
    HANDLE_NULL( (fout = fopen(OUT, "w")) );    

    //malloc and set input array
    in = (double *) malloc (N * D * sizeof(double));
    HANDLE_EOF( fread(in, sizeof(double), N*D, finp) );
    
    for (i=0; i<N; i++){
        for (j=0; j<D; j++){
            HANDLE_EOF( fprintf(fout, "%lf ", in[i*D+j]) );
        }
        HANDLE_EOF( fprintf(fout, "\n") );
    }
    
    HANDLE_EOF( fclose(finp) );
    HANDLE_EOF( fclose(fout) );
}
