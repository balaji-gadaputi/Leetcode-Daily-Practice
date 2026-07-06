// Last updated: 06/07/2026, 12:00:36
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
    int *rowflag=(int*)calloc(sizeof(int),matrixSize);
    int *colflag=(int*)calloc(sizeof(int),(*matrixColSize));
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<(*matrixColSize);j++){
            if(matrix[i][j]==0){
                rowflag[i]=1;
                colflag[j]=1;
            }
        }
    }
    for(int i=0;i<matrixSize;i++){
        if(rowflag[i]){
            for(int k=0;k<(*matrixColSize);k++){
                matrix[i][k]=0;
            }
        }
    }
    for(int i=0;i<(*matrixColSize);i++){
        if(colflag[i]){
            for(int k=0;k<matrixSize;k++){
                matrix[k][i]=0;
            }
        }
    }
}
