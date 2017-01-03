#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    int  num;                 //编号              
    char bname[50];          //书名
    char wname[20];          //作者
    char press[50];          //出版社
    char sort[50];           //类别
    struct date              //出版时间
    {
        int year;
        int month;
        int day;
    }time;                
    float price;             //价格
    struct book *next;
};
struct student
{
    char num[15]; //学生学号
    char name[20];//学生名字
    int numbook;  //图书编号
    struct student *next;
};
struct admin 
{
    char  account[15];  //账号
    char  password[15]; //密码
    struct admin *next;
};

int mainmenu();                                     //主菜单界面
int pwYanzheng();                                   //密码验证
int adminmenu();                                    //1.管理员主界面
int user();                                         //2.用户界面
void tushu_tianjia();                               //1.1.添加图书信息
void tushu_luru();                                  //1.2.录入图书信息
void tushu_chaxun1();                               //1.3.查询图书信息
void tushu_paixu();                                 //1.4./2.2.图书信息排序
void tushu_xiugai();                                //1.5.修改图书信息
void tushu_shanchu();                               //1.6.删除图书信息
void admin_xiugai();                                //1.7.账号编辑
void tushu_chaxun2();                               //2.1.查询图书信息
void tushu_jieyue();                                //2.3.图书借阅
void tushu_guihuan();                               //2.4.图书归还
struct book *addbook(struct book *head);            //1.1.添加图书
struct book *creatbook();                           //1.2.录入数据
void chaxun1(struct book *head);                    //1.3.查询图书信息
void chaxun2(struct book *head);                    //2.1.查询图书信息
void tushu_liebiao();                               //1.3.1图书列表
void print_jie();                                   //1.3.2输出所有借书人的信息
void num_chaxun(struct book *head);                 //1.3.3按图书编号查询图书
void wname_chaxun(struct book *head);               //1.3.4按作者名查询图书
void sort_chaxun(struct book *head);                //1.3.5按类别查询图书
void time_chaxun(struct book *head);                //1.3.6按出版时间查询图书
void bname_chaxun(struct book *head);               //1.3.7按图书名查询图书
void price_chaxun(struct book *head);               //1.3.8按图书价格查询图书信息 
void paixu(struct book *head);                      //1.4.对图书进行排序
void num_paixu(struct book *head);                  //1.4.1按图书编号排序
void time_paixu(struct book *head);                 //1.4.2按图书出版时间排序
void price_paixu(struct book *head);                //1.4.3按图书价格排序
void bname_paixu(struct book *head);                //1.4.4按图书名排序
void wname_paixu(struct book *head);                //1.4.5按作者名排序
void xiugai(struct book *head);                     //1.5.修改图书信息
void deletebook(struct book *head);                 //1.6.删除图书
void print_book(struct book *head);                 //1.3.1.将文件信息全部输出
struct book *load();                                //从文件中读取信息并建成链表
void fprint(struct book *head);                     //将链表写入文件
int  yanzheng(struct book *head, int m);            //验证新添加的图书编码是否已存在

int main()
{
    int choice, n, x, y=1;
    struct book *head = NULL;
    while (y)
    {
        system("cls");
        n = mainmenu();   //主菜单界面
        switch(n)
        {
            case 3: y = 0; break;   //退出系统
            case 1:               //进入管理员模式
                x = pwYanzheng(); //密码验证
                while(x)
                {
                    system("cls");
                    choice = adminmenu(); //管理员主界面
                    switch(choice)
                    {
                        case 0: system("cls"); x = 0;           break;
                        case 1: system("cls"); tushu_tianjia(); break;
                        case 2: system("cls"); tushu_luru();    break;
                        case 3: system("cls"); tushu_chaxun1();  break;
                        case 4: system("cls"); tushu_paixu();   break;
                        case 5: system("cls"); tushu_xiugai();  break;
                        case 6: system("cls"); tushu_shanchu(); break;
                        case 7: system("cls"); admin_xiugai();  break;
                        default:
                            printf("\n\t\t\t\t您的输入有误,请重新输入!\n");
                            getchar();
                            break;     
                    }     
                }
                break;
            case 2: 
                x = 1;                                //进入用户模式
                while(x) 
                {
                    system("cls");
                    choice = user();
                    switch(choice)
                    {
                         case 0: system("cls"); x = 0;           break;
                         case 1: system("cls"); tushu_chaxun2(); break;
                         case 2: system("cls"); tushu_paixu();   break;
                         case 3: system("cls"); tushu_jieyue();  break;
                         case 4: system("cls"); tushu_guihuan(); break;
                         default:
                            printf("\n\t\t\t\t您的输入有误,请重新输入!\n");
                            getchar();
                            break;    
                    }
                }
                break;

            default:                                //输入有误
                printf("\t\t您的输入有误!  请重新输入!\n");
                getchar();
                break;
        }
    }
    printf("\t\t\t\t\t 谢谢使用图书信息管理系统！\n\n\n");
    system("pause");
}    


//主菜单栏
int mainmenu()
{
    int x;
    printf("\n\n\n\n\n\n\n");
    printf("\t\t----------------------------------------------------------------------------\n");
    printf("\t\t                        ********** 欢迎光临 *********                        \n");
    printf("\t\t                                                                            \n");   
    printf("\t\t        ********************** 图书信息管理系统 ************************     \n");
    printf("\t\t                                                                            \n");  
    printf("\t\t                                                                            \n");  
    printf("\t\t                                                                           \n");  
    printf("\t\t                    ============1-管理员模式============                    \n");
    printf("\t\t                                                                           \n"); 
    printf("\t\t                    ============2-客户模式==============                    \n");
    printf("\t\t                                                                           \n"); 
    printf("\t\t                    ============3-退出系统==============                    \n");
    printf("\t\t                                                                           \n");  
    printf("\t\t                                                                           \n");  
    printf("\t\t---------------------------------------------------------------------------\n\n");
    printf("\t\t请输入您的选择:");
    scanf("%d", &x);
    printf("\n");
    getchar();
    return x;    
}

