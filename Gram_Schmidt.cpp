#include<stdio.h>
#include<stdlib.h>

int input_matrix(double *Q, int N);
int output_matrix(double *Q, int N);

int main()
{
   int N, size;
   double *Q, *R;

   printf("please input the size of the matrix:");
   scanf("%d", &N);
   size=N*N;
   
   Q=(double *) malloc(size*sizeof(double));
   R=(double *) malloc(size*sizeof(double));

   input_matrix(Q, N);
   output_matrix(Q, N);
}

int input_matrix(double *Q, int N)
{
   int i, t1, t2;
   t1=0;
   t2=0;

   while(t1<N)
   {
      for(i=0;i<N;i++)
      {
         printf("A[%d][%d]=", t1, i);
         scanf("%lf", &Q[t2+i]);
      }
      t1=t1+1;
      t2=t2+N;
   }
}

int output_matrix(double *Q, int N)
{
   int i, t1, t2;
   t1=0;
   t2=0;

   printf("A=\n");
   while(t1<N)
   {
      for(i=0;i<N;i++)
      {
         printf("%.2f   ", Q[i+t2]);
      }
      t1=t1+1;
      t2=t2+N;
      printf("\n");
   }
}
