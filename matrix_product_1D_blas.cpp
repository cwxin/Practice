#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<cblas.h>

int input_matrix(int size, int N, double *array1, double *array2);
int output_matrix(int size, int N, double *array1, double *array2);
int product_matrix(int size, int N, double *array1, double *array2, double *array3);
int dgemm_row(double *array1, double *array2, double *array5, int N);

int main()
{
   int N, size, i;
   double *array1, *array2, *array3, *array4, *array5, temp;
   double t1, t2, t3, t4;
   printf("Please input the size of the matrix:");
   scanf("%d", &N);
   size=N*N;
   temp=0.0;
   
   array1=(double *) malloc(size*sizeof(double));
   array2=(double *) malloc(size*sizeof(double));
   array3=(double *) malloc(N*sizeof(double));
   array4=(double *) malloc(size*sizeof(double));
   array5=(double *) malloc(size*sizeof(double));

   
   input_matrix(size, N, array1, array2);
   //output_matrix(size, N, array1, array2);
   
   t1=clock();
   product_matrix(size, N, array1, array2, array3);
   t2=clock();
   printf("%.8f sec\n", 1.0*(t2-t1)/CLOCKS_PER_SEC);
    
   for(i=0;i<size;i++)
   {
      array4[i]=array1[i];
   }
   input_matrix(size, N, array1, array2);
   t3=clock();
   dgemm_row(array1, array2, array5, N);
   t4=clock();
   //output_matrix(size, N, array5, array2);
   for(i=0;i<size;i++)
   {
      array1[i]=fabs(array4[i]-array5[i]);
   }

   for(i=0;i<size;i++)
   {
      if(temp>=array1[i])
      {
         temp=temp;
      }
      else
      {
         temp=array1[i];
      }
   }
   printf("max error=%e\n", temp);
   printf("%.8f sec\n", 1.0*(t4-t3)/CLOCKS_PER_SEC);
   
}

int input_matrix(int size, int N, double *array1, double *array2)
{
   int i, t1, t2, t3;
   t1=0;

   while(t1<size)
   {
      for(i=t1;i<N+t1;i++)
      {
         array1[i]=i*1.0;
      }
      t1=t1+N;
   }

   t1=0;
   while(t1<size)
   {
      for(i=t1;i<N+t1;i++)
      {
         array2[i]=i*1.0;
      }
      t1=t1+N;
   }  
}

int output_matrix(int size, int N, double *array5, double *array2)
{
   int i, t1, t2, t3;
   t1=0;
   t3=0;

   printf("A=\n");
   while(t3<N)
   {
      for(i=t1;i<N+t1;i++)
      {
         printf("%.3lf     ", array5[i]);
      }
      t3=t3+1;
      t1=t1+N;
      printf("\n");
   }
 
   /*t1=0;
   t3=0;

   printf("B=\n");
   while(t3<N)
   {
      for(i=t1;i<N+t1;i++)
      {
         printf("%.3lf     ", array2[i]);
      }
      t3=t3+1;
      t1=t1+N;
      printf("\n");
   }*/
}

int product_matrix(int size, int N, double *array1, double *array2, double *array3)
{
   int i, j, k, t1, t2, t3, t4;
   double n;
   t1=0;
   t2=0;
   t3=0;
   t4=0;
   n=0.0;

   while(t1<N)
   {
      for(j=0;j<N;j++)
      {
         for(i=t3;i<N+t3;i++)
         {
            n=n+(array1[i]*array2[t2+j]);
            t2=t2+N;
         }
         array3[j]=n;
         n=0.0;
         t2=0;
      }
      
      for(k=0;k<N;k++)
      {
         array1[t4+k]=array3[k];
      }
      t1=t1+1;
      t4=t4+N;
      t3=t3+N;
   }
   
   /*t1=0;
   t3=0;
   printf("A*B=\n");
   while(t3<N)
   {
      for(i=t1;i<N+t1;i++)
      {
         printf("%.3lf     ", array1[i]);
      }
      t3=t3+1;
      t1=t1+N;
      printf("\n");
   }*/
}

int dgemm_row(double *array1, double *array2, double *array5, int N)
{
   double alpha, beta;
   alpha=1.0;
   beta=0.0;
   cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, N, N, N, alpha, array1, N, array2, N, beta, array5, N);
}

