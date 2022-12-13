#include <stdio.h>
#include <stdlib.h>

#define LENTH 1000

int num[LENTH], arr[LENTH][LENTH];

int main()
{
        int n;
        printf("Enter n: ");
        while(scanf("%d", &n)!=EOF){
                int LR= 0, RL= 0;

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
                printf("Diagonal sum \:  %d\n", LR);
                printf("Diagonal sum /:  %d\n", RL);

                printf("Enter n: ");
        }
        return 0;
}
