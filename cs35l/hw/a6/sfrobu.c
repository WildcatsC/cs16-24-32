#include <unistd.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

const char decoder = '*';
const int ARRAY_SIZE = 10;
const int CHAR_SIZE = 10;
int option_f = 0;

// helper functions:
int frobcmp(char const * a, char const * b);
int frobcmp_f(char const * a, char const * b);
int qsort_fcmp (const void * left, const void * right);
int qsort_fcmp_f (const void * left, const void * right);

void free_space(char ** wordlist, long list_size){
    long index;
    for(index = 0; index < list_size; index++){
        free(wordlist[index]);
    }
    free(wordlist);
}


// MAIN 
int main(int argc, char * argv[]){
    //check error
    if(argc == 2){
        char * op = argv[1];
        if(strcmp(op, "-f") != 0){
            char err_message[] = "Invalid option, use \'-f\'.\n";
            write(2, err_message, sizeof(err_message));
            exit(1);
        }
        else{
            option_f = 1;
        }
    }
    else if(argc == 1){
        option_f = 0;
    }
    else{
        char err_message[] = "Invalid operand number.\n";
        write(2, err_message, sizeof(err_message));
        exit(1);
    }


    char temp_input;  // temporary input character
    char * file_copy; // a copy of the file

    struct stat buf;
    long alloc_size;
    int status = fstat(0, &buf);

    if(status == -1){
        char err_message[] = "Unable to obtian file status.\n";
        write(2, err_message, sizeof(err_message));
        exit(1);
    }
    alloc_size = S_ISREG(buf.st_mode) ? buf.st_size : ARRAY_SIZE;
    file_copy = (char *)malloc(alloc_size * sizeof(char));

    // cannot allocate memory to store file
    if(file_copy == NULL){
        char err_message[] = "Initial allocation of memory failed when copying input.\n";
        write(2, err_message, sizeof(err_message));
        exit(1);
    }

    //read and store everything to file_copy
    int num_char;
    for(num_char = 0; 1; num_char++){
        int rst = read(0,&temp_input,1);
        if(rst == 0){
            break;
        }
        // fail in reading
        else if(rst == -1){
            free(file_copy);
            char err_message[] = "Reading in file failed.\n";
            write(2, err_message, sizeof(err_message));
            exit(1);
        }
        if(num_char >= alloc_size){
            file_copy = (char *)realloc(file_copy, (alloc_size + ARRAY_SIZE) * sizeof(char));
            if(file_copy == NULL) {
                char err_message[] = "reallocation of memory failed when copying input.\n";
                write(2, err_message, sizeof(err_message));
                exit(1);
            }
            alloc_size += ARRAY_SIZE;
        }
        file_copy[num_char] = temp_input;
    } 

    // organize the file_copy into wordlists 
    char ** wordlist = (char **)malloc(ARRAY_SIZE * sizeof(char *));

    // track the whole word list
    int list_size = ARRAY_SIZE;  
    int occupied_size = 0;

    // track word
    int wordlen = 0;   
    int wordsize = 0;    

    // track which character pointer are we currently working on
    int index = 0;

    if (wordlist == NULL){
        char err_message[] = "Initial allocation of memory failed when organizing input.\n";
        write(2, err_message, sizeof(err_message));
        exit(1);
    }

    int n = 0;
    while(n < num_char){
        temp_input = file_copy[n];

        // change size of the character array (word)
        if (wordlen >= wordsize){
            if (wordsize == 0){ // char array not initialized
                wordlist[index] = (char *)malloc(CHAR_SIZE * sizeof(char));
                if (wordlist[index] == NULL){
                    free(file_copy);
                    free_space(wordlist,occupied_size);
                    char err_message[] = "Initial allocation of memory failed when making char_array.\n";
                    write(2, err_message, sizeof(err_message));
                    exit(1);
                }
                wordsize += CHAR_SIZE;
                occupied_size++;
            }
            else{ // array is initialized
                wordlist[index] = (char *)realloc(wordlist[index], (wordsize + CHAR_SIZE) * sizeof(char));
                if (wordlist[index] == NULL){
                    free(file_copy);
                    free_space(wordlist,occupied_size);
                    char err_message[] = "Reallocation of memory failed when making char_array.\n";
                    write(2, err_message, sizeof(err_message));
                    exit(1);
                }
                wordsize += CHAR_SIZE;
            }
        }

        // change the size of the wordlist
        if (occupied_size >= list_size){
            wordlist = (char **)realloc(wordlist, (list_size + ARRAY_SIZE) * sizeof(char *));
            if(wordlist == NULL){
                free(file_copy);
                free_space(wordlist,occupied_size);
                char err_message[] = "Reallocation of memory failed when organizing input.\n";
                write(2, err_message, sizeof(err_message));
                exit(1);
            }
            list_size += ARRAY_SIZE;
        }

        // put the new char in
        wordlist[index][wordlen] = temp_input;
        wordlen++;

        if (temp_input == ' '){
            index++;
            wordsize = 0;
            wordlen = 0;
        }
        // copy next element of file_copy
        n++;
    }

    // free the copy of the file saved
    free(file_copy);

    if (wordlen != 0 && wordlist[index][wordlen-1] != ' '){
        // check if we are putting sp on invalid space
        if (wordlen >= wordsize){
            wordlist[index] = (char *)realloc(wordlist[index], (wordsize + CHAR_SIZE) * sizeof(char));
            if (wordlist[index] == NULL){
                free_space(wordlist,occupied_size);
                char err_message[] = "Reallocation of memory failed when making char_array.\n";
                write(2, err_message, sizeof(err_message));
                exit(1);
            }
            wordsize += CHAR_SIZE;
        }
        wordlist[index][wordlen] = ' ';
        index++;
        wordsize = 0;
        wordlen = 0;
    }



    //sorting according to option
    if(option_f == 0){
        qsort(wordlist,index,sizeof(char *),qsort_fcmp);
    }
    else{
        qsort(wordlist,index,sizeof(char *),qsort_fcmp_f);
    }

    // output result
    int i=0;
    int j;
    for(; i < occupied_size; i++){
        for(j=0; 1; j++){
            int result = write(1, &wordlist[i][j], 1);
            if(result == -1){
                free_space(wordlist,occupied_size);
                char err_message[] = "Output failure.\n";
                write(2, err_message, sizeof(err_message));
                exit(1);
            }
            if(wordlist[i][j]==' '){
                // if we just output space successfully, stop the inner loop.
                break;
            }
        }
    }

    // free the wordlist
    free_space(wordlist,occupied_size);

    /* output the # of comparision */
    //fprintf(stdout, "# string: %d\n", occupied_size);
    //fprintf(stdout, "# comparison: %d\n", comp_num);
    return 0;
}



