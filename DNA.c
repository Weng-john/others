#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 10000

int pal_len, index;
char *top, *bottom, *pal_top, *pal_bottom;

void init(){
        top= (char*)calloc(LEN,sizeof(char));
        bottom= (char*)calloc(LEN,sizeof(char));
        pal_top= (char*)calloc(LEN,sizeof(char));
        pal_bottom= (char*)calloc(LEN,sizeof(char));

        for(int i=0;i<LEN;i++){
                top[i]= '\0';
                bottom[i]= '\0';
                pal_top[i]= '\0';
                pal_bottom[i]= '\0';
        }
}

void input(){
        printf("Enter on strand of DNA molecule segment:\n");
        scanf("%s", top);
        printf("Enter complementary strand:\n");
        scanf("%s", bottom);
        printf("Enter length of palindromic sequence: ");
        scanf("%d", &pal_len);
}
void output(){
        printf("\nThe DNA:\n%s\n%s\n", top, bottom);
        printf("\nPalindromes of length is %d\n", pal_len);
        printf("\nPalindrome at position %d\n", index);
        printf("%s\n%s\n", pal_top, pal_bottom);
        printf("\n=================\n\n");
}

int main()
{
        while(1){
                init();
                input();

                for(int i= 0;(i+pal_len-1)<strlen(top);i++){
                        if(top[i]!=bottom[i+pal_len-1])
                                continue;

                        index= i;
                        for(int j=i, k=0;j<i+pal_len-1;j++, k++){
                                if(top[j]!=bottom[i+pal_len-1-k])
                                        break;
                                pal_top[k]= top[j];
                                pal_bottom[pal_len-k]= bottom[i+pal_len-1-k];
                        }

                        if(pal_len==strlen(pal_top))
                                break;
                }

                output();

                free(top);
                free(bottom);
                free(pal_top);
                free(pal_bottom);
        }
        return 0;
}
