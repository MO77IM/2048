#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int up(int desk[][10]);//���� 
int down(int desk[][10]);//���� 
int right(int desk[][10]);//���� 
int left(int desk[][10]);//���� 
void MakeBlock(int desk[][10]);//�ڿհײ��������µ����� 
void output(int desk[][10]);//����ǰ״����� 
int check(int desk[][10]); //�����Ϸ�Ƿ���� 

int main(void){
	int desk[10][10]={0};
	int suc;//�ж��Ƿ��ƶ��ɹ� 
	char act;
	srand(time(0));
	MakeBlock(desk);
	output(desk);
	while(1)
	{
		act=getch();//ֱ�ӴӼ��̶�ȡһ���ַ� 
        if(act==72)
            suc=up(desk);
        else if(act==80)
            suc=down(desk);
        else if(act==75)
            suc=left(desk);    
        else if(act==77)
            suc=right(desk);
        else
            continue;
        if(!suc)//�ƶ�ʧ�� 
            continue;
	    system("cls");
		MakeBlock(desk);
	    output(desk);
		if(!check(desk))
		  break;
	}
	printf("GAME OVER!!!\n");
	system("pause"); 
	return 0;
}

int up(int desk[][10]){
	int suc=0;//�ж��Ƿ��ƶ��ɹ�
	
	//���������Ϸ��������У��м�û�пհ� 
	for(int j=0;j<4;j++)
	{
		for(int i=1;i<4;i++)
		{
			if(desk[i][j]==0)//�����ǰλ�������֣������в��� 
			  continue;
			int k=i;
			while(desk[k-1][j]==0&&k>0)//�����������ƶ�ֱ���Ϸ����ֲ�Ϊ��Ϊֹ 
			{
				suc=1;
				int t=desk[k][j];
				desk[k][j]=desk[k-1][j];
				desk[k-1][j]=t; 
				k--;
			}
		}
		
		//�����ڵ���ͬ�����кϲ� 
		for(int i=0;i<3;i++)
		{
			if(desk[i+1][j]==desk[i][j])
			{
				if(desk[i][j]!=0)
				  suc=1;
				desk[i][j]+=desk[i+1][j];
				for(int k=i+1;desk[k][j]!=0;k++)//�ƶ�������� 
				{
					desk[k][j]=desk[k+1][j];
				}
				desk[3][j]=0;
			}
		}
	} 
	return suc;
}

int down(int desk[][10]){
	int suc=0;
	for(int j=0;j<4;j++)
	{
		for(int i=2;i>=0;i--)
		{
			if(desk[i][j]==0)
			  continue;
			int k=i;
			while(desk[k+1][j]==0&&k<3)
			{
				suc=1;
				int t=desk[k][j];
				desk[k][j]=desk[k+1][j];
				desk[k+1][j]=t;
				k++;
			}
		}
		for(int i=3;i>0;i--)
		{
			if(desk[i-1][j]==desk[i][j])
			{
				if(desk[i][j]!=0)
				  suc=1;
				desk[i][j]+=desk[i-1][j];
				for(int k=i-1;desk[k][j]!=0&&k>=0;k--)
				{
					desk[k][j]=desk[k-1][j];
				}
				desk[0][j]=0;
			}
		}
	}
	return suc;
}

int left(int desk[][10])
{
	int suc=0;
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			if(desk[i][j]==0)
			  continue;
			int k=j;
			while(desk[i][k-1]==0&&k>0)
			{
				suc=1;
				int t=desk[i][k];
				desk[i][k]=desk[i][k-1];
				desk[i][k-1]=t;
				k--;
			}  
		}
		for(int j=0;j<3;j++)
		{
			if(desk[i][j+1]==desk[i][j])
			{
				if(desk[i][j]!=0)
				  suc=1;
				desk[i][j]+=desk[i][j+1];
				for(int k=j+1;desk[i][k]!=0;k++)
				{
					desk[i][k]=desk[i][k+1];
				}
				desk[i][3]=0;
			}
		}
	}
	return suc;
}

int right(int desk[][10]){
	int suc=0;
	for(int i=0;i<4;i++)
	{
		for(int j=2;j>=0;j--)
		{
			if(desk[i][j]==0)
			  continue;
			int k=j;
			while(desk[i][k+1]==0&&k<3)
			{
				suc=1;
				int t=desk[i][k];
				desk[i][k]=desk[i][k+1];
				desk[i][k+1]=t;
				k++;
			}
		}
		for(int j=3;j>0;j--)
		{
			if(desk[i][j]==desk[i][j-1])
			{
				if(desk[i][j]!=0)
				  suc=1;
				desk[i][j]+=desk[i][j-1];
				for(int k=j-1;desk[i][k]!=0&&k>0;k--)
				{
					desk[i][k]=desk[i][k-1];
				}
				desk[i][0]=0;
			}
		}
	}
	return suc;
}

void MakeBlock(int desk[][10]){
	int count=0; 
	for(int i=0;i<4;i++)
	  for(int j=0;j<4;j++)
	    if(desk[i][j]==0)
	      count++;//����һ���ж��ٿհ� 
	int add=rand()%count+1;//����һ������հ׵�λ�ã��ڵڼ����հף� 
	int yes=0;
	count=1;
	for(int i=0;i<4;i++)
	{
	  for(int j=0;j<4;j++)
	    if(desk[i][j]==0)
	    {
	    	if(count==add)
	    	{
	    		int val=rand()%100;//�������4����2 
	    		if(val>=79)
	    		  desk[i][j]=4;
	    		else
	    		  desk[i][j]=2;
	    		yes=1;
	    		break;
			}
			count++;
		}
        if(yes)
          break;
   }
   //Ѱ�����ɵĿհ�λ�� 
}

void output(int desk[][10]){
   for(int i=0;i<4;i++)
   {
       printf("---------------------\n");
       for(int j=0;j<4;j++)
       {
			if(desk[i][j]!=0) 
			  printf("|%4d",desk[i][j]);
	        else
	          printf("|    ");
	   }
	   printf("|\n");
   }
   printf("---------------------\n");
}

int check(int desk[][10]){
	for(int i=0;i<4;i++)
	  for(int j=0;j<3;j++)
	  {
	  	  if(desk[i][j]==0||desk[i][j]==desk[i][j+1])
	  	    return 1;
	  }//�ж��Ƿ��пհ׻����Ƿ���һ�������ڵ�������ͬ 
	for(int i=0;i<3;i++)
	  for(int j=0;j<4;j++)
	  {
	  	if(desk[i][j]==desk[i+1][j])
	  	  return 1;
	  }//�ж��Ƿ���һ�������ڵ�������ͬ 
	return 0;
}

