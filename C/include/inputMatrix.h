#pragma once
#include <stdio.h>
void inputMatrix(size_t rows, size_t columns, double matrix[rows][columns]) {
    int i,j,k, n = (int)rows, m = (int)columns;
    for ( i=0;i<n;i++){
        printf("\n");

        for ( j=0;j<m;j++){
            printf("\033[A\r\033[J"); // Explained at bottom

            fflush(stdout);
            for ( k=0;k<j;k++){
                printf(" %.4lf ",matrix[i][k]);
            }
            printf(" ");scanf("%lf",&matrix[i][j]);

            if(j==n-1){printf("\033[A\r\033[J");
                for ( k=0;k<n;k++){
                    printf(" %.4lf ",matrix[i][k]);
                }
            }
        }
        printf("\n");
    }
}

//  \033  : Octal code of ASCII Escape character (ESC key) to put terminal in control mode(like in vi editor), 
//  [ A   : key combination to move cursor up (conbined = ESC [ A )
//  (try pressing arrow UP key when entering input))
//   \r   : carriage return, moves cursor to beginning of line
//  [ 2 K : command to clear entire line (combined with control mode = ESC [ 2 K )
//  [ J   : command to clear everything after cursor (combined with control mode = ESC [ J )