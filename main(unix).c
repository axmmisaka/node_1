/****************************************************************************************/
/************Node(OMG) by ***************     Support on Unix or Older Windows***********/
/*****Still Need c99 support(Many features) but not Windows OS(Windows.h&Winbase.h).*****/
/****************************************************************************************/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "time.h"
#define DEBUG
#define VERSION1_4
typedef struct node
{
    int number;
    char name[60];
    struct node * next;
}LLIST;
LLIST * make(void);
LLIST * insert(LLIST *head,LLIST *newstr,int position);//For inserting node
LLIST * delnode(LLIST *head,int position);//For deleting node
int Flocation(LLIST * head);//For find a location of a node
int freenode(LLIST * head);//For free the node
int print(LLIST * head);//Print all nodes
int question(void);//Optional,for otaku and communists.
int sortnode(LLIST * head,const int len);//Sort the node by name or number.
#ifdef VERSION1_4
int main(void)
{
    int pos;
    char choice;
    LLIST * original_node,* modify_node;
    printf("Reloading AK47,please wait......\n");
    printf("Node by AXM_MISAKA20001.\n");
    printf("VER:Alpha 1.4 Debug.\nThis program servers only ONE node.");
    question();
    printf("Please insert:\n\
                N:Free the original node and make a new node\n\
                I:Insert a node\n\
                D:Delete a node in the original node\n\
                S:Search a node by its name or number\n\
                P:Print the original node.\n\
                O:Sort the node by name or number\n\
                H:Help\n\
                or insert E to quit the program.\n");
    original_node=make();
    modify_node = (LLIST*)malloc(sizeof(LLIST));
    while (1)
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
        printf("Input your choice:");
        scanf("%c",&choice);
        fflush(stdin);
        printf("\n");
        switch (choice)
        {
        case 'N':
        case 'n':
                    {
                    pos=freenode(original_node);
                    if(pos)
                    original_node=make();
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
                    original_node = insert(original_node,modify_node,pos);
                    break;
                    }
        case 'D':
        case 'd':
                    {
                        printf("Input position.input -1 to end mission\n");
                        scanf("%d",&pos);
                        if (pos == -1) break;
                        original_node = delnode(original_node,pos);
                        break;
                    }
        case 's':
        case 'S':
                    {
                        Flocation(original_node);break;
                    }
        case 'P':
        case 'p':
                    {
                        print(original_node);break;
                    }
        case 'E':
        case 'e':
                    {
                        printf("Are you sure want to quit the program?(Y to exit)\n");
                        scanf("%c",&choice);
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
                        printf("Node by AXM_MISAKA20001,DEBUG 1.4\n");
                        printf("This program is by Creative Commons Attribution-NonCommercial-Cc-NoDeductive 3.0(CC-BY NC ND 3.0)");
                    }
        default:printf("Unknown command!\n");

        }
    }
    return 0;
}
#endif // second
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
            return(head);
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
LLIST * insert(LLIST *head,LLIST *newstr,int position)
{
    LLIST * temp;
    if(head==NULL)
    {
        head=newstr;
        printf("Node is NULL but I help you made it.It's just what you inserted.\n");
        return head;
    }
    if (position==1)//Get the node to its head
    {
        newstr->next=head;
        head=newstr;
        printf("Node completely inserted.\n");
        return head;
    }
    for(temp=head;temp->next!=NULL&&position>2;temp=temp->next,--position);//locate the pointer
    {
        if(temp==NULL)
        {
            printf("No match(es) found.\n");
        }
        else
        {
            newstr->next=temp->next;//inserting
            temp->next=newstr;
            printf("Node completely inserted.\n");
        }
    }
    return head;
}
LLIST * delnode(LLIST *head,int position)
{
    LLIST * temp;
    LLIST * tempdel;
    if(head == NULL)
    {
        printf("链表都是空的你叫我删除个锤子\n");
        return head;
    }
    if (position == 1)
    {
        temp=head;//deleting head
        head=head->next;
        free(temp);
        printf("Node completely deleted.\n");
        return head;
    }
    for(temp=head;temp->next!=NULL&&position>2;temp=temp->next,--position);//locate the pointer
    {
        if (temp == NULL)
        {
            printf("给我一空玩意儿干嘛?\n");
        }
        else
        {
            tempdel=temp->next;//deleting
            temp->next=tempdel->next;
            free(tempdel);
            printf("Node completely deleted.\n");
        }
    }
    return head;

}
int Flocation(LLIST * head)
{
    LLIST * match;
    match = head;
    char select;
    short find = 0;
    int w_node=0;
    printf("Search a location of a node either using number or using name.(input U to search by number)\n");
    scanf("%c",&select);
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
                find = 1;
                printf("Search complete.Node number %d,number of it is %d,string of it is %s\n",w_node,match->number,match->name);
                printf("Continue?(Y to exit)\n");
                scanf("%c",&select);
                if(select == 'Y' || select == 'y')
                {
                    printf("Search completed and task canceled.\n");
                    return 0;
                }
            }
            match=match->next;
        }
        if (find)
        {
            printf("Search completed.\n");
            return 0;
        }
        else
        {
            printf("Search completed,no match found.\n");
            return 1;
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
                find = 1;
                printf("Search complete.Node number %d,number of it is %d,string of it is %s\n",w_node,match->number,match->name);
                printf("Continue?(Y to exit)\n");
                scanf("%c",&select);
                if(select == 'Y' || select == 'y')
                {
                    printf("Search completed and task canceled.\n");
                    return 0;
                }
            }
            match=match->next;
        }
        if (find)
        {
            printf("Search completed.\n");
            return 0;
        }
        else
        {
            printf("Search completed,no match found.");
            return 1;
        }
    }
}
int freenode(LLIST * head)
{
    LLIST * temp;
    char choice;
    printf("Are you SURE you want to free the node?This action CANNOT revert.(Y to continue)\n");
    scanf("%c",&choice);
    if (choice == 'Y'||choice == 'y')
    {
        while(head != NULL)
        {
            temp = head->next;
            free(head);
            head=temp;
        }
        printf("Node(s) freed successfully.\n");\
        return 1;
    }
    return 0;
}
int print(LLIST * head)
{
    LLIST * temp;
    if (head==NULL)
    {
        printf("R U FUCKING KIDDING ME???\n");
        return 1;
    }
    for(temp=head;temp!=NULL;temp=temp->next)
    {
        printf("%d,%s\n",temp->number,temp->name);
    #ifdef DEBUG
        printf("(DEBUG)%p\n",&temp);
    #endif // DEBUG
    }
    printf("Print successfully.\n");
    return 0;
}
int question(void)
{
    int a;
    char ans[100];
    char array[10][2][100];
    strcpy(array[0][0],"起来,饥寒交迫的奴隶,______.");
    strcpy(array[0][1],"起来,全世界受苦的人");
    strcpy(array[1][0],"恨爹不成刚,__________.");
    strcpy(array[1][1],"恨妹不成穹");
    strcpy(array[2][0],"踏まれた花の,__________.");
    strcpy(array[2][1],"名前も知らずに");
    strcpy(array[3][0],"PX是___化学物质?");
    strcpy(array[3][1],"剧毒致癌有核辐射能导致全球变暖并能轻易摧毁城市的转基因");
    strcpy(array[4][0],"三千预算进卡吧,____________.十核E7装上去,四路泰坦抱回家.");
    strcpy(array[4][1],"加钱加到十万八");
    strcpy(array[5][0],"是谁创造了人类世界?______.");
    strcpy(array[5][1],"是我们劳动群众");
    strcpy(array[6][0],"本文经过________审查认可，可供无产阶级乡民阅读。");
    strcpy(array[6][1],"共惨国际");
    strcpy(array[7][0],"________的人________都相信________，但高达八成的高达八成都高达八成不精确。");
    strcpy(array[7][1],"高达八成");
    strcpy(array[8][0],"炮姐的CP是:");
    strcpy(array[8][1],"上条当妈");
    strcpy(array[9][0],"使吧基友来相会,_______.");
    strcpy(array[9][1],"我们都爱黑绿皮");
    for(int loop=3;loop > 0;loop--)
    {
        srand((unsigned)time(NULL));
        a=rand() % 8 +1;
        printf("Enter the answer of the question:%s\nYou still have %d chances.\n",array[a][0],loop);
        gets(ans);
        if(!strcmp(ans,array[a][1]))
            return 0;
    }
    printf("You wrong for too many times!\n");
    exit(0);
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
    scanf("%c",&choice);
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
    return 0;

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