//密码验证
int pwYanzheng()
{
    FILE *fp;
    int a, y = 0;
    char account[15], password[15];
    struct admin *p1, *head = NULL, *tail;
    if ((fp = fopen("admin.txt", "r")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    if (fgetc(fp) == EOF)     //没有管理员信息不需要验证  
        return 1;
    rewind(fp);
    while (!feof(fp))
    {
        p1 = (struct admin *)malloc(sizeof(struct book));
        fscanf(fp, "%s%s\n", p1->account, p1->password);
        if (head == NULL)
            head = p1;
        else
            tail->next = p1;
        tail = p1;
    }
    tail->next = NULL;
    fclose(fp);
    p1 = head;
    printf("\t\t请输入您的用户名:");
    gets(account);
    while (p1 != NULL)
    {
        if (strcmp(p1->account, account) == 0)
        {
            y = 1;
            break;
        }
        p1 = p1->next;
    }
    if (p1 == NULL)
    {
        printf("\t\t该账号不存在!\n");
        getchar();
        return 0;
    }
    if(y)
    {
        printf("\n\t\t请输入您的密码:");
        gets(password);
        printf("\n");
        if(strcmp(p1->password, password) != 0)
        {
            printf("\t\t验证失败,请重新输入!\n");
            getchar();
            system("cls");
            return 0;
        }
        else
        {
            printf("\t\t验证通过!请按Enter键进入!\n");
            getchar();
            system("cls");
            return 1;
        }
    }
}

//1.管理员主界面
int adminmenu()
{
    int a;
    printf("\t\t\t\t                          -------------------\n");
    printf("\t\t\t\t                           *图书信息管理系统*\n");
    printf("\t\t\t\t                          -------------------\n\n");
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t|| 1-添加图书信息                                    2-录入图书信息 ||\n\n");
    printf("\t\t\t\t|| 3-查看图书信息                                    4-图书信息排序 ||\n\n");
    printf("\t\t\t\t|| 5-修改图书信息                                    6-删除图书信息 ||\n\n");
    printf("\t\t\t\t|| 7-管理账号编辑                                    0-退出管理系统 || \n\n");        
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t请输入所选择的序号:");
    scanf("%d", &a);
    getchar();  
    return a;                  
}

//2.用户主界面
int user()
{
    int a;
    printf("\t\t\t\t                      -------------------\n");
    printf("\t\t\t\t                       *图书信息管理系统*\n");
    printf("\t\t\t\t                      -------------------\n\n");
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t|| 1-查询图书                                       2-图书排序 ||\n\n");
    printf("\t\t\t\t|| 3-图书借阅                                       4-图书归还 ||\n\n");
    printf("\t\t\t\t|| 0-退出系统                                                   \n\n");         
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t#请输入所选择的序号:");
    scanf("%d", &a);
    getchar();  
    return a;                  
}

//1.1.添加图书信息
void tushu_tianjia()
{
    struct book *head = NULL;
    char a;
    head = load();
    if (head == NULL)
    {
        printf("\n\t\t\t\t\t文件为空,请先录入数据!\n");
        getchar();
    }
    else
    {
        head = addbook(head);
        printf("添加成功!\n");
        printf("是否将新信息保存到文件?(y/n)\n");
        scanf("%c", &a);
        getchar();
        switch(a)
        {
            case 'n':
                break;
            case 'y':
                fprint(head);
                printf("保存成功!\n");
                getchar();
                system("cls");
                break;
        }
    }                            
}

//1.2.录入数据
void tushu_luru()
{
    struct book *head = NULL;
    char a;
    printf("注意:输入图书编码为0时结束!\n");
    head = creatbook();
    printf("是否将输入的信息保存到文件以覆盖文件中已存在的信息?(y/n)\n");
    getchar();
    scanf("%c", &a);
    getchar();
    switch(a)
    {
        case 'n':
            break;
        case 'y':
            fprint(head);
            printf("保存成功!\n");
            getchar();
            break;
    }
}

//1.3.查询图书
void tushu_chaxun1()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("文件为空,请先录入数据!\n");
        getchar();
    }
    else
    {
        chaxun1(head);
        getchar();
    }
}      

//1.4.图书排序
void tushu_paixu()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("文件为空,请先录入数据!\n");
        getchar();
    }
    else
    {
        paixu(head);
        getchar();
    }
}

//1.5.修改图书信息
void tushu_xiugai()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("文件为空,请先录入数据!\n");
        getchar();
    }
    else
    {
        xiugai(head);
        getchar();
    }
}      

//1.6.删除图书信息
void tushu_shanchu()
{
    struct book *head = NULL;
    head = load();
    if(head == NULL)
    {
        printf("文件为空,请先录入数据!\n");
        getchar();
    }
    else
    {
        deletebook(head);
        getchar();
    }
}   

