#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define FLAG_C 0x1
#define FLAG_L 0x2
#define FLAG_W 0x4
#define FLAG_M 0x8

#define IN_WORD 0x10

int main(int argc, char *argv[]) {
  FILE *fp;
  int flags = 0;
  int filename = -1;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
        case 'c':
          flags |= FLAG_C;
          break;
        case 'l':
          flags |= FLAG_L;
          break;
        case 'w':
          flags |= FLAG_W;
          break;
        case 'm':
          flags |= FLAG_M;
          break;
      }
    } else {
      filename = i;
    }
  } 

  uint64_t charCount = 0;
  uint64_t byteCount = 0;
  uint64_t lineCount = 0;
  uint64_t wordCount = 0;

  fp = fopen(argv[filename], "r");

  if (fp == NULL) {
    printf("%s: %s: No such file or directory\n", argv[0], argv[1]);
    return EXIT_FAILURE;
  }

  char ch;
  while(1) {
    ch = fgetc(fp);
    if (ch == EOF)
      break;

    charCount++;
    byteCount += sizeof(ch);
    
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) 
      flags |= IN_WORD;
  
    if ((ch == ' ' || ch == '\n') && (flags & IN_WORD)) {
      wordCount++;
      flags &= ~(flags & IN_WORD);
    }
    
    if (ch == '\n') 
      lineCount++;
  }
  fclose(fp);

  // printf("c: %lu b: %lu l: %lu w: %lu\n" , charCount, byteCount, lineCount, wordCount);
  if ((flags & FLAG_C) == 0 && (flags & FLAG_L) == 0 && (flags & FLAG_M) == 0 && (flags & FLAG_W) == 0) {
    printf("%lu %lu %lu", lineCount, wordCount, charCount);
    if (filename != -1) printf(" %s\n", argv[filename]);
    return EXIT_SUCCESS;
  }
  

  if ((flags & FLAG_C)) {
    printf("%lu ", charCount);
  }
  
  if ((flags & FLAG_W)) {
    printf("%lu ", wordCount);
  }

  if ((flags & FLAG_L)) {
    printf("%lu ", lineCount);
  }

  if ((flags & FLAG_M)) {
    printf("%lu", byteCount);
  }

  if (filename != -1) printf(" %s", argv[filename]);
  printf("\n");

  return EXIT_SUCCESS;
}
