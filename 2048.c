#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int i,j,a[5][5]={};

int defen(int a[][5])
{
  int max=a[0][0];
  int static sum=0;
  for(i=0;i<5;i++)
    for(j=0;j<5;j++)
      if(a[i][j]>max)
        max=a[i][j];
  sum+=max;
  return sum;
}
void randomize(int a[][5])
{
  int b[2]={2,4},c[5]={0,1,2,3,4},sum,n,m;
  do
  {
    srand((int)time(NULL));
    m=c[rand()%5];
    n=c[rand()%5];
   
    if(a[m][n]==0)
    {
      a[m][n]=b[rand()%2];
      break;
    }
  }while(1);
  printf("%d %d %d\n",m,n,a[m][n]);
  for(i=0;i<5;i++)
  {
    printf("-------------------------\n");
    for(j=0;j<5;j++)
      {
        if((m==i)&&(n==j))
          printf("| %d ",a[m][n]);
        else
        {
          if(a[i][j]>0)
            printf("| %d ",a[i][j]);
          else
            printf("|   ");
        }
      }
    printf("|\n");
  }
    printf("-------------------------\n");
    printf("      score :%d\n",sum=defen(a));
}
void up(int a[][5])
{
  int m;
  for(j=0;j<5;j++)
    for(i=0;i<4;i++)
      if(a[i][j]>0)
        if(a[i][j]==a[i+1][j]&&a[i][j]!=0)
        {
          a[i][j]=2*a[i][j];
          if(i==2)
            a[i+1][j]=0;
          else
            for(m=i+1;m<3;m++)
            {
              a[m][j]=a[m+1][j];
              a[m+1][j]=0;
            }
         
        }
}
void down(int a[][5])
{
  int m;
  for(j=0;j<5;j++)
    for(i=4;i>0;i--)
      if(a[i][j]>0)
        if(a[i][j]==a[i-1][j])
        {
          a[i][j]=2*a[i][j];
          if(i==1)
            a[i-1][j]=0;
          else
            for(m=i-1;m>0;m--)
            {
              a[m][j]=a[m-1][j];
              a[m-1][j]=0;
            }
        }
}
void left(int a[][5])
{
  int m;
  for(i=0;i<5;i++)
    for(j=0;j<4;j++)
      if(a[i][j]>0)
        if(a[i][j]==a[i][j+1])
        {
          a[i][j]=2*a[i][j];
          if(j==2)
            a[i][j+1]=0;
          else
            for(m=j+1;m<4;m++)
            {
              a[i][m]=a[i][m+1];
              a[i][m+1]=0;
            }
        }
}
void right(int a[][5])
{
  int m;
  for(i=0;i<5;i++)
    for(j=4;j>0;j--)
      if(a[i][j]>0)
        if(a[i][j]==a[i][j-1])
        {
          a[i][j]=2*a[i][j];
          if(j==1)
            a[i][j-1]=0;
          else
            for(m=j-1;m>0;m--)
            {
              a[i][m]=a[i][m-1];
              a[i][m-1]=0;
            }
        }
}
void choose_keys(char b)
{
  int x,m;
  switch(b)
  {
    case 'w' :
      for(j=0;j<5;j++)
        for(i=1;i<=4;i++)
          for(x=i,m=i;x>0;x--,m--)
          {
            if(a[m-1][j]>0)
              break;
            else
            {
              a[m-1][j]=a[m][j];
              a[m][j]=0;
            }
          }
      up(a);
      break;
    case 's' :
      for(j=0;j<5;j++)
        for(i=2;i>=0;i--)
          for(x=4-i,m=i;x>0;x--,m++)
          {
            if(a[m+1][j]>0)
              break;
            else
            {
              a[m+1][j]=a[m][j];
              a[m][j]=0;
            }
          }
      down(a);
      break;
    case 'a' :
      for(i=0;i<5;i++)
        for(j=1;j<=4;j++)
          for(x=j,m=j;x>0;x--,m--)
          {
            if(a[i][m-1]>0)
              break;
            else
            {
              a[i][m-1]=a[i][m];
              a[i][m]=0;
            }
          }
      left(a);
      break;
    case 'd' :
      for(i=0;i<5;i++)
        for(j=2;j>=0;j--)
          for(x=4-j,m=j;x>0;x--,m++)
          {
            if(a[i][m+1]>0)
              break;
            else
            {
              a[i][m+1]=a[i][m];
              a[i][m]=0;
            }
          }
      right(a);
      break;
  }
}
int main(int argc,char *argv[])
{
  int flag=1;
  char c,k;
  system("stty -icanon");
outloop:;
  
  printf("Use the keys W, A, S and D");
  printf("\n");
  
    while(flag==1)
    {
      randomize(a);
      c=getchar();
      
      choose_keys(c);
      for(i=0;i<5;i++)
        for(j=0;j<5;j++)
        {
          if(a[i][j]==0)
          {
            flag=1;
            goto end;
          }
          else
            flag=0;
        }
       end:;
    }
  
  
  printf(" Game over \n");
  return 0;
}
