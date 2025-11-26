# Assignment14

# Assignment - Set Operations on Students Using Linked Lists

## Managing Two Groups of Students Based on Favorite Sports Using Linked Lists

This program represents two groups of students using singly linked lists, where:
- **Set A** contains students who like Cricket.
- **Set B** contains students who like Football.

The program performs set operations on these linked lists to:
a) Find and display students who like both Cricket and Football (intersection).
b) Find and display students who like either Cricket or Football but not both (symmetric difference).
c) Display the number of students who like neither Cricket nor Football from the total class population.

### Operations Implemented
- **Intersection:** Traverse both lists and collect students present in both sets.
- **Symmetric Difference:** Collect students appearing exclusively in one set but not both.
- **Neither Count:** Given total class size, count students who are not present in either list.

### Key Concepts: Linked Lists and Set Operations
- **Linked List Representation:** Each set is represented as a singly linked list where each node contains a student's identifier.
- **Set Operations via Traversal:** Intersection and symmetric difference are computed by traversing and comparing nodes in each list.
- **Complement Calculation:** Based on the known universe of students (total class size), subtraction of union size yields the count of students liking neither sport.

### Time Complexity
- Intersection and symmetric difference operations take \(O(n \times m)\) where \(n\) and \(m\) are list sizes if implemented naïvely; can be optimized using sorting or hashing.
- Counting neither involves simple arithmetic once union count is known.

### Example Scenario
| Set            | Students (IDs)          |
|----------------|------------------------|
| Cricket (A)    | 1, 2, 3, 4             |
| Football (B)   | 3, 4, 5, 6             |
| Total students | 10                     |

- **Intersection (A ∩ B):** 3, 4  
- **Symmetric Difference (A Δ B):** 1, 2, 5, 6  
- **Neither:** 10 - (union count) = 10 - 6 = 4 students

### Applications
- Grouping and classification based on preferences or attributes.  
- Academic or sports team selections based on aggregated attributes.  
- Fundamental illustration of set theory operations in data structures coursework.


## Code
```cpp
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
```

## Output:
<img width="418" height="124" alt="image" src="https://github.com/user-attachments/assets/689f5861-4542-4775-9014-8836aa13d057" />

