# Assignment13

# Assignment – Appointment Scheduling System Using Linked List

## Managing Single-Day Appointment Schedule with Linked List

This program implements an appointment scheduling system for a single day using a singly linked list. Each node in the list represents one appointment slot with its start time, end time, and duration. The schedule is managed within fixed working hours, and each appointment must respect predefined minimum and maximum duration limits.

### Operations Implemented
- **Display Available Time Slots:**  
  The program scans through the working day from the global start time to end time and compares it with the existing appointments stored in the linked list. All gaps between consecutive appointments that satisfy the minimum duration requirement are shown as available slots for new bookings.

- **Book a New Appointment:**  
  The user specifies a desired start and end time (or duration). The program validates that:
  - The appointment lies within the working day’s start and end times.  
  - The duration is between the minimum and maximum allowed limits.  
  - The requested interval does not overlap with any existing appointment in the linked list.  
  On success, a new node is created and inserted into the list at the correct chronological position.

- **Cancel an Existing Appointment:**  
  The user inputs the exact start (and possibly end) time of an existing appointment. The program validates:
  - That a matching appointment exists in the list.  
  - That the time interval matches the stored appointment slot.  
  If valid, the corresponding node is removed from the linked list by updating pointers, and the time becomes available again.

- **Sort Appointment List by Time (Data Swap Version):**  
  The program can sort all existing appointment nodes in ascending order of their start times by using a simple sorting algorithm (like bubble sort) that swaps the data fields (start time, end time, duration) within nodes while keeping the node links unchanged.

- **Sort Appointment List Using Pointer Manipulation (Without Swapping Data):**  
  This version rearranges the appointment list only by changing node pointers rather than swapping the internal data. Sorting is done by:
  - Detaching and re-inserting nodes in correct order, or  
  - Using a pointer-based sorting algorithm (like insertion sort on linked list) that relinks nodes into sorted order based on their start time.  
  This emphasizes linked-list pointer manipulation and preserves data encapsulation inside each node.

### Key Concepts: Time Slots and Linked List Scheduling
- **Working Day Bounds:** Global start and end times define the total scheduling window (for example, 9:00 to 17:00).  
- **Duration Constraints:** Each appointment must respect the allowed minimum and maximum duration (for instance, 15 to 60 minutes).  
- **Non-Overlapping Intervals:** Appointments are stored so that time intervals do not overlap; validation ensures correctness before insertion.  
- **Linked List Representation:** Each appointment node contains fields like start time, end time, and duration, with a `next` pointer linking to the following appointment in chronological order.

### Time Complexity
- **Display Available Slots:** \(O(n)\), scanning existing appointments once, where \(n\) is the number of booked appointments.  
- **Book Appointment:** \(O(n)\) for validation and finding correct insertion position in sorted order.  
- **Cancel Appointment:** \(O(n)\) to locate and remove the relevant node.  
- **Sort by Time (Data Swap):** Typically \(O(n^2)\) using simple comparison-based algorithms.  
- **Sort by Pointer Manipulation:** Also \(O(n^2)\) with basic insertion/bubble-style algorithms, though more pointer-intensive.

### Example Scenario
| Setting                      | Description                                      |
|------------------------------|--------------------------------------------------|
| Working hours                | 09:00 to 17:00                                  |
| Min/Max duration             | 30 min (min), 120 min (max)                     |
| Booked appointments          | 09:00–10:00, 11:30–12:00, 15:00–16:00           |
| Available slots (>= 30 min)  | 10:00–11:30, 12:00–15:00, 16:00–17:00           |
| Cancel                       | 11:30–12:00 removed from list                   |
| Sorted (by pointers)         | All nodes relinked in ascending start-time order |

### Applications
- Real-world appointment systems for clinics, salons, or consultation services.  
- Demonstration of linked list usage for time-interval management.  
- Practice of pointer-based sorting and interval validation in C++ data structure assignments.


