#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef struct course
{
    int semester;  //ѧ��
    int cno;  // �γ̺�
    char course_name[20]; //�γ�����
    int cpno1;  //���п�
    int cpno2;
    float ccredit; //ѧ��
}course;

int n=0; //��¼��ǰע���˼���ѧ���������´�ע��
int m=0; //��¼��ǰ�Ƿ����˵�¼�ɹ�
int ap ;   //��ǰ���ĸ��û��ڵ�¼
typedef struct stu
{
    char  number[20]; // ѧ��ѧ��
    char name[20]; //ѧ������
    char sex[6]; //�Ա�
    char mima[20]; //ѧ���ʻ�����
    int num;  //��ǰѡ����������ע���û�ʱ��ʼ��Ϊ0
    course choices[100]; //ѧ��ѡ��
}stu;

void title()
{
printf("---------��ӭʹ���������պ����ѧ--ѧ��ѡ��ϵͳ ------------\n");
printf("---------                                       ------------\n");
printf("---------             1.ע��ѧ����Ϣ            ------------\n");
printf("---------             2.����γ���Ϣ            ------------\n");
printf("---------             3.���ѧ����Ϣ            ------------\n");
printf("---------             4.ѧ��ѡ��                ------------\n");
printf("---------             5.ѧ����¼                ------------\n");
printf("---------             0.�˳�����                ------------\n");
printf("---------                                       ------------\n");
}

void Opis(int choice,stu *pstu,course *pcourse)
{
    if(choice == 1) //ע��ѧ����Ϣ
    {
        reinfor(pstu);
    }
    else if (choice == 2)  //����γ���Ϣ
    {
        viewcourse(pcourse);
    }
    else if(choice == 3)   //���ѧ����Ϣ
    {
        viewstu(ap,pstu);
    }
    else if(choice == 4)    //ѧ��ѡ��
    {
        stuselect(pstu,pcourse);
    }
    else  if(choice == 5)   //ѧ����¼
    {
        ap=login(pstu);
    }
    else
    {
        printf("\n\n---------��ӭ�´�ʹ���������պ����ѧ--ѧ��ѡ��ϵͳ ------------\n");
    }
}

void reinfor(stu *pstu) //ע����Ϣ,�ж�֮ǰ�Ƿ�ע���
{
    int i=0;
    char ID[20];
    printf("Please input your Student ID : \n");
    if(n==0)
    {
        scanf("%s",&pstu[n].number);
        printf("\nPlease input your Name : \n");
        scanf("%s",&pstu[n].name);
        printf("\nPlease input your Sex : \n");
        scanf("%s",&pstu[n].sex);
        printf("\nPlease input your Password : \n");
        scanf("%s",&pstu[n].mima);
        printf("\nRegistration Successful!\n");
        pstu[n].num = 0;
        n++;

    }
    else
    {
        scanf("%s",&ID);
        for(i=0;i<n;i++) //�ж�֮ǰ�Ƿ�ע���
        {
            if(strcmp(ID,pstu[i].number)==0)
            {
                printf("\n This account has been registered!!! \n");
                i=-1;
                break;
            }
        }
        if(i!=-1)
        {
            strcpy(&pstu[n].number,ID);
            printf("\nPlease input your Name : \n");
            scanf("%s",&pstu[n].name);
            printf("\nPlease input your Sex : \n");
            scanf("%s",&pstu[n].sex);
            printf("\nPlease input your Password : \n");
            scanf("%s",&pstu[n].mima);
            printf("\nRegistration Successful!!!\n");
            pstu[n].num = 0;
            n++;
        }
    }
}

void  viewstu(int ap,stu *pstu)  //���ѧ����Ϣ
{
    int i=0;
    if(m==0)  //�ж��Ƿ��¼��������ѡ��
    {
        printf("%\nPlease login first!\n");
    }
    else
    {
        printf("\nѧ�ţ�%s\n������%s\n�Ա�%s\n",pstu[ap].number,pstu[ap].name,pstu[ap].sex);
        printf("\nѡ����Ϣ��\n\n");
        printf("\n�γ����ƣ�             �γ̺ţ�    ѧ�֣�   ���пΣ�  \n");
        for(i=0;i<pstu[ap].num;i++)
        {
            printf("        %s       %d       %.2f         %d,%d\n", pstu[ap].choices[i].course_name, pstu[ap].choices[i].cno, pstu[ap].choices[i].ccredit, pstu[ap].choices[i].cpno1, pstu[ap].choices[i].cpno2);
        }
    }

}

