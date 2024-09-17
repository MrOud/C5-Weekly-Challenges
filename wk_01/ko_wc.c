#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main() {
  FILE *fp;

  char ch;
  fp = fopen("smtest.txt", "r");

  uint64_t charCount = 0;
  uint64_t byteCount = 0;
  uint64_t lineCount = 1; //We always start a file on the first line
  uint64_t wordCount = 0;

  while(1) {
    ch = fgetc(fp);
    if (ch == EOF)
      break;

    //printf("%d\n", (int)ch);
    
    charCount++;
    byteCount += sizeof(byteCount);
    
    if (ch == ' ' || ch == '\n')
      wordCount++;
    if (ch == '\n') 
      lineCount++;
  }
  printf("\n");
  printf("c: %lu b: %lu l: %lu w: %lu\n" , charCount, byteCount, lineCount, wordCount);
  fclose(fp);

  return EXIT_SUCCESS;
}
