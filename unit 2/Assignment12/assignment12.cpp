#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Seat {
    int seatNo;
    bool booked;
    Seat* next;
    Seat* prev;
};

class GalaxyMultiplex {
    Seat* rows[8];

public:
    GalaxyMultiplex() {
        srand(time(0));
        for (int i = 0; i < 8; i++) {
            rows[i] = NULL;
            createRow(i);
        }
    }

    void createRow(int row) {
        Seat* head = NULL;
        Seat* last = NULL;
        for (int i = 1; i <= 8; i++) {
            Seat* newSeat = new Seat{i, rand() % 2, NULL, NULL};
            if (!head) {
                head = newSeat;
                head->next = head->prev = head;
            } else {
                newSeat->prev = last;
                newSeat->next = head;
                last->next = newSeat;
                head->prev = newSeat;
            }
            last = newSeat;
        }
        rows[row] = head;
    }

    void displaySeats() {
        cout << "\n--- Galaxy Multiplex Seat Layout ---\n";
        for (int r = 0; r < 8; r++) {
            Seat* temp = rows[r];
            cout << "Row " << r + 1 << ": ";
            if (!temp) continue;
            do {
                cout << (temp->booked ? "[X]" : "[O]") << " ";
                temp = temp->next;
            } while (temp != rows[r]);
            cout << endl;
        }
    }

    void bookSeat(int row, int seatNo) {
        if (row < 1 || row > 8 || seatNo < 1 || seatNo > 8) {
            cout << "Invalid row or seat number.\n";
            return;
        }
        Seat* temp = rows[row - 1];
        do {
            if (temp->seatNo == seatNo) {
                if (temp->booked) cout << "Seat already booked!\n";
                else { temp->booked = true; cout << "Seat booked successfully.\n"; }
                return;
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);
    }

    void cancelSeat(int row, int seatNo) {
        if (row < 1 || row > 8 || seatNo < 1 || seatNo > 8) {
            cout << "Invalid row or seat number.\n";
            return;
        }
        Seat* temp = rows[row - 1];
        do {
            if (temp->seatNo == seatNo) {
                if (!temp->booked) cout << "Seat not booked yet!\n";
                else { temp->booked = false; cout << "Booking cancelled.\n"; }
                return;
            }
            temp = temp->next;
        } while (temp != rows[row - 1]);
    }
};

int main() {
    GalaxyMultiplex g;
    int choice, row, seat;
    do {
        cout << "\n--- Galaxy Multiplex Menu ---\n";
        cout << "1. Display Seat Layout\n2. Book Seat\n3. Cancel Booking\n0. Exit\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            g.displaySeats();
            break;
        case 2:
            cout << "Enter Row (1-8) and Seat (1-8): ";
            cin >> row >> seat;
            g.bookSeat(row, seat);
            break;
        case 3:
            cout << "Enter Row (1-8) and Seat (1-8): ";
            cin >> row >> seat;
            g.cancelSeat(row, seat);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);
    return 0;
}
