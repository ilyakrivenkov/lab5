#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
int main(){
// Создадим квадратный массив размера size
	int size;
	printf("Put size:\n");
	scanf("%d", &size);
	int* a;
	int i, j, count = 0;
	srand(time(NULL));
	a = (int*)malloc(sizeof(int) * size);

    int** array = (int**)malloc(sizeof(int*) * size);
    for(i = 0; i < size; i++)
        array[i] = (int*)malloc(sizeof(int) * size);

	//for (i = 0; i < size; i++) {
	//	for (int j = 0; j < size; j++) {
	//		array[i][j] = array[j][i] = rand() % 2;
	//		array[i][i] = 0;
	//		printf("%4d", array[i][j]);
	//	}
	//	printf("\n");
	//}


	for (i = 0; i < size; i++) {
		a[i] = 0;
        for (j = i; j < size; j++) {
			if (i==j){
				array[i][j] = 0;
				continue;
			}
            array[i][j] = rand() % 2;
			array[j][i] = array[i][j];
			if (array[i][j] == 1) { count++; }
            //printf("%3d", array[i][j]);
        }
    }


	
	for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
			printf("%3d", array[i][j]);
		if(array[i][j] != 0)
			a[i] += 1;
		}
		printf("\n");
	}
	printf("\n");

	for (i = 0; i < size; i++) {
		if(a[i] == 1){
			printf("end = %d\n", i);}
	}

	printf("\n");

	for (i = 0; i < size; i++) {
		if(a[i] == 0){
			printf("isolated = %d\n", i);}
	}

	for (i = 0; i < size; i++) {
		if(a[i] == size - 1){
			printf("dominated = %d\n", i);}
	}
	printf("\n");
	/*for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
			if(array[j][i]==array[i][j])
				count++;
		}
	}*/
	printf("\n");
	printf("graph size = %d\n", count);
	printf("\n");
    // Очистим память
    for(i = 0; i < size; i++)
        free(array[i]);
    free(array);


}