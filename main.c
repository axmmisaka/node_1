/****************************************************************************************/
/************Node by AXM_MISAKA20001     Not support on Unix or Older Windows************/
/****Which means Need c99 support(Many features)  and Windows OS(Windows.h&Winbase.h)****/
/****************************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "conio.h"
#include "stdbool.h"
#include "string.h"
#include "Windows.h"
#include "Winbase.h"
#include "time.h"
#define DEBUG
#define VERSION1_5
#define SUCCESS 0
#define FAILED1 1
#define FAILED2 2
//Down here,is two Enabler.Just delete "//" to use.Not fully support.
//#define UD
//#define ROLL
#if defined ROLL
typedef struct node
{
    bool head;
    int number;
    char name[60];
    struct node * next;
}LLIST;
#elif defined UD
typedef struct node
{
    int number;
    char name[60];
    struct node * next;
    struct node * prev;
}LLIST;
#else
typedef struct node
{
    int number;
    char name[60];
    struct node * next;
}LLIST;
#endif // define

LLIST * make(void);
LLIST * insert(LLIST *head,LLIST *newstr,int position,int * returnv);//For inserting node
LLIST * delnode(LLIST *head,int position,int * returnv);//For deleting node
int Flocation(LLIST * head,char select);//For find a location of a node
int freenode(LLIST * head);//For free the node
int print(LLIST * head);//Print all nodes
int question(void);//Optional,for otaku and communists.
int sortnode(LLIST * head,const int len);//Sort the node by name or number.
#ifdef VERSION1_5
int main(void)
{
    int pos;
    int returnvalve;
    char choice;
    LLIST * original_node,* modify_node;
    SetConsoleTitle("Ass��We��Can!");// Change current window title
    Sleep(40);// Ensure window title has been updated.
    printf("Reloading AK47,please wait......\n");
    printf("Node by AXM_MISAKA20001.\n");
    printf("VER:Alpha 1.5 Debug.\nThis program servers only ONE node.");
    #ifndef DEBUG
    question();
    #endif // DEBUG
    original_node=make();
    modify_node = (LLIST*)malloc(sizeof(LLIST));
    while (1)
    {
        #ifdef DEBUG
        printf("Please insert:\n\
            N:Free the original node and make a new node\n\
            I:Insert a node\n\
            D:Delete a node in the original node\n\
            S:Search a node by its name or number\n\
            P:Print the original node.\n\
            O:Sort the node by name or number\n\
            H:Help\n\
            Q:Test Question\n\
                or insert E to quit the program.\n");
        #else
        printf("Please insert:\n\
            N:Free the original node and make a new node\n\
            I:Insert a node\n\
            D:Delete a node in the original node\n\
            S:Search a node by its name or number\n\
            P:Print the original node.\n\
            O:Sort the node by name or number\n\
            H:Help\n\
                or insert E to quit the program.\n");
        #endif
        printf("Input your choice:");
        choice=getch();
        fflush(stdin);
        printf("\n");
        switch (choice)
        {
        case 'N':
        case 'n':
                    {
                    printf("Are you sure want to free the node?This action cannot cancel.(Y to continue)\n");
                    choice = getch();
                    if(choice == 'Y'||choice == 'y')
                    {
                    pos=freenode(original_node);
                    (pos==0)?printf("Node freed successfully\n"):printf("Node freed failed.\n");
                    original_node=make();
                    }
                    break;
                    }
        case 'I':
        case 'i':
                    {
                    printf("Input number name position,input -1 to end mission\n");
                    scanf("%d",&(modify_node->number));
                    if (modify_node->number == -1) break;

                    scanf("%59s",modify_node->name);
                    fflush(stdin);
                    scanf("%d",&pos);
                    fflush(stdin);
                    original_node = insert(original_node,modify_node,pos,&returnvalve);
                    switch(returnvalve)
                    {
                        case FAILED2:{printf("Node is NULL but I help you made it.It's just what you inserted.\n");break;}
                        case FAILED1:{printf("No match(es) found.\n");break;}
                        case SUCCESS:{printf("Node inserted successfully.\n");break;}
                    }
                    break;
                    }
        case 'D':
        case 'd':
                    {
                        printf("Input position.input -1 to end mission\n");
                        scanf("%d",&pos);
                        if (pos == -1) break;
                        original_node = delnode(original_node,pos,&returnvalve);
                        switch(returnvalve)
                        {
                            case FAILED2:{printf("�����ǿյ������ɾ��������\n");break;}
                            case FAILED1:{printf("����һ�����������?\n");break;}
                            case SUCCESS:{printf("Node completely deleted.\n");break;}
                        }
                        break;
                    }
        case 's':
        case 'S':
                    {
                        printf("Search a location of a node either using number or using name.(input U to search by number)\n");
                        choice=getch();
                        Flocation(original_node,choice);
                        switch(returnvalve)
                        {
                            case FAILED2:{printf("Search completed.\n");break;}
                            case FAILED1:{printf("Search completed,no match found.\n");break;}
                            case SUCCESS:{printf("Search completed and task canceled.\n");break;}
                        }
                        break;
                    }
        case 'P':
        case 'p':
                    {
                        pos=print(original_node);
                        (pos==FAILED1)?printf("R U FUCKING KIDDING ME???\n"):printf("Print successfully.\n");
                        break;
                    }
        case 'E':
        case 'e':
                    {
                        printf("Are you sure want to quit the program?(Y to exit)\n");
                        choice=getch();
                        if(choice == 'Y'||choice == 'y')
                        {
                            while(original_node != NULL)
                            {
                                modify_node = original_node->next;
                                free(original_node);
                                original_node=modify_node;
                            }
                            free(modify_node);
                            printf("Bye bye!");
                            return 0;
                        }

                    }
        case 'O':
        case 'o':
                    {
                        for(pos=0,modify_node=original_node;modify_node != NULL;pos++,modify_node=modify_node->next);
                        sortnode(original_node,pos);
                        break;
                    }
        case 'H':
        case 'h':
                    {
                        printf("Please insert:\n\
                        N:Free the original node and make a new node\n\
                        I:Insert a node\n\
                        D:Delete a node in the original node\n\
                        S:Search a node by its name or number\n\
                        P:Print the original node.\n\
                        O:Sort the node by name or number\n\
                        H:Help\n\
                        or insert E to quit the program.\n");
                        printf("Node by AXM_MISAKA20001,DEBUG 1.5\n");
                        printf("This program is by Creative Commons Attribution-NonCommercial-Cc-NoDeductive 3.0(CC-BY NC ND 3.0)\n");
                        printf("Problem:When deleting\\adding a node,if you input a position bigger than count of the node,it will add\\delete the end of the node.\n");
                        break;
                    }
        #ifdef DEBUG
        case 'Q':
        case 'q':
                    {
                        question();
                        break;
                    }
        #endif // DEBUG
        default:printf("Unknown command!\n");

        }
    }
    return 0;
}
#endif //VERSION 1_5
#if defined ROLL
LLIST* make(void)
{
    LLIST *head=NULL,*newnode,*prevnode;
    int count=0;
    printf("Type the number and name(Do NOT include space in the name!PROGRAM is NOT support!).Type a enter at their center and type a \"-1\" if you want to quit(so number cannot be -1.\n");
    while(1)
    {
        newnode=(LLIST*)malloc(sizeof(LLIST));
        newnode->next=NULL;
        scanf("%d",&(newnode->number));
        if (newnode->number==-1)//over
        {
            newnode ->next = head;
            return(head);
        }
        scanf("%59s",newnode->name);
        fflush(stdin);
        count++;
        #ifdef DEBUG
        printf("(DEBUG)%d,%s\n",newnode->number,newnode->name);
        #endif // DEBUG
        if (count==1)//is head or not
        {
            head=prevnode=newnode;
            newnode->head = true;
        }
        else
        {
            prevnode->next=newnode;
            prevnode=newnode;
            newnode->head = false;
        }

    }
}
#elif defined UD
LLIST* make(void)
{
    LLIST *head=NULL,*newnode,*prevnode;
    int count=0;
    printf("Type the number and name(Do NOT include space in the name!PROGRAM is NOT support!).Type a enter at their center and type a \"-1\" if you want to quit(so number cannot be -1.\n");
    while(1)
    {
        newnode=(LLIST*)malloc(sizeof(LLIST));
        newnode->next=NULL;
        scanf("%d",&(newnode->number));
        if (newnode->number==-1)//over
        {
            return(head);
        }
        scanf("%59s",newnode->name);
        fflush(stdin);
        count++;
        #ifdef DEBUG
        printf("(DEBUG)%d,%s\n",newnode->number,newnode->name);
        #endif // DEBUG
        if (count==1)//is head or not
        {
            head=prevnode=newnode;
            newnode->prev = NULL;
        }
        else
        {
            prevnode->next = newnode;
            newnode->prev = prevnode;
            prevnode=newnode;
        }

    }
}
#else
LLIST* make(void)
{
    LLIST *head=NULL,*newnode,*prevnode;
    int count=0;
    printf("Type the number and name(Do NOT include space in the name!PROGRAM is NOT support!).Type a enter at their center and type a \"-1\" if you want to quit(so number cannot be -1.\n");
    while(1)
    {
        newnode=(LLIST*)malloc(sizeof(LLIST));
        newnode->next=NULL;
        scanf("%d",&(newnode->number));
        if (newnode->number==-1)//over
        {
            return(head);
        }
        scanf("%59s",newnode->name);
        fflush(stdin);
        count++;
        #ifdef DEBUG
        printf("(DEBUG)%d,%s\n",newnode->number,newnode->name);
        #endif // DEBUG
        if (count==1)//is head or not
            head=prevnode=newnode;
        else
        {
            prevnode->next=newnode;
            prevnode=newnode;
        }

    }
}
#endif // ROLL/UD/NORMAL

LLIST * insert(LLIST *head,LLIST *newstr,int position,int * returnv)
{
    LLIST * temp;
    if(head==NULL)
    {
        head=newstr;
        *returnv = FAILED2;
        return head;
    }
    if (position==1)//Get the node to its head
    {
        newstr->next=head;
        head=newstr;
        *returnv = SUCCESS;
        return head;
    }
    for(temp=head;temp->next!=NULL&&position>2;temp=temp->next,--position);//locate the pointer
    {
        if(temp==NULL)
        {
            *returnv = FAILED1;
        }
        else
        {
            newstr->next=temp->next;//inserting
            temp->next=newstr;
        }
    }
    *returnv = SUCCESS;
    return head;
}
LLIST * delnode(LLIST *head,int position,int * returnv)
{
    LLIST * temp;
    LLIST * tempdel;
    if(head == NULL)
    {
        *returnv = FAILED2;
        return head;
    }
    if (position == 1)
    {
        temp=head;//deleting head
        head=head->next;
        free(temp);
        *returnv = SUCCESS;
        return head;
    }
    for(temp=head;(temp->next->next)!=NULL&&position>2;temp=temp->next,--position);//locate the pointer
    {
        if (temp == NULL)
        {
            *returnv = FAILED1;
        }
        else
        {
            tempdel=temp->next;//deleting
            temp->next=tempdel->next;
            free(tempdel);
            *returnv = SUCCESS;
        }
    }
    return head;

}
int Flocation(LLIST * head,char select)
{
    LLIST * match;
    match = head;
    bool find = false;
    int w_node=0;
    if (select=='U' || select == 'u')
    {
        int number;
        printf("Input your number!\n");
        scanf("%d",&number);
        while (match!=NULL)
        {
            w_node++;
            if (number == match->number)
            {
                find = true;
                printf("Search complete.Node number %d,number of it is %d,string of it is %s\n",w_node,match->number,match->name);
                printf("Continue?(Y to exit)\n");
                select=getch();
                if(select == 'Y' || select == 'y')
                {
                    return FAILED2;
                }
            }
            match=match->next;
        }
        if (find)
        {
            return SUCCESS;
        }
        else
        {
            return FAILED1;
        }
    }
    else
    {
        char string[60];
        printf("Input your string!\n");
        scanf("%59s",string);
        while (match!=NULL)
        {
            w_node++;
            if (!strcmp(string,match->name))
            {
                find = true;
                printf("Search complete.Node number %d,number of it is %d,string of it is %s\n",w_node,match->number,match->name);
                printf("Continue?(Y to exit)\n");
                select=getch();
                if(select == 'Y' || select == 'y')
                {
                    return FAILED2;
                }
            }
            match=match->next;
        }
        if (find)
        {
            return SUCCESS;
        }
        else
        {
            return FAILED1;
        }
    }
}
int freenode(LLIST * head)
{
    LLIST * temp;
    char choice;
    choice = getch();
    if (choice == 'Y'||choice == 'y')
    {
        while(head != NULL)
        {
            temp = head->next;
            free(head);
            head=temp;
        }
        return SUCCESS;
    }
    return FAILED1;
}
int print(LLIST * head)
{
    LLIST * temp;
    if (head==NULL)
    {
        return 1;
    }
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d,%s\n",temp->number,temp->name);
    #ifdef DEBUG
        printf("(DEBUG)%p\n",&temp);
    #endif // DEBUG
    }
    return 0;
}
int question(void)
{
    int a;
    char ans[100];
    LARGE_INTEGER litmp;
    LONGLONG Q;
    const char array[10][2][100]={
                            {"����,�������ȵ�ū��,______.","����,ȫ�����ܿ����"},
                            {"�޵����ɸ�,__________.","���ò����"},
                            {"̤�ޤ줿����,__________.","��ǰ��֪�餺��"},
                            {"PX��___��ѧ����?","�綾�°��к˷����ܵ���ȫ���ů�������״ݻٳ��е�ת����"},
                            {"��ǧԤ�������,____________.ʮ��E7װ��ȥ,��·̩̹���ؼ�.","��Ǯ�ӵ�ʮ���"},
                            {"��˭��������������?______.","�������Ͷ�Ⱥ��"},
                            {"���ľ���________����Ͽɣ��ɹ��޲��׼������Ķ���","���ҹ���"},
                            {"________����________������________�����ߴ�˳ɵĸߴ�˳ɶ��ߴ�˳ɲ���ȷ��","�ߴ�˳�"},
                            {"�ڽ��CP��:","��������"},
                            {"ʹ�ɻ��������,_______.","���Ƕ�������Ƥ"},
                            };
    /*strcpy(array[0][0],"����,�������ȵ�ū��,______.");
    strcpy(array[0][1],"����,ȫ�����ܿ����");
    strcpy(array[1][0],"�޵����ɸ�,__________.");
    strcpy(array[1][1],"���ò����");
    strcpy(array[2][0],"̤�ޤ줿����,__________.");
    strcpy(array[2][1],"��ǰ��֪�餺��");
    strcpy(array[3][0],"PX��___��ѧ����?");
    strcpy(array[3][1],"�綾�°��к˷����ܵ���ȫ���ů�������״ݻٳ��е�ת����");
    strcpy(array[4][0],"��ǧԤ�������,____________.ʮ��E7װ��ȥ,��·̩̹���ؼ�.");
    strcpy(array[4][1],"��Ǯ�ӵ�ʮ���");
    strcpy(array[5][0],"��˭��������������?______.");
    strcpy(array[5][1],"�������Ͷ�Ⱥ��");
    strcpy(array[6][0],"���ľ���________����Ͽɣ��ɹ��޲��׼������Ķ���");
    strcpy(array[6][1],"���ҹ���");
    strcpy(array[7][0],"________����________������________�����ߴ�˳ɵĸߴ�˳ɶ��ߴ�˳ɲ���ȷ��");
    strcpy(array[7][1],"�ߴ�˳�");
    strcpy(array[8][0],"�ڽ��CP��:");
    strcpy(array[8][1],"��������");
    strcpy(array[9][0],"ʹ�ɻ��������,_______.");
    strcpy(array[9][1],"���Ƕ�������Ƥ");*/
    for(int loop=3;loop > 0;loop--)
    {
        QueryPerformanceCounter(&litmp);
        Q = litmp.QuadPart;
        srand((unsigned)time(NULL)+(unsigned int)Q);
        a=rand() % 8 +1;
        printf("Enter the answer of the question:%s\nYou still have %d chances.\n",array[a][0],loop);
        gets(ans);
        if(!strcmp(ans,array[a][1]))
            return SUCCESS;
    }
    printf("You wrong for too many times!\n");
    #ifdef DEBUG
    return FAILED1;
    #else // DEBUG
    exit(0);
    #endif
}
int sortnode(LLIST * head,const int len)
{
    typedef struct nod
    {
        int num;
        char nam[60];
    }array;
    array arr[len];
    char choice;
    short flag;
    LLIST * temp;
    temp = head;
    char tem[60];
    for(int loop=0;loop < len;loop++)//Let arr be a copy of LLIST
    {
        arr[loop].num = temp->number;
        strcpy(arr[loop].nam,temp->name);
        temp = temp->next;
    }
    printf("Do you want to sort by number or by name(U/A)\n");
    choice=getch();
    if(choice=='U'||choice=='u')//by number,Bubble sort,an SB sorting
    {
        for (int i=0;i<len-1;i++)
        {
            flag = 0;
            for (int j=1;j<len-i;j++)
            {
                if (arr[j].num<arr[j-1].num)
                {
                    arr[j].num = arr[j].num ^ arr[j-1].num;
                    arr[j-1].num = arr[j].num ^ arr[j-1].num;
                    arr[j].num = arr[j].num ^ arr[j-1].num;
                    strcpy(tem,arr[j].nam);
                    strcpy(arr[j].nam,arr[j-1].nam);
                    strcpy(arr[j-1].nam,tem);

                    flag = 1;
                }
            }
             if(flag != 1)
        {
            break;
        }
        }

        }//sort complete
        if(choice=='A'||choice=='a')//by name,Bubble sort,an SB sorting
        {
        for (int i=0;i<len-1;i++)
        {
            flag = 0;
            for (int j=1;j<len-i;j++)
            {
                if (strcmp(arr[j].nam,arr[j-1].nam) > 0)
                {
                    arr[j].num = arr[j].num ^ arr[j-1].num;
                    arr[j-1].num = arr[j].num ^ arr[j-1].num;
                    arr[j].num = arr[j].num ^ arr[j-1].num;
                    strcpy(tem,arr[j].nam);
                    strcpy(arr[j].nam,arr[j-1].nam);
                    strcpy(arr[j-1].nam,tem);

                    flag = 1;
                }
                if(flag != 1)
            {
                break;
            }
            }

        }//sort complete
        }
        printf("Sort complete.Printing.\n");
        for(int loop=0;loop < len;loop++)
        {
            printf("%d,%s\n",arr[loop].num,arr[loop].nam);

        }
    free(arr);
    return SUCCESS;

}
#ifdef VERSION1_1
int main()
{
    int pos;
    LLIST * test,* test1;
        printf("Node by AXM_MISAKA20001.\n");
        printf("VER:Alpha 1.1 Debug.\n");
        printf("Reloading AK47,please wait......\n");
    test=make();
    print(test);
    test1=(LLIST*)malloc(sizeof(LLIST));
	test1->next = NULL;
	printf("Node Created\n");
	scanf("%d",&(test1->number));
	scanf("%59s",test1->name);
	fflush(stdin);
	scanf("%d",&pos);
	fflush(stdin);
	test = insert(test,test1,pos);
	printf("Node inserted\n");
	print(test);
	fflush(stdin);
	scanf("%d",&pos);
	test = delnode(test,pos);
	printf("Node Deleted.\n");
	print(test);
	Flocation(test);
	Flocation(test);
    return 0;
}
#endif // DEBUG

#ifdef release
int main(void)
{
    printf("Debug Version.");
    return 0;
}
#endif // release