//1.7.账号编辑
void admin_xiugai()
{
    FILE *fp;
    int x = 1, y = 1;
    char a;
    char account[15], password1[15], password2[15], password3[15];
    struct admin *p1, *p2 = NULL, *head = NULL, *tail;
    
    while(x)
    {
        if ((fp = fopen("admin.txt", "r")) == NULL)
        {
            printf("File open error!\n");
            exit(0);
        }
        while (!feof(fp))
        {
            p1 = (struct admin *)malloc(sizeof(struct admin));
            fscanf(fp, "%s%s\n", p1->account, p1->password);
            if (head == NULL)
                head = p1;
            else
                tail->next = p1;
            tail = p1;
        }
        tail->next = NULL;
        fclose(fp);
        p1 = head;
        system("cls");
        printf("\t\t\t\t                   -----------------\n");
        printf("\t\t\t\t                    *管理员信息编辑*\n");
        printf("\t\t\t\t                   -----------------\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t** 1-注册账号                           2-删除账号 **\n\n");
        printf("\t\t\t\t** 3-修改密码                           0-取消编辑 **\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t请输入您选择的序号:");
        scanf("%c", &a);
        getchar();
        switch(a)
        {
            case '0':
                    x = 0; 
                    break;
            ///////////////////////注册新用户/////////////////////////
            case '1':
                y = 1;
                printf("\t\t\t\t请输入您的新账号:");
                gets(account);
                while (p1 != NULL)
                {
                    if (strcmp(p1->account,account) == 0)
                    {
                        y = 0;
                        printf("\t\t\t\t该账号已存在！");
                        getchar();
                        break;
                    }
                    p1 = p1->next;
                }
                if (y)
                {
                    printf("\t\t\t\t请输入密码:");
                    gets(password1);
                    printf("\t\t\t\t请再次输入密码:");
                    gets(password2);
                    if (strcmp(password1,password2) == 0)
                    {
                        if ((fp = fopen("admin.txt", "a")) == NULL)
                        {
                            printf("File open error!\n");
                            exit(0);
                        }
                        fprintf(fp, "%s %s\n", account, password1);
                        fclose(fp);
                        printf("\n\t\t\t\t账号注册成功！");
                        getchar();
                    }
                    else
                    {
                        printf("\t\t\t\t两次输入的密码不一致!");
                        getchar();
                    }
                }
                break;
            ///////////////////////删除账号//?????you wen titittiitittiti???????????????????????????????????????????????????????????????????/////////////////////////
            case '2':
                y = 0;
                fp = fopen("admin.txt", "r");
                if (fgetc(fp)==EOF)   
                {
                    rewind(fp);
                    fclose(fp);
                    printf("\n\t\t\t\t该系统不存在账号!\n\n");
                    getchar();
                }   
                else
                {
                    rewind(fp);
                    fclose(fp);
                    printf("\t\t\t\t请输入您的账号:");
                    gets(account);
                    while(p1 != NULL)
                    {
                        if (strcmp(p1->account, account) == 0)
                        {
                            y = 1;
                            break;
                        }
                        p1 = p1->next;
                    }
                    //////////删除归还人信息///////////////
                    if (y)
                    {  
                        p1 = head;
                        p2 = p1->next;
                        //数据在表头
                        if (strcmp(p1->account, account) == 0) 
                        {
                            head = p2;
                        }
                        else
                        {
                            while(p2 != NULL)
                            {
                                if(strcmp(p2->account, account) == 0)
                                {
                                    p1->next = p2->next;
                                    break;
                                }
                                else 
                                {
                                    p1 = p2;
                                    p2 = p2->next;
                                }
                            }
                        }
                        /////////将新的信息写入文件////////////
                        if ((fp = fopen("admin.txt", "w")) == NULL)
                        {
                            printf("File open error!\n");
                            exit(0);
                        }
                        for (p1 = head; p1; p1 = p1->next)
                        {
                            fprintf(fp, "%s %s\n", p1->account, p1->password);
                        }
                        fclose(fp);
                        printf("\n\t\t\t\t账号删除成功！\n\n");
                        getchar();
                    }
                    else
                    {
                        printf("\n\t\t\t\t不存在该账号!\n\n");
                        getchar();
                    }
                }
                break;       
            ///////////////////////修改密码//////////////////////////
            case '3':
                y = 0;
                p1 = head;
                printf("\t\t\t\t请输入您的账号:");
                gets(account);
                while (p1 != NULL)
                {
                    if (strcmp(p1->account,account) == 0)
                    {
                        y = 1;
                        break;
                    }
                    p1 = p1->next;
                }
                if (p1 == NULL)
                {
                    printf("\t\t\t\t该账号不存在!\n");
                    getchar();
                }
                if (y)
                {
                    printf("\t\t\t\t请输入原始密码:");
                    gets(password3);
                    if (strcmp(p1->password,password3) == 0)
                    {
                        printf("\t\t\t\t请输入新密码:");
                        gets(password1);
                        printf("\t\t\t\t请再次输入新密码:");
                        gets(password2);
                        if (strcmp(password1, password2) == 0)
                        {
                            strcpy(p1->password,password1);
                            if ((fp = fopen("admin.txt","w")) == NULL)
                            {
                                printf("File open error!\n");
                                exit(0);
                            }
                            for (p1 = head; p1; p1 = p1->next)
                            {
                                fprintf(fp, "%s %s\n", p1->account, p1->password);
                            }
                            fclose(fp);
                            printf("\t\t\t\t您已成功修改了密码！");
                        }
                        else
                        {
                            printf("\t\t\t\t你两次输入的密码不一致！");
                            getchar(); 
                        }
                    }
                    else
                    {
                        printf("\t\t\t\t你输入的密码有误！");
                        getchar();
                    }
                }
                 break;
            default:                              
                printf("\t\t\t\t您的输入有误!  请重新输入!\n");
                getchar();
                break; 
        
        }
    }
}

//2.1.查询图书
void tushu_chaxun2()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("文件为空,请先录入数据!\n");
        getchar();
    }
    else
    {
        chaxun2(head);
        getchar();
    }
}   

