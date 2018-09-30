#include <iostream>
struct Node
{
    int data;
    Node * next;
    Node(int a=-1)
    {
        data=a;
        next=NULL;
    }
};
class List
{
public:
    List()
    {
        root = new Node();
    }
    ~List()
    {
        Node * temp = root;
        Node * next = temp->next;
        while(next != NULL)
        {
            delete temp;
            temp = next;
            next = temp->next;
        }
    }
    Node * Locate(int n)
    {
        if(n < 0) return NULL;
        Node * temp = root;
        for(int i=-1;i<n && temp != NULL;i++)
        {
            temp = temp->next;
        }
        return temp;
    }
    Node * max()
    {
        Node * temp = root->next;
        Node * maxs = temp;
        while(temp != NULL)
        {
            if(maxs->data < temp->data)
            {
                maxs = temp;
            }
            temp = temp->next;
        }
        return maxs;
    }
    int number(int x)
    {
        int num = 0;
        Node * temp = root->next;
        while(temp != NULL)
        {
            if(temp->data == x)
                num++;
            temp = temp->next;
        }
        return num;
    }

    void create(int *array, int n)
    {
        Node * temp = root;
        for(int i=0;i<n;i++)
        {
            temp->next = new Node(array[i]);
            temp = temp->next;
        }
    }

    void tidyup()
    {
        Node * current = root->next;
        while(current != NULL)
        {
            Node * equal = current->next;
            while( equal != NULL && equal->data == current->data)
            {
                Node * temp = equal;
                equal = equal->next;
                delete temp;
            }
            current->next = equal;
            current = current->next;
        }
    }
    void print()
    {
        Node * temp = root->next;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
private:
    Node *root;               //root为头节点
};

int main()
{
    int a[10]={1,1,1,3,5,5,5,7,8,8};
    List list;

    list.create(a, 10);

    printf("Locate:%p\n", list.Locate(3));
    printf("max:%d\n", list.max()->data);
    printf("number:%d\n", list.number(5));

    printf("origin:");
    list.print();

    list.tidyup();

    printf("tidyup:");
    list.print();


    return 0;
}