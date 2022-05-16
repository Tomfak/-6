#include<stdio.h>
struct Medal
{
	char country[10];
	int goldNum;
	int silverNum;
	int bronzeNum;
	int totalNum;
};
typedef struct Medal Medal;
int main()
{
	Medal medal[8],min;
	char a[5][10];
	FILE*fp;
	fp=fopen("c:\\file.txt","r");
	if(fp==NULL)
	{
		printf("打开文本文档失败\n");
		return 0;
	}
	for(int i=0;i<9;i++)
	{
		if(i==0)
		{
			fscanf(fp,"%s %s %s %s %s",&a[0],&a[1],&a[2],&a[3],&a[4]);
			continue;
		}
		fscanf(fp,"%s %d %d %d %d\n",medal[i-1].country,&medal[i-1].goldNum,&medal[i-1].silverNum,&medal[i-1].bronzeNum,&medal[i-1].totalNum);
	}
	fclose(fp);
	min=medal[0];
	FILE*fa;
	fa=fopen("c:\\2.txt","w");
	fprintf(fa,"%s\t%s\t%s\t%s\t%s\n",a[0],a[1],a[2],a[3],a[4]);
	for(int j=1;j<8;j++)
	{
		if(min.goldNum>medal[j].goldNum)
			min=medal[j];
		else if((min.goldNum==medal[j].goldNum)&&min.silverNum>medal[j].silverNum)
			min=medal[j];
	}
	fprintf(fa,"%s\t%d\t%d\t%d\t%d\n",min.country,min.goldNum,min.silverNum,min.bronzeNum,min.totalNum);
	fclose(fa);
	return 0;
}
