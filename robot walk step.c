#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, acc=0;
int steps[2]={1, 2};
char * all_step;

void DFS(int step){
        acc += step;
        all_step[strlen(all_step)]= step+'0';

        if(acc==n){
                for(int i=0;i<strlen(all_step);i++){
                        printf("%c", all_step[i]);
                        if(i==strlen(all_step)-1)
                                printf("\n");
                        else
                                printf(" ");
                }
        }
        else{
                for(int i=0;i<2;i++){
                        if(acc+steps[i]<=n){
                                DFS(steps[i]);
                                acc -= (all_step[strlen(all_step)-1]-'0');
                                all_step[strlen(all_step)-1]= '\0';
                        }
                }
        }
}

int main()
{
         all_step= (char*)malloc(100000*sizeof(char));
         for(int i=0;i<100000;i++)
                all_step[i]= '\0';

        printf("\nPlease input n meters: ");
        while(scanf("%d", &n)!=EOF){

                for(int i=0;i<2;i++){
                        DFS(steps[i]);
                        acc = acc- (all_step[strlen(all_step)-1]-'0');
                        all_step[strlen(all_step)-1]= '\0';
                }

                printf("\nPlease input n meters: ");
        }
        free(all_step);
        return 0;
}
