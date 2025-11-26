
# Assignment 26 - Patient Queue Management and Doctor Assignment in Medical Clinic

## Managing Patient Check-ins and Doctor Assignments Using Queues and Linked Lists

This program simulates a medical clinic’s patient tracking system by maintaining a waiting queue of patients and assigning them to doctors on a first-come, first-served basis. It uses linked lists to implement dynamic queues for patients and maintains a linked list of doctors.

### Operations Implemented
- **Add Patient to Queue:** New patients are enqueued into the waiting list in arrival order.  
- **Add Doctor:** Doctors are added to the clinic's available doctor list.  
- **Assign Patient to Doctor:** The patient at the front of the queue is assigned to the first available doctor.  
- **Complete Patient Treatment:** Mark a doctor as available by completing the treatment of their current patient.  
- **Display Waiting Queue:** Show all patients currently waiting.  
- **Display Doctors Status:** Show the status of doctors and their currently assigned patients.

### Key Concept: Queue and Linked Lists for Dynamic Management

The waiting queue of patients is implemented as a singly linked list where patients are enqueued at the rear and dequeued from the front, preserving order. Doctors are maintained in a linked list with pointers to their current patient, enabling easy assignment and status tracking.

### Time Complexity
- **Add Patient & Add Doctor:** $$O(n)$$ for inserting at the end of linked lists, where $$n$$ is current list length.  
- **Assign Patient to Doctor:** $$O(m)$$ to find the first available doctor, $$m$$ is the number of doctors.  
- **Complete Treatment:** $$O(m)$$ to locate doctor by ID and free patient.  
- **Display:** $$O(n)$$ for patients and $$O(m)$$ for doctors.

### Example Scenario

- Patient A checks in → Enqueued  
- Patient B checks in → Enqueued  
- Doctor X added → Available  
- Doctor Y added → Available  
- Assign Patient to Doctor → Patient A assigned to Doctor X  
- Assign Patient to Doctor → Patient B assigned to Doctor Y  
- Complete Patient Treatment for Doctor X → Doctor X becomes available  
- Assign next patient if available

### Applications
- Hospital or clinic patient management systems ensuring fair and efficient doctor assignments.  
- Queue management in customer service centers or any first-come-first-served setup.  
- Modeling and simulation of real-world service systems with multiple servers and queueing.  
- Teaching linked list, queue dynamics, and resource allocation algorithms in computer science education.  





