#include "stdio.h"
#include "stdlib.h" 
#include "math.h"

int filtro_gris(char nombre[],char out[]);

int umbralizar(char nombre[],char out[], int umbral);

int convolucionar(char nombre[],char out[], int matrix[][3]);

int convolucionar_abs(char nombre[],char out[],int matrix[][3]);

int convolucionar_Magnitud(char nombre[],char out[], int matrix[][3], int matrix2[][3]);

int filtroKirch(char nombre[], char out[]);

int convolucionar_float(char nombre[],char out[], float matrix[][3]);
