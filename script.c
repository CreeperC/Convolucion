#include "stdio.h"
#include "stdlib.h" 
#include "math.h"
#include "script.h"

int convolucionar_float(char nombre[],char out[], float matrix[][3])
{
		
	
	
	float aux1=matrix[0][0], aux2=matrix[0][1], aux3=matrix[0][2];
	matrix[0][0]=matrix[2][0];
	matrix[0][1]=matrix[2][1];
	matrix[0][2]=matrix[2][2];
	
	matrix[2][0]=aux1;
	matrix[2][1]=aux2;
	matrix[2][2]=aux3;
	
	
	
	FILE *img1, *img2;
	
	int space[54];
	
	img1=fopen(nombre,"r");	
    img2=fopen(out,"w");
    
    for(int i= 0;i<54;i++)
    {	
    	space[i]=fgetc(img1);
    	//printf("%c|",space[i]);
		fputc(space[i],img2);	
	}
	
	int ancho = space[18] +space[19] * 256  + space[20] * 256  * 256 +space[21] * 256 * 256 * 256;
    int alto = space[22] +space[23] * 256  + space[24] * 256  * 256 +space[25] * 256 * 256 * 256;
                     
	//printf("\n %d ",ancho);
	//printf("\n %d \n\n",alto);
	
	fflush(stdin);
	int i,j;
	
	
	int **imagen;
	imagen = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen[i] = (int*)malloc(ancho*sizeof(int)); 
	}
		
	
	int a,b,ce;
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++){	
			a=fgetc(img1);
			b=fgetc(img1);
			ce=fgetc(img1);
			
			if(a==b && b==ce)
			{
				imagen[i][j]=a;
				//printf("%d,%d,%d\t ",imagen[i][j],b,c);
			}
			else
			{
			 printf("\nERROR %d = %d = %d",a,b,ce);
			}
		}
		//printf("\n");
	}
	
	/*
	printf("\n\n\n");
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{
			printf("%d\t ",imagen[i][j]);
		}
		printf("\n\n");
	}
	*/
	/////TRATAMIENTO DE LA MATRIZ DE CONvOLUCION
	
	float **imagen2;
	imagen2 = (float **)malloc(alto*sizeof(float*)); 
	for (i=0;i<alto;i++) 
	{
		imagen2[i] = (float*)malloc(ancho*sizeof(float)); 
	}
	
	
	//cALCULAR C
	float c=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c=c+matrix[i][j];
		}
	}
	
	//printf("c=%d",c);
	if(c==0){c=1;}
	//aPLICAR CONVOLUCION
	for(i=1;i<alto-1;i++)
	{
		for(j=1;j<ancho-1;j++)
		{	
			
			imagen2[i][j]=imagen[i][j]*matrix[1][1]+imagen[i-1][j]*matrix[0][1]+imagen[i][j-1]*matrix[1][0]+imagen[i-1][j-1]*matrix[0][0]+imagen[i+1][j]*matrix[2][1]+imagen[i][j+1]*matrix[1][2]+imagen[i+1][j+1]*matrix[2][2]+imagen[i-1][j+1]*matrix[0][2]+imagen[i+1][j-1]*matrix[2][0];
			imagen2[i][j]=imagen2[i][j]/c;
			imagen2[i][j]=abs(imagen2[i][j]);
			
			//imagen2[i][j]=sqrt(imagen2[i][j]*imagen2[i][j]);	
		}
		
	}
	
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{	
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
		}
		
	}
		
	fclose(img1);
	fclose(img2);
	return 0;
	
	
}