void  viewcourse(course pcourse[]) //����γ���Ϣ
{
    int i,s;
    char str[30];
    printf("\n1.��ѯȫ���γ��밴1\n");
    printf("\n2.��ѯĳѧ�ڿγ��밴2\n");
    printf("\n3.��ѯ���ſγ��밴3\n");
    scanf("%d",&s);
    if(s == 1)
    {
        printf("\n�γ����ƣ�               �γ̺ţ�  ѧ�֣�  ���пΣ�\n");
        for(i=0;i<=33;i++)
        {
            printf("        %s     \n  %d       %.2f         %d,%d\n", pcourse[i].course_name, pcourse[i].cno, pcourse[i].ccredit, pcourse[i].cpno1, pcourse[i].cpno2);
        }
    }
    else if(s == 2)
    {
        printf("\n�������ѯ��ѧ�ڣ�\n");
        scanf("%d",&s);
        printf("\n�γ����ƣ�               �γ̺ţ�  ѧ�֣�  ���пΣ�\n");
        for(i=0;i<=33;i++)
        {
            if(pcourse[i].semester == s)
            {
                printf("        %s    \n   %d       %.2f         %d,%d\n", pcourse[i].course_name, pcourse[i].cno, pcourse[i].ccredit, pcourse[i].cpno1, pcourse[i].cpno2);
            }
        }
    }
    else if(s == 3)
    {
        printf("\n�������ѯ�Ŀγ̣�\n");
        scanf("%s",&str);
        for(i=0;i<=33;i++)
        {
            if(strcmp(str,pcourse[i].course_name)==0);
            {
                printf("        %s       %d       %.2f         %d,%d\n", pcourse[i].course_name, pcourse[i].cno, pcourse[i].ccredit, pcourse[i].cpno1, pcourse[i].cpno2);
                break;
            }
        }
    }
}

void  stuselect(stu *pstu,course *pcourse) //ѧ��ѡ��
{
    int k,a,c,num;
    char str[30];
    if(m==0)  //�ж��Ƿ��¼��������ѡ��
    {
        printf("%\nPlease login first!\n");
    }
    else
    {
        printf("\n��������Ҫѡ�޵�ѧ��\n");
        scanf("%d",&k);
        printf("\n���Ǹ�ѧ��������ѡ�޵Ŀγ̣�\n");
        for(a=0;a<33;a++)
        {
            if(pcourse[a].semester == k)
            {
                for(c=0,num=0;c<pstu[ap].num;c++)
                {
                    if(pcourse[a].cpno1==pstu[ap].choices[c].cno || pcourse[a].cpno2==pstu[ap].choices[c].cno)
                    {
                        num++;
                    }
                }
                if((pcourse[a].cpno1*pcourse[a].cpno2 > 0  && num == 2) || (num == 1 && (pcourse[a].cpno1*pcourse[a].cpno2 == 0 && pcourse[a].cpno1+pcourse[a].cpno2>0)) || (num == 0 && pcourse[a].cpno1 == 0 && pcourse[a].cpno2 == 0) )
                {
                    printf("        %s    \n   %d       %.2f         %d,%d\n", pcourse[a].course_name, pcourse[a].cno, pcourse[a].ccredit, pcourse[a].cpno1, pcourse[a].cpno2);
                }
            }
        }
        printf("\n��������Ҫѡ�޵Ŀγ̣�\n\n\n");
        scanf("%s",&str);
        for(a=0;a<33;a++)
        {
            if(strcmp(str,pcourse[a].course_name)==0)
            {
                for(c=0,num=0;c<pstu[ap].num;c++)
                {
                    if(pcourse[a].cpno1==pstu[ap].choices[c].cno || pcourse[a].cpno2==pstu[ap].choices[c].cno)
                    {
                        num++;
                    }
                }
                if((pcourse[a].cpno1*pcourse[a].cpno2 > 0  && num == 2) || (num == 1 && ( pcourse[a].cpno1*pcourse[a].cpno2 == 0 && pcourse[a].cpno1+pcourse[a].cpno2>0)) || (num == 0 && pcourse[a].cpno1 == 0 && pcourse[a].cpno2 == 0))
                {
                    printf("\n��ϲѡ�޳ɹ�!!!  \n\n\n\n\n");
                    pstu[ap].choices[ pstu[ap].num ]=pcourse[a];
                    pstu[ap].num++;
                }
                else
                {
                    printf("\n������ѡ�˿Σ���Ϊ�˿ε����п�����δ���꣡��\n \n \n\n\n");
                }
                break;
            }
        }
    }
}

