#include <stdio.h>
#include <stdlib.h>

int main() {


    int n,col,x,y,start,end;
    printf("Enter a number: ");
    scanf("%d",&n);

    col = (2*n)-1;
    char p[n+1][col+1];

    x=(col/2);
    y=(col/2);

    start=0;
    end=(col)-1;
    if(n>=3 && n%2==1){

        for(int i=0; i<n; i++){
            for(int j=0; j<col; j++){
                if(j>=start && j<=end){
                    p[i][j] = '*';
                }
                else{
                    p[i][j] = ' ';
                }
            }
            start++;
            end--;
        }

        if(n>=9){
            for(int i=0; i<(n/2); i++){
                for(int j=0; j<col; j++){
                    if((j==x || j==y || j==(col/2)) && i>0 && i<(n/2)+1){
                        p[i][j] = ' ';
                    }
                    else if(j>x && j<y){
                        p[i][j] = ' ';
                    }

                }
                if(i>=1){
                    x--;
                    y++;
                }

            }
        }
    }
    else{
        printf("Invalid input");
        exit(0);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<col; j++){
            printf("%c ",p[i][j]);
        }
        printf("\n");
    }

    return 0;
}