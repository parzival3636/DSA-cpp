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