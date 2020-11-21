#include <stdio.h>
#include <stdlib.h>

int main(){
	int* k = NULL;
	k = (int*)malloc(4);
	printf("%lu", sizeof(k));
	free(k);
	return 0;
}
