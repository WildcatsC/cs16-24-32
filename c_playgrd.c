#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b) {
return (*(int*)a - *(int*)b);
}

int main(){
	int values[] = { 40, 10, 100, 90, 20, 25 };
qsort(values, 6, sizeof(int), compare);
int i;
for(i = 0; i < 6; ++i) {
printf("%d\n", values[i]);
}

	
	return 0;
}
