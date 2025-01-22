#include <iostream>
#include <fstream>
#include <string>
#include <limits> // For numeric_limits
using namespace std;

class gym {
private:
    int id;
    string name;
    string address;
    long long contact; // Changed to long long
    string dateofjoin;
    float weight;
    string exercise;
    float fee; // Added to calculate the fee
    string diet; // Added to manage diet plan

public:
    void setid(int n) { id = n; }
    int getid() { return id; }
    void setname(string n) { name = n; }
    string getname() { return name; }

    void setaddress(string n) { address = n; }
    string getaddress() { return address; }

    void setcontact(long long n) { contact = n; } // Updated
    long long getcontact() { return contact; }    // Updated

    void setdateofjoin(string n) { dateofjoin = n; }
    string getdateofjoin() { return dateofjoin; }

    void setweight(float n) { weight = n; }
    float getweight() { return weight; }

    void setexercise(string n) { exercise = n; }
    string getexercise() { return exercise; }

    void setfee(float n) { fee = n; }
    float getfee() { return fee; }

    void setdiet(string d) { diet = d; }
    string getdiet() { return diet; }

    void calculate_fee() {
        if (weight < 60) {
            fee = 1000;
        } else if (weight >= 60 && weight < 80) {
            fee = 1200;
        } else {
            fee = 1500;
        }
    }

    void diet_plan() {
        if (weight < 60) {
            diet = "High Protein, Low Carb, 5-6 meals a day.";
        } else if (weight >= 60 && weight < 80) {
            diet = "Balanced Diet with Protein, Carbs, and Fats.";
        } else {
            diet = "Calorie Control, High Fiber, and Protein Diet.";
        }
    }

    void printgym() {
        cout << "-----------------------------" << endl;
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact: " << contact << endl;
        cout << "Date of Join: " << dateofjoin << endl;
        cout << "Weight: " << weight << endl;
        cout << "Exercises: " << exercise << endl;
        cout << "Fee: " << fee << endl;
        cout << "Diet Plan: " << diet << endl;
        cout << "------------------------------" << endl;
    }

    string to_string() {
        return std::to_string(id) + "," + name + "," + address + "," + std::to_string(contact) + "," + dateofjoin + "," + 
               std::to_string(weight) + "," + exercise + "," + std::to_string(fee) + "," + diet + "\n";
    }

    void from_string(const string& record) {
        size_t pos = 0;
        size_t idx = 0;
        string token;
        string fields[9];

        string temp = record;
        while ((pos = temp.find(",")) != string::npos && idx < 9) {
            fields[idx++] = temp.substr(0, pos);
            temp.erase(0, pos + 1);
        }
        fields[8] = temp; // Last field

        id = stoi(fields[0]);
        name = fields[1];
        address = fields[2];
        contact = stoll(fields[3]);
        dateofjoin = fields[4];
        weight = stof(fields[5]);
        exercise = fields[6];
        fee = stof(fields[7]);
        diet = fields[8];
    }
};

class Node {
public:
    gym data;
    Node* next;

    Node() {
        next = NULL;
    }
};

class linklist {
public:
    Node* head;

    linklist() {
        head = NULL;
    }

    void save_to_file() {
        ofstream file("gym_records.txt");
        Node* temp = head;
        while (temp) {
            file << temp->data.to_string();
            temp = temp->next;
        }
        file.close();
    }

    void load_from_file() {
        ifstream file("gym_records.txt");
        if (!file.is_open()) return;

        string record;
        while (getline(file, record)) {
            gym g;
            g.from_string(record);

            Node* temp = new Node();
            temp->data = g;

            temp->next = head;
            head = temp;
        }
        file.close();
    }

