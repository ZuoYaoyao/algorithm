#include <stdio.h>
#include <stdlib.h>

int main()
{
    //1-dim
    int *a;
    a=(int *)malloc(sizeof(int)*2);
    *(a+0)=1;
    *(a+1)=2;
    printf("%d %d\n",*a,*(a+1));
    printf("%d %d\n",a[0],a[1]);
    printf("\n \n");
    
    //2-dim
    int **b;
    b=(int **)malloc(sizeof(*b)*2);
    for(int i=0;i<2;++i)
        b[i]=(int *)malloc(sizeof(**b)*3);

    for(int i =0;i<2;i++)
        for(int j=0;j<3;j++)
            b[i][j]=(i+1)*(j+1);
    
     for(int i =0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",b[i][j]);
        }
           printf("\n");
     }
      
     for(int i =0;i<2;i++){
        for(int j=0;j<3;j++){
            printf("%d ",*(b[i]+j));
        }
           printf("\n");
        }
        
        printf("\n\n");
    //3-dim
    int ***c;
    c=(int***)malloc(sizeof(*c)*3);//int **
    for(int i=0;i<3;i++){
        c[i]=(int **)malloc(sizeof(**c)*4);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
        c[i][j]=(int *)malloc(sizeof(***c)*5);
    }
    }
    
    
    for(int i =0;i<3;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<5;k++)
                c[i][j][k]=(i+1)*(j+1)*(k+1);
    
    for(int i =0;i<3;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<5;k++){
                printf("%d ",c[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }
        
            


    return 0;
}