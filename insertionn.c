#include<stdio.h>
#include<time.h>
void insertion(int ins[],int n);
void selection(int sel[],int n);
void print(int a[],int n);
int i,y,j,t,c=1,s;
void main()
{
       int ins[100],sel[100],i,n;
       clock_t start,end,start1,end1;
       double cpu_time,cpu_time1;
       printf("\n Enter no. of elements:\n");
       scanf("%d",&n);
       printf("\n Enter elements:\n");
       for(i=0;i<n;i++)
       {
            scanf("%d",&ins[i]);
            sel[i]=ins[i];
       }
       start=clock();
       insertion(ins,n);
       end=clock();
       cpu_time = ((double) (end - start)/CLOCKS_PER_SEC);
       printf("\n Execution time for insertion sort=%lf\n",cpu_time);
       printf("\n Selection Sort:");
       start1=clock();
       selection(sel,n);
       end1=clock();
       cpu_time1 = ((double) (end1 - start1)/CLOCKS_PER_SEC);
       printf("\n Execution time for selection sort=%lf",cpu_time1);
      
}  
void insertion(int ins[],int n)
{
       for(i=1;i<n;i++)
       {
            y=ins[i];
            j=i-1;
            while(j>=0&&y<ins[j])
            {
                 
                 ins[j+1]=ins[j];
                 j--;
            }
            ins[j+1]=y;
            printf("\n pass %d:\t",c);
            for(t=0;t<i+1;t++)
            {
                 printf("%d\t",ins[t]);
            } 
           c++;
       }
       printf("\n Sorted array of insertion sort:");
       print(ins,n);
}     
void selection(int sel[],int n) 
{     
       c=1;        
       for(i=0;i<n;i++)
       {
           for(j=i+1;j<n;j++)
           {
                if(sel[i]>sel[j])
                {
                    t=sel[i];
                    sel[i]=sel[j];
                    sel[j]=t;
                }
            }
            printf("\n pass %d:\t",c);
            for(s=0;s<n;s++)
            {
                 printf("%d\t",sel[s]);
            } 
           c++;
            
       }
       printf("\n Sorted array of selection sort:");
       print(sel,n);
}  
void print(int a[],int n)
{
     for(i=0;i<n;i++)
     {
            printf("\n %d",a[i]);
     } 
}    

/*tejal@ubuntu:~/Desktop/daa$ ./a.out

 Enter no. of elements:
5

 Enter elements:
8 9 7 1 2

 pass 1:	8	9	
 pass 2:	7	8	9	
 pass 3:	1	7	8	9	
 pass 4:	1	2	7	8	9	
 Sorted array of insertion sort:
 1
 2
 7
 8
 9
 Execution time for insertion sort=0.000030

 Selection Sort:
 pass 1:	1	9	8	7	2	
 pass 2:	1	2	9	8	7	
 pass 3:	1	2	7	9	8	
 pass 4:	1	2	7	8	9	
 pass 5:	1	2	7	8	9	
 Sorted array of selection sort:
 1
 2
 7
 8
 9
 Execution time for selection sort=0.000020tejal@ubuntu:~/Desktop/daa$ */
