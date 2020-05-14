struct node
{
    int value;
    struct node * next;
};



void reverse(struct node **head)
{
  struct node *p, *pc;
  if(head)
  {
    pc=*head;
    while(pc->next)
    {
      p=pc->next;
      pc->next=p->next;
      p->next=*head;
      *head=p;
    }
  }
}
int main()
{

}