## Code
```cpp
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

typedef struct Appointment_lac
{
    int start_lac;
    int end_lac;
    bool booked_lac;
    Appointment_lac *next_lac;
} Appointment_lac;

void displayTime_lac(int time_lac)
{
    int hour_lac = time_lac / 60;
    int min_lac = time_lac % 60;
    string period_lac;

    if (hour_lac >= 12)
    {
        period_lac = "PM";
    }
    else
    {
        period_lac = "AM";
    }

    if (hour_lac == 0)
    {
        hour_lac = 12;
    }
    else if (hour_lac > 12)
    {
        hour_lac = hour_lac - 12;
    }

    cout << setw(2) << setfill('0') << hour_lac << ":" 
         << setw(2) << setfill('0') << min_lac << " " << period_lac;
}

Appointment_lac* createSchedule_lac(int startMin_lac, int endMin_lac)
{
    Appointment_lac *head_lac = NULL;
    Appointment_lac *prev_lac = NULL;

    for (int curr_lac = startMin_lac ; curr_lac + 60 <= endMin_lac ; curr_lac = curr_lac + 60)
    {
        Appointment_lac *node_lac = new Appointment_lac;
        node_lac->start_lac = curr_lac;
        node_lac->end_lac  = curr_lac + 60;
        node_lac->booked_lac = false;
        node_lac->next_lac = NULL;

        if (head_lac == NULL)
        {
            head_lac = node_lac;
        }
        else
        {
            prev_lac->next_lac = node_lac;
        }

        prev_lac = node_lac;
    }

    return head_lac;
}

void displaySlots_lac(Appointment_lac *head_lac)
{
    Appointment_lac *temp_lac = head_lac;
    int index_lac = 1;

    cout << "\n========== TODAY'S AVAILABLE SLOTS ==========\n";

    while (temp_lac != NULL)
    {
        cout << index_lac << ") ";
        displayTime_lac(temp_lac->start_lac);
        cout << " - ";
        displayTime_lac(temp_lac->end_lac);

        if (temp_lac->booked_lac == true)
        {
            cout << "  [Booked]\n";
        }
        else
        {
            cout << "  [Available]\n";
        }

        temp_lac = temp_lac->next_lac;
        index_lac = index_lac + 1;
    }
}

void bookAppointment_lac(Appointment_lac *head_lac)
{
    displaySlots_lac(head_lac);

    int hr_lac, min_lac;
    string period_lac;

    cout << "\nEnter Start Time (HH MM): ";
    cin >> hr_lac >> min_lac;

    cout << "Enter AM/PM: ";
    cin >> period_lac;

    for (char &c_lac : period_lac)
    {
        c_lac = toupper(c_lac);
    }

    if (period_lac == "PM" && hr_lac != 12)
    {
        hr_lac = hr_lac + 12;
    }
    else if (period_lac == "AM" && hr_lac == 12)
    {
        hr_lac = 0;
    }

    int st_lac = (hr_lac * 60) + min_lac;
    Appointment_lac *temp_lac = head_lac;

    while (temp_lac != NULL)
    {
        if (temp_lac->start_lac == st_lac)
        {
            if (temp_lac->booked_lac == true)
            {
                cout << "\nSlot Already Booked!\n";
            }
            else
            {
                temp_lac->booked_lac = true;
                cout << "\nAppointment Successfully Booked!\n";
            }
            return;
        }

        temp_lac = temp_lac->next_lac;
    }

    cout << "\nNo such slot exists.\n";
}

void cancelAppointment_lac(Appointment_lac *head_lac)
{
    displaySlots_lac(head_lac);

    int hr_lac, min_lac;
    string period_lac;

    cout << "\nEnter Start Time to Cancel (HH MM): ";
    cin >> hr_lac >> min_lac;

    cout << "Enter AM/PM: ";
    cin >> period_lac;

    for (char &c_lac : period_lac)
    {
        c_lac = toupper(c_lac);
    }

    if (period_lac == "PM" && hr_lac != 12)
    {
        hr_lac = hr_lac + 12;
    }
    else if (period_lac == "AM" && hr_lac == 12)
    {
        hr_lac = 0;
    }

    int st_lac = (hr_lac * 60) + min_lac;
    Appointment_lac *temp_lac = head_lac;

    while (temp_lac != NULL)
    {
        if (temp_lac->start_lac == st_lac)
        {
            if (temp_lac->booked_lac == false)
            {
                cout << "\nSlot Isn't Booked!\n";
            }
            else
            {
                temp_lac->booked_lac = false;
                cout << "\nAppointment Cancelled Successfully!\n";
            }
            return;
        }

        temp_lac = temp_lac->next_lac;
    }

    cout << "\nInvalid Slot.\n";
}

int main()
{
    int start_lac = 9 * 60;
    int end_lac   = 17 * 60;

    Appointment_lac *head_lac = createSchedule_lac(start_lac, end_lac);
    int choice_lac = -1;

    while (choice_lac != 0)
    {
        cout << "\n================ MENU ================\n";
        cout << "1) Display Available Slots\n";
        cout << "2) Book Appointment\n";
        cout << "3) Cancel Appointment\n";
        cout << "0) Exit\n";
        cout << "Enter Choice: ";
        cin >> choice_lac;

        if (choice_lac == 1)
        {
            displaySlots_lac(head_lac);
        }
        else if (choice_lac == 2)
        {
            bookAppointment_lac(head_lac);
        }
        else if (choice_lac == 3)
        {
            cancelAppointment_lac(head_lac);
        }
        else if (choice_lac == 0)
        {
            cout << "\nExiting Program...\n";
        }
        else
        {
            cout << "\nInvalid Input\n";
        }
    }

    return 0;
}
```

## Output:
<img width="465" height="586" alt="image" src="https://github.com/user-attachments/assets/2b11b6cd-7650-4233-9129-e8389482f2bc" />
<img width="386" height="585" alt="image" src="https://github.com/user-attachments/assets/973f86d9-fc5b-4a14-8247-b6c06b82a1e2" />