```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct patient {
    int id;
    char name[100];
    int age;
    char problem[100];
    struct patient* next;
} patient;

typedef struct doctor {
    int id;
    char name[100];
    char specialization[100];
    patient* currentPatient;
    struct doctor* next;
} doctor;

patient* createPatient(int id, const char* name, int age, const char* problem) {
    patient* newPatient = (patient*)malloc(sizeof(patient));
    if (!newPatient) {
        cout << "Memory allocation failed!\n";
        exit(-1);
    }
    newPatient->id = id;
    strncpy(newPatient->name, name, 99);
    newPatient->name[99] = '\0';
    newPatient->age = age;
    strncpy(newPatient->problem, problem, 99);
    newPatient->problem[99] = '\0';
    newPatient->next = nullptr;
    return newPatient;
}

doctor* createDoctor(int id, const char* name, const char* specialization) {
    doctor* newDoctor = (doctor*)malloc(sizeof(doctor));
    if (!newDoctor) {
        cout << "Memory allocation failed!\n";
        exit(-1);
    }
    newDoctor->id = id;
    strncpy(newDoctor->name, name, 99);
    newDoctor->name[99] = '\0';
    strncpy(newDoctor->specialization, specialization, 99);
    newDoctor->specialization[99] = '\0';
    newDoctor->currentPatient = nullptr;
    newDoctor->next = nullptr;
    return newDoctor;
}

void addPatientToQueue(patient* &queue, patient* newPatient) {
    if (!queue) {
        queue = newPatient;
    } else {
        patient* temp = queue;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newPatient;
    }
    cout << "Patient " << newPatient->name << " added to waiting queue.\n";
}

void addDoctor(doctor* &doctors, doctor* newDoctor) {
    if (!doctors) {
        doctors = newDoctor;
    } else {
        doctor* temp = doctors;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newDoctor;
    }
    cout << "Doctor " << newDoctor->name << " added to clinic.\n";
}

patient* removePatientFromQueue(patient* &queue) {
    if (!queue) {
        return nullptr;
    }
    patient* temp = queue;
    queue = queue->next;
    temp->next = nullptr;
    return temp;
}

void assignPatientToDoctor(doctor* doctors, patient* &queue) {
    if (!queue) {
        cout << "No patients in waiting queue!\n";
        return;
    }
    
    doctor* temp = doctors;
    while (temp) {
        if (!temp->currentPatient) {
            patient* nextPatient = removePatientFromQueue(queue);
            if (nextPatient) {
                temp->currentPatient = nextPatient;
                cout << "Assigned patient " << nextPatient->name 
                     << " to Dr. " << temp->name << " (" << temp->specialization << ")\n";
                return;
            }
        }
        temp = temp->next;
    }
    cout << "All doctors are currently busy!\n";
}

void completeCurrentPatient(doctor* doctors, int doctorId) {
    doctor* temp = doctors;
    while (temp) {
        if (temp->id == doctorId && temp->currentPatient) {
            cout << "Dr. " << temp->name << " completed treatment of patient " 
                 << temp->currentPatient->name << "\n";
            free(temp->currentPatient);
            temp->currentPatient = nullptr;
            return;
        }
        temp = temp->next;
    }
    cout << "Doctor not found or no current patient!\n";
}

void displayWaitingQueue(patient* queue) {
    if (!queue) {
        cout << "No patients in waiting queue.\n";
        return;
    }
    
    cout << "\n====== Waiting Queue ======\n";
    patient* temp = queue;
    int position = 1;
    while (temp) {
        cout << position << ". " << temp->name << " (ID: " << temp->id 
             << ", Age: " << temp->age << ", Problem: " << temp->problem << ")\n";
        temp = temp->next;
        position++;
    }
}

void displayDoctorsStatus(doctor* doctors) {
    if (!doctors) {
        cout << "No doctors available.\n";
        return;
    }
    
    cout << "\n====== Doctors Status ======\n";
    doctor* temp = doctors;
    while (temp) {
        cout << "Dr. " << temp->name << " (" << temp->specialization << ") - ";
        if (temp->currentPatient) {
            cout << "Treating: " << temp->currentPatient->name << "\n";
        } else {
            cout << "Available\n";
        }
        temp = temp->next;
    }
}

void freePatients(patient* &queue) {
    while (queue) {
        patient* temp = queue;
        queue = queue->next;
        free(temp);
    }
}

void freeDoctors(doctor* &doctors) {
    while (doctors) {
        if (doctors->currentPatient) {
            free(doctors->currentPatient);
        }
        doctor* temp = doctors;
        doctors = doctors->next;
        free(temp);
    }
}

int main() {
    patient* waitingQueue = nullptr;
    doctor* doctors = nullptr;
    int patientIdCounter = 1;
    int doctorIdCounter = 1;
    int choice;
    
    do {
        cout << "\n====== Medical Clinic Management System ======\n";
        cout << "1) Add Patient to Queue\n";
        cout << "2) Add Doctor\n";
        cout << "3) Assign Patient to Doctor\n";
        cout << "4) Complete Patient Treatment\n";
        cout << "5) Display Waiting Queue\n";
        cout << "6) Display Doctors Status\n";
        cout << "0) Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                char name[100], problem[100];
                int age;
                cout << "Enter patient name: ";
                cin.ignore();
                cin.getline(name, 100);
                cout << "Enter patient age: ";
                cin >> age;
                cout << "Enter medical problem: ";
                cin.ignore();
                cin.getline(problem, 100);
                
                patient* newPatient = createPatient(patientIdCounter++, name, age, problem);
                addPatientToQueue(waitingQueue, newPatient);
                break;
            }
            case 2: {
                char name[100], specialization[100];
                cout << "Enter doctor name: ";
                cin.ignore();
                cin.getline(name, 100);
                cout << "Enter specialization: ";
                cin.getline(specialization, 100);
                
                doctor* newDoctor = createDoctor(doctorIdCounter++, name, specialization);
                addDoctor(doctors, newDoctor);
                break;
            }
            case 3:
                assignPatientToDoctor(doctors, waitingQueue);
                break;
            case 4: {
                int doctorId;
                cout << "Enter doctor ID to complete current patient: ";
                cin >> doctorId;
                completeCurrentPatient(doctors, doctorId);
                break;
            }
            case 5:
                displayWaitingQueue(waitingQueue);
                break;
            case 6:
                displayDoctorsStatus(doctors);
                break;
            case 0:
                cout << "Exiting program...\n";
                freePatients(waitingQueue);
                freeDoctors(doctors);
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);
    
    return 0;
}
```
<img width="472" height="740" alt="image" src="https://github.com/user-attachments/assets/c161f05d-f7fd-4ab5-949b-6d73b62b6580" />
<img width="478" height="846" alt="image" src="https://github.com/user-attachments/assets/42299a40-f5bb-42a7-b7a2-577eecebd979" />
<img width="532" height="640" alt="image" src="https://github.com/user-attachments/assets/08e91ab7-9202-4893-817f-d59d1a97d131" />