//2.3.图书借阅
void tushu_jieyue()
{
    FILE *fp;
    int x = 1, numbook;
    char b;
    char num[15], name[20];
    struct student *p1, *head=NULL, *tail;
    struct book *p = NULL;
    printf("\n\t\t\t\t\t\t 请输入您要借阅的图书编号:");
    scanf("%d", &numbook);
    getchar();
    ////////////////判断图书是否被借走///////////////////////
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        p1 = (struct student *)malloc(sizeof(struct book));
        fscanf(fp, "%s%s%d\n", p1->num, p1->name, &p1->numbook);
        if (head == NULL)
            head = p1;
        else
            tail->next = p1;
        tail = p1;
    }
    tail->next = NULL;
    fclose(fp);
    p1 = head;
    while(p1 != NULL)
    {
        if (p1->numbook == numbook)
        {
            x = 0;
            printf("\n\n\t\t\t\t\t\t  Sorry！该图书已被借走！");
            getchar();
            break;
        }
        p1 = p1->next;
    }
 
    //////////////////查看是否有此图书，并借阅/////////////////////////
    if(x)
    {  
        p = load();
        while (p != NULL)
        {
            if(p->num == numbook)
                break;
            p = p->next;
        }
        if (p == NULL)
        {
            printf("\n\n\t\t\t\t\t\t  没有找到该编号的图书!\n");
            getchar();
        }
        else
        {
            printf("\n\t\t\t\t\t\t   你所借阅的图书信息如下\n");
            printf("\t\t\t===========================================================================\n");
            printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
            printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                        p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);
            printf("\t\t\t===========================================================================\n");
            printf("\t\t\t请输入你的学号：");
            gets(num);
            printf("\t\t\t请输入你的名字：");
            gets(name);
            printf("\n\t\t\t是否借阅该书?(y/n)");
            scanf("%c", &b);
            getchar();
            switch(b)
            {
                case 'n':
                    break;
                case 'y':
                    if ((fp = fopen("student.txt", "a")) == NULL)
                    {
                        printf("File open error!\n");
                        exit(0);
                    }
                    fprintf(fp, "%s %s %d\n", num, name, numbook);
                    fclose(fp);
                    printf("\n\t\t\t图书借阅成功！");
                    getchar();
            }
        }
    }
    
}

//2.4.图书归还
void tushu_guihuan()
{
    FILE *fp;
    int a;
    char num[20];
    struct student *head, *tail, *p1, *p2;
    head = tail = NULL;
    printf("\n\n\t\t\t\t\t\t请输入您要归还的图书编号:");
    scanf("%d", &a);
    getchar();
    ///////////从文件读取数据/////////////
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    while (!feof(fp))
    {
        p1 = (struct student *)malloc(sizeof(struct book));
        fscanf(fp, "%s%s%d\n", p1->num, p1->name, &p1->numbook);
        if (head == NULL)
            head = p1;
        else
            tail->next = p1;
        tail = p1;
    }
    tail->next = NULL;
    fclose(fp);
    /////////////////////////////////
    p1 = head;
    while(p1 != NULL)
    {
        if (p1->numbook == a)
            break;
        p1 = p1->next;
    }
    if (p1 == NULL)
    {
        printf("\n\n\t\t\t\t\t\t  没有借出该编号的图书!\n\n");
        getchar();
    }
    else
    {
        printf("\n\t\t\t\t\t\t请输入你的学号:");
        gets(num);
        if (strcmp(p1->num, num) == 0)
        {
            //////////删除归还人信息///////////////
            p1 = head;
            p2 = p1->next;
            if(p1->numbook == a)  //数据在表头
            {
                head = p2;
                free(p1);
            }
            else
            {
                while(p2 != NULL)
                {
                    if(p2->numbook == a)
                    {
                        p1->next = p2->next;
                        free(p2);
                        break;
                    }
                    else 
                    {
                        p1 = p2;
                        p2 = p2->next;
                    }
                }
            }
            /////////将新的信息写入文件////////////
            if ((fp = fopen("student.txt", "w")) == NULL)
            {
                printf("File open error!\n");
                exit(0);
            }
            for (p1 = head; p1; p1 = p1->next)
            {
                fprintf(fp, "%s %s %d\n", p1->num, p1->name, p1->numbook);
            }
            fclose(fp);
            printf("\n\t\t\t\t\t\t图书归还成功！谢谢使用！\n\n");
            getchar();
        }
        else
        {
            printf("\n\t\t\t\t\t\t你输入的学号有误！");
            getchar();
        }
    }
}     

//1.1.添加图书 插入结点，并且插入后仍按一定顺序
struct book *addbook(struct book *head)
{
 
    struct book *ptr, *p1, *p2, *p;
    char bname[50], wname[20], press[50], sort[50];
    int size = sizeof(struct book);
    int num, year, month, day, n=1;
    float price;
    do
    {
        printf("请输入图书编号:");
        scanf("%d", &num);
        n = yanzheng(head, num);
        if (n == 0)
            break;
        else
            printf("您输入的编号已存在,请重新输入!\n");
    }while(1);
    printf("请输入图书名:");
    scanf("%s", bname);
    getchar();
    printf("请输入作者名:");
    scanf("%s", wname);
    getchar();
    printf("请输入出版社:");
    scanf("%s", press);
    getchar();
    printf("请输入类别:");
    scanf("%s", sort);
    getchar();
    printf("请输入出版时间:");
    scanf("%d%d%d", &year, &month, &day);
    getchar();
    printf("请输入价格:");
    scanf("%f", &price);
    getchar();
    p = (struct book *)malloc(size);
    p->num = num;
    strcpy(p->bname, bname);
    strcpy(p->wname, wname);
    strcpy(p->press, press);
    strcpy(p->sort, sort);
    p->time.year = year;
    p->time.month = month;
    p->time.day = day;
    p->price = price;
    p2 = head;
    ptr = p;
    while ((ptr->num > p2->num) && (p2->next != NULL))
    {
        p1 = p2;
        p2 = p2->next;
    }
    if (ptr->num <= p2->num)
    {
        if (head == p2)
            head = ptr;
        else
        {
            p1->next = ptr;
            p->next = p2;
        }
    }
    else
    {
        p2->next = ptr;
        p->next = NULL;
    }
    return head;
}

