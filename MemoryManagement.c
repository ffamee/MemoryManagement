#include <stdio.h>
#include <stdlib.h>

int init_global_var = 5;
int uninit_global_var1;
int init_global_var2 = 5;
int uninit_global_var2;
char word[3][8] = {"first", "second", "third"};

void recursive(int i){
	if (i == 4) return ;
	int local_var1 = i;
	int local_var2 = i;
	int local_var3 = i;
	int *malloc_var1 = (int *)malloc(sizeof(int));
	int *malloc_var2 = (int *)malloc(sizeof(int));
	int *malloc_var3 = (int *)malloc(sizeof(int));
	printf("at the %s recursive call\n", word[i-1]);
	printf("address of local_var1:           %p\n", &local_var1);
	printf("address of local_var2:           %p\n", &local_var2);
	printf("address of local_var3:           %p\n", &local_var3);
	printf("address of malloc_var1:          %p\n", malloc_var1);
	printf("address of malloc_var2:          %p\n", malloc_var2);
	printf("address of malloc_var3:          %p\n", malloc_var3);
	printf("+--------------------------------------+\n");
	recursive(i+1);
	free(malloc_var1);
	free(malloc_var2);
	free(malloc_var3);
	return ;
}

int main(int argc, char *argv[]){
	printf("---- Part 1: text segment ----\n");
	printf("address of recursive function:  %p\n", recursive);
	printf("address of main function:       %p\n", main);
	printf("\n---- Part 2: data segment ----\n");
	printf("address of inti_global_var:     %p\n", &init_global_var);
	printf("address of inti_global_var2:    %p\n", &init_global_var2);
	printf("address of uninit_global_var1:  %p\n", &uninit_global_var1);
	printf("address of uninit_global_var2:  %p\n", &uninit_global_var2);
	printf("\n---- Part 3: stack and heap segment ----\n");
	printf("represents the starting point of the stack at: %p\n", &argc);
	printf("start recursive:\n");
	recursive(1);
}
