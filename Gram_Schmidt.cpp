#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int input_matrix(double *Q, int N);
int output_matrix(double *Q, int N);

int main()
{
   int N, size;
   double *Q, *R, *lengh;

   printf("please input the size of the matrix:");
   scanf("%d", &N);
   size=N*N;
   
   Q=(double *) malloc(size*sizeof(double));
   R=(double *) malloc(size*sizeof(double));
   lengh=(double *) malloc(N*sizeof(double));

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

int Orthogonal_Unitization(double *Q, double *R, double *lengh, int N)
{
   int i, j, t, k, t2, t3;
   double temp, inner;
   t=0;
   temp=0.0;
   inner=0.0;
   
   for(i=0;i<N;i++)
   {
      temp=pow(Q[t3],2)+temp;
      t3=t3+N;
   }
   lengh[0]=sqrt(temp);
   t3=0;
   for(i=0;<N;i++)
   {
      R[t3]=Q[t3];
      t3=t3+N;
   }
   
   while(t<N-1)
   {
      for(j=0;j<t+1;j++)
      {
         t2=j;
         for(i=0;i<N;i++)
         {
            inner=R[j+t2]*Q[t2]+inner;         
            t2=t2+N;
         }
         t2=0;
         for(k=0;k<N;k++)
         {
            R[j+t2+1]=Q[j+t2+1]-(inner/pow(lengh[j],2))*R[j+t2+1];
            t2=t2+N;
         }
         t3=0;
         temp=0.0;
         for(i=0;i<N;i++)
         {
            temp=pow(Q[t3+j+1],2)+temp;
            t3=t3+N;
         }
         lengh[j+1]=sqrt(temp);
         inner=0.0;
      }
      t=t+1;
   }  
   
}