int filtroKirch(char nombre[], char out[])
{
	int vertical[3][3]={{ 1, 1, 1},
	                      { 0, 0, 0},
	                      {-1,-1,-1}};
	                      
	int horizontal[3][3]={{-1,0,1},
	                    {-1,0,1},
	                    {-1,0,1}};
							                      
	int kirch1[3][3]=  {{ 0, 1, 1},
	                    {-1, 0, 1},
	                    {-1,-1, 0}};
							            
	int kirch2[3][3]=  {{ -1,-1, 0},
	                    { -1, 0, 1},
	                    {  0, 1, 1}};
	                    
	                    

    FILE *img1, *img2;
	
	int space[54];
	
	img1=fopen(nombre,"r");	
    img2=fopen(out,"w");
    
    for(int i= 0;i<54;i++)
    {	
    	space[i]=fgetc(img1);
    	//printf("%c|",space[i]);
		fputc(space[i],img2);	
	}
	
	int ancho = space[18] +space[19] * 256  + space[20] * 256  * 256 +space[21] * 256 * 256 * 256;
    int alto = space[22] +space[23] * 256  + space[24] * 256  * 256 +space[25] * 256 * 256 * 256;
                     
	//printf("\n %d ",ancho);
	//printf("\n %d \n\n",alto);
	
	fflush(stdin);
	int i,j;
	
	
	int **imagen;
	imagen = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen[i] = (int*)malloc(ancho*sizeof(int)); 
	}
		
	
	int a,b,c;
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++){	
			a=fgetc(img1);
			b=fgetc(img1);
			c=fgetc(img1);
			
			if(a==b && b==c)
			{
				imagen[i][j]=a;
				//printf("%d,%d,%d\t ",imagen[i][j],b,c);
			}
			else
			{
			 printf("\nERROR %d = %d = %d",a,b,c);
			}
		}
		//printf("\n");
	}
	
	/*
	printf("\n\n\n");
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{
			printf("%d\t ",imagen[i][j]);
		}
		printf("\n\n");
	}
	*/
	/////TRATAMIENTO DE LA MATRIZ DE CONvOLUCION
	
	int **imagen2;
	imagen2 = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen2[i] = (int*)malloc(ancho*sizeof(int)); 
	}
	
	int v,h,k1,k2;
	//aPLICAR CONVOLUCION
	for(i=1;i<alto-1;i++)
	{
		for(j=1;j<ancho-1;j++)
		{	
			
			v=imagen[i][j]*vertical[1][1]+imagen[i-1][j]*vertical[0][1]+imagen[i][j-1]*vertical[1][0]+imagen[i-1][j-1]*vertical[0][0]+imagen[i+1][j]*vertical[2][1]+imagen[i][j+1]*vertical[1][2]+imagen[i+1][j+1]*vertical[2][2]+imagen[i-1][j+1]*vertical[0][2]+imagen[i+1][j-1]*vertical[2][0];
			h=imagen[i][j]*horizontal[1][1]+imagen[i-1][j]*horizontal[0][1]+imagen[i][j-1]*horizontal[1][0]+imagen[i-1][j-1]*horizontal[0][0]+imagen[i+1][j]*horizontal[2][1]+imagen[i][j+1]*horizontal[1][2]+imagen[i+1][j+1]*horizontal[2][2]+imagen[i-1][j+1]*horizontal[0][2]+imagen[i+1][j-1]*horizontal[2][0];
			k1=imagen[i][j]*kirch1[1][1]+imagen[i-1][j]*kirch1[0][1]+imagen[i][j-1]*kirch1[1][0]+imagen[i-1][j-1]*kirch1[0][0]+imagen[i+1][j]*kirch1[2][1]+imagen[i][j+1]*kirch1[1][2]+imagen[i+1][j+1]*kirch1[2][2]+imagen[i-1][j+1]*kirch1[0][2]+imagen[i+1][j-1]*kirch1[2][0];
			k2=imagen[i][j]*kirch2[1][1]+imagen[i-1][j]*kirch2[0][1]+imagen[i][j-1]*kirch2[1][0]+imagen[i-1][j-1]*kirch2[0][0]+imagen[i+1][j]*kirch2[2][1]+imagen[i][j+1]*kirch2[1][2]+imagen[i+1][j+1]*kirch2[2][2]+imagen[i-1][j+1]*kirch2[0][2]+imagen[i+1][j-1]*kirch2[2][0];
			
			
			
			v=abs(v);
			h=abs(h);
			k1=abs(k1);
			k2=abs(k2);
			
			if(v>=h && v>=k1 && v>=k2 )
			{
				imagen2[i][j]=v;
			}
			if(h>=v && h>=k1 && h>=k2 )
			{
				imagen2[i][j]=h;
			}
			
			if(k1>=h && k1>=v && k1>=k2 )
			{
				imagen2[i][j]=k1;
			}
			
			if(k2>=h && k2>=k1 && k2>=v )
			{
				imagen2[i][j]=v;
			}
				
		}
		
	}
	
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{	
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
		}
		
	}
		
	fclose(img1);
	fclose(img2);
	return 0;
	
}



