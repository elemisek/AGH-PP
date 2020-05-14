#include <stdio.h>
#include <stdlib.h>


struct tnode
{
    int value;
    struct tnode * next;
};

struct tnode * dodaj_na_poczatek(struct tnode * head, int val);
void wypisz(struct tnode *head);
struct tnode * zwolnij(struct tnode *head);
struct tnode * dodaj_na_koniec(struct tnode * head, int val);
struct tnode * dodaj_do_posortowanej(struct tnode * head, int val, int flag);
struct tnode * find(struct tnode * head, int key);
struct tnode * delete(struct tnode * head, int key);



int main()
{

    int values[]= {23,13,67,3,123};
    int key;
    struct tnode *head=dodaj_na_poczatek(NULL,values[0]);
    for(int i=1; i<5; i++)
        head=dodaj_na_poczatek(head,values[i]);
    wypisz(head);
    head=zwolnij(head);
    head=dodaj_na_koniec(NULL,23);
    for(int i=1; i<5; i++)
        head=dodaj_na_koniec(head,values[i]);
    printf("Backwards:\n");
    wypisz(head);
    head=zwolnij(head);
    head=dodaj_do_posortowanej(NULL,23,1);
    for(int i=1; i<5; i++)
        head=dodaj_do_posortowanej(head,values[i],1);
    printf("Ascending:\n");
    wypisz(head);
    head=zwolnij(head);
    head=dodaj_do_posortowanej(NULL,23,0);
    for(int i=1; i<5; i++)
        head=dodaj_do_posortowanej(head,values[i],0);
    printf("Descending:\n");
    wypisz(head);
    printf("Enter number:\n");
    scanf("%d", &key);
    struct tnode *liczba=find(head, key);
    if(liczba)
        printf("Adress: %p\n", liczba);
    else
        printf("Not found\n");
    printf("Number to delete:\n");
    scanf("%d", &key);
    head=delete(head, key);
    wypisz(head);
    head=zwolnij(head);
}

struct tnode * dodaj_na_poczatek(struct tnode * head, int val)
{
    struct tnode *p=malloc(sizeof(struct tnode));
    if(!p)
    {
        printf("ERROR\n");
        return head;
    }
    p->value=val;
    p->next=head;
    return p;
}

void wypisz(struct tnode *head)
{
    if(!head)
    {
        printf("EMPTY\n");
        return;
    }
    struct tnode *p=head;
    while(p)
    {
        printf("%d \n", p->value);
        p=p->next;
    }
}

struct tnode * zwolnij(struct tnode *head)
{
    struct tnode *p=head;
    while(p)
    {
        struct tnode *t=p->next;
        free(p);
        p=t;
    }
    return NULL;
}

struct tnode * dodaj_na_koniec(struct tnode * head, int val)
{
    struct tnode *p=malloc(sizeof(struct tnode));
    if(!p)
    {
        printf("ERROR\n");
        return head;
    }
    p->value=val;
    p->next=NULL;
    if(head)
    {
        struct tnode *tab=head, *prev=NULL;
        while(tab)
        {
            prev=tab;
            tab=tab->next;
        }
        prev->next=p;
    }
    else
        head=p;
    return head;
}

struct tnode * dodaj_do_posortowanej(struct tnode * head, int val, int flag)
{
    struct tnode *p=malloc(sizeof(struct tnode));
    if(!p)
    {
        printf("ERROR\n");
        return head;
    }

    p->value=val;

    if(flag)
    {
        if(head)
        {
            if(head->value > p->value)
            {
                p->next=head;
                head=p;
            }
            else
            {
                struct tnode *tab=head, *prev=NULL;
                while(tab && tab->value < p->value)
                {
                    prev=tab;
                    tab=tab->next;
                }
                p->next=tab;
                prev->next=p;
            }
        }
        else
        {
            p->next=NULL;
            head=p;
        }
        return head;
    }
    else
    {
        if(head)
        {
            if(head->value < p->value)
            {
                p->next=head;
                head=p;
            }
            else
            {
                struct tnode *tab=head, *prev=NULL;
                while(tab && tab->value > p->value)
                {
                    prev=tab;
                    tab=tab->next;
                }
                p->next=tab;
                prev->next=p;
            }
        }
        else
        {
            p->next=NULL;
            head=p;
        }
        return head;
    }


}

struct tnode *find(struct tnode * head, int key)
{
    struct tnode *p=head;
    while(p)
    {
        if(p->value == key)
            return p;
        p=p->next;
    }
    return NULL;
}

struct tnode * delete(struct tnode * head, int key)
{
    struct tnode *p=head, *prev=NULL;
    while(p)
    {
        if(p->value == key)
        {
            if(!prev)
                head=p->next;
            else
                prev->next=p->next;
            printf("Deleted\n");
            free(p);
            return head;
        }
        prev=p;
        p=p->next;
    }
    printf("Not found\n");

    return head;
}