//1.2.录入数据 并形成链表
struct book *creatbook()
{
    struct book *head, *tail, *p;
    int num, year, month, day, n;
    char bname[50], wname[20], press[50], sort[50];
    float price;
    int size = sizeof(struct book);
    head = tail = NULL;
    printf("请输入图书编号:");
    scanf("%d", &num);
    printf("请输入图书名:");
    scanf("%s", bname);
    getchar();
    printf("请输入作者名:");
    scanf("%s", wname);
    getchar();
    printf("请输入出版社:");
    scanf("%s", press);
    getchar();
    printf("请输入类别:");
    scanf("%s", sort);
    getchar();
    printf("请输入出版时间:");
    scanf("%d%d%d", &year, &month, &day);
    getchar();
    printf("请输入价格:");
    scanf("%f", &price);
    getchar();
    while(1)
    {
        p = (struct book *)malloc(size);
        p->num = num;
        strcpy(p->bname, bname);
        strcpy(p->wname, wname);
        strcpy(p->press, press);
        strcpy(p->sort, sort);
        p->time.year = year;
        p->time.month = month;
        p->time.day = day;
        p->price = price;
        p->next = NULL;
        if (head == NULL)
            head = p;
        else
            tail->next = p;
        tail = p;
        do
        { 
            printf("请输入图书编号:");
            scanf("%d", &num);
            n = yanzheng(head, num);
            if (n == 0)
                break;
            else
                printf("您输入的编号已存在,请重新输入!\n");
        }while(1);
        if (num == 0)
            break;
        else
        {
            printf("请输入图书名:");
            scanf("%s", bname);
            getchar();
            printf("请输入作者名:");
            scanf("%s", wname);
            getchar();
            printf("请输入出版社:");
            scanf("%s", press);
            getchar();
            printf("请输入类别:");
            scanf("%s", sort);
            getchar();
            printf("请输入出版时间:");
            scanf("%d%d%d", &year, &month, &day);
            getchar();
            printf("请输入价格:");
            scanf("%f", &price);
            getchar();
        }
    }
    return head;
}

//1.3.图书查询
void chaxun1(struct book *p1)
{
    int a, x = 1;
    while(x)
    {
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t                         *图书查询*\n");
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t============================================================\n\n");
        printf("\t\t\t\t** 1-所有图书信息                          2-图书借阅信息 **\n\n");
        printf("\t\t\t\t** 3-按图书编号查询                        4-按图书名查询 **\n\n");
        printf("\t\t\t\t** 5-按图书类别查询                        6-按作者名查询 **\n\n");
        printf("\t\t\t\t** 7-按出版时间查询                        8-按价格查询   **\n\n");
        printf("\t\t\t\t** 0-退出查询                                              \n\n");
        printf("\t\t\t\t============================================================\n");
        printf("\t\t\t\t请输入所选择的序号:");
        scanf("%d", &a);
        getchar();
        switch(a)
        {
            case 0:
                    x = 0; break;
            case 1:
                tushu_liebiao();
                getchar();
                system("cls");
                break;
            case 2:
                print_jie();
                getchar();
                system("cls");
                break;
            case 3:
                num_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 4:
                bname_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 5:
                sort_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 6:
                wname_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 7:
                time_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 8:
                price_chaxun(p1);
                getchar();
                system("cls");
                break;
            default:
                printf("\t\t\t\t您的输入有误！请重新输入！\n");
                getchar();
                system("cls");
                break;
        }
    }
}

//2.1图书查询
void chaxun2(struct book *p1)
{
    int a, x = 1;
    while(x)
    {
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t                         *图书查询*\n");
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t===============================================================\n\n");
        printf("\t\t\t\t** 1-所有图书信息                          2-按图书编号查询 **\n\n");
        printf("\t\t\t\t** 3-按图书名查询                          4-按图书类别查询 **\n\n");
        printf("\t\t\t\t** 5-按作者名查询                          6-按出版时间查询 **\n\n");
        printf("\t\t\t\t** 7-按价格查询                            0-退出查询系统   **\n\n");
        printf("\t\t\t\t==============================================================\n");
        printf("\t\t\t\t请输入所选择的序号:");
        scanf("%d", &a);
        getchar();
        switch(a)
        {
            case 0:
                    x = 0; break;
            case 1:
                tushu_liebiao();
                getchar();
                system("cls");
                break;
            case 2:
                num_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 3:
                bname_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 4:
                sort_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 5:
                wname_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 6:
                time_chaxun(p1);
                getchar();
                system("cls");
                break;
            case 7:
                price_chaxun(p1);
                getchar();
                system("cls");
                break;
            default:
                printf("\t\t\t\t您的输入有误！请重新输入！\n");
                getchar();
                system("cls");
                break;
        }
    }
}

//1.3.1图书列表
void tushu_liebiao()
{
    struct book *head = NULL;
    head = load();
    if(head == NULL)
    {
        printf("文件为空,请先录入数据!\n");
        getchar();
    }
    else
    {
        print_book(head);
        getchar();
    }
}  