int convolucionar_Magnitud(char nombre[],char out[],int matrix[][3], int matrix2[][3])
{
	
	int aux1=matrix[0][0], aux2=matrix[0][1], aux3=matrix[0][2];
	matrix[0][0]=matrix[2][0];
	matrix[0][1]=matrix[2][1];
	matrix[0][2]=matrix[2][2];
	
	matrix[2][0]=aux1;
	matrix[2][1]=aux2;
	matrix[2][2]=aux3;
	
	
	aux1=matrix2[0][0], aux2=matrix2[0][1], aux3=matrix2[0][2];
	matrix2[0][0]=matrix2[2][0];
	matrix2[0][1]=matrix2[2][1];
	matrix2[0][2]=matrix2[2][2];
	
	matrix2[2][0]=aux1;
	matrix2[2][1]=aux2;
	matrix2[2][2]=aux3;
	
	
	
	FILE *img1, *img2;
	
	int space[54];
	
	img1=fopen(nombre,"r");	
    img2=fopen(out,"w");
    
    for(int i= 0;i<54;i++)
    {	
    	space[i]=fgetc(img1);
    	//printf("%c|",space[i]);
		fputc(space[i],img2);	
	}
	
	int ancho = space[18] +space[19] * 256  + space[20] * 256  * 256 +space[21] * 256 * 256 * 256;
    int alto = space[22] +space[23] * 256  + space[24] * 256  * 256 +space[25] * 256 * 256 * 256;
                     
	//printf("\n %d ",ancho);
	//printf("\n %d \n\n",alto);
	
	fflush(stdin);
	int i,j;
	
	
	int **imagen;
	imagen = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen[i] = (int*)malloc(ancho*sizeof(int)); 
	}
		
	
	int a,b,c;
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++){	
			a=fgetc(img1);
			b=fgetc(img1);
			c=fgetc(img1);
			
			if(a==b && b==c)
			{
				imagen[i][j]=a;
				//printf("%d,%d,%d\t ",imagen[i][j],b,c);
			}
			else
			{
			 printf("\nERROR %d = %d = %d",a,b,c);
			}
		}
		//printf("\n");
	}
	
	/*
	printf("\n\n\n");
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{
			printf("%d\t ",imagen[i][j]);
		}
		printf("\n\n");
	}
	*/
	/////TRATAMIENTO DE LA MATRIZ DE CONvOLUCION
	
	int **imagen2;
	imagen2 = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen2[i] = (int*)malloc(ancho*sizeof(int)); 
	}
	
	
	//cALCULAR C
	c=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c=c+matrix[i][j];
		}
	}
	int aux, c2=0;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c2=c2+matrix2[i][j];
		}
	}
	
	
	
	
	//printf("c=%d",c);
	if(c==0){c=1;}
	if(c2==0){c2=1;}
	//aPLICAR CONVOLUCION
	for(i=1;i<alto-1;i++)
	{
		for(j=1;j<ancho-1;j++)
		{	
			
			imagen2[i][j]=imagen[i][j]*matrix[1][1]+imagen[i-1][j]*matrix[0][1]+imagen[i][j-1]*matrix[1][0]+imagen[i-1][j-1]*matrix[0][0]+imagen[i+1][j]*matrix[2][1]+imagen[i][j+1]*matrix[1][2]+imagen[i+1][j+1]*matrix[2][2]+imagen[i-1][j+1]*matrix[0][2]+imagen[i+1][j-1]*matrix[2][0];
			imagen2[i][j]=imagen2[i][j]/c;
			
			          
			aux=imagen[i][j]*matrix2[1][1]+imagen[i-1][j]*matrix2[0][1]+imagen[i][j-1]*matrix2[1][0]+imagen[i-1][j-1]*matrix2[0][0]+imagen[i+1][j]*matrix2[2][1]+imagen[i][j+1]*matrix2[1][2]+imagen[i+1][j+1]*matrix2[2][2]+imagen[i-1][j+1]*matrix2[0][2]+imagen[i+1][j-1]*matrix2[2][0];
			aux=aux/c;
			
			imagen2[i][j]=sqrt(imagen2[i][j]*imagen2[i][j]+aux*aux);
				
		}
		
	}
	
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{	
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
		}
		
	}
		
	fclose(img1);
	fclose(img2);
	return 0;
}