// ===
// helper functions: 
int frobcmp(char const * a, char const * b){
    //increment comparision count
    //comp_num++;

    if (a == NULL || b == NULL){
        char err_message[] = "Invalid inputs: character array cannot be NULL.\n";
        write(2, err_message, sizeof(err_message));
        exit(1);
    }
    int i = 0;
    while(a[i] == b[i]){
        //increment until one of them hits the space
        if (a[i] == ' ' || b[i] == ' '){
            return 0;
        }
        i++;
    }
    if (a[i] != ' ' && b[i] != ' '){
        int diff = ((a[i]) ^ decoder) < ((b[i]) ^ decoder) ? -1 : 1;
        return diff;
    }
    else if(a[i] == ' '){
        return -1;
    }
    else{
        return 1;
    }
}
//option -f
int frobcmp_f(char const * a, char const * b){
    //increment comparision count
    //comp_num++;

    if (a == NULL || b == NULL){
        char err_message[] = "Invalid inputs: character array cannot be NULL.\n";
        write(2, err_message, sizeof(err_message));
        exit(1);
    }
    int i = 0;
    while( (a[i] != ' ') && (b[i] != ' ') ){
        char temp1 = a[i] ^ decoder;
        char temp2 = b[i] ^ decoder;
        temp1 = (temp1 > -2) ? toupper(temp1) : temp1;
        temp2 = (temp2 > -2) ? toupper(temp2) : temp2;
        if(temp1 == temp2){
            i++;
        }
        else if(temp1 < temp2){
            return -1;
        }
        else{
            return 1;
        }
    }
    if( (a[i] == ' ') && (b[i] == ' ') ){
        return 0;
    }
    else if(a[i] == ' '){
        return -1;
    }
    else{
        return 1;
    }
}

int qsort_fcmp (const void * left, const void * right){
    return ( frobcmp( *(char const **)left, *(char const **)right ) );
}
//option -f
int qsort_fcmp_f (const void * left, const void * right){
    return ( frobcmp_f( *(char const **)left, *(char const **)right ) );
}