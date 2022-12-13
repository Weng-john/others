#include <stdio.h>
#include <stdlib.h>

#define LENTH 1000

int *num, **arr;

int init(){
        num= (int*)calloc(LENTH, sizeof(int));
        arr= (int**)calloc(LENTH, sizeof(int*));
        for(int i=0;i<LENTH;i++)
                arr[i]= (int*)calloc(LENTH, sizeof(int));
}

int main()
{
        int n;
        while(init()){
                int LR= 0, RL= 0;

                printf("Enter n: ");
                scanf("%d", &n);
                printf("Enter num: ");
                for(int i=0;i<n;i++)
                        scanf("%d", num+i);

                for(int i=0;i<n;i++){
                        if(i)
                                for(int j=1;j<n;j++)
                                        arr[i][j]= arr[i-1][j-1];
                        else{
                                for(int j=0;j<n;j++){
                                        arr[j][i]= num[j];
                                        arr[i][j]= num[j];
                                }
                        }
                }

                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                if((i+j)==(n-1))
                                        RL += arr[i][j];
                                if(i==j)
                                        LR += arr[i][j];
                        }
                }

                printf("\nThe Matrix:\n");
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++)
                                printf("   %d", arr[i][j]);
                        printf("\n");
                }
                printf("Diagonal sum \\:  %d\n", LR);
                printf("Diagonal sum /:  %d\n", RL);

                printf("Enter n: ");
        }
        return 0;
}