    bool check(int x) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data.getid() == x)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void Insert_Record(int id, const string& name, const string& address, long long contact, const string& dateofjoin, float weight, const string& exercise) {
        if (check(id)) {
            cout << "Member with this record already exists.\n";
            return;
        }

        Node* temp = new Node();
        temp->data.setid(id);
        temp->data.setname(name);
        temp->data.setaddress(address);
        temp->data.setcontact(contact);
        temp->data.setdateofjoin(dateofjoin);
        temp->data.setweight(weight);
        temp->data.setexercise(exercise);

        temp->data.calculate_fee();
        temp->data.diet_plan();

        temp->next = head;
        head = temp;

        save_to_file();
        cout << "Record inserted successfully.\n";
    }

    void Search_Record(int id) {
        if (!head) {
            cout << "Management System is empty.\n";
            return;
        }

        Node* p = head;
        while (p) {
            if (p->data.getid() == id) {
                p->data.printgym();
                return;
            }
            p = p->next;
        }

        cout << "No such record available.\n";
    }

    void Delete_Record(int id) {
        if (!head) {
            cout << "Management System is empty.\n";
            return;
        }

        Node* temp = head;
        Node* p = NULL;

        if (temp && temp->data.getid() == id) {
            head = temp->next;
            delete temp;
            save_to_file();
            cout << "Record Deleted Successfully.\n";
            return;
        }

        while (temp) {
            if (temp->data.getid() == id) {
                p->next = temp->next;
                delete temp;
                save_to_file();
                cout << "Record Deleted Successfully.\n";
                return;
            }
            p = temp;
            temp = temp->next;
        }

        cout << "ID entered is invalid.\n";
    }

    void Display_Diet_Plan(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->data.getid() == id) {
                cout << "Diet Plan for Member ID " << id << ": " << temp->data.getdiet() << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found.\n";
    }

    void Recalculate_Fee(int id) {
        Node* temp = head;
        while (temp) {
            if (temp->data.getid() == id) {
                temp->data.calculate_fee();
                save_to_file();
                cout << "Updated Fee for Member ID " << id << ": " << temp->data.getfee() << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Member not found.\n";
    }

    void displayrecord() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "No Record Available\n";
        } else {
            while (temp != NULL) {
                temp->data.printgym();
                temp = temp->next;
            }
        }
    }
};

int main() {
    linklist gymList;
    gymList.load_from_file();

    int choice;
    do {
        cout << "\n\n\t\t\t\t*BUILD YOUR BODY STRONG*\n";
        cout << "\t\t\t\t1. Add New Member\n";
        cout << "\t\t\t\t2. Search Member\n";
        cout << "\t\t\t\t3. Delete Member\n";
        cout << "\t\t\t\t4. Display All Records\n";
        cout << "\t\t\t\t5. Show Diet Plan\n";
        cout << "\t\t\t\t6. Recalculate Fee\n";
        cout << "\t\t\t\t7. Exit\n";
        cout << "\t\t\t\tChoose an option: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        int id;
        long long contact;
        string name, address, dateofjoin, exercise;
        float weight;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                while (!(cin >> id) || id <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter a valid positive integer for ID: ";
                }
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Address: ";
                getline(cin, address);
                cout << "Enter Contact: ";
                while (!(cin >> contact) || contact <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter a valid positive integer for Contact: ";
                }
                cout << "Enter Date of Join: ";
                cin.ignore();
                getline(cin, dateofjoin);
                cout << "Enter Weight: ";
                while (!(cin >> weight) || weight <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter a valid positive value for Weight: ";
                }
                cout << "Enter Exercise: ";
                cin.ignore();
                getline(cin, exercise);
                gymList.Insert_Record(id, name, address, contact, dateofjoin, weight, exercise);
                break;

            case 2:
                cout << "Enter ID to search: ";
                while (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid integer ID: ";
                }
                gymList.Search_Record(id);
                break;

            case 3:
                cout << "Enter ID to delete: ";
                while (!(cin >> id) || id <= 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Enter a valid positive integer for ID: ";
                }
                gymList.Delete_Record(id);
                break;

            case 4:
                gymList.displayrecord();
                break;

            case 5:
                cout << "Enter Member ID to show diet plan: ";
                while (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid integer ID: ";
                }
                gymList.Display_Diet_Plan(id);
                break;

            case 6:
                cout << "Enter Member ID to recalculate fee: ";
                while (!(cin >> id)) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid integer ID: ";
                }
                gymList.Recalculate_Fee(id);
                break;

            case 7:
                cout << "Exiting program. Goodbye!\n";
                break;

            default:
                cout << "Invalid choice. Please choose between 1 and 7.\n";
        }
    } while (choice != 7);

    return 0;
}