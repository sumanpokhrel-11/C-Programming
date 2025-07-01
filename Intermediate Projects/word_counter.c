#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("word.txt", "r");
    char buffer[256];
    int ch,w,l;
    int chcounter=0;
    int word_counter = 0;
    int line_counter = 0;
    char paragraph;
    while((ch=fgetc(fp)) !=EOF) {
        chcounter++;
    }
    printf("Character counts: %d \n", chcounter);
    while((w=fgetc(fp)) !=EOF) {

        if(w == ' ') {
            word_counter ++;
        }
    }
    printf("word counts : %d\n", word_counter);

    while((l=fgetc(fp)) != EOF) {
        if(l=='\n') {
            line_counter ++;
        }
        
    }
    printf("Line Counts: %d \n", line_counter);
    fclose(fp);
}