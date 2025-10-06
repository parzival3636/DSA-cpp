#include <iostream>
#include <string>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* next;
};

class VertexClub {
    Node* head;
public:
    VertexClub() { head = NULL; }

    void addPresident(int prn, string name) {
        Node* newNode = new Node{prn, name, head};
        head = newNode;
        cout << "President added.\n";
    }

    void addSecretary(int prn, string name) {
        Node* newNode = new Node{prn, name, NULL};
        if (head == NULL) { head = newNode; return; }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        cout << "Secretary added.\n";
    }

    void addMember(int prn, string name) {
        if (head == NULL) { cout << "Add President first!\n"; return; }
        Node* newNode = new Node{prn, name, NULL};
        Node* temp = head;
        while (temp->next != NULL && temp->next->next != NULL) temp = temp->next;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Member added.\n";
    }

    void deleteMember(int prn) {
        if (head == NULL) { cout << "List empty.\n"; return; }
        if (head->prn == prn) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "President deleted.\n";
            return;
        }
        Node* curr = head; Node* prev = NULL;
        while (curr != NULL && curr->prn != prn) { prev = curr; curr = curr->next; }
        if (curr == NULL) { cout << "PRN not found.\n"; return; }
        prev->next = curr->next;
        if (curr->next == NULL) cout << "Secretary deleted.\n";
        else cout << "Member deleted.\n";
        delete curr;
    }

    void display() {
        if (head == NULL) { cout << "No members in list.\n"; return; }
        Node* temp = head;
        cout << "\n--- Vertex Club Members ---\n";
        while (temp != NULL) {
            cout << "PRN: " << temp->prn << " | Name: " << temp->name << endl;
            temp = temp->next;
        }
    }

    void count() {
        int cnt = 0; Node* temp = head;
        while (temp != NULL) { cnt++; temp = temp->next; }
        cout << "Total members: " << cnt << endl;
    }

    void search(int prn) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->prn == prn) {
                cout << "Found: " << temp->name << " (PRN: " << temp->prn << ")\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found.\n";
    }

    void reverse() {
        Node* prev = NULL; Node* curr = head; Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        cout << "List reversed.\n";
    }

    void sortByPRN() {
        if (head == NULL) return;
        for (Node* i = head; i->next != NULL; i = i->next)
            for (Node* j = i->next; j != NULL; j = j->next)
                if (i->prn > j->prn) {
                    swap(i->prn, j->prn);
                    swap(i->name, j->name);
                }
        cout << "List sorted by PRN.\n";
    }

    void concatenate(VertexClub& other) {
        if (head == NULL) { head = other.head; return; }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = other.head;
        cout << "Lists concatenated.\n";
    }
};

int main() {
    VertexClub divA, divB;
    int choice, prn;
    string name;
    do {
        cout << "\n--- Vertex Club Menu ---\n";
        cout << "1. Add President\n2. Add Member\n3. Add Secretary\n";
        cout << "4. Delete Member\n5. Display\n6. Count\n";
        cout << "7. Search by PRN\n8. Reverse List\n9. Sort by PRN\n";
        cout << "10. Concatenate Div B to Div A\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1: cout << "Enter PRN and Name: "; cin >> prn >> name; divA.addPresident(prn, name); break;
        case 2: cout << "Enter PRN and Name: "; cin >> prn >> name; divA.addMember(prn, name); break;
        case 3: cout << "Enter PRN and Name: "; cin >> prn >> name; divA.addSecretary(prn, name); break;
        case 4: cout << "Enter PRN to delete: "; cin >> prn; divA.deleteMember(prn); break;
        case 5: divA.display(); break;
        case 6: divA.count(); break;
        case 7: cout << "Enter PRN to search: "; cin >> prn; divA.search(prn); break;
        case 8: divA.reverse(); break;
        case 9: divA.sortByPRN(); break;
        case 10: divB.addPresident(101, "Raj"); divB.addMember(105, "Siya"); divB.addSecretary(109, "Tina"); divA.concatenate(divB); break;
        case 0: cout << "Exiting program.\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
