#include<stdio.h>
#include <stdlib.h>
/*��������*/
void shuru();
int  welcome();
void menu();
void xinxi();
void cj1();
void cj2();
void xiugai();
void chaxun();
void EXIT();
/*����ѧ����Ϣ�ṹ��*/
typedef struct 
{
	int     xh;
	char    name[7];
	char    sex[3];
	int     snum,num,paiming;
	double  yw,sx,yy,aver1,aver2,pf1,pf2,pf3;
}stud;
stud a[4];
/*������*/
int main()
{
	 int i,j;
	 FILE *fp=NULL;
	 printf("�������û���:");
	 scanf("%d",&i);
  	 printf("����������:");
	 scanf("%d",&j);
	 if(i==1&&j==8)
		{
				printf("����������ȷ\n");
				shuru();
				menu();
		}
	 else
		 printf("�����������\n");
}
/*����ѧ��������Ϣ����*/
void shuru()
{
	int i;
	stud parr[4];
	FILE *fp=NULL;
	for(i=0;i<4;i++)
		{
			printf("�������%d��ѧ������Ϣ:\n",i+1);
			printf("ѧ��:");
			scanf("%d",&parr[i].xh);
			printf("����:");
			scanf("%s",parr[i].name);
			printf("�Ա�:");
			scanf("%s",parr[i].sex);
			printf("�������:");
			scanf("%d",&parr[i].snum);
			printf("��ϵ�绰:");
			scanf("%d",&parr[i].num);
		}
	fp=fopen("D:\\Stuinfo.txt","w+");
		{
			for(i=0;i<4;i++)
			fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",parr[i].xh,parr[i].name,parr[i].sex,parr[i].snum,parr[i].num);
			fclose(fp);
		}
	printf("�ѽ�ѧ����Ϣ���浽D�̸�Ŀ¼�µ�Stuinfo.txt�ļ���\n");
}
/*��ӭ����*/
int welcome()
{
	int n;
	printf("\t\t*********��ӭʹ��ѧ���ۺϲ���ϵͳ************************\n");
	printf("\t\t-----------1.�鿴ȫ��ѧ����Ϣ----------------------------\n");
	printf("\t\t-----------2.ѧ���ɼ�¼����㿼�Գɼ�--------------------\n");
	printf("\t\t-----------3.ѧ�������������벢�����ۺϲ����ּܷ�����----\n");
	printf("\t\t-----------4.�޸�ѧ����Ϣ--------------------------------\n");
	printf("\t\t-----------5.ѧ�����ݲ�ѯ--------------------------------\n");
	printf("\t\t-----------6.�˳�----------------------------------------\n");
	printf("\t\t*********************************************************\n");
	printf("��������Ҫ�Ĳ���:");
	scanf("%d",&n);
	return n;
}
/*�˵�����*/
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
						default:printf("\t�������\n");
						getchar();
					}
}
/*�鿴ѧ��������Ϣ*/
void xinxi()
{
	int i;
	FILE *fp;
	fp=fopen("D:\\Stuinfo.txt","r+");
	if(fp==NULL)
		{
			printf("���ܴ�\n");
			exit(0);
		}
    else
		{
		 printf("ѧ��\t����\t�Ա�\t�������\t��ϵ�绰\n");
		 for(i=0;i<4;i++)
			{
				fscanf(fp,"%d\t%s\t%s\t%d\t%d\n",&a[i].xh,a[i].name,a[i].sex,&a[i].snum,&a[i].num);
				printf("%2d\t%6s%4s\t%d\t%16d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
			}
		}
	fclose(fp);
	getchar();
	printf("���س����ز˵�\n");
	getchar();
	menu();
}
/*ѧ���ɼ�¼����㿼�Գɼ�*/
void cj1()
{
	int i;
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","a+");
	if((fp=fopen("D:\\Stuinfo.txt","a+"))==NULL)
		{
			printf("�ļ�Ϊ��\n");
			exit(0);
		}
	for(i=0;i<4;i++)
		{
			printf("�������%d��ѧ�������ġ���ѧ��Ӣ��ɼ�:\n",i+1);
			scanf("%lf%lf%lf",&a[i].yw,&a[i].sx,&a[i].yy);
			a[i].aver1=(a[i].yw+a[i].sx+a[i].yy)/3;
			printf("��%d��ѧ���Ŀ���ƽ���ɼ�Ϊ:%.2lf\n",i+1,a[i].aver1);
			fprintf(fp,"%lf\t%lf\t%lf\t%.2lf\n",a[i].yw,a[i].sx,a[i].yy,a[i].aver1);
		}
	printf("�ѽ�ѧ���ɼ����浽D�̸�Ŀ¼�µ�Stuinfo.txt�ļ���\n");
	fclose(fp);
	getchar();
	printf("���س����ز˵�\n");
	getchar();
	menu();
}
/*ѧ�������������벢�����ۺϲ����ּܷ�����*/
void cj2()
{
	int i,j,s,m[4]; 
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","a+");
	if((fp=fopen("D:\\Stuinfo.txt","a+"))==NULL)
		{
			printf("�ļ�Ϊ��\n");
			exit(0);
		}
	for(i=0;i<4;i++)
		{
			printf("�������%d��ѧ����ͬѧ�����֡�Ʒ�³ɼ����ον�ʦ����:\n",i+1);
			scanf("%lf%lf%lf",&a[i].pf1,&a[i].pf2,&a[i].pf3);
			a[i].aver2=a[i].aver1*0.6+a[i].pf1*0.1+a[i].pf2*0.1+a[i].pf3*0.2;
			printf("��%d��ѧ�����ۺϲ����ܷ�Ϊ:%.2lf\n",i+1,a[i].aver2);
			fprintf(fp,"%lf\t%lf\t%lf\t%.2lf\n",a[i].pf1,a[i].pf2,a[i].pf3,a[i].aver2);
		}
	        /*ð�ݷ�����*/
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
    printf("��%d��ͬѧ���ۺϲ�������Ϊ%d\t",i+1,m[i]);
	printf("\n");
	printf("�ѽ�ѧ���ɼ����浽D�̸�Ŀ¼�µ�Stuinfo.txt�ļ���\n");
	fclose(fp);
	getchar();
	printf("���س����ز˵�\n");
	getchar();
	menu();
} 
/*�޸�ѧ����Ϣ*/
void xiugai()
{
	int i,n=0;
	char ch='\0';
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","w+");
	if((fp=fopen("D:\\Stuinfo.txt","w+"))==NULL)
		{
			printf("�ļ�Ϊ��\n");
			exit(0);
		}
	for(i=0;i<4;i++)
	fscanf(fp,"%d\t%s\t%s\t%d\t%d\n",&a[i].xh,a[i].name,a[i].sex,&a[i].snum,&a[i].num);
	printf("������Ҫ�޸ĵ�ѧ����ѧ��:\n");
	scanf("%d",&n);
	for(i=0;i<4;i++)
		{
			if(n==a[i].xh)
				{
					printf("ѧ��\t����\t�Ա�\t�������\t��ϵ�绰\n");
					printf("%2d\t%6s%4s\t%d\t%16d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
					printf("ȷ��Ҫ�޸ĸ�ѧ����Ϣ��(y/n):");
					getchar();
					scanf("%c",&ch);
					if((ch=='y')||(ch=='Y'))
						{
								printf("������ѧ��:");
								scanf("%d",&a[i].xh);
								printf("����������:");
								scanf("%s",a[i].name);
								printf("�������Ա�:");
								scanf("%s",a[i].sex);
								printf("�������������:");
								scanf("%d",&a[i].snum);
								printf("��������ϵ�绰:");
								scanf("%d",&a[i].num);
								fprintf(fp,"%d\t%s\t%s\t%d\t%d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
								printf("�޸���ɣ�\n");
						}
					break;
				}
		}
	if(i>=4)
	printf("δ�ҵ���ѧ��\n");
	fclose(fp);
	getchar();
	printf("���س����ز˵�\n");
	getchar();
	menu();
}
/*ѧ�����ݲ�ѯ*/
void chaxun()
{
	int i,n=0;
	FILE *fp=NULL;
	fp=fopen("D:\\Stuinfo.txt","r");
	if((fp=fopen("D:\\Stuinfo.txt","w+"))==NULL)
		{
			printf("�ļ�Ϊ��\n");
			exit(0);
		}
	for(i=0;i<4;i++)
	fscanf(fp,"%d\t%s\t%s\t%d\t%d\n",&a[i].xh,a[i].name,a[i].sex,&a[i].snum,&a[i].num);
	printf("������Ҫ��ѯ��ѧ����ѧ��:");
	scanf("%d",&n);
    for(i=0;i<4;i++)
		{
			if(n==a[i].xh)
				{
					printf("ѧ��\t����\t�Ա�\t�������\t��ϵ�绰\n");
					printf("%2d\t%6s%4s\t%d\t%16d\n",a[i].xh,a[i].name,a[i].sex,a[i].snum,a[i].num);
					break;
				}
		}
	if(i>=4)
	printf("δ�ҵ���ѧ��\n");
	fclose(fp);
	getchar();
	printf("���س����ز˵�\n");
	getchar();
	menu();
}
/*�˳�*/
void EXIT()
{
	printf("ллʹ�ã�\n");
	exit(0);
}

