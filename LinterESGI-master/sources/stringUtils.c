/*
	Creator : LAURENT Louis 20181021
	Last change : LAURENT Louis 20181027

	Fichier avec des utilitaires pour les chaines de caractères.

*/

#include "stringUtils.h"

void** initArray2(char* type, int collums, int* cells){
	void** result = NULL;

	if(strcmp(type, "char") == 0){
		result = (void**)initChar2(collums, cells);

	}else if(strcmp(type, "int") == 0){
		result = (void**)initInt2(collums, cells);

	}else if(strcmp(type, "double") == 0){
		result = (void**)initDouble2(collums, cells);

	}else if(strcmp(type, "float") == 0){
		result = (void**)initFloat2(collums, cells);

	}else{
		return NULL;
	}

	return result;
}

void* initArray(char* type, int size){
	void* result = NULL;

	if(strcmp(type, "char") == 0){
		result = (void*)initChar(size);

	}else if(strcmp(type, "int") == 0){
		result = (void*)initInt(size);

	}else if(strcmp(type, "double") == 0){
		result = (void*)initDouble(size);

	}else if(strcmp(type, "float") == 0){
		result = (void*)initFloat(size);

	}else{
		return NULL;
	}

	return result;
} 

char** initChar2(int collums, int* cells){
		char** result = NULL;
		int i = 0;

		result = malloc(sizeof(char*) * collums);
		if(result == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}
		for(i = 0; i < collums; i++){
			result[i] = malloc(sizeof(char) * (cells[i] + 1));
			if(result[i] == NULL){
				printf("Erreur d'allocation \n");
				free(result);
				exit(EXIT_FAILURE);
			}
		}

		return result;	
} 

char* initChar(int size){
		char* result = NULL;

		result = malloc(sizeof(char) * (size + 1));
		if(result == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}

		return result;	
}

int** initInt2(int collums, int* cells){
		int** result = NULL;
		int i = 0;

		result = malloc(sizeof(int*) * collums);
		if(result == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}
		for(i = 0; i < collums; i++){
			result[i] = malloc(sizeof(int) * cells[i]);
			if(result[i] == NULL){
				printf("Erreur d'allocation \n");
				free(result);
				exit(EXIT_FAILURE);
			}
		}

		return result;	
}

int* initInt(int size){
		int* result = NULL;

		result = malloc(sizeof(int) * size);
		if(result == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}

		return result;	
}

float** initFloat2(int collums, int* cells){
		float** result = NULL;
		int i = 0;

		result = malloc(sizeof(float*) * collums);
		if(result[i] == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}
		for(i = 0; i < collums; i++){
			result[i] = malloc(sizeof(float) * cells[i]);
			if(result[i] == NULL){
				printf("Erreur d'allocation \n");
				free(result);
				exit(EXIT_FAILURE);
			}
		}

		return result;	
}

float* initFloat(int size){
		float* result = NULL;

		result = malloc(sizeof(float) * size);
		if(result == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}

		return result;	
}

double** initDouble2(int collums, int* cells){
		double** result = NULL;
		int i = 0;

		result = malloc(sizeof(double*) * collums);
		if(result == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}
		for(i = 0; i < collums; i++){
			result[i] = malloc(sizeof(double) * cells[i]);
			if(result[i] == NULL){
				printf("Erreur d'allocation \n");
				free(result);
				exit(EXIT_FAILURE);
			}
		}

		return result;	
}

double* initDouble(int size){
		double* result = NULL;

		result = malloc(sizeof(double) * size);
		if(result == NULL){
			printf("Erreur d'allocation \n");
			exit(EXIT_FAILURE);
		}

		return result;	
}

void showArray2(char* type, void** array, int collums, int cells){
	if(strcmp(type, "char") == 0){
		showChar2((char**)array, collums);

	}else if(strcmp(type, "int") == 0){
		showInt2((int**)array, collums, cells);

	}else if(strcmp(type, "double") == 0){
		showDouble2((double**)array, collums, cells);

	}else if(strcmp(type, "float") == 0){
		showFloat2((float**)array, collums, cells);

	}
}

void showChar2(char** array, int collums){
	int i = 0;
	
	for(i = 0; i < collums; i++){
		fprintf(stdout, "%s\n", array[i]);
	}
}


void showInt2(int** array, int collums, int cells){
	int i = 0;
	int y = 0;

	for(i = 0; i < collums; i++){
		for(y = 0; y < cells; y++){
			fprintf(stdout, "%d\n", array[i][y]);
		}
	}
}

void showDouble2(double** array, int collums, int cells){
	int i = 0;
	int y = 0;

	for(i = 0; i < collums; i++){
		for(y = 0; y < cells; y++){
			fprintf(stdout, "%lf\n", array[i][y]);
		}
	}
}

void showFloat2(float** array, int collums, int cells){
	int i = 0;
	int y = 0;

	for(i = 0; i < collums; i++){
		for(y = 0; y < cells; y++){
			fprintf(stdout, "%f\n", array[i][y]);
		}
	}
}

void freeArray2(void** array, int collums){
	int i = 0;

	for(i = 0; i < collums; i++)
		free(array[i]);

	free(array);
}