int umbralizar(char nombre[],char out[], int umbral)
{
	FILE *img1, *img2;
	
	int space[54];
	
	img1=fopen(nombre,"r");	
    img2=fopen(out,"w");
    
    
    
    for(int i= 0;i<54;i++)
    {	
    	space[i]=fgetc(img1);
    	//printf("%c|",space[i]);
		fputc(space[i],img2);	
	}
	/*
	int ancho = space[18] +space[19] * 256  + space[20] * 256  * 256 +space[21] * 256 * 256 * 256;
    int alto = space[22] +space[23] * 256  + space[24] * 256  * 256 +space[25] * 256 * 256 * 256;
                     
	printf("\n %d ",ancho);
	printf("\n %d ",alto);
	*/
	
	
	int r,g,b;
	do{
		
		g=fgetc(img1);
		b=fgetc(img1);
		r=fgetc(img1);
		
		
		
		if((r+g+b)/3<umbral)
		{
			fputc((255),img2);
			fputc((255),img2);
			fputc((255),img2);
		}
		else
		{
			fputc((0),img2);
			fputc((0),img2);
			fputc((0),img2);			
		}
			
	}while((r!=EOF && g!=EOF && b!=EOF));
	
		
	fclose(img1);
	fclose(img2);
	return 0;
}


int convolucionar_abs(char nombre[],char out[],int matrix[][3])
{
	
	
	
	int aux1=matrix[0][0], aux2=matrix[0][1], aux3=matrix[0][2];
	matrix[0][0]=matrix[2][0];
	matrix[0][1]=matrix[2][1];
	matrix[0][2]=matrix[2][2];
	
	matrix[2][0]=aux1;
	matrix[2][1]=aux2;
	matrix[2][2]=aux3;
	
	
	
	FILE *img1, *img2;
	
	int space[54];
	
	img1=fopen(nombre,"r");	
    img2=fopen(out,"w");
    
    for(int i= 0;i<54;i++)
    {	
    	space[i]=fgetc(img1);
    	//printf("%c|",space[i]);
		fputc(space[i],img2);	
	}
	
	int ancho = space[18] +space[19] * 256  + space[20] * 256  * 256 +space[21] * 256 * 256 * 256;
    int alto = space[22] +space[23] * 256  + space[24] * 256  * 256 +space[25] * 256 * 256 * 256;
                     
	//printf("\n %d ",ancho);
	//printf("\n %d \n\n",alto);
	
	fflush(stdin);
	int i,j;
	
	
	int **imagen;
	imagen = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen[i] = (int*)malloc(ancho*sizeof(int)); 
	}
		
	
	int a,b,c;
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++){	
			a=fgetc(img1);
			b=fgetc(img1);
			c=fgetc(img1);
			
			if(a==b && b==c)
			{
				imagen[i][j]=a;
				//printf("%d,%d,%d\t ",imagen[i][j],b,c);
			}
			else
			{
			 printf("\nERROR %d = %d = %d",a,b,c);
			}
		}
		//printf("\n");
	}
	
	/*
	printf("\n\n\n");
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{
			printf("%d\t ",imagen[i][j]);
		}
		printf("\n\n");
	}
	*/
	/////TRATAMIENTO DE LA MATRIZ DE CONvOLUCION
	
	int **imagen2;
	imagen2 = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen2[i] = (int*)malloc(ancho*sizeof(int)); 
	}
	
	
	//cALCULAR C
	c=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c=c+matrix[i][j];
		}
	}
	
	//printf("c=%d",c);
	if(c==0){c=1;}
	//aPLICAR CONVOLUCION
	for(i=1;i<alto-1;i++)
	{
		for(j=1;j<ancho-1;j++)
		{	
			
			imagen2[i][j]=imagen[i][j]*matrix[1][1]+imagen[i-1][j]*matrix[0][1]+imagen[i][j-1]*matrix[1][0]+imagen[i-1][j-1]*matrix[0][0]+imagen[i+1][j]*matrix[2][1]+imagen[i][j+1]*matrix[1][2]+imagen[i+1][j+1]*matrix[2][2]+imagen[i-1][j+1]*matrix[0][2]+imagen[i+1][j-1]*matrix[2][0];
			imagen2[i][j]=imagen2[i][j]/c;
			imagen2[i][j]=abs(imagen2[i][j]);
			
			//imagen2[i][j]=sqrt(imagen2[i][j]*imagen2[i][j]);	
		}
		
	}
	
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{	
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
		}
		
	}
		
	fclose(img1);
	fclose(img2);
	return 0;
}



