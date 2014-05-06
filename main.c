/****************************************************************************************/
/************Node by AXM_MISAKA20001     Not support on Unix or Older Windows************/
/****Which means Need c99 support(Many features) and Windows OS(Windows.h&Winbase.h).****/
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
typedef struct node
{
    int number;
    char name[60];
    struct node * next;
}LLIST;
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
    SetConsoleTitle("Ass＝We＝Can!");// Change current window title
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
                            case FAILED2:{printf("全燕脅頁腎議低出厘評茅倖憾徨\n");break;}
                            case FAILED1:{printf("公厘匯腎螺吭隅孤啄?\n");break;}
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
                        printf("This program is by Creative Commons Attribution-NonCommercial-Cc-NoDeductive 3.0(CC-BY NC ND 3.0)");
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
                            {"軟栖,滋混住独議笛船,______.","軟栖,畠弊順鞭逗議繁"},
                            {"剤漁音撹胡,__________.","剤鍛音撹餬"},
                            {"未まれた雑の,__________.","兆念も岑らずに"},
                            {"PX頁___晒僥麗嵎?","丞蕎崑逢嗤宰堅符嬬擬崑畠白延哲旺嬬煤叟丸支廓偏議廬児咀"},
                            {"眉認圓麻序触杏,____________.噴宰E7廾貧肇,膨揃密鵡宇指社.","紗熱紗欺噴嵐伊"},
                            {"頁豊幹夛阻繁窃弊順?______.","頁厘断斥強蛤巉"},
                            {"云猟将狛________蕪臥範辛��辛工涙恢竣雫�臙駸超繊�","慌禍忽縞"},
                            {"________議繁________脅�猥�________��徽互器伊撹議互器伊撹脅互器伊撹音娼鳩。","互器伊撹"},
                            {"土純議CP頁:","貧訳輝第"},
                            {"聞杏児嗔栖�犹�,_______.","厘断脅握菜駄討"},
                            };
    /*strcpy(array[0][0],"軟栖,滋混住独議笛船,______.");
    strcpy(array[0][1],"軟栖,畠弊順鞭逗議繁");
    strcpy(array[1][0],"剤漁音撹胡,__________.");
    strcpy(array[1][1],"剤鍛音撹餬");
    strcpy(array[2][0],"未まれた雑の,__________.");
    strcpy(array[2][1],"兆念も岑らずに");
    strcpy(array[3][0],"PX頁___晒僥麗嵎?");
    strcpy(array[3][1],"丞蕎崑逢嗤宰堅符嬬擬崑畠白延哲旺嬬煤叟丸支廓偏議廬児咀");
    strcpy(array[4][0],"眉認圓麻序触杏,____________.噴宰E7廾貧肇,膨揃密鵡宇指社.");
    strcpy(array[4][1],"紗熱紗欺噴嵐伊");
    strcpy(array[5][0],"頁豊幹夛阻繁窃弊順?______.");
    strcpy(array[5][1],"頁厘断斥強蛤巉");
    strcpy(array[6][0],"云猟将狛________蕪臥範辛��辛工涙恢竣雫�臙駸超繊�");
    strcpy(array[6][1],"慌禍忽縞");
    strcpy(array[7][0],"________議繁________脅�猥�________��徽互器伊撹議互器伊撹脅互器伊撹音娼鳩。");
    strcpy(array[7][1],"互器伊撹");
    strcpy(array[8][0],"土純議CP頁:");
    strcpy(array[8][1],"貧訳輝第");
    strcpy(array[9][0],"聞杏児嗔栖�犹�,_______.");
    strcpy(array[9][1],"厘断脅握菜駄討");*/
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
