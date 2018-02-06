#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define IN_PATH_1   "./data/parallel.txt"
#define IN_PATH_2   "./data/serial.txt"

#define PRECISION 0.00001

// error handlers
#define HANDLE_NULL( a ) {if (a == NULL) { \
                            printf( "Open file failed in %s at line %d\n", \
                                    __FILE__, __LINE__ ); \
                            exit( EXIT_FAILURE );}}

#define HANDLE_EOF( a ) {if (a == EOF) { \
                            printf( "File reading failed in %s at line %d\n", \
                                    __FILE__, __LINE__ ); \
                            exit( EXIT_FAILURE );}}

// definitions
int checkFiles(const int N, const int D);


int main(int argc, char **argv){
  int N, D;
  // check and setarguments
  if (argc != 3) {
    printf("==============================================\n");
    printf("Usage: compare 2 text files(space delimiter).\n");
    printf("==============================================\n");
    printf("arg[1] = N    ==> number of rows\n");
    printf("arg[2] = D    ==> number of columns\n");
    printf("\n\nExiting program..\n");
    exit(1);
  }

  N = atoi(argv[1]);
  D = atoi(argv[2]);

  if (checkFiles(N,D)) printf("Files are identical\n");

  return 0;
}

int checkFiles(const int N, const int D){
  int i,j;
  double tmp1, tmp2;
  int isIdentical = 1;

  // open files
  FILE * fp1, * fp2;
  HANDLE_NULL( (fp1 = fopen (IN_PATH_1, "r")) );
  HANDLE_NULL( (fp2 = fopen (IN_PATH_2, "r")) );

  // check elemets
  for (i=0; i<N; i++) 
    for (j=0; j<D; j++){
      HANDLE_EOF( (fscanf(fp1, "%lf", &tmp1)) );
      HANDLE_EOF( (fscanf(fp2, "%lf", &tmp2)) );
      if ( fabs(tmp1-tmp2) > PRECISION ){
        isIdentical = 0;
        printf("Differences at (row, column) = (%d, %d)\n",i+1,j+1);
      }     
    }

  //close files
  HANDLE_EOF(fclose(fp1));
  HANDLE_EOF(fclose(fp2));

  return isIdentical;
}
