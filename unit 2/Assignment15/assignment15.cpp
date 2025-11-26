#include <iostream>
#include <string>
using namespace std;

struct Node_lac
{
    string bin_lac;
    Node_lac *prev_lac;
    Node_lac *next_lac;
};

void insertAtEnd_lac(Node_lac *head, string bin_lac)
{
    Node_lac *node_lac = new Node_lac;
    node_lac->bin_lac = bin_lac;
    node_lac->next_lac = nullptr;

    Node_lac *temp_lac = head;
    while(temp_lac->next_lac != nullptr)
    {
        temp_lac = temp_lac->next_lac;
    }

    temp_lac->next_lac = node_lac;
    node_lac->prev_lac = temp_lac;
}

void display_lac(Node_lac *head)
{
    Node_lac *temp_lac = head->next_lac;
    while(temp_lac != nullptr)
    {
        cout << temp_lac->bin_lac << " ";
        temp_lac = temp_lac->next_lac;
    }
    cout << endl;
}

Node_lac* onesComplement_lac(Node_lac *head)
{
    Node_lac *newHead_lac = new Node_lac;
    newHead_lac->next_lac = nullptr;
    newHead_lac->prev_lac = nullptr;

    Node_lac *temp_lac = head->next_lac;

    while(temp_lac != nullptr)
    {
        string str_lac = temp_lac->bin_lac;
        for(int i=0;i<str_lac.length();i++)
        {
            str_lac[i] = (str_lac[i]=='0') ? '1' : '0';
        }
        insertAtEnd_lac(newHead_lac,str_lac);
        temp_lac = temp_lac->next_lac;
    }

    return newHead_lac;
}

string addBinaryString_lac(string a_lac, string b_lac)
{
    string res_lac = "";
    int carry_lac = 0;

    int i = a_lac.size()-1;
    int j = b_lac.size()-1;

    while(i>=0 || j>=0 || carry_lac)
    {
        int sum_lac = carry_lac;
        if(i>=0) sum_lac += a_lac[i--]-'0';
        if(j>=0) sum_lac += b_lac[j--]-'0';

        res_lac = char(sum_lac%2+'0') + res_lac;
        carry_lac = sum_lac/2;
    }

    return res_lac;
}

Node_lac* twosComplement_lac(Node_lac *head)
{
    Node_lac *oneComp_lac = onesComplement_lac(head);
    Node_lac *temp_lac = oneComp_lac->next_lac;

    while(temp_lac != nullptr)
    {
        temp_lac->bin_lac = addBinaryString_lac(temp_lac->bin_lac,"1");
        temp_lac = temp_lac->next_lac;
    }
    return oneComp_lac;
}

Node_lac* addBinary_lac(Node_lac *A_lac, Node_lac *B_lac)
{
    Node_lac *sumHead_lac = new Node_lac;
    sumHead_lac->next_lac = nullptr;
    sumHead_lac->prev_lac = nullptr;

    Node_lac *p_lac = A_lac->next_lac;
    Node_lac *q_lac = B_lac->next_lac;

    while(p_lac != nullptr || q_lac != nullptr)
    {
        string num1_lac = (p_lac) ? p_lac->bin_lac : "0";
        string num2_lac = (q_lac) ? q_lac->bin_lac : "0";

        string res_lac = addBinaryString_lac(num1_lac,num2_lac);
        insertAtEnd_lac(sumHead_lac,res_lac);

        if(p_lac) p_lac = p_lac->next_lac;
        if(q_lac) q_lac = q_lac->next_lac;
    }
    return sumHead_lac;
}

int main()
{
    Node_lac *head1 = new Node_lac;
    head1->next_lac = nullptr;
    head1->prev_lac = nullptr;

    Node_lac *head2 = new Node_lac;
    head2->next_lac = nullptr;
    head2->prev_lac = nullptr;

    int n1_lac,n2_lac;
    cout << "Enter number of nodes for first binary list: ";
    cin >> n1_lac;

    for(int i=0;i<n1_lac;i++)
    {
        string s_lac;
        cout << "Binary node " << i+1 << ": ";
        cin >> s_lac;
        insertAtEnd_lac(head1,s_lac);
    }

    cout << "Enter number of nodes for second binary list: ";
    cin >> n2_lac;

    for(int i=0;i<n2_lac;i++)
    {
        string s_lac;
        cout << "Binary node " << i+1 << ": ";
        cin >> s_lac;
        insertAtEnd_lac(head2,s_lac);
    }

    cout << "\nFirst List: ";
    display_lac(head1);

    cout << "Second List: ";
    display_lac(head2);

    cout << "\n1's Complement: ";
    display_lac(onesComplement_lac(head1));

    cout << "2's Complement: ";
    display_lac(twosComplement_lac(head1));

    cout << "\nBinary Addition Result: ";
    display_lac(addBinary_lac(head1,head2));

    return 0;
}