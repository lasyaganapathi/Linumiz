#include <stdio.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
}*head;

void createList(int);
void reverseList();
void displayList();


int main()
{
    int n;
    printf("Enter the number of letters in the word: ");
    scanf("%d", &n);
    createList(n);
    printf("word in reverse order\n");
    reverseList(head);
    displayList(head);

    return 0;
}

void createList(int n)
{
    struct node *newNode, *temp;
    int i;
    char data;

    if(n <= 0)
    {
        printf("List size must be greater than zero.\n");
        return;
    }

    head = (struct node *)malloc(sizeof(struct node *));


    if(head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {   printf("Enter word\n");
        scanf(" %c", &data);

        head->data = data;
        head->next = NULL;

        temp = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node *));
            if(newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                scanf(" %c", &data);

                newNode->data = data;
                newNode->next = NULL;

                temp->next = newNode;
                temp = temp->next;
            }
        }
    }
}


void reverseList()
{
    struct node *prevNode, *curNode;

    if(head != NULL)
    {
        prevNode = head;
        curNode = head->next;
        head = head->next;

        prevNode->next = NULL;

        while(head != NULL)
        {
            head = head->next;
            curNode->next = prevNode;

            prevNode = curNode;
            curNode = head;
        }

        head = prevNode;
    }
}

void displayList()
{
    struct node *temp;
    if(head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%c", temp->data);
            temp = temp->next;
        }
    }
}

