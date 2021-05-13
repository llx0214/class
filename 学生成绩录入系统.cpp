#include<stdio.h>
#include <stdlib.h>
/*声明函数*/
void shuru();
int  welcome();
void menu();
void xinxi();
void cj1();
void cj2();
void xiugai();
void chaxun();
void EXIT();
/*定义学生信息结构体*/
typedef struct 
{
	int     xh;
	char    name[7];
	char    sex[3];
	int     snum,num,paiming;
	double  yw,sx,yy,aver1,aver2,pf1,pf2,pf3;
}stud;
stud a[4];
/*主函数*/
int main()
{
	 int i,j;
	 FILE *fp=NULL;
	 printf("请输入用户名:");
	 scanf("%d",&i);
  	 printf("请输入密码:");
	 scanf("%d",&j);
	 if(i==1&&j==8)
		{
				printf("密码输入正确\n");
				shuru();
				menu();
		}
	 else
		 printf("密码输入错误\n");
}
/*输入学生基本信息函数*/
void shuru()
{
	int i;
	stud parr[4];
	FILE *fp=NULL;
	for(i=0;i<4;i++)
		{
			printf("请输入第%d个学生的信息:\n",i+1);
			printf("学号:");
			scanf("%d",&parr[i].xh);
			printf("姓名:");
			scanf("%s",parr[i].name);
			printf("性别:");
			scanf("%s",parr[i].sex);
			printf("宿舍号码:");
			scanf("%d",&parr[i].snum);
			printf("联系电话:");
			scanf("%d",&parr[i].num);
		}
	fp=fopen("D:\\Stuinfo.txt","w+");
		{
			for(i=0;i<4;i++)
			fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",parr[i].xh,parr[i].name,parr[i].sex,parr[i].snum,parr[i].num);
			fclose(fp);
		}
	printf("已将学生信息保存到D盘根目录下的Stuinfo.txt文件中\n");
}
/*欢迎函数*/
int welcome()
{
	int n;
	printf("\t\t*********欢迎使用学生综合测评系统************************\n");
	printf("\t\t-----------1.查看全部学生信息----------------------------\n");
	printf("\t\t-----------2.学生成绩录入计算考试成绩--------------------\n");
	printf("\t\t-----------3.学生测评数据输入并计算综合测评总分及名次----\n");
	printf("\t\t-----------4.修改学生信息--------------------------------\n");
	printf("\t\t-----------5.学生数据查询--------------------------------\n");
	printf("\t\t-----------6.退出----------------------------------------\n");
	printf("\t\t*********************************************************\n");
	printf("请输入需要的操作:");
	scanf("%d",&n);
	return n;
}
/*菜单函数*/
void menu()
{
				int n;
				n=welcome();
				switch(n)
					{
						case 1:xinxi();break;
						case 2:cj1();break;
						case 3:cj2();break;
						case 4:xiugai();break;
						case 5:chaxun();break;
						case 6:EXIT();break;
						default:printf("\t输入错误！\n");
						getchar();
					}
}
/*查看学生基本信息*/
void xinxi()
{
	int i;
	FILE *fp;
	fp=fopen("D:\\Stuinfo.txt","r+");
	if(fp==NULL)
		{
			printf("不能打开\n");
			exit(0);
		}
    else
		{
		 printf("学号\t姓名\t性别\t宿舍号码\t联系电话\n");
		 for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\t%s\t%s\t%d\t%d\n",&a[i].xh,a[i].name,a[i].sex,&a[i].snum,&a[i].num);
				printf("%2d\t%6s%4s\t%d\t%16d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
			}
		}
	fclose(fp);
	getchar();
	printf("按回车返回菜单\n");
	getchar();
	menu();
}
/*学生成绩录入计算考试成绩*/
void cj1()
{
	int i;
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","a+");
	if((fp=fopen("D:\\Stuinfo.txt","a+"))==NULL)
		{
			printf("文件为空\n");
			exit(0);
		}
	for(i=0;i<4;i++)
		{
			printf("请输入第%d个学生的语文、数学、英语成绩:\n",i+1);
			scanf("%lf%lf%lf",&a[i].yw,&a[i].sx,&a[i].yy);
			a[i].aver1=(a[i].yw+a[i].sx+a[i].yy)/3;
			printf("第%d个学生的考试平均成绩为:%.2lf\n",i+1,a[i].aver1);
			fprintf(fp,"%lf\t%lf\t%lf\t%.2lf\n",a[i].yw,a[i].sx,a[i].yy,a[i].aver1);
		}
	printf("已将学生成绩保存到D盘根目录下的Stuinfo.txt文件中\n");
	fclose(fp);
	getchar();
	printf("按回车返回菜单\n");
	getchar();
	menu();
}
/*学生测评数据输入并计算综合测评总分及名次*/
void cj2()
{
	int i,j,s,m[4]; 
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","a+");
	if((fp=fopen("D:\\Stuinfo.txt","a+"))==NULL)
		{
			printf("文件为空\n");
			exit(0);
		}
	for(i=0;i<4;i++)
		{
			printf("请输入第%d个学生的同学互评分、品德成绩、任课教师评分:\n",i+1);
			scanf("%lf%lf%lf",&a[i].pf1,&a[i].pf2,&a[i].pf3);
			a[i].aver2=a[i].aver1*0.6+a[i].pf1*0.1+a[i].pf2*0.1+a[i].pf3*0.2;
			printf("第%d个学生的综合测评总分为:%.2lf\n",i+1,a[i].aver2);
			fprintf(fp,"%lf\t%lf\t%lf\t%.2lf\n",a[i].pf1,a[i].pf2,a[i].pf3,a[i].aver2);
		}
	        /*冒泡法排名*/
	for(i=0;i<4;i++)
		m[i]=i+1;
	for(i=0;i<3;i++)
		{
			 for(j=0;j<3-i;j++)
			 {
				if(a[j+1].aver2>a[j].aver2)
					{
						s=m[j];
					    m[j]=m[j+1];
					    m[j+1]=s;
					}
			 }
		}
	for(i=0;i<4;i++)
    printf("第%d个同学的综合测评排名为%d\t",i+1,m[i]);
	printf("\n");
	printf("已将学生成绩保存到D盘根目录下的Stuinfo.txt文件中\n");
	fclose(fp);
	getchar();
	printf("按回车返回菜单\n");
	getchar();
	menu();
} 
/*修改学生信息*/
void xiugai()
{
	int i,n=0;
	char ch='\0';
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","w+");
	if((fp=fopen("D:\\Stuinfo.txt","w+"))==NULL)
		{
			printf("文件为空\n");
			exit(0);
		}
	for(i=0;i<4;i++)
	fscanf(fp,"%d\t%s\t%s\t%d\t%d\n",&a[i].xh,a[i].name,a[i].sex,&a[i].snum,&a[i].num);
	printf("请输入要修改的学生的学号:\n");
	scanf("%d",&n);
	for(i=0;i<4;i++)
		{
			if(n==a[i].xh)
				{
					printf("学号\t姓名\t性别\t宿舍号码\t联系电话\n");
					printf("%2d\t%6s%4s\t%d\t%16d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
					printf("确定要修改该学生信息吗？(y/n):");
					getchar();
					scanf("%c",&ch);
					if((ch=='y')||(ch=='Y'))
						{
								printf("请输入学号:");
								scanf("%d",&a[i].xh);
								printf("请输入姓名:");
								scanf("%s",a[i].name);
								printf("请输入性别:");
								scanf("%s",a[i].sex);
								printf("请输入宿舍号码:");
								scanf("%d",&a[i].snum);
								printf("请输入联系电话:");
								scanf("%d",&a[i].num);
								fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
								printf("修改完成！\n");
						}
					break;
				}
		}
	if(i>=4)
	printf("未找到该学生\n");
	fclose(fp);
	getchar();
	printf("按回车返回菜单\n");
	getchar();
	menu();
}
/*学生数据查询*/
void chaxun()
{
	int i,n=0;
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","r");
	if((fp=fopen("D:\\Stuinfo.txt","w+"))==NULL)
		{
			printf("文件为空\n");
			exit(0);
		}
	for(i=0;i<4;i++)
	fscanf(fp,"%d\t%s\t%s\t%d\t%d\n",&a[i].xh,a[i].name,a[i].sex,&a[i].snum,&a[i].num);
	printf("请输入要查询的学生的学号:");
	scanf("%d",&n);
    for(i=0;i<4;i++)
		{
			if(n==a[i].xh)
				{
					printf("学号\t姓名\t性别\t宿舍号码\t联系电话\n");
					printf("%2d\t%6s%4s\t%d\t%16d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
					break;
				}
		}
	if(i>=4)
	printf("未找到该学生\n");
	fclose(fp);
	getchar();
	printf("按回车返回菜单\n");
	getchar();
	menu();
}
/*退出*/
void EXIT()
{
	printf("谢谢使用！\n");
	exit(0);
}

