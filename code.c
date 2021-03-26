//Author: 2020212710-计6-周思乐
//Create: 2021/3/21
//Email: 851892190@qq.com
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
#include<windows.h>

void Init();
void Enter();//进入界面
void Menu();//进入菜单
void Clean_Screen();//清空屏幕
void Add_TXT();//添加文本
void Delete_TXT();//删除文本
void Print_Result();//打印结果
void Sort_Result();//结果排序
void Show_TXT_List();//展示文件列表
void Compare_TXT();//文本比较返回相似度
void Prework_TXT();//文本预处理

int main()
{
    system("pause");
    Init();
    Enter();
    Menu();
    return 0;
}

void Init()
{
    printf("环境初始化中……\n");

    printf("初始化完成……\n");
}

void Enter()
{
    printf("--------------------------------------------------------------------------------------------------------------------------------\n\n");
    printf("|-------------|     |-|       |-|     |-------------|       ----------|            |-|         |-|            |--------|       |\n");
    printf("---------------      |-|     |-|      ---------------       |---------|           |-|-|       |-|-|           |-|    |-|       |\n");
    printf("      |-|             |-|   |-|             |-|             |-|                  |-| |-|     |-|-|-|          |-|    |-|       |\n");
    printf("      |-|              |-|-|-|              |-|             |-|                 |-|   |-|   |-|   |-|         |-|-------       |\n");
    printf("      |-|             |-|   |-|             |-|             |-|                 |-|   |-|   |-|   |-|         |-|              |\n");
    printf("      |-|            |-|     |-|            |-|             |---------|        |-|     |-|-|-|     |-|        |-|              |\n");
    printf("      |-|           |-|       |-|           |-|             |---------|        |-|      |-|-|      |-|        |-|              |\n\n");
    printf("--------------------------------------------------------------------------------------------------------------------------------\n\n");
}

void Menu()
{
    char op;
    printf("菜单\n");
    printf("请选择你要做出的操作\n");
    printf("1.添加文本\n");
    printf("2.删除文本\n");
    printf("3.文本相似度比较\n");
    printf("4.展示已添加的文本列表\n");
    printf("C.清空屏幕并回到菜单\n");
    printf("E.退出程序\n");
    scanf(" %c",&op);
    switch(op)
    {
    /*    case '1':
            Add_TXT();
            break;
        case '2':
            Delete_TXT();
            break;*/
        case '3':
            Compare_TXT();
            break;
        case '4':
            Show_TXT_List();
            break;
        case 'C':
            Clean_Screen();
            break;
        case 'E':
            exit(0);
            break;
    }

}
void Clean_Screen()//清空屏幕
{
    system("cls");
    Menu();
}
void Prework_TXT()//文本预处理
{
    char choice[2];//选择是否
    bool option[10];//选项设置
    do
    {
        printf("是否忽略空格:Y/N\n");
        scanf("%s",choice);
        if(choice[0]=='Y'||choice[0]=='y')option[0]=true;
    }while(choice[0]!='Y'&&choice[0]!='y'&&choice[0]!='N'&&choice[0]!='n');

    do
    {
        printf("是否忽略():Y/N\n");
        scanf("%s",choice);
        if(choice[0]=='Y'||choice[0]=='y')option[1]=true;
    }while(choice[0]!='Y'&&choice[0]!='y'&&choice[0]!='N'&&choice[0]!='n');

    do
    {
        printf("是否忽略数字:Y/N\n");
        scanf("%s",choice);
        if(choice[0]=='Y'||choice[0]=='y')option[2]=true;
    }while(choice[0]!='Y'&&choice[0]!='y'&&choice[0]!='N'&&choice[0]!='n');

    do
    {
        printf("是否忽略大小写差异:Y/N\n");
        scanf("%s",choice);
        if(choice[0]=='Y'||choice[0]=='y')option[3]=true;
    }while(choice[0]!='Y'&&choice[0]!='y'&&choice[0]!='N'&&choice[0]!='n');


}
void Compare_TXT()
{
    char File_A[100],File_B[100];
    char buff_A[100000],buff_B[100000];
    int Size_A=0,Size_B=0; //文件大小

    printf("请输入需要进行比较的文件名(注意加入后缀名）\n");
    printf("eg：错误的输入:abc   正确的输入:abc.txt\n");

    printf("请输入第一个文件名:\n");
    scanf("%s",File_A);
    printf("请输入第二个文件名:\n");
    scanf("%s",File_B);

    FILE *fp_A=NULL;
    FILE *fp_B=NULL;

    fp_A=fopen(File_A,"r");
    fp_B=fopen(File_B,"r");
    while(fp_A==NULL)
    {
        printf("文件A不存在请重新输入:\n");
        scanf("%s",File_A);
        fp_A=fopen(File_A,"r");
    }
    while(fp_B==NULL)
    {
        printf("文件B不存在请重新输入:\n");
        scanf("%s",File_B);
        fp_B=fopen(File_B,"r");
    }
    char ch;
    while((ch=fgetc(fp_A))!=EOF)
    {
        buff_A[Size_A++]=ch;
    }

    while((ch=fgetc(fp_B))!=EOF)
    {
        buff_B[Size_B++]=ch;
    }


//    printf("FILE A:\n%s\n\n\nFILE B:\n%s\n\n\n",buff_A,buff_B);

    printf("请选择需要预处理的选项：\n");
    Prework_TXT(buff_A,buff_B);
    /*


    */
    printf("文本相似度比较已完成，相似度为\n");
    fclose(fp_A);fclose(fp_B);
    printf("是否回到菜单Y/N\n");
}

void Show_TXT_List()
{

}
