#include<stdio.h>

int main(void){
    int x, y;
    printf("Enter the number of rows: ");
    scanf("%d", &x);
    printf("Enter the number of columns: ");
    scanf("%d", &y);

    int matrix[x][y];
    printf("Enter elements into the matrix: \n");
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("matrix[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    int count = 0;
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            if(matrix[i][j] == 0)
                count++;
        }
    }

    if(count > ((x*y)/2)){
        int s = 0;
        int sparse[(x*y)-count][3];
        printf("It is a sparse matrix\n");

        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(matrix[i][j] != 0){
                    sparse[s][0] = i;
                    sparse[s][1] = j;
                    sparse[s][2] = matrix[i][j];
                    s++;
                }
            }
        }

        printf("3-tuple representation of this sparse matrix is: \n");
        for(int i=0; i<s; i++){
            for(int j=0; j<3; j++){
                printf("%3d", sparse[i][j]);
            }
            printf("\n");
        }
    }else{
        printf("It is not a sparse matrix.\n");
    }

    return 0;
}