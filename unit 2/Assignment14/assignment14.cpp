#include<iostream>
#include<math.h>
#include<string>
#include<ctime>
using namespace std;

typedef struct sll_lac{
    int rno_lac;
    string name_lac;
    bool likesCricket_lac;
    bool likesFootball_lac;
    sll_lac *next_lac;
}sll_lac;

sll_lac *getNode_lac()
{
    sll_lac *node_lac = new sll_lac;
    node_lac->next_lac = nullptr;
    return node_lac;
}

sll_lac *createList_lac(int n)
{
    int no_lac = 100;
    string namearr_lac[6] = {"likhit","sahil","pranil","prem","rohan","pralhad"};
    sll_lac *head_lac = getNode_lac();
    sll_lac *temp_lac = head_lac;
    for(int i=0; i<n; i++)
    {
        sll_lac *node_lac = getNode_lac();
        int cvar_lac = rand() % 2;
        int fvar_lac = rand() % 2;
        int svar_lac = rand() % 6;

        node_lac->rno_lac = no_lac++;
        node_lac->name_lac = namearr_lac[svar_lac];
        node_lac->likesCricket_lac = cvar_lac;
        node_lac->likesFootball_lac = fvar_lac;

        temp_lac->next_lac = node_lac;
        temp_lac = temp_lac->next_lac;
    }
    return head_lac;
}

void DisplayIntersection_lac(sll_lac *head_lac)
{
    sll_lac *temp_lac = head_lac->next_lac;
    while(temp_lac != nullptr)
    {
        if(temp_lac->likesCricket_lac && temp_lac->likesFootball_lac)
        {
            cout<<" Roll no : "<<temp_lac->rno_lac<<" , name : "<<temp_lac->name_lac<<" Likes both cricket and football";
            cout<<endl;
        }
        temp_lac = temp_lac->next_lac;
    }
}

void DisplayNonIntersection_lac(sll_lac *head_lac)
{
    sll_lac *temp_lac = head_lac->next_lac;
    while(temp_lac != nullptr)
    {
        if(temp_lac->likesCricket_lac || temp_lac->likesFootball_lac)
        {
            if(temp_lac->likesCricket_lac && !temp_lac->likesFootball_lac)
            {
                cout<<" Roll no : "<<temp_lac->rno_lac<<" , name : "<<temp_lac->name_lac<<" Likes only cricket";
                cout<<endl;
            }
            if(temp_lac->likesFootball_lac && !temp_lac->likesCricket_lac)
            {
                cout<<" Roll no : "<<temp_lac->rno_lac<<" , name : "<<temp_lac->name_lac<<" Likes only football";
                cout<<endl;
            }
        }
        temp_lac = temp_lac->next_lac;
    }
}

void displayLikeNone_lac(sll_lac *head_lac)
{
    sll_lac *temp_lac = head_lac->next_lac;
    while(temp_lac != nullptr)
    {
        if(!temp_lac->likesCricket_lac && !temp_lac->likesFootball_lac)
        {
            cout<<" Roll no : "<<temp_lac->rno_lac<<" , name : "<<temp_lac->name_lac<<" Likes neither cricket and football";
            cout<<endl;
        }
        temp_lac = temp_lac->next_lac;
    }
}

int main()
{
    srand(time(0));
    int x_lac;
    cout<<"Enter the number of student data to be used : ";
    cin>>x_lac;
    sll_lac *list_lac = createList_lac(x_lac);   

    cout<<"The students who love either cricket or football : "<<endl;
    DisplayNonIntersection_lac(list_lac);

    cout<<"The student who like both : "<<endl;
    DisplayIntersection_lac(list_lac);

    cout<<"The students who like neither : "<<endl;
    displayLikeNone_lac(list_lac);

    return 0;
}