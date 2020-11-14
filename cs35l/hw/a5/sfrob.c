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
// inline
void reportErr(const char* msg){
    fprintf(stderr, "%s Error: %d\n", msg, errno);
    exit(1);
}

// Check IO Error 
// inline
void checkIOErr(FILE* p){
    if (ferror(p))      
        reportErr("IO Error");
}

// Check if malloc / realloc allocates memory successfully 
// inline
void checkMemErr(void* ptr){
    if (ptr == NULL)    
        reportErr("Memory Leak");
}

//  Decrypt each character 
// inline
char decrypt(const char a){
    return a ^ 42;      // 00101010 is 0x2a, 42 
}

// Wrapper function 
// inline
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
    // Declare Variables, a pain in C 
    int (* cmp) (const void*, const void*);
    char* input, * input2, ** linebuf, curChar;
    size_t lineNum, lineSize, bufferSize, i, fileSize;
    int isEOF, isSpace;
    
    // Initialize variables 
    bufferSize = 0, lineNum = 0, lineSize = 0, isEOF = feof(stdin);
    fileSize = 20;
    
    // Set frobcmp pointer
    cmp = &cmpWrapper;
    
    // Setup Initial Buffer 
    input = (char*) malloc(sizeof(char) * fileSize);
    checkMemErr(input);
    
    /*                                                      *
     *  To prevent getting a char with value EOF,           *
     *  We use feof(STDIN_FILENO) as the condition for the loop.   *
     */
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
                return 0;         // An Empty file or a file with only spaces
            }
            // Append a space if there is none 
            if (input[bufferSize-1] != ' ')
                input[bufferSize++] = ' ';
            if ( ! lineSize)
                break;
        }
        
        lineNum++;  // New Line
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

