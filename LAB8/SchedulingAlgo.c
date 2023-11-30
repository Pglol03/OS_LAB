// Arrival Time: Time at which the process arrives in the ready queue.
// Completion Time: Time at which process completes its execution.
// Burst Time: Time required by a process for CPU execution.
// Turn Around Time: Time Difference between completion time and arrival time.

//```Turn Around Time = Completion Time  –  Arrival Time```
//```Waiting Time = Turn Around Time  –  Burst Time```

#include<stdio.h>
#include<stdlib.h>

int size;


struct Node
{
    int ID;
    int BT;
    int AT;
    int ST;
    int TAT;
    int WT;
    struct Node *next;
};

void fifoSA(struct Node **head){
    struct Node *sorted_head = NULL;
    struct Node *temp = *head;
    struct Node *prevleast = NULL;
    struct Node *least = NULL;
    for(int i = 0 ; i < size ; i++){
        int leastAT = temp->AT;
        *prevleast = *temp;
        while(temp->next!=NULL){
            *temp = *temp->next;
            if(leastAT>temp->AT){
                leastAT = temp->AT;
                *prevleast = *temp;
            }
        }
        
    }
}

void deleteStart (struct Node **head)
{
  struct Node *temp = *head;

  // if there are no nodes in Linked List can't delete
  if (*head == NULL)
    {
      printf ("Queue Empty, nothing to execute here");
      return;
    }

    int id = temp->ID;
  // move head to next node
  *head = (*head)->next;

  printf ("\n%d Process done executing \n", temp->ID);
  free (temp);
}

void insertStart (struct Node **head, int data)
{

  // dynamically create memory for this newNode
  struct Node *newNode = (struct Node *) malloc (sizeof (struct Node));

  // assign data value
  newNode->data = data;
  // change the next node of this newNode 
  // to current head of Linked List
  newNode->next = *head;

  //re-assign head to this newNode
  *head = newNode;
  printf ("\n%d Inserted\n", newNode->data);
}

void display (struct Node *node)
{
  printf ("\nLinked List: ");

  // as linked list will end when Node is Null
  while (node != NULL)
    {
      printf ("%d ", node->data);
      node = node->next;
    }
  printf ("\n");
}

int main ()
{
  struct Node *head = NULL;

  // Need '&' i.e. address as we need to change head
  insertStart (&head, 100);
  insertStart (&head, 80);
  insertStart (&head, 60);
  insertStart (&head, 40);
  insertStart (&head, 20);

  // No Need for '&' as not changing head in display operation
  display (head);

  deleteStart (&head);
  deleteStart (&head);
  display (head);

  return 0;
}