//1.3.2输出所有借书人的信息
void print_jie()
{
    FILE *fp;
    char ch;
    struct student *head, *tail, *p1;
    head = tail = NULL;
    if ((fp = fopen("student.txt","r")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    if (fgetc(fp)==EOF)   
    {
        rewind(fp);
        fclose(fp);
        printf("\n\n\t\t\t\t\t\t没有人借阅了图书!\n\n");
        getchar();
    }  
    else
    {
        rewind(fp);
        while (!feof(fp))
        {
            p1 = (struct student *)malloc(sizeof(struct book));
            fscanf(fp, "%s%s%d\n", p1->num, p1->name, &p1->numbook);
            if (head == NULL)
                head = p1;
            else
                tail->next = p1;
            tail = p1;
        }
        tail->next = NULL;
        fclose(fp);
        printf("\n\n\t\t\t\t                借阅人信息\n");
        printf("\t\t\t\t===========================================\n");
        printf("\t\t\t\t    学号           姓名           图书编号\n");
        for (p1 = head; p1; p1 = p1->next)
            printf("\t\t\t\t %-17s%-19s%-5d\n",p1->num, p1->name, p1->numbook);
        printf("\t\t\t\t===========================================\n");   
        getchar();
    }  
}

//1.3.3按编号查询图书信息
void num_chaxun(struct book *head)
{
    int a;
    struct book *p;
    printf("\t\t\t\t请输入您要查询的图书编号:");
    scanf("%d", &a);
    getchar();
    p = head;
    while(p != NULL)
    {
        if (p->num == a)
            break;
        p = p->next;
    }
     
    if (p == NULL)
        printf("\t\t\t\t没有找到该编号的图书!\n");
    else
    {
        printf("\n\t\t\t                           你所查询的图书信息如下\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
        printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);
        printf("\t\t\t===========================================================================\n");
    }
}

//1.3.4按图书名查询图书信息
void bname_chaxun(struct book *head)
{
    char a[50];
    int flag = 0;
    struct book *p;
    printf("\t\t\t\t请输入您要查询的图书名:");
    gets(a);
    p = head;
    while (p != NULL)
    {
        if(strcmp(p->bname, a) == 0)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 0)
        printf("\t\t\t\t没有找到该图书名的图书!\n");
    else
    {
        printf("\n\t\t\t                           你所查询的图书信息如下\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
        while (p != NULL)
        {
            if (strcmp(p->bname,a) == 0)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                        p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);     
            p = p->next;
        }
        printf("\t\t\t===========================================================================\n");
    }
}

//1.3.5按图书类别查询图书信息
void sort_chaxun(struct book *head)
{
    char a[50];
    int flag = 0;
    struct book *p;
    printf("\t\t\t\t请输入您要查询图书的类别:");
    gets(a);
    p = head;
    while (p != NULL)
    {
        if (strcmp(p->sort, a) == 0)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if(flag == 0)
        printf("\t\t\t\t没有找到该类别的图书!\n");
    else
    {
        printf("\n\t\t\t                           你所查询的图书信息如下\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
        while(p != NULL)
        {
            if (strcmp(p->sort, a) == 0)
            {
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                        p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);   
                flag = 1;
            }
            p = p->next;
        }
        printf("\t\t\t===========================================================================\n");
    }
}

//1.3.6按作者名查询图书信息
void wname_chaxun(struct book *head)
{
    char a[50];
    int flag = 0;
    struct book *p;
    printf("\t\t\t\t请选择您要查询图书的作者名:");
    gets(a);
    p = head;
    while (p != NULL)
    {
        if (strcmp(p->wname,a) == 0)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if(flag == 0)
        printf("\t\t\t\t没有找到该作者的图书!\n");      
    else
    {
        printf("\n\t\t\t                           你所查询的图书信息如下\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
        while(p != NULL)
        {
            if (strcmp(p->wname,a) == 0)
            {
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                        p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);   
                flag = 1;
            }
            p = p->next;
        }
        printf("\t\t\t===========================================================================\n");
     }  
}

//1.3.7按图书出版时间查询图书信息
void time_chaxun(struct book *head)
{
    int a, flag = 0;
    struct book *p;
    printf("\t\t\t\t请选择您要查询图书的出版时间:");
    scanf("%d", &a);
    getchar();
    p = head;
    while (p != NULL)
    {
        if (p->time.year == a)
        {
            flag = 1;
            break;
        }
        p = p->next;
    }
    if (flag == 0)
        printf("\t\t\t\t没有找到该出版时间的图书!\n");
    else
    {
        printf("\n\t\t\t                           你所查询的图书信息如下\n");
        printf("\t\t\t============================================================================\n");
        printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
        while(p != NULL)
        {
            if (p->time.year == a)
            {
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                        p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);   
                flag = 1;
            }
            p = p->next;
        }
        printf("\t\t\t============================================================================\n");
    }
}

//1.3.8按图书价格查询图书信息
void price_chaxun(struct book *head)
{
    int a, b, flag = 0;
    struct book *p;
    printf("\t\t\t\t请输入图书的价格区间:");
    scanf("%d%d", &a, &b);
    getchar();
    p = head;
    while (p != NULL)
    {
        if (p->price >= a && p->price <= b)
        {
            flag = 1;
            break;
        }
        
        p = p->next;
    }
    if (flag == 0)
        printf("\t\t\t\t没有找到该价位的图书!\n");
    else
    {
        printf("\n\t\t\t\t                           你所查询的图书信息如下\n");
        printf("\t\t\t============================================================================\n");
        printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
        while(p != NULL)
        {
            if (p->price >= a && p->price <= b)
            {
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                        p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);   
                flag = 1;
            }
            p = p->next;
        }
        printf("\t\t\t============================================================================\n");
    }
}

//1.4.图书排序主函数
void paixu(struct book *head)
{
    int a, x = 1;
    while(x)
    {
        printf("\t\t\t\t                     --------------------\n");
        printf("\t\t\t\t                      *图书信息管理系统*\n");
        printf("\t\t\t\t                     --------------------\n");
        printf("\t\t\t\t================================================================\n");
        printf("\t\t\t\t**  1-按图书编号排序                        2-按出版时间排序  **\n\n");
        printf("\t\t\t\t**  3-按图书价格排序                        4-按图书名排序    **\n\n");
        printf("\t\t\t\t**  5-按作者名排序                          0-取消排序操作    **\n\n");
        printf("\t\t\t\t================================================================\n");
        printf("\t\t\t\t请输入您选择的序号:");
        scanf("%d", &a);
        getchar();
        switch(a)
        {
            case 0:
                x = 0; 
                break;
            case 1:
                num_paixu(head);
                getchar();
                system("cls");
                break;
            case 2:
                time_paixu(head);
                getchar();
                system("cls");
                break;
            case 3:
                price_paixu(head);
                getchar();
                system("cls");
                break;
            case 4:
                bname_paixu(head);
                getchar();
                system("cls");
                break;
            case 5:
                wname_paixu(head);
                getchar();
                system("cls");
                break;
            default:
                printf("\t\t\t\t您的输入有误！请重新输入！\n");
                getchar();
                system("cls");
                break;
        }
    }
}

//1.4.1按图书编号排序
void num_paixu(struct book *head)
{
    struct book *a[1000], *p, *p1, *temp;
    int i, k, index, n = 0;
    char b;
    p1 = head;
    for (p = head; p; p = p->next)
        n++;
    for (i = 0; i < n; i++)
    {
        a[i] = p1;
        p1 = p1->next;
    }

    for (k = 0; k < n-1; k++)     //选择法排序
    {
        index = k;
        for (i = k+1; i < n; i++)
        {
            if (a[i]->num < a[index]->num)
                index = i;
        }
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }
    printf("\t\t\t\t排序成功!\n");
    printf("\t\t\t\t是否显示排序结果?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t您的输入有误！请重新输入！\n");
            break;
    }
}

//1.4.2按出版时间排序        
void time_paixu(struct book *head)
{
    struct book *a[1000], *p, *p1, *temp;
    int i, k, index, n = 0;
    char b;
    p1 = head;
    for (p = head; p; p = p->next)
        n++;
    for(i = 0; i < n; i++)
    {
        a[i] = p1;
        p1 = p1->next;
    }
    for (k = 0; k < n-1; k++)
    {
        index = k;
        for (i = k+1; i < n; i++)
        {
            if (a[i]->time.year < a[index]->time.year)
                index = i;
        }
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }
    printf("\t\t\t\t排序成功!\n");
    printf("\t\t\t\t是否显示排序结果?(y/n)");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t您的输入有误！请重新输入！\n");
            break;
    }
}

//1.4.3按图书价格排序
void price_paixu(struct book *head)
{
    struct book *a[1000], *p, *p1, *temp;
    int i, k, index, n = 0;
    char b;
    p1 = head;
    for (p = head; p; p = p->next)
        n++;
    for (i = 0; i < n; i++)
    {
        a[i] = p1;
        p1 = p1->next;
    }
    for (k = 0; k < n-1; k++)
    {
        index = k;
        for (i = k+1; i < n; i++)
        {
            if (a[i]->price < a[index]->price)
                index = i;
        }
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }
    printf("\t\t\t\t排序成功!\n");
    printf("\t\t\t\t是否显示排序结果?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t您的输入有误！请重新输入！\n");
            break;
    }
}     

//1.4.4按图书名排序
void bname_paixu(struct book *head)
{
    struct book *a[1000], *p, *p1, *temp;
    int i, k, index, n = 0;
    char b;
    p1 = head;
    for (p = head; p; p = p->next)
        n++;
    for (i = 0; i < n; i++)
    {
        a[i] = p1;
        p1 = p1->next;
    }
    for (k = 0; k < n-1; k++)
    {
        index = k;
        for (i = k+1; i < n; i++)
        {
            if (strcmp(a[index]->bname, a[i]->bname) > 0)
                index = i;
        }
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }
    printf("\t\t\t\t排序成功!\n");
    printf("\t\t\t\t是否显示排序结果?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t您的输入有误！请重新输入！\n");
            break;
    }
}    

//1.4.5按作者名排序
void wname_paixu(struct book *head)
{
    struct book *a[1000], *p, *p1, *temp;
    int i, k, index, n = 0;
    char b;
    p1 = head;
    for (p = head; p; p = p->next)
        n++;
    for (i = 0; i < n; i++)
    {
        a[i] = p1;
        p1 = p1->next;
    }
    for (k = 0; k < n-1; k++)
    {
        index = k;
        for (i = k+1; i < n; i++)
        {
            if (strcmp(a[index]->wname, a[i]->wname) > 0)
                index = i;
        }
        temp = a[index];
        a[index] = a[k];
        a[k] = temp;
    }
    printf("\t\t\t\t排序成功!\n");
    printf("\t\t\t\t是否显示排序结果?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
	{
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t您的输入有误！请重新输入！\n");
            break;
    }
}      

 //1.5.修改图书信息
void xiugai(struct book *head)
{
    int a,b;
    char c;
    struct book *p;
    printf("\n\n\t\t\t                          请输入要修改的图书编号:");
    scanf("%d",&a);
    p = head;
    while (p != NULL)
    {
        if (p->num == a)
            break;
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\t\t\t\t    没有找到该编号的图书!\n");
        getchar();
    }
    else
    {
        printf("\n\t\t\t                           你要修改的图书信息如下\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t编号  图书名           作者名  出版社           类别     出版时间     价格\n");
        printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);
        printf("\t\t\t===========================================================================\n\n");

        printf("\t\t\t                       修改信息选项\n");
        printf("\t\t\t============================================================\n");
        printf("\t\t\t**  1-编号               2-图书名              3-作者名   **\n");
        printf("\t\t\t**  4-出版社             5-类别                6-出版时间 **\n");
        printf("\t\t\t**  7-价格               8-修改全部            0-放弃修改 **\n");
        printf("\t\t\t============================================================\n");
        printf("\t\t\t请选择你要修改的信息编号:");
        scanf("%d", &b);
        getchar();
        switch(b)
        {
            case 1:
                printf("\t\t\t请输入新编号:");
                scanf("%d",&p->num);
                printf("\t\t\t修改成功!\n");
                getchar();
                break;
            case 2:
                printf("\t\t\t请输入新图书名:");
                gets(p->bname);
                printf("\t\t\t修改成功!\n");
                break;
            case 3:
                printf("\t\t\t请输入新作者名:");
                gets(p->wname);
                printf("\t\t\t修改成功!\n");
                break;
            case 4:
                printf("\t\t\t请输入新出版社:");
                gets(p->press);
                printf("\t\t\t修改成功!\n");
                break;
            case 5:
                printf("\t\t\t请输入新类别:");
                gets(p->sort);
                printf("\t\t\t修改成功!\n");
                break;
            case 6:
                printf("\t\t\t请输入新出版时间:");
                scanf("%d%d%d",&p->time.year,&p->time.month,&p->time.day);
                printf("\t\t\t修改成功!\n");
                getchar();
                break;
            case 7:
                printf("\t\t\t请输入新价格:");
                scanf("%f",&p->price);
                printf("\t\t\t修改成功!\n");
                getchar();
                break;
            case 8:
                printf("\t\t\t请输入新图书编号:");
                scanf("%d",&p->num);
                printf("\t\t\t请输入新图书名:");
                scanf("%s",p->bname);
                getchar();
                printf("\t\t\t请输入新作者名:");
                scanf("%s",p->wname);
                getchar();
                printf("\t\t\t请输入新出版社:");
                scanf("%s",p->press);
                getchar();
                printf("\t\t\t请输入新类别:");
                scanf("%s",p->sort);
                getchar();
                printf("\t\t\t请输入新出版时间:");
                scanf("%d%d%d",&p->time.year, &p->time.month, &p->time.day);
                getchar();
                printf("\t\t\t请输入新价格:");
                scanf("%f",&p->price);
                getchar();
                printf("\t\t\t修改成功!\n");
                getchar();
                break;
            case 0:
                break;
            default :
                printf("\t\t\t您的输入有误!\n");
                break;
        }
        printf("\t\t\t是否将修改后的信息保存到文件中?(y/n)");
        scanf("%c",&c);
        getchar();
        switch(c)
        {
            case 'n':
                break;
            case 'y':
                fprint(head);
                printf("\t\t\t保存成功!\n");
                getchar();
                break;
        }
                      
    }
}

//1.6.删除图书信息
void deletebook(struct book *head)
{
    int a;
    char b,ch='1';
    struct book *p1,*p2;
    FILE *fp;
    printf("请输入要删除的图书编号:");
    scanf("%d",&a);
    p1=head;
    if(p1->num==a&&p1->next==NULL)
    {          //对于文件中只有一组数据
        printf("是否清空文件!(y/n)\n");
        getchar();
        scanf("%c",&b);
        getchar();
        switch(b)
        {
            case 'n':
                break;
            case 'y':
    
                if((fp=fopen("tushu.txt","w"))==NULL)
                {
                    printf("File open error!\n");
                    exit(0);
                }
                fclose(fp);
                printf("文件已清空!\n");
        }
    }
    else
    {
        while(p1->num!=a&&p1->next!=NULL)
        {
            p2=p1;
            p1=p1->next;
        }
     
        if(p1->next==NULL)
        {
            if(p1->num==a)
            {
                p2->next=NULL;
                printf("是否确定从文件中彻底删除该图书?(y/n)\n");
                getchar();
                scanf("%c",&b);
          
                switch(b)
                {
                    case 'n':
                    break;
                    case 'y':
                    fprint(head);
                    printf("删除成功!\n");
                    getchar();
                    break;
                }
            }
                 
            else
            {
               printf("没有找到要删除的数据!\n");
               getchar();
            }
        }
        else if(p1==head)
        {
            head=p1->next;
            printf("是否确定从文件中彻底删除该图书?(y/n)\n");
            getchar();
            scanf("%c",&b);
          
            switch(b)
            {
                case 'n':
                    break;
                case 'y':
                    fprint(head);
                    printf("删除成功!\n");
                    getchar();
                    break;
            }
                 
        }
        else
        {
            p2->next=p1->next;
            printf("是否确定从文件中彻底删除该图书?(y/n)\n");
            getchar();
            scanf("%c",&b);
         
            switch(b)
            {
                case 'n':
                    break;
                case 'y':
                    fprint(head);
                    printf("删除成功!\n");
                    getchar();
                    break;
            }
        }
    }    
}

//1.3.1.将文件信息全部输出
void print_book(struct book *head)
{
    struct book *ptr;
    if (head == NULL)
    {
        printf("\n\t\t没有信息!\n");
        return;
    }
    printf("\n\n\t\t                                 图书信息列表如下\n\n");
    printf("\t\t ==============================================================================\n");
    printf("\t\t 编号  图书名           作者名    出版社           类别     出版时间     价格\n");
    for (ptr = head; ptr; ptr = ptr->next)
        printf("\t\t %-6d%-17s%-10s%-17s%-9s%-d.%2d.%-5d%-.2f\n", ptr->num, ptr->bname, ptr->wname,
                ptr->press, ptr->sort, ptr->time.year, ptr->time.month, ptr->time.day, ptr->price);
    printf("\t\t ==============================================================================\n");
}

//从文件中读取图书信息
struct book *load()
{
    FILE *fp;
    char ch;
    struct book *head, *tail, *p1;
    head = tail = NULL;
    if ((fp = fopen("tushu.txt","r")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    ch = fgetc(fp);
    if (ch == '1')
    { 
        while (!feof(fp))
        {
            p1 = (struct book *)malloc(sizeof(struct book));
            fscanf(fp, "%d%s%s%s%s%d%d%d%f\n", &p1->num, p1->bname, p1->wname, p1->press, 
                   p1->sort, &p1->time.year, &p1->time.month, &p1->time.day, &p1->price);
            if (head == NULL)
                head = p1;
            else
                tail->next = p1;
            tail = p1;
        }
        tail->next = NULL;
        fclose(fp);
        return head;
    }
    else
        return NULL;
}

//将新链表写入文件中
void fprint(struct book *head)
{
    FILE *fp;
    char ch = '1';
    struct book *p1;
    if ((fp = fopen("tushu.txt","w")) == NULL)
    {
        printf("File open error!\n");
        exit(0);
    }
    fputc(ch, fp);
    for (p1 = head; p1; p1 = p1->next)
    {
        fprintf(fp, "%d %s %s %s %s %d %d %d %f\n", p1->num, p1->bname, p1->wname, p1->press, 
                p1->sort, p1->time.year, p1->time.month, p1->time.day, p1->price);
    }
    fclose(fp);
}

//验证添加的图书编号是否已存在
int yanzheng(struct book *head,int m)
{
    struct book *p;
    p = head;
    while (p != NULL)
    {
        if (p->num == m)
            break;
        p = p->next;
    }
    if (p == NULL)
        return 0;
    else
        return 1;
}



