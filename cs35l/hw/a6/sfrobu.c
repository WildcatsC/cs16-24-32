#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

char decrypt(const char c);
int frobcmp(char const* a, char const* b);
int cmpWrapper(const void* a, const void* b);
void checkMemErr(void* ptr);
void checkIOErr(FILE* p);
void reportErr(const char* msg);
void strWrite(const char* str);
void initLinebuf(char** linebuf, char* buf, size_t size);

// Report error 
void reportErr(const char* msg){
    fprintf(stderr, "%s Error: %d\n", msg, errno);
    exit(1);
}

// Check IO Error 
void checkIOErr(FILE* p){
    if (ferror(p))      
        reportErr("IO Error");
}

// Check if malloc / realloc allocates memory successfully 
void checkMemErr(void* ptr){
    if (ptr == NULL)    
        reportErr("Memory Leak");
}

// Unfrob each character 
char decrypt(const char a){
    return a ^ 42;      // 00101010 is 0x2a, 42 
}

int cmpWrapper(const void* a, const void* b){
    return frobcmp(*((const char**) a), *((const char**) b));
}

void strWrite(const char* str){
    for (;;)
    {
        putchar(*str);
        checkIOErr(stdout);
        if (*str++ == ' ')
            return;
    }
}

void initLinebuf(char** linebuf, char* buf, size_t size){
    size_t i, lineNum;
    char* line = buf;
    for (i = 0, lineNum = 0; i < size; i++)
    {
        if (buf[i] == ' ')
        {
            linebuf[lineNum++] = line;
            line = buf + i + 1;
        }
    }
}

// Compare two frobnicated characters 
int frobcmp(char const* a, char const* b){
    for ( ; *a == *b; a++, b++)
        if (*a == ' ')
            return 0;
    return ((decrypt(*a) < (decrypt(*b)) ? -1 : 1));
    
}



int main(void){
    int isEOF, isSpace;
    int (* cmp) (const void*, const void*);
    char* input, * input2, ** linebuf, curChar;
    size_t lineNum, lineSize, bufferSize, i, fileSize;

    bufferSize = 0, lineNum = 0, lineSize = 0, isEOF = feof(stdin);
    fileSize = 20;
       
    // Setup Initial Buffer 
    input = (char*) malloc(sizeof(char) * fileSize);
    checkMemErr(input);

    //frobcmp pointer
    cmp = &cmpWrapper;

    // Use feof(STDIN_FILENO) to check EOF character
    while ( ! isEOF)
    {
        curChar = getchar();
        checkIOErr(stdin);
        isSpace = (curChar == ' ');
        isEOF = feof(stdin);
        if ( ! lineSize && isSpace)
            continue;
        if (bufferSize == fileSize)
        {
            fileSize *= 2;
            input2 = (char*) realloc(input, sizeof(char) * fileSize);
            checkMemErr(input2);
            input = input2;
        }
        
        // Store the current character
        if ( ! isEOF)
        {
            input[bufferSize++] = curChar;
            lineSize++;
            if ( ! isSpace)
                continue;
        }
        else
        {
            if ( ! bufferSize)
            {
                free(input);
                return 0;
            }
            // Append a space if there is none 
            if (input[bufferSize-1] != ' ')
                input[bufferSize++] = ' ';
            if ( ! lineSize)
                break;
        }
        
        lineNum++;  
        lineSize = 0;
    }
    linebuf = (char**) malloc(sizeof(char*) * lineNum);
    checkMemErr(linebuf);
    
    initLinebuf(linebuf, input, bufferSize);
    
    // Sort the input 
    qsort(linebuf, lineNum, sizeof(char*), cmp);
    
    for (i = 0; i < lineNum; i++)
        strWrite(linebuf[i]);
    
    free(linebuf);
    free(input);
    return 0;
}

