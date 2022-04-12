//
//  main.cpp
//  List Operations
//
//  Created by Paula Ostolska on 31/03/2022.
//

#include <iostream>
#include <stdlib.h>

using namespace std;

typedef int item_t;

typedef struct node {
  item_t item;
  node* next_ptr;
} node_t;

typedef node_t *list_ptr_t;


void create(list_ptr_t &list_ptr)
{
    node_t *new_list_ptr=new node_t;
    new_list_ptr->item=0;
    new_list_ptr->next_ptr=NULL;
    list_ptr=new_list_ptr;
    
}


void insert(node_t *p, item_t x)
{
    node_t *new_element=new node_t;
    new_element->item=x;
    new_element->next_ptr=p->next_ptr;
    p->next_ptr= new_element;
    
}


void print(node_t *list_ptr)
{
    if (list_ptr==NULL) cout<<"List doesn´t exist. Create it\n";
    else
    {
    node_t *p= list_ptr->next_ptr;
    while (p!=NULL)
        {
            cout<<p->item<<" ";
            p=p->next_ptr;
        }
    }
}

bool found_iter(node_t *list_ptr, int x)
{
    if (list_ptr==NULL) cout<<"List doesn´t exist. Create it\n";
    else
    {
    node_t *p=list_ptr->next_ptr;
        while (p!=NULL)
        {
            if (p->item!=x) p=p->next_ptr;
            else return true;
        }
    }
        return false;
    
}



void delete_node(node_t *p)
{
    if (p == NULL || p -> next_ptr == NULL)
    {
        cout<<"List doesn't exist or doesn't have any elements. Create it."<<endl;
    return;
    }
    else
    {
    node_t *tmp;
    tmp=p->next_ptr;
    p->next_ptr=tmp->next_ptr;
    delete tmp;
    }
}

void delete_list(list_ptr_t &list_ptr)
{
    
    node_t *p=list_ptr->next_ptr;
    while(p!=NULL)
    {
        node_t *q=p->next_ptr;
        delete p;
        p=q;
    }
    delete list_ptr;
    list_ptr=NULL;
}
node_t *tail(node_t *list_ptr)
{
    node_t *p;
    p=list_ptr;
    while (p->next_ptr!=NULL) p=p->next_ptr;
        return p;
}
int count (node_t *list_ptr)
{
    node_t *p;
    int i=0;
    p=list_ptr;
    while(p->next_ptr!=NULL)
    {
        p=p->next_ptr;
        i=i+1;
    }
    return i;
}
void insertLast(node_t *list_ptr, item_t x)
{
    node_t *p= new node_t;
    p->item=x;
    p->next_ptr=NULL;
    tail(list_ptr)->next_ptr=p;
    cout<<"Element "<<x<<" has been inserted as the last on the list. \n";
    
}


int main() {
  item_t x;
  list_ptr_t list_ptr = NULL;
  int wybor;
  do {
    cout << "[0] End\n";
    cout << "[1] Create a list\n";
    cout << "[2] Insert x\n";
    cout << "[3] Print list\n";
    cout << "[4] Find x on the list\n";
    cout << "[5] Delete first element \n";
    cout << "[6] Delete element\n";
    cout << "[7] Print the last element of the list\n";
    cout << "[8] Delete list\n";
    cout << "[9] Print number of elements \n";
    cout << "[10] Insert element on the end of the list \n";
    cin >> wybor;
    switch (wybor) {
    case 1:
      if (list_ptr != NULL) {
        cout << "List already exsist. You have to delete it.\n";
        break;
      }
      create(list_ptr);
      break;
    case 2:
      cout << "Write x: ";
      cin >> x;
      insert(list_ptr, x);
      cout << x << " has been inserted\n";
      break;
    case 3:
      cout << "Your list:\n";
      print(list_ptr);
      break;
    case 4:
      cout << "Write x: ";
      cin >> x;
      if (found_iter(list_ptr, x))
        cout << "Element " << x << " has been found\n";
      else
        cout << "Element " << x << " is not on the list.\n";
      break;
    case 5:
            delete_node(list_ptr);
            cout<<"First element has been succesfully deleted.\n";
      break;
    case 6:
            item_t q;
            cout<<"Write a value of element you want to remove\n";
            cin>>q;
            node_t *p;
            p=list_ptr;
            while (p->next_ptr->item!=q && p->next_ptr!=NULL) p=p->next_ptr;
            if (p==NULL) cout<<"Element has not been found.\n";
            else
            delete_node(p);
            cout<<"Element has been deleted\n";
            break;
        case 7:
        {
          node_t *x = tail(list_ptr);
            cout<<"Tail item: "<<x->item<<endl;
            cout<<"Tail adress: "<<x<<endl;
        }
      break;
        case 8:
            if(list_ptr==NULL)
            {
                cout<<"List doesn't exist. Nothing to delete.\n";
                break;
            }
            else
            {
                delete_list(list_ptr);
                cout<<"List has been succesfully deleted.\n";
                break;
            }
   case 9:
            if(list_ptr==NULL)
            {
                cout<<"List doesn't exist. Nothing to delete.\n";
                break;
            }
            else
            {
                cout<<"There is "<<count(list_ptr)<<" elements\n";
            }
            
          
      break;
            case 10:
            int x;
            cout<<"Write a value of element you want to insert: \n";
            cin>>x;
            insertLast(list_ptr, x);
            break;
    }
    cout << "\n\n";

  } while (wybor);

  // system("PAUSE");

  return 0;
}
