#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct book
{
    int  num;                 //���              
    char bname[50];          //����
    char wname[20];          //����
    char press[50];          //������
    char sort[50];           //���
    struct date              //����ʱ��
    {
        int year;
        int month;
        int day;
    }time;                
    float price;             //�۸�
    struct book *next;
};
struct student
{
    char num[15]; //ѧ��ѧ��
    char name[20];//ѧ������
    int numbook;  //ͼ����
    struct student *next;
};
struct admin 
{
    char  account[15];  //�˺�
    char  password[15]; //����
    struct admin *next;
};

int mainmenu();                                     //���˵�����
int pwYanzheng();                                   //������֤
int adminmenu();                                    //1.����Ա������
int user();                                         //2.�û�����
void tushu_tianjia();                               //1.1.���ͼ����Ϣ
void tushu_luru();                                  //1.2.¼��ͼ����Ϣ
void tushu_chaxun1();                               //1.3.��ѯͼ����Ϣ
void tushu_paixu();                                 //1.4./2.2.ͼ����Ϣ����
void tushu_xiugai();                                //1.5.�޸�ͼ����Ϣ
void tushu_shanchu();                               //1.6.ɾ��ͼ����Ϣ
void admin_xiugai();                                //1.7.�˺ű༭
void tushu_chaxun2();                               //2.1.��ѯͼ����Ϣ
void tushu_jieyue();                                //2.3.ͼ�����
void tushu_guihuan();                               //2.4.ͼ��黹
struct book *addbook(struct book *head);            //1.1.���ͼ��
struct book *creatbook();                           //1.2.¼������
void chaxun1(struct book *head);                    //1.3.��ѯͼ����Ϣ
void chaxun2(struct book *head);                    //2.1.��ѯͼ����Ϣ
void tushu_liebiao();                               //1.3.1ͼ���б�
void print_jie();                                   //1.3.2������н����˵���Ϣ
void num_chaxun(struct book *head);                 //1.3.3��ͼ���Ų�ѯͼ��
void wname_chaxun(struct book *head);               //1.3.4����������ѯͼ��
void sort_chaxun(struct book *head);                //1.3.5������ѯͼ��
void time_chaxun(struct book *head);                //1.3.6������ʱ���ѯͼ��
void bname_chaxun(struct book *head);               //1.3.7��ͼ������ѯͼ��
void price_chaxun(struct book *head);               //1.3.8��ͼ��۸��ѯͼ����Ϣ 
void paixu(struct book *head);                      //1.4.��ͼ���������
void num_paixu(struct book *head);                  //1.4.1��ͼ��������
void time_paixu(struct book *head);                 //1.4.2��ͼ�����ʱ������
void price_paixu(struct book *head);                //1.4.3��ͼ��۸�����
void bname_paixu(struct book *head);                //1.4.4��ͼ��������
void wname_paixu(struct book *head);                //1.4.5������������
void xiugai(struct book *head);                     //1.5.�޸�ͼ����Ϣ
void deletebook(struct book *head);                 //1.6.ɾ��ͼ��
void print_book(struct book *head);                 //1.3.1.���ļ���Ϣȫ�����
struct book *load();                                //���ļ��ж�ȡ��Ϣ����������
void fprint(struct book *head);                     //������д���ļ�
int  yanzheng(struct book *head, int m);            //��֤����ӵ�ͼ������Ƿ��Ѵ���

int main()
{
    int choice, n, x, y=1;
    struct book *head = NULL;
    while (y)
    {
        system("cls");
        n = mainmenu();   //���˵�����
        switch(n)
        {
            case 3: y = 0; break;   //�˳�ϵͳ
            case 1:               //�������Աģʽ
                x = pwYanzheng(); //������֤
                while(x)
                {
                    system("cls");
                    choice = adminmenu(); //����Ա������
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
                            printf("\n\t\t\t\t������������,����������!\n");
                            getchar();
                            break;     
                    }     
                }
                break;
            case 2: 
                x = 1;                                //�����û�ģʽ
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
                            printf("\n\t\t\t\t������������,����������!\n");
                            getchar();
                            break;    
                    }
                }
                break;

            default:                                //��������
                printf("\t\t������������!  ����������!\n");
                getchar();
                break;
        }
    }
    printf("\t\t\t\t\t ллʹ��ͼ����Ϣ����ϵͳ��\n\n\n");
    system("pause");
}    


