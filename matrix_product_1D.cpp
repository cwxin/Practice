#include<stdio.h>
#include<stdlib.h>

int input_matrix(int size, int N, double *array1, double *array2);
int output_matrix(int size, int N, double *array1, double *array2);
int product_matrix(int size, int N, double *array1, double *array2, double *array3);

int main()
{
   int N, size;
   double *array1, *array2, *array3;
   printf("Please input the size of the matrix:");
   scanf("%d", &N);
   size=N*N;
   
   array1=(double *) malloc(size*sizeof(double));
   array2=(double *) malloc(size*sizeof(double));
   array3=(double *) malloc(N*sizeof(double));

   input_matrix(size, N, array1, array2);
   output_matrix(size, N, array1, array2);
   product_matrix(size, N, array1, array2, array3);
}

int input_matrix(int size, int N, double *array1, double *array2)
{
   int i, t1, t2, t3;
   t1=0;
   t2=0;
   t3=0;

   printf("Please input the elements of the first matrix.\n");
   while(t3<N)
   {
      for(i=t1;i<N+t1;i++)
      {
         printf("A[%d][%d]=", t3, t2);
         scanf("%lf", &array1[i]);
         t2=t2+1;
      }
      t3=t3+1;
      t1=t1+N;
      t2=0;
   }

   t1=0;
   t2=0;
   t3=0;
   printf("Please input the elements of the second matrix.\n");
   while(t3<N)
   {
      for(i=t1;i<N+t1;i++)
      {
         printf("B[%d][%d]=", t3, t2);
         scanf("%lf", &array2[i]);
         t2=t2+1;
      }
      t3=t3+1;
      t1=t1+N;
      t2=0;
   }  
}

int output_matrix(int size, int N, double *array1, double *array2)
{
   int i, t1, t2, t3;
   t1=0;
   t3=0;

   printf("A=\n");
   while(t3<N)
   {
      for(i=t1;i<N+t1;i++)
      {
         printf("%.3lf     ", array1[i]);
      }
      t3=t3+1;
      t1=t1+N;
      printf("\n");
   }
 
   t1=0;
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
   }
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
   
   t1=0;
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
   }
}
