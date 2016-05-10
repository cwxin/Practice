#include <stdio.h>
#include <stdlib.h>

int input_matrix(double **array1, double **array2, int N);
int output_matrix(double **array1, double **array2, int N);
int product(double **array1, double **array2, double *array3, int N);

int main()
{
   int i, j, k, N;
   double **array1, **array2, *array3;
   printf("Please size of matrix:");
   scanf("%d", &N);
   array1 = (double **)malloc(N*sizeof(double *));
   for(i=0;i<N;i++)
   {
      array1[i]=(double *)malloc(N*sizeof(double));
   }
   array2 = (double **)malloc(N*sizeof(double *));
   for(i=0;i<N;i++)
   {
      array2[i]=(double *)malloc(N*sizeof(double));
   }
   array3 = (double *)malloc(N*sizeof(double));
  
   printf("Please input the elements of the first matrix.\n");
   input_matrix(array1, array2, N);
   output_matrix(array1, array2, N);
   product(array1, array2, array3, N);   

   printf("A*B=\n");
   for(j=0;j<N;j++)
   {
      for(k=0;k<N;k++)
      {
         printf("%.2lf ", array1[j][k]);
      }
      printf("\n");
   }

   return 0;
}

int input_matrix(double **array1, double **array2, int N)
{
   int j, k;
   for(j=0;j<N;j++)
   {
      for(k=0;k<N;k++)
      {
         printf("A[%d][%d]=", j, k);
         scanf("%lf", &array1[j][k]);
      }
   }

   printf("Please input the elements of the second matrix.\n");
   
   for(j=0;j<N;j++)
   {
      for(k=0;k<N;k++)
      {
         printf("B[%d][%d]=", j, k);
         scanf("%lf", &array2[j][k]);
      }
   }
}

int output_matrix(double **array1, double **array2, int N)
{
   int j, k;
   printf("matrix A= \n");
   for(j=0;j<N;j++)
   {
      for(k=0;k<N;k++)
      {
         printf("%.2lf ", array1[j][k]);
      }
      printf("\n");
   }

   printf("matrix B= \n");

   for(j=0;j<N;j++)
   {
      for(k=0;k<N;k++)
      {
         printf("%.2lf ", array2[j][k]);
      }
      printf("\n");
   }
}

int product(double **array1, double **array2, double *array3, int N)
{
   int j, k, i, s, t;
   double p;
   p=0.0;
   s=0;
   t=0;
   while(s<N)
   {
      for(j=0;j<N;j++)
      {
         for(i=0;i<N;i++)
         {
            p=p+(array1[s][i])*(array2[i][t]);
         }
         array3[j]=p;
         p=0.0;
         t=t+1;
      }
      for(k=0;k<N;k++)
      {
         array1[s][k]=array3[k];
      }
      s=s+1;
      t=0;
   }
}