int convolucionar(char nombre[],char out[],int matrix[][3])
{
	
	int aux1=matrix[0][0], aux2=matrix[0][1], aux3=matrix[0][2];
	matrix[0][0]=matrix[2][0];
	matrix[0][1]=matrix[2][1];
	matrix[0][2]=matrix[2][2];
	
	matrix[2][0]=aux1;
	matrix[2][1]=aux2;
	matrix[2][2]=aux3;
	
	
	
	
	
	
	
	FILE *img1, *img2;
	
	int space[54];
	
	img1=fopen(nombre,"r");	
    img2=fopen(out,"w");
    
    for(int i= 0;i<54;i++)
    {	
    	space[i]=fgetc(img1);
    	//printf("%c|",space[i]);
		fputc(space[i],img2);	
	}
	
	int ancho = space[18] +space[19] * 256  + space[20] * 256  * 256 +space[21] * 256 * 256 * 256;
    int alto = space[22] +space[23] * 256  + space[24] * 256  * 256 +space[25] * 256 * 256 * 256;
                     
	//printf("\n %d ",ancho);
	//printf("\n %d \n\n",alto);
	
	fflush(stdin);
	int i,j;
	
	
	int **imagen;
	imagen = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen[i] = (int*)malloc(ancho*sizeof(int)); 
	}
		
	
	int a,b,c;
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++){	
			a=fgetc(img1);
			b=fgetc(img1);
			c=fgetc(img1);
			
			if(a==b && b==c)
			{
				imagen[i][j]=a;
				//printf("%d,%d,%d\t ",imagen[i][j],b,c);
			}
			else
			{
			 printf("\nERROR %d = %d = %d",a,b,c);
			}
		}
		//printf("\n");
	}
	
	/*
	printf("\n\n\n");
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{
			printf("%d\t ",imagen[i][j]);
		}
		printf("\n\n");
	}
	*/
	/////TRATAMIENTO DE LA MATRIZ DE CONvOLUCION
	
	int **imagen2;
	imagen2 = (int **)malloc(alto*sizeof(int*)); 
	for (i=0;i<alto;i++) 
	{
		imagen2[i] = (int*)malloc(ancho*sizeof(int)); 
	}
	
	
	//cALCULAR C
	c=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			c=c+matrix[i][j];
		}
	}
	
	//printf("c=%d",c);
	if(c==0){c=1;}
	//aPLICAR CONVOLUCION
	for(i=1;i<alto-1;i++)
	{
		for(j=1;j<ancho-1;j++)
		{	
			
			imagen2[i][j]=imagen[i][j]*matrix[1][1]+imagen[i-1][j]*matrix[0][1]+imagen[i][j-1]*matrix[1][0]+imagen[i-1][j-1]*matrix[0][0]+imagen[i+1][j]*matrix[2][1]+imagen[i][j+1]*matrix[1][2]+imagen[i+1][j+1]*matrix[2][2]+imagen[i-1][j+1]*matrix[0][2]+imagen[i+1][j-1]*matrix[2][0];
			imagen2[i][j]=imagen2[i][j]/c;
			//imagen2[i][j]=abs(imagen2[i][j]);
			
			//imagen2[i][j]=sqrt(imagen2[i][j]*imagen2[i][j]);	
		}
		
	}
	
	for(i=0;i<alto;i++)
	{
		for(j=0;j<ancho;j++)
		{	
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
			fputc(imagen2[i][j],img2);
		}
		
	}
		
	fclose(img1);
	fclose(img2);
	return 0;
}



int filtro_gris(char nombre[], char out[])
{
	FILE *img1, *img2;
	
	int space[54];
	
	img1=fopen(nombre,"r");	
    img2=fopen(out,"w");
    
    
    
    for(int i= 0;i<54;i++)
    {	
    	space[i]=fgetc(img1);
    	//printf("%c|",space[i]);
		fputc(space[i],img2);	
	}
	/*
	int ancho = space[18] +space[19] * 256  + space[20] * 256  * 256 +space[21] * 256 * 256 * 256;
    int alto = space[22] +space[23] * 256  + space[24] * 256  * 256 +space[25] * 256 * 256 * 256;
                     
	printf("\n %d ",ancho);
	printf("\n %d ",alto);
	*/
	
	
	int r,g,b;
	do{
		
		g=fgetc(img1);
		b=fgetc(img1);
		r=fgetc(img1);
		
		fputc((g+b+r)/3,img2);
		fputc((g+b+r)/3,img2);
		fputc((g+b+r)/3,img2);			
	}while((r!=EOF && g!=EOF && b!=EOF));
	
		
	fclose(img1);
	fclose(img2);
	return 0;
}