int login(stu pstu[]) //ѧ����¼
{
    char ID[20];
    char pw[20];
    int i,k;
    printf("\nPlease Input your ID : \n");
    scanf("%s",&ID);
    for(i=0,k=0;i<n;i++)
    {
        if(strcmp(ID,pstu[i].number)==0)
        {
            k=1;
            break;
        }

    }
    if(k == 0)
    {
        printf("\nDo not have this account, please register\n");
        return 0;
    }
    else
    {
        printf("\nPlease Input your Password : \n");
        scanf("%s",&pw);
        if(strcmp(pw,pstu[i].mima)==0)
        {
            printf("\nLogin Success!!!\n");
            m=1; //��ʾ��ǰ��¼�ɹ�
            return i;
        }
        else
        {
            printf("\nwrong password !!!\n");
            return 0;
        }
    }
}
int main()
{
    int choice = 1; //����

    stu pstu[100];
    course pcourse[100];

    pcourse[0].semester=1; pcourse[0].cno=1; strcpy(pcourse[0].course_name,"�ߵ���ѧ1"); pcourse[0].cpno1=0; pcourse[0].cpno2=0; pcourse[0].ccredit=5;
    pcourse[1].semester=1; pcourse[1].cno=2; strcpy(pcourse[1].course_name,"�������"); pcourse[1].cpno1=0; pcourse[1].cpno2=0;pcourse[1].ccredit=3;
    pcourse[2].semester=1; pcourse[2].cno=3; strcpy(pcourse[2].course_name,"��ɢ��ѧ"); pcourse[2].cpno1=0; pcourse[2].cpno2=0;pcourse[2].ccredit=4;
    pcourse[3].semester=1; pcourse[3].cno=4; strcpy(pcourse[3].course_name,"�й�����ʷ��Ҫ"); pcourse[3].cpno1=0; pcourse[3].cpno2=0;pcourse[3].ccredit=2;
    pcourse[4].semester=1; pcourse[4].cno=5; strcpy(pcourse[4].course_name,"��ѧӢ��1"); pcourse[4].cpno1=0; pcourse[4].cpno2=0;pcourse[4].ccredit=4;
    pcourse[5].semester=1; pcourse[5].cno=6; strcpy(pcourse[5].course_name,"�������ѧ����"); pcourse[5].cpno1=0; pcourse[5].cpno2=0;pcourse[5].ccredit=1.5;
    pcourse[6].semester=1; pcourse[6].cno=7; strcpy(pcourse[6].course_name,"˼��"); pcourse[6].cpno1=0; pcourse[6].cpno2=0;pcourse[6].ccredit=3;
    pcourse[7].semester=1; pcourse[7].cno=8; strcpy(pcourse[7].course_name,"����1"); pcourse[7].cpno1=0; pcourse[7].cpno2=0;pcourse[7].ccredit=1;
    pcourse[8].semester=1; pcourse[8].cno=9; strcpy(pcourse[8].course_name,"����������1"); pcourse[8].cpno1=0; pcourse[8].cpno2=0;pcourse[8].ccredit=0.25;

    pcourse[9].semester=2; pcourse[9].cno=10; strcpy(pcourse[9].course_name,"�ߵ���ѧ2"); pcourse[9].cpno1=1; pcourse[9].cpno2=0;pcourse[9].ccredit=5;
    pcourse[10].semester=2; pcourse[10].cno=11; strcpy(pcourse[10].course_name,"�����߼�"); pcourse[10].cpno1=0; pcourse[10].cpno2=0;pcourse[10].ccredit=3;
    pcourse[11].semester=2; pcourse[11].cno=12; strcpy(pcourse[11].course_name,"��ѧ����1"); pcourse[11].cpno1=1; pcourse[11].cpno2=0;pcourse[11].ccredit=3;
    pcourse[12].semester=2; pcourse[12].cno=13; strcpy(pcourse[12].course_name,"��ѧӢ��2"); pcourse[12].cpno1=5; pcourse[12].cpno2=2;pcourse[12].ccredit=4;
    pcourse[13].semester=2; pcourse[13].cno=14; strcpy(pcourse[13].course_name,"�߼�����"); pcourse[13].cpno1=2; pcourse[13].cpno2=0;pcourse[13].ccredit=4;
    pcourse[14].semester=2; pcourse[14].cno=15; strcpy(pcourse[14].course_name,"��ѧ�����｡��"); pcourse[14].cpno1=0; pcourse[14].cpno2=0;pcourse[14].ccredit=1;
    pcourse[15].semester=2; pcourse[15].cno=16; strcpy(pcourse[15].course_name,"������ͼ"); pcourse[15].cpno1=0; pcourse[15].cpno2=0;pcourse[15].ccredit=1.5;
    pcourse[16].semester=2; pcourse[16].cno=17; strcpy(pcourse[16].course_name,"��ͨ��ѧ"); pcourse[16].cpno1=0; pcourse[16].cpno2=0;pcourse[16].ccredit=1.5;
    pcourse[17].semester=2; pcourse[17].cno=18; strcpy(pcourse[17].course_name,"��ѧ�����»���"); pcourse[17].cpno1=0; pcourse[17].cpno2=0;pcourse[17].ccredit=0.5;
    pcourse[18].semester=2; pcourse[18].cno=19; strcpy(pcourse[18].course_name,"����������2"); pcourse[18].cpno1=9; pcourse[18].cpno2=0;pcourse[18].ccredit=0.25;
    pcourse[19].semester=2; pcourse[19].cno=20; strcpy(pcourse[19].course_name,"��ѧ��ְҵ�滮"); pcourse[19].cpno1=0; pcourse[19].cpno2=0;pcourse[19].ccredit=0.5;

    pcourse[20].semester=3; pcourse[20].cno=21; strcpy(pcourse[20].course_name,"���ݽṹ"); pcourse[20].cpno1=2; pcourse[20].cpno2=14;pcourse[20].ccredit=4;
    pcourse[21].semester=3; pcourse[21].cno=22; strcpy(pcourse[21].course_name,"��ѧӢ��3"); pcourse[21].cpno1=13; pcourse[21].cpno2=2;pcourse[21].ccredit=2;
    pcourse[22].semester=3; pcourse[22].cno=23; strcpy(pcourse[22].course_name,"��������ԭ��"); pcourse[22].cpno1=6; pcourse[22].cpno2=11;pcourse[22].ccredit=4;
    pcourse[23].semester=3; pcourse[23].cno=24; strcpy(pcourse[23].course_name,"��ѧ����2"); pcourse[23].cpno1=10; pcourse[23].cpno2=12;pcourse[23].ccredit=2.5;
    pcourse[24].semester=3; pcourse[24].cno=25; strcpy(pcourse[24].course_name,"��ԭ"); pcourse[24].cpno1=0; pcourse[24].cpno2=0;pcourse[20].ccredit=3;
    pcourse[25].semester=3; pcourse[25].cno=26; strcpy(pcourse[25].course_name,"����������3"); pcourse[25].cpno1=19; pcourse[25].cpno2=0;pcourse[25].ccredit=0.25;
    pcourse[26].semester=3; pcourse[26].cno=27; strcpy(pcourse[26].course_name,"��ѧ����ҵ����"); pcourse[26].cpno1=18; pcourse[26].cpno2=0;pcourse[26].ccredit=0.5;


    pcourse[27].semester=4; pcourse[27].cno=28; strcpy(pcourse[27].course_name,"��ѧӢ��4"); pcourse[27].cpno1=22; pcourse[27].cpno2=0;pcourse[27].ccredit=2;
    pcourse[28].semester=4; pcourse[28].cno=29; strcpy(pcourse[28].course_name,"���Դ���A"); pcourse[28].cpno1=10; pcourse[28].cpno2=0;pcourse[28].ccredit=2.5;
    pcourse[29].semester=4; pcourse[29].cno=30; strcpy(pcourse[29].course_name,"����ϵͳ"); pcourse[29].cpno1=21; pcourse[29].cpno2=0;pcourse[29].ccredit=4;
    pcourse[30].semester=4; pcourse[30].cno=31; strcpy(pcourse[30].course_name,"����ԭ��"); pcourse[30].cpno1=21; pcourse[30].cpno2=0;pcourse[30].ccredit=3;
    pcourse[31].semester=4; pcourse[31].cno=32; strcpy(pcourse[31].course_name,"ë��"); pcourse[31].cpno1=0; pcourse[31].cpno2=0;pcourse[31].ccredit=6;
    pcourse[32].semester=4; pcourse[32].cno=33; strcpy(pcourse[32].course_name,"��·B"); pcourse[32].cpno1=24; pcourse[32].cpno2=0;pcourse[32].ccredit=3;
    while(choice!=0)
    {
        title();
        scanf("%d",&choice); //����ѡ��
        Opis(choice,pstu,pcourse);
    }
    return 0;
}
