#include "stdio.h"
#include "stdlib.h" 
#include "math.h"
#include "script.c"
int main()
{
	
	filtro_gris("ejemplo.bmp","ejemplo_gris.bmp");
	int kernel[3][3]=  {{-1, 0,  1},
	                      {-1, 0,  1},
						  {-1, 0,  1}};
	convolucionar_abs("ejemplo_gris.bmp","ejemplo_gris_bordes.bmp",kernel);
	umbralizar("ejemplo_gris_bordes.bmp","ejemplo_gris_bordes_umbral.bmp",10);
	                      
    
}