//���˵���
int mainmenu()
{
    int x;
    printf("\n\n\n\n\n\n\n");
    printf("\t\t----------------------------------------------------------------------------\n");
    printf("\t\t                        ********** ��ӭ���� *********                        \n");
    printf("\t\t                                                                            \n");   
    printf("\t\t        ********************** ͼ����Ϣ����ϵͳ ************************     \n");
    printf("\t\t                                                                            \n");  
    printf("\t\t                                                                            \n");  
    printf("\t\t                                                                           \n");  
    printf("\t\t                    ============1-����Աģʽ============                    \n");
    printf("\t\t                                                                           \n"); 
    printf("\t\t                    ============2-�ͻ�ģʽ==============                    \n");
    printf("\t\t                                                                           \n"); 
    printf("\t\t                    ============3-�˳�ϵͳ==============                    \n");
    printf("\t\t                                                                           \n");  
    printf("\t\t                                                                           \n");  
    printf("\t\t---------------------------------------------------------------------------\n\n");
    printf("\t\t����������ѡ��:");
    scanf("%d", &x);
    printf("\n");
    getchar();
    return x;    
}

//������֤
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
    if (fgetc(fp) == EOF)     //û�й���Ա��Ϣ����Ҫ��֤  
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
    printf("\t\t�����������û���:");
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
        printf("\t\t���˺Ų�����!\n");
        getchar();
        return 0;
    }
    if(y)
    {
        printf("\n\t\t��������������:");
        gets(password);
        printf("\n");
        if(strcmp(p1->password, password) != 0)
        {
            printf("\t\t��֤ʧ��,����������!\n");
            getchar();
            system("cls");
            return 0;
        }
        else
        {
            printf("\t\t��֤ͨ��!�밴Enter������!\n");
            getchar();
            system("cls");
            return 1;
        }
    }
}

//1.����Ա������
int adminmenu()
{
    int a;
    printf("\t\t\t\t                          -------------------\n");
    printf("\t\t\t\t                           *ͼ����Ϣ����ϵͳ*\n");
    printf("\t\t\t\t                          -------------------\n\n");
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t|| 1-���ͼ����Ϣ                                    2-¼��ͼ����Ϣ ||\n\n");
    printf("\t\t\t\t|| 3-�鿴ͼ����Ϣ                                    4-ͼ����Ϣ���� ||\n\n");
    printf("\t\t\t\t|| 5-�޸�ͼ����Ϣ                                    6-ɾ��ͼ����Ϣ ||\n\n");
    printf("\t\t\t\t|| 7-�����˺ű༭                                    0-�˳�����ϵͳ || \n\n");        
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t**********************************************************************\n\n");
    printf("\t\t\t\t��������ѡ������:");
    scanf("%d", &a);
    getchar();  
    return a;                  
}

//2.�û�������
int user()
{
    int a;
    printf("\t\t\t\t                      -------------------\n");
    printf("\t\t\t\t                       *ͼ����Ϣ����ϵͳ*\n");
    printf("\t\t\t\t                      -------------------\n\n");
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t|| 1-��ѯͼ��                                       2-ͼ������ ||\n\n");
    printf("\t\t\t\t|| 3-ͼ�����                                       4-ͼ��黹 ||\n\n");
    printf("\t\t\t\t|| 0-�˳�ϵͳ                                                   \n\n");         
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t*****************************************************************\n\n");
    printf("\t\t\t\t#��������ѡ������:");
    scanf("%d", &a);
    getchar();  
    return a;                  
}

//1.1.���ͼ����Ϣ
void tushu_tianjia()
{
    struct book *head = NULL;
    char a;
    head = load();
    if (head == NULL)
    {
        printf("\n\t\t\t\t\t�ļ�Ϊ��,����¼������!\n");
        getchar();
    }
    else
    {
        head = addbook(head);
        printf("��ӳɹ�!\n");
        printf("�Ƿ�����Ϣ���浽�ļ�?(y/n)\n");
        scanf("%c", &a);
        getchar();
        switch(a)
        {
            case 'n':
                break;
            case 'y':
                fprint(head);
                printf("����ɹ�!\n");
                getchar();
                system("cls");
                break;
        }
    }                            
}

//1.2.¼������
void tushu_luru()
{
    struct book *head = NULL;
    char a;
    printf("ע��:����ͼ�����Ϊ0ʱ����!\n");
    head = creatbook();
    printf("�Ƿ��������Ϣ���浽�ļ��Ը����ļ����Ѵ��ڵ���Ϣ?(y/n)\n");
    getchar();
    scanf("%c", &a);
    getchar();
    switch(a)
    {
        case 'n':
            break;
        case 'y':
            fprint(head);
            printf("����ɹ�!\n");
            getchar();
            break;
    }
}

//1.3.��ѯͼ��
void tushu_chaxun1()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("�ļ�Ϊ��,����¼������!\n");
        getchar();
    }
    else
    {
        chaxun1(head);
        getchar();
    }
}      

//1.4.ͼ������
void tushu_paixu()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("�ļ�Ϊ��,����¼������!\n");
        getchar();
    }
    else
    {
        paixu(head);
        getchar();
    }
}

//1.5.�޸�ͼ����Ϣ
void tushu_xiugai()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("�ļ�Ϊ��,����¼������!\n");
        getchar();
    }
    else
    {
        xiugai(head);
        getchar();
    }
}      

//1.6.ɾ��ͼ����Ϣ
void tushu_shanchu()
{
    struct book *head = NULL;
    head = load();
    if(head == NULL)
    {
        printf("�ļ�Ϊ��,����¼������!\n");
        getchar();
    }
    else
    {
        deletebook(head);
        getchar();
    }
}   

//1.7.�˺ű༭
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
        printf("\t\t\t\t                    *����Ա��Ϣ�༭*\n");
        printf("\t\t\t\t                   -----------------\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t** 1-ע���˺�                           2-ɾ���˺� **\n\n");
        printf("\t\t\t\t** 3-�޸�����                           0-ȡ���༭ **\n");
        printf("\t\t\t\t=======================================================\n");
        printf("\t\t\t\t��������ѡ������:");
        scanf("%c", &a);
        getchar();
        switch(a)
        {
            case '0':
                    x = 0; 
                    break;
            ///////////////////////ע�����û�/////////////////////////
            case '1':
                y = 1;
                printf("\t\t\t\t�������������˺�:");
                gets(account);
                while (p1 != NULL)
                {
                    if (strcmp(p1->account,account) == 0)
                    {
                        y = 0;
                        printf("\t\t\t\t���˺��Ѵ��ڣ�");
                        getchar();
                        break;
                    }
                    p1 = p1->next;
                }
                if (y)
                {
                    printf("\t\t\t\t����������:");
                    gets(password1);
                    printf("\t\t\t\t���ٴ���������:");
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
                        printf("\n\t\t\t\t�˺�ע��ɹ���");
                        getchar();
                    }
                    else
                    {
                        printf("\t\t\t\t������������벻һ��!");
                        getchar();
                    }
                }
                break;
            ///////////////////////ɾ���˺�//?????you wen titittiitittiti???????????????????????????????????????????????????????????????????/////////////////////////
            case '2':
                y = 0;
                fp = fopen("admin.txt", "r");
                if (fgetc(fp)==EOF)   
                {
                    rewind(fp);
                    fclose(fp);
                    printf("\n\t\t\t\t��ϵͳ�������˺�!\n\n");
                    getchar();
                }   
                else
                {
                    rewind(fp);
                    fclose(fp);
                    printf("\t\t\t\t�����������˺�:");
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
                    //////////ɾ���黹����Ϣ///////////////
                    if (y)
                    {  
                        p1 = head;
                        p2 = p1->next;
                        //�����ڱ�ͷ
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
                        /////////���µ���Ϣд���ļ�////////////
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
                        printf("\n\t\t\t\t�˺�ɾ���ɹ���\n\n");
                        getchar();
                    }
                    else
                    {
                        printf("\n\t\t\t\t�����ڸ��˺�!\n\n");
                        getchar();
                    }
                }
                break;       
            ///////////////////////�޸�����//////////////////////////
            case '3':
                y = 0;
                p1 = head;
                printf("\t\t\t\t�����������˺�:");
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
                    printf("\t\t\t\t���˺Ų�����!\n");
                    getchar();
                }
                if (y)
                {
                    printf("\t\t\t\t������ԭʼ����:");
                    gets(password3);
                    if (strcmp(p1->password,password3) == 0)
                    {
                        printf("\t\t\t\t������������:");
                        gets(password1);
                        printf("\t\t\t\t���ٴ�����������:");
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
                            printf("\t\t\t\t���ѳɹ��޸������룡");
                        }
                        else
                        {
                            printf("\t\t\t\t��������������벻һ�£�");
                            getchar(); 
                        }
                    }
                    else
                    {
                        printf("\t\t\t\t���������������");
                        getchar();
                    }
                }
                 break;
            default:                              
                printf("\t\t\t\t������������!  ����������!\n");
                getchar();
                break; 
        
        }
    }
}

//2.1.��ѯͼ��
void tushu_chaxun2()
{
    struct book *head = NULL;
    head = load();
    if (head == NULL)
    {
        printf("�ļ�Ϊ��,����¼������!\n");
        getchar();
    }
    else
    {
        chaxun2(head);
        getchar();
    }
}   

//2.3.ͼ�����
void tushu_jieyue()
{
    FILE *fp;
    int x = 1, numbook;
    char b;
    char num[15], name[20];
    struct student *p1, *head=NULL, *tail;
    struct book *p = NULL;
    printf("\n\t\t\t\t\t\t ��������Ҫ���ĵ�ͼ����:");
    scanf("%d", &numbook);
    getchar();
    ////////////////�ж�ͼ���Ƿ񱻽���///////////////////////
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
            printf("\n\n\t\t\t\t\t\t  Sorry����ͼ���ѱ����ߣ�");
            getchar();
            break;
        }
        p1 = p1->next;
    }
 
    //////////////////�鿴�Ƿ��д�ͼ�飬������/////////////////////////
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
            printf("\n\n\t\t\t\t\t\t  û���ҵ��ñ�ŵ�ͼ��!\n");
            getchar();
        }
        else
        {
            printf("\n\t\t\t\t\t\t   �������ĵ�ͼ����Ϣ����\n");
            printf("\t\t\t===========================================================================\n");
            printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
            printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                        p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);
            printf("\t\t\t===========================================================================\n");
            printf("\t\t\t���������ѧ�ţ�");
            gets(num);
            printf("\t\t\t������������֣�");
            gets(name);
            printf("\n\t\t\t�Ƿ���ĸ���?(y/n)");
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
                    printf("\n\t\t\tͼ����ĳɹ���");
                    getchar();
            }
        }
    }
    
}

//2.4.ͼ��黹
void tushu_guihuan()
{
    FILE *fp;
    int a;
    char num[20];
    struct student *head, *tail, *p1, *p2;
    head = tail = NULL;
    printf("\n\n\t\t\t\t\t\t��������Ҫ�黹��ͼ����:");
    scanf("%d", &a);
    getchar();
    ///////////���ļ���ȡ����/////////////
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
        printf("\n\n\t\t\t\t\t\t  û�н���ñ�ŵ�ͼ��!\n\n");
        getchar();
    }
    else
    {
        printf("\n\t\t\t\t\t\t���������ѧ��:");
        gets(num);
        if (strcmp(p1->num, num) == 0)
        {
            //////////ɾ���黹����Ϣ///////////////
            p1 = head;
            p2 = p1->next;
            if(p1->numbook == a)  //�����ڱ�ͷ
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
            /////////���µ���Ϣд���ļ�////////////
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
            printf("\n\t\t\t\t\t\tͼ��黹�ɹ���ллʹ�ã�\n\n");
            getchar();
        }
        else
        {
            printf("\n\t\t\t\t\t\t�������ѧ������");
            getchar();
        }
    }
}     

//1.1.���ͼ�� �����㣬���Ҳ�����԰�һ��˳��
struct book *addbook(struct book *head)
{
 
    struct book *ptr, *p1, *p2, *p;
    char bname[50], wname[20], press[50], sort[50];
    int size = sizeof(struct book);
    int num, year, month, day, n=1;
    float price;
    do
    {
        printf("������ͼ����:");
        scanf("%d", &num);
        n = yanzheng(head, num);
        if (n == 0)
            break;
        else
            printf("������ı���Ѵ���,����������!\n");
    }while(1);
    printf("������ͼ����:");
    scanf("%s", bname);
    getchar();
    printf("������������:");
    scanf("%s", wname);
    getchar();
    printf("�����������:");
    scanf("%s", press);
    getchar();
    printf("���������:");
    scanf("%s", sort);
    getchar();
    printf("���������ʱ��:");
    scanf("%d%d%d", &year, &month, &day);
    getchar();
    printf("������۸�:");
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

//1.2.¼������ ���γ�����
struct book *creatbook()
{
    struct book *head, *tail, *p;
    int num, year, month, day, n;
    char bname[50], wname[20], press[50], sort[50];
    float price;
    int size = sizeof(struct book);
    head = tail = NULL;
    printf("������ͼ����:");
    scanf("%d", &num);
    printf("������ͼ����:");
    scanf("%s", bname);
    getchar();
    printf("������������:");
    scanf("%s", wname);
    getchar();
    printf("�����������:");
    scanf("%s", press);
    getchar();
    printf("���������:");
    scanf("%s", sort);
    getchar();
    printf("���������ʱ��:");
    scanf("%d%d%d", &year, &month, &day);
    getchar();
    printf("������۸�:");
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
            printf("������ͼ����:");
            scanf("%d", &num);
            n = yanzheng(head, num);
            if (n == 0)
                break;
            else
                printf("������ı���Ѵ���,����������!\n");
        }while(1);
        if (num == 0)
            break;
        else
        {
            printf("������ͼ����:");
            scanf("%s", bname);
            getchar();
            printf("������������:");
            scanf("%s", wname);
            getchar();
            printf("�����������:");
            scanf("%s", press);
            getchar();
            printf("���������:");
            scanf("%s", sort);
            getchar();
            printf("���������ʱ��:");
            scanf("%d%d%d", &year, &month, &day);
            getchar();
            printf("������۸�:");
            scanf("%f", &price);
            getchar();
        }
    }
    return head;
}

//1.3.ͼ���ѯ
void chaxun1(struct book *p1)
{
    int a, x = 1;
    while(x)
    {
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t                         *ͼ���ѯ*\n");
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t============================================================\n\n");
        printf("\t\t\t\t** 1-����ͼ����Ϣ                          2-ͼ�������Ϣ **\n\n");
        printf("\t\t\t\t** 3-��ͼ���Ų�ѯ                        4-��ͼ������ѯ **\n\n");
        printf("\t\t\t\t** 5-��ͼ������ѯ                        6-����������ѯ **\n\n");
        printf("\t\t\t\t** 7-������ʱ���ѯ                        8-���۸��ѯ   **\n\n");
        printf("\t\t\t\t** 0-�˳���ѯ                                              \n\n");
        printf("\t\t\t\t============================================================\n");
        printf("\t\t\t\t��������ѡ������:");
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
                printf("\t\t\t\t���������������������룡\n");
                getchar();
                system("cls");
                break;
        }
    }
}

//2.1ͼ���ѯ
void chaxun2(struct book *p1)
{
    int a, x = 1;
    while(x)
    {
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t                         *ͼ���ѯ*\n");
        printf("\t\t\t\t                        ------------\n");
        printf("\t\t\t\t===============================================================\n\n");
        printf("\t\t\t\t** 1-����ͼ����Ϣ                          2-��ͼ���Ų�ѯ **\n\n");
        printf("\t\t\t\t** 3-��ͼ������ѯ                          4-��ͼ������ѯ **\n\n");
        printf("\t\t\t\t** 5-����������ѯ                          6-������ʱ���ѯ **\n\n");
        printf("\t\t\t\t** 7-���۸��ѯ                            0-�˳���ѯϵͳ   **\n\n");
        printf("\t\t\t\t==============================================================\n");
        printf("\t\t\t\t��������ѡ������:");
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
                printf("\t\t\t\t���������������������룡\n");
                getchar();
                system("cls");
                break;
        }
    }
}

//1.3.1ͼ���б�
void tushu_liebiao()
{
    struct book *head = NULL;
    head = load();
    if(head == NULL)
    {
        printf("�ļ�Ϊ��,����¼������!\n");
        getchar();
    }
    else
    {
        print_book(head);
        getchar();
    }
}  

//1.3.2������н����˵���Ϣ
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
        printf("\n\n\t\t\t\t\t\tû���˽�����ͼ��!\n\n");
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
        printf("\n\n\t\t\t\t                ��������Ϣ\n");
        printf("\t\t\t\t===========================================\n");
        printf("\t\t\t\t    ѧ��           ����           ͼ����\n");
        for (p1 = head; p1; p1 = p1->next)
            printf("\t\t\t\t %-17s%-19s%-5d\n",p1->num, p1->name, p1->numbook);
        printf("\t\t\t\t===========================================\n");   
        getchar();
    }  
}

//1.3.3����Ų�ѯͼ����Ϣ
void num_chaxun(struct book *head)
{
    int a;
    struct book *p;
    printf("\t\t\t\t��������Ҫ��ѯ��ͼ����:");
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
        printf("\t\t\t\tû���ҵ��ñ�ŵ�ͼ��!\n");
    else
    {
        printf("\n\t\t\t                           ������ѯ��ͼ����Ϣ����\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
        printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);
        printf("\t\t\t===========================================================================\n");
    }
}

//1.3.4��ͼ������ѯͼ����Ϣ
void bname_chaxun(struct book *head)
{
    char a[50];
    int flag = 0;
    struct book *p;
    printf("\t\t\t\t��������Ҫ��ѯ��ͼ����:");
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
        printf("\t\t\t\tû���ҵ���ͼ������ͼ��!\n");
    else
    {
        printf("\n\t\t\t                           ������ѯ��ͼ����Ϣ����\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
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

//1.3.5��ͼ������ѯͼ����Ϣ
void sort_chaxun(struct book *head)
{
    char a[50];
    int flag = 0;
    struct book *p;
    printf("\t\t\t\t��������Ҫ��ѯͼ������:");
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
        printf("\t\t\t\tû���ҵ�������ͼ��!\n");
    else
    {
        printf("\n\t\t\t                           ������ѯ��ͼ����Ϣ����\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
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

//1.3.6����������ѯͼ����Ϣ
void wname_chaxun(struct book *head)
{
    char a[50];
    int flag = 0;
    struct book *p;
    printf("\t\t\t\t��ѡ����Ҫ��ѯͼ���������:");
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
        printf("\t\t\t\tû���ҵ������ߵ�ͼ��!\n");      
    else
    {
        printf("\n\t\t\t                           ������ѯ��ͼ����Ϣ����\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
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

//1.3.7��ͼ�����ʱ���ѯͼ����Ϣ
void time_chaxun(struct book *head)
{
    int a, flag = 0;
    struct book *p;
    printf("\t\t\t\t��ѡ����Ҫ��ѯͼ��ĳ���ʱ��:");
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
        printf("\t\t\t\tû���ҵ��ó���ʱ���ͼ��!\n");
    else
    {
        printf("\n\t\t\t                           ������ѯ��ͼ����Ϣ����\n");
        printf("\t\t\t============================================================================\n");
        printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
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

//1.3.8��ͼ��۸��ѯͼ����Ϣ
void price_chaxun(struct book *head)
{
    int a, b, flag = 0;
    struct book *p;
    printf("\t\t\t\t������ͼ��ļ۸�����:");
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
        printf("\t\t\t\tû���ҵ��ü�λ��ͼ��!\n");
    else
    {
        printf("\n\t\t\t\t                           ������ѯ��ͼ����Ϣ����\n");
        printf("\t\t\t============================================================================\n");
        printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
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

//1.4.ͼ������������
void paixu(struct book *head)
{
    int a, x = 1;
    while(x)
    {
        printf("\t\t\t\t                     --------------------\n");
        printf("\t\t\t\t                      *ͼ����Ϣ����ϵͳ*\n");
        printf("\t\t\t\t                     --------------------\n");
        printf("\t\t\t\t================================================================\n");
        printf("\t\t\t\t**  1-��ͼ��������                        2-������ʱ������  **\n\n");
        printf("\t\t\t\t**  3-��ͼ��۸�����                        4-��ͼ��������    **\n\n");
        printf("\t\t\t\t**  5-������������                          0-ȡ���������    **\n\n");
        printf("\t\t\t\t================================================================\n");
        printf("\t\t\t\t��������ѡ������:");
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
                printf("\t\t\t\t���������������������룡\n");
                getchar();
                system("cls");
                break;
        }
    }
}

//1.4.1��ͼ��������
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

    for (k = 0; k < n-1; k++)     //ѡ������
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
    printf("\t\t\t\t����ɹ�!\n");
    printf("\t\t\t\t�Ƿ���ʾ������?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t���������������������룡\n");
            break;
    }
}

//1.4.2������ʱ������        
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
    printf("\t\t\t\t����ɹ�!\n");
    printf("\t\t\t\t�Ƿ���ʾ������?(y/n)");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t���������������������룡\n");
            break;
    }
}

//1.4.3��ͼ��۸�����
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
    printf("\t\t\t\t����ɹ�!\n");
    printf("\t\t\t\t�Ƿ���ʾ������?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t���������������������룡\n");
            break;
    }
}     

//1.4.4��ͼ��������
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
    printf("\t\t\t\t����ɹ�!\n");
    printf("\t\t\t\t�Ƿ���ʾ������?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
    {
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t���������������������룡\n");
            break;
    }
}    

//1.4.5������������
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
    printf("\t\t\t\t����ɹ�!\n");
    printf("\t\t\t\t�Ƿ���ʾ������?(y/n) ");
    scanf("%c", &b);
    getchar();
    switch(b)
	{
        case 'n':
            break;
        case 'y':
            printf("\n\n\t\t\t==============================================================================\n");
            printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
            for (i = 0; i < n; i++)
                printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%-2d.%-5d%.2f \n", a[i]->num, a[i]->bname, a[i]->wname,
                        a[i]->press, a[i]->sort, a[i]->time.year, a[i]->time.month, a[i]->time.day, a[i]->price);
            printf("\t\t\t==============================================================================\n");
            break;
        default:
            printf("\n\t\t\t\t���������������������룡\n");
            break;
    }
}      

 //1.5.�޸�ͼ����Ϣ
void xiugai(struct book *head)
{
    int a,b;
    char c;
    struct book *p;
    printf("\n\n\t\t\t                          ������Ҫ�޸ĵ�ͼ����:");
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
        printf("\t\t\t\t    û���ҵ��ñ�ŵ�ͼ��!\n");
        getchar();
    }
    else
    {
        printf("\n\t\t\t                           ��Ҫ�޸ĵ�ͼ����Ϣ����\n");
        printf("\t\t\t===========================================================================\n");
        printf("\t\t\t���  ͼ����           ������  ������           ���     ����ʱ��     �۸�\n");
        printf("\t\t\t%-6d%-17s%-8s%-17s%-9s%-d.%2d.%-5d%-.2f\n", p->num, p->bname, p->wname,
                p->press, p->sort, p->time.year, p->time.month, p->time.day, p->price);
        printf("\t\t\t===========================================================================\n\n");

        printf("\t\t\t                       �޸���Ϣѡ��\n");
        printf("\t\t\t============================================================\n");
        printf("\t\t\t**  1-���               2-ͼ����              3-������   **\n");
        printf("\t\t\t**  4-������             5-���                6-����ʱ�� **\n");
        printf("\t\t\t**  7-�۸�               8-�޸�ȫ��            0-�����޸� **\n");
        printf("\t\t\t============================================================\n");
        printf("\t\t\t��ѡ����Ҫ�޸ĵ���Ϣ���:");
        scanf("%d", &b);
        getchar();
        switch(b)
        {
            case 1:
                printf("\t\t\t�������±��:");
                scanf("%d",&p->num);
                printf("\t\t\t�޸ĳɹ�!\n");
                getchar();
                break;
            case 2:
                printf("\t\t\t��������ͼ����:");
                gets(p->bname);
                printf("\t\t\t�޸ĳɹ�!\n");
                break;
            case 3:
                printf("\t\t\t��������������:");
                gets(p->wname);
                printf("\t\t\t�޸ĳɹ�!\n");
                break;
            case 4:
                printf("\t\t\t�������³�����:");
                gets(p->press);
                printf("\t\t\t�޸ĳɹ�!\n");
                break;
            case 5:
                printf("\t\t\t�����������:");
                gets(p->sort);
                printf("\t\t\t�޸ĳɹ�!\n");
                break;
            case 6:
                printf("\t\t\t�������³���ʱ��:");
                scanf("%d%d%d",&p->time.year,&p->time.month,&p->time.day);
                printf("\t\t\t�޸ĳɹ�!\n");
                getchar();
                break;
            case 7:
                printf("\t\t\t�������¼۸�:");
                scanf("%f",&p->price);
                printf("\t\t\t�޸ĳɹ�!\n");
                getchar();
                break;
            case 8:
                printf("\t\t\t��������ͼ����:");
                scanf("%d",&p->num);
                printf("\t\t\t��������ͼ����:");
                scanf("%s",p->bname);
                getchar();
                printf("\t\t\t��������������:");
                scanf("%s",p->wname);
                getchar();
                printf("\t\t\t�������³�����:");
                scanf("%s",p->press);
                getchar();
                printf("\t\t\t�����������:");
                scanf("%s",p->sort);
                getchar();
                printf("\t\t\t�������³���ʱ��:");
                scanf("%d%d%d",&p->time.year, &p->time.month, &p->time.day);
                getchar();
                printf("\t\t\t�������¼۸�:");
                scanf("%f",&p->price);
                getchar();
                printf("\t\t\t�޸ĳɹ�!\n");
                getchar();
                break;
            case 0:
                break;
            default :
                printf("\t\t\t������������!\n");
                break;
        }
        printf("\t\t\t�Ƿ��޸ĺ����Ϣ���浽�ļ���?(y/n)");
        scanf("%c",&c);
        getchar();
        switch(c)
        {
            case 'n':
                break;
            case 'y':
                fprint(head);
                printf("\t\t\t����ɹ�!\n");
                getchar();
                break;
        }
                      
    }
}

//1.6.ɾ��ͼ����Ϣ
void deletebook(struct book *head)
{
    int a;
    char b,ch='1';
    struct book *p1,*p2;
    FILE *fp;
    printf("������Ҫɾ����ͼ����:");
    scanf("%d",&a);
    p1=head;
    if(p1->num==a&&p1->next==NULL)
    {          //�����ļ���ֻ��һ������
        printf("�Ƿ�����ļ�!(y/n)\n");
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
                printf("�ļ������!\n");
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
                printf("�Ƿ�ȷ�����ļ��г���ɾ����ͼ��?(y/n)\n");
                getchar();
                scanf("%c",&b);
          
                switch(b)
                {
                    case 'n':
                    break;
                    case 'y':
                    fprint(head);
                    printf("ɾ���ɹ�!\n");
                    getchar();
                    break;
                }
            }
                 
            else
            {
               printf("û���ҵ�Ҫɾ��������!\n");
               getchar();
            }
        }
        else if(p1==head)
        {
            head=p1->next;
            printf("�Ƿ�ȷ�����ļ��г���ɾ����ͼ��?(y/n)\n");
            getchar();
            scanf("%c",&b);
          
            switch(b)
            {
                case 'n':
                    break;
                case 'y':
                    fprint(head);
                    printf("ɾ���ɹ�!\n");
                    getchar();
                    break;
            }
                 
        }
        else
        {
            p2->next=p1->next;
            printf("�Ƿ�ȷ�����ļ��г���ɾ����ͼ��?(y/n)\n");
            getchar();
            scanf("%c",&b);
         
            switch(b)
            {
                case 'n':
                    break;
                case 'y':
                    fprint(head);
                    printf("ɾ���ɹ�!\n");
                    getchar();
                    break;
            }
        }
    }    
}

//1.3.1.���ļ���Ϣȫ�����
void print_book(struct book *head)
{
    struct book *ptr;
    if (head == NULL)
    {
        printf("\n\t\tû����Ϣ!\n");
        return;
    }
    printf("\n\n\t\t                                 ͼ����Ϣ�б�����\n\n");
    printf("\t\t ==============================================================================\n");
    printf("\t\t ���  ͼ����           ������    ������           ���     ����ʱ��     �۸�\n");
    for (ptr = head; ptr; ptr = ptr->next)
        printf("\t\t %-6d%-17s%-10s%-17s%-9s%-d.%2d.%-5d%-.2f\n", ptr->num, ptr->bname, ptr->wname,
                ptr->press, ptr->sort, ptr->time.year, ptr->time.month, ptr->time.day, ptr->price);
    printf("\t\t ==============================================================================\n");
}

//���ļ��ж�ȡͼ����Ϣ
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

//��������д���ļ���
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

//��֤��ӵ�ͼ�����Ƿ��Ѵ���
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



