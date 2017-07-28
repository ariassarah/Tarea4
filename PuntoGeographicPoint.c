#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <time.h>
int Nx;
int Ny;
int N = 120877;

void freePointer(double **matrix);
float Calcular_radio(double x0, double y0, double *x, double *y);
void ind(double **matrix, double *x, double *y);
void cargar_datos(double **Matriz);
double _random(void);

int main(void)
{
    int filas = 500;
    int columnas = 744;
    int i,j;
    double *x = malloc(sizeof(double)*N);
    double *y = malloc(sizeof(double)*N);

    double **matrix = malloc(filas*sizeof(double *));
    
    for (i = 0; i < filas; i++)
    {
        matrix[i] = malloc(columnas*sizeof(double));
    }

    cargar_datos(matrix);
    
    ind(matrix,x,y);
    //freePointer(matrix);
    FILE *datos;
    datos = fopen("datos.txt","w+");
    double x0, xf, yf, y0, r0, rf, alpha;
    double delta = 5;
    double rangox = N/500;
    double rangoy = N/744;
    xf = 2*_random() *N/500;
    
    yf = 2*_random() *N/744;
    rf = Calcular_radio(xf, yf,x,y);
    for (int i = 0; i < 1000; ++i)
    {
        
    
    x0 = xf + (2*_random() - 1)*delta;
    
    y0 = yf + (2*_random() - 1)*delta;
    
    if(x0 < 0){
        x0 = 744-x0;
    }
    if(x0> 744){
        x0 = x0-744;
    }
    if(y0<0){
        y0= 500-y0;
    }
    if(y0>500){
        y0 = y0 - 500;
    }
    r0 = Calcular_radio(x0, y0,x,y);

    alpha = exp((r0 - rf));

        if(alpha > 1)
        {
            alpha = 1;
        }
        if(alpha > _random())
        {
            xf = x0;
            yf = y0;
            rf = r0;
}
        fprintf(datos,"%f %f %f\n", xf, yf, rf);
       

}
    
    
//fclose(data);
    return 0;
}


void ind(double **matrix, double *x, double *y){
    int i,j;
    int k =0;
    for (i = 0; i < 500; i++)
    {
        for(j = 0; j < 744; j++){
            if(matrix[i][j] == 1){
                x[k] = i;
                y[k] = j;
                k = k +1;
            }
        }
    }
}
float Calcular_radio(double xp, double yp,double *x, double *y){
    int i;
    double actual, radio;
    actual = pow(pow(x[0] - xp, 2.0) + pow(y[0] - yp, 2.0), 0.5) ;
    for(i = 1; i<N; i++)
    {
        radio = pow(pow(x[i] - xp, 2.0) + pow(y[i] - yp, 2.0), 0.5) ;
        if(radio < actual)
        {
            actual = radio;
        }
    }
    return actual;
    
}
void cargar_datos(double **Matriz)
{
 
    char *delimiter=" ";

    FILE *infile=fopen("map_data.txt","r");

    char datos[2000];
    char * a;

    int j=0;
    while(fscanf(infile, "%s",datos)==1)
    {
        

            a = strtok(datos," ");
        Matriz[j/744][j%744]=atof(a);
        
        j++;

    }


    fclose(infile);

}
double _random(void)
{
    return (double) rand()/RAND_MAX;
}

void freePointer(double **matrix)
{
    int i;
    for(i = 0; i<Ny; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}