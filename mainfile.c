#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#define DEBUG
#define VERSION1_2
typedef struct node
{
    int number;
    char name[60];
    struct node * next;
}LLIST;
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
        if (newnode->number==-1)
            return(head);
        scanf("%59s",newnode->name);
        fflush(stdin);
        count++;
        #ifdef DEBUG
        printf("(DEBUG)%d,%s\n",newnode->number,newnode->name);
        #endif // DEBUG
        if (count==1)
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
    if (position==1)
    {
        newstr->next=head;
        head=newstr;
        printf("Node completely inserted.\n");
        return head;
    }
    for(temp=head;temp->next!=NULL&&position>2;temp=temp->next,--position);
    {
        if(temp==NULL)
        {
            printf("No match(es) found.\n");
        }
        else
        {
            newstr->next=temp->next;
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
        printf("链表都是空的你TM叫我删除个锤子\n");
        return head;
    }
    if (position == 1)
    {
        temp=head;
        head=head->next;
        free(temp);
        printf("Node completely deleted.\n");
        return head;
    }
    for(temp=head;temp->next!=NULL&&position>2;temp=temp->next,--position);
    {
        if (temp == NULL)
        {
            printf("给我一空玩意儿干嘛,信不信我爆你蛋?\n");
        }
        else
        {
            tempdel=temp->next;
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
    bool find = false;
    int w_node=0;
    printf("Search a location of a node either using number or using name.(input U to search by number)\n");
    select=getch();
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
                find = true;
                printf("Search complete.Node number %d,number of it is %d,string of it is %s\n",w_node,match->number,match->name);
                printf("Continue?(Y to exit)\n");
                select=getch();
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
    choice = getch();
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
#ifdef VERSION1_2
int main(void)
{
    int pos;
    char choice;
    LLIST * original_node,* modify_node;
    printf("Reloading AK47,please wait......\n");
    printf("Node by AXM_MISAKA20001.\n");
    printf("VER:Alpha 1.2 Debug.\nThis program servers only ONE node.");
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
                or insert E to quit the program.\n");
        choice=getch();
        fflush(stdin);
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
                        choice=getch();
                        if(choice == 'Y'||choice == 'y')
                        {
                            printf("Bye bye!");
                            return 0;
                        }

                    }
        default:printf("Empty command!\n");

        }
    }
    return 0;
}
#endif // second


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

