#include<iostream>
#include<windows.h>    //sleep function
#include<fstream>      //file handling
#include<string>      //required for string func
using namespace std;
class gym
{
private:         //access specifier private
	//class data members
	int id;
	string name;
	string address;
	int contact;
	string dateofjoin;
	float weight;
	string exercise;
public:            //access specifier public
	 // member functions
	void setid(int n)
	{
		id = n;
	}
	int getid()
	{
		return id;
	}
	void setname(string n)
	{
		name = n;
	}
	string getname()
	{
		return name;
	}
	void setaddress(string n)
	{
		address = n;
	}
	string getaddress()
	{
		return address;
	}
	void setcontact(int n)
	{
		contact = n;
	}
	int getcontact()
	{
		return contact;
	}
	void setdateofjoin(string n)
	{
		dateofjoin = n;

	}
	string getdateofjoin()
	{
		return dateofjoin;
	}
	void setweight(float n)
	{
		weight = n;
	}
	float getweight()
	{
		return weight;
	}
	void setexercise(string n)
	{
		exercise = n;
	}
	string getexercise()
	{
		return exercise;
	}
	void printgym()
	{
		cout << "-----------------------------" << endl;
		cout << "Id is " << id << endl;
		cout << "Name is " << name << endl;
		cout << "Address is " << address << endl;
		cout << "Contact is " << contact << endl;
		cout << "Date of join is " << dateofjoin << endl;
		cout << "Weight of member is " << weight << endl;
		cout << "Exercises for this member " << exercise << endl;
		cout << "------------------------------" << endl;


	}


};
class Node
{
public:
	gym data;     //call gym class & create object
	Node* next;
	Node()       // default constructor
	{
		data.setid(0);
		data.setname("a");
		data.setaddress("b");
		data.setcontact(0);
		data.setdateofjoin("s");
		data.setweight(0);
		data.setexercise("d");
		next = NULL;
	}

};
class linklist
{
public:
	Node* head;//from where linklist starts
	linklist() // default constructor
	{
		head = NULL;
	}

	bool check(int x)
	{

		if (head == NULL)
			return false;

		Node* temp;
		temp = head;
		//Traverse the Linked List
		while (temp->next != NULL) {
			if (temp->data.getid() == x)  //if user id == temp id
				return true;
			temp = temp->next;
		}

		return false;
	}
	void Insert_Record(int id, string name, string address, int contact, string dateofjoin, float weight, string exercise) //parametrized constructor
	{


		//Node *temp;
	 // func to check rec already exist or not 
		if (check(id)) {
			cout << "Member with this " << "record Already Exists\n";
			return;
		}

		// Create new Node to Insert Record
		Node* temp = new Node();
		//data ke part me values rkhdin
		temp->data.setid(id);
		temp->data.setname(name);
		temp->data.setaddress(address);
		temp->data.setcontact(contact);
		temp->data.setdateofjoin(dateofjoin);
		temp->data.setweight(weight);
		temp->data.setexercise(exercise);
		//1st time jub code run hoga to temp next null
		temp->next = NULL;

		// Insert at Begin
		if (head == NULL)
		{
			head = temp;
		}
		else if (head->data.getid() >= temp->data.getid())
		{
			temp->next = head;
			head = temp;
		}
		//insert other than begin
		else {
			Node* curr = head;
			while (curr->next != NULL && curr->next->data.getid() < temp->data.getid())
			{
				curr = curr->next;
			}
			// ;

			temp->next = curr->next;
			curr->next = temp;

		}


		cout << "Record Inserted " << "Successfully\n";



	}
	// Function to search record for any
	// member Record with id number
	void Search_Record(int id)
	{
		// if head is NULL
		if (!head) {
			cout << "Managment System  " << "Is Empty\n";
			return;
		}

		// Otherwise
		else {
			Node* p = head;
			while (p != NULL) {
				if (p->data.getid() == id)
				{

					p->data.printgym();

					return;
				}
				p = p->next;
			}

			if (p == NULL)
				cout << "No such Record " << "Available\n";
		}
	}

	//function to update member record with id
	void update(int id, string name, string address, int contact, string dateofjoin, float weight, string exercise)
	{
		if (!head)
		{
			cout << "Managment System  " << "is empty\n";
			return;
		}
		else {

			int found = 0;
			Node* temp;

			temp = head;
			while (temp != NULL)
			{
				if (temp->data.getid() == id)
				{

					temp->data.setid(id);
					temp->data.setname(name);
					temp->data.setaddress(address);
					temp->data.setcontact(contact);
					temp->data.setdateofjoin(dateofjoin);
					temp->data.setweight(weight);
					temp->data.setexercise(exercise);

					found++;
					cout << " Member Updated " << endl;
					return;

				}
				temp = temp->next;
			}
			if (found == 0)
			{
				cout << "Id is invalid" << endl;
			}
		}

	}
	// funtion to delete record with given id
	void Delete_Record(int id)
	{
		int found = 0;
		Node* temp = head;
		Node* p = NULL;

		// Deletion at Begin
		if (temp != NULL && temp->data.getid() == id) {
			head = temp->next;
			delete temp;

			cout << "Record Deleted " << "Successfully\n";
			found++;
			// return 0;
		}

		// Deletion Other than Begin
		else
		{
			while (temp != NULL)
			{
				if (id == temp->data.getid())
				{
					p->next = temp->next;
					delete temp;
					cout << "Record Deleted " << "Successfully\n";
					found++;
					break;

				}
				p = temp;
				temp = temp->next;
			}
		}
		if (found == 0)
		{
			cout << "\n\n Id you entered is invalid.." << endl;
		}

	}
	void dlt_all()     //to delete file or record
	{
		char filename[] = "hooor.txt";   //declare variable & store name of file which want to delete

		if (head == NULL)
		{
			cout << "Managment system " << "Is empty" << " Record in file is deleted " << endl;
			int result = remove(filename);      //remove function is use to delete a file
			//cout<<result;
		}
		else
		{

			Node* temp;
			temp = head;
			while (head != NULL)    //traversing
			{
				head = head->next;
				delete temp;
				temp = head;

			}
			int result = remove(filename);  //remove function is use to delete a file  
			cout << "All record Deleted" << endl;


		}
	}
	//count total members record
	void count()
	{
		Node* temp;
		temp = head;
		int count = 0;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		cout << count << endl;

	}



	// Function to display the member Record
	void displayrecord()
	{
		Node* temp = head;
		//temp is null 
		if (temp == NULL) {
			cout << "No Record " << "Available\n";
		}
		else {


			// Until temp is not NULL
			while (temp != NULL) {
				temp->data.printgym(); "    \t";

				temp = temp->next;
			}
		}

	}
	//function to read data from file
	void Show_Record()
	{
		string myfile;    //declare string data type variable
		ifstream mydata("hooor.txt");
		while (getline(mydata, myfile))
		{
			cout << myfile << endl;
		}

	}
	void Fee()    //function 
	{
		int choice, month, Fee;
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		cout << "\t\t\t\t\tGYM MANAGMENT SYSTEM" << endl;
		cout << "\t\t\t\t\t1. For the Students " << endl;
		cout << "\t\t\t\t\t2. For the Bussiness Man " << endl;
		cout << "\t\t\t\t\t3. For the Employee " << endl;
		cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		cout << "\t\t\t\t\tTell Us Who You Are: ";
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			switch (choice)
			{

			case 1:
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				cout << "\t\t\t\tHow many Months You have to join Gym: ";
				cin >> month;
				Fee = month * 500;
				cout << "\t\t\t\tYour Fee is:" << Fee << endl;
				cout << "\t\t\t\tThanks For Joinning" << endl;
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				break;
			case 2:
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				cout << "\t\t\t\tHow many Months You have to join Gym: ";
				cin >> month;
				Fee = month * 3000;
				cout << "\t\t\t\tYour Fee is:" << Fee << endl;
				cout << "\t\t\t\tThanks For Joinning" << endl;
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				break;
			case 3:
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				cout << "\t\t\t\tHow many Months You have to join Gym: ";
				cin >> month;
				Fee = month * 1500;
				cout << "\t\t\t\tYour Fee is:" << Fee << endl;
				cout << "\t\t\t\tThanks For Joinning" << endl;
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				break;
			default:
				cout << "\t\t\t\tinvaild choice" << endl;

			}
		}
	}
	void dietplan()
	{

		int choice;
		cout << "\n\n\n\n\n\n\n\n\n\n";
		cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		cout << "\t\t\t\t\tGYM MANAGMENT SYSTEM" << endl;
		cout << "\t\t\t\t\t1. For the Teen Age " << endl;
		cout << "\t\t\t\t\t2. For the Adult" << endl;
		cout << "\t\t\t\t\t3. For the Young Childs " << endl;
		cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
		cout << "\t\t\t\t\tTell us Which One You Are: ";
		cin >> choice;
		if (choice == 1 || choice == 2 || choice == 3)
		{
			switch (choice)
			{

			case 1:
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				cout << "\t\t\t\tYour Diet Plan Is Protien diet" << endl;
				cout << "\t\t\t\thalf Cup hot water in Morning " << endl;
				cout << "\t\t\t\tBrawn bread with peanut butter at 10 am" << endl;
				cout << "\t\t\t\tTake 1 apple at 12pm" << endl;
				cout << "\t\t\t\tLunch time: half chapati with BBQ" << endl;
				cout << "\t\t\t\tAfter lunch drink green tea" << endl;
				cout << "\t\t\t\tAt 6 pm take nuts full of hand and eat" << endl;
				cout << "\t\t\t\tDinner time: At 8pm or 9pm Grilled the breast peice and eat" << endl;
				cout << "\t\t\t\tAnd at 10pm sleep" << endl;
				cout << "\t\t\t\tThanks For Joinning" << endl;
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				break;
			case 2:
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				cout << "\t\t\t\tYour Diet Plan Is Keto diet" << endl;
				cout << "\t\t\t\thalf Cup hot water in Morning " << endl;
				cout << "\t\t\t\tBrawn bread with Cucumber at 10 am" << endl;
				cout << "\t\t\t\tTake 1 apple at 12pm" << endl;
				cout << "\t\t\t\tLunch time: half chapati with Saalad" << endl;
				cout << "\t\t\t\tAfter lunch drink green tea" << endl;
				cout << "\t\t\t\tAt 6 pm take nuts full of hand and eat" << endl;
				cout << "\t\t\t\tDinner time: At 8pm or 9pm Grilled the breast peice and eat with salad " << endl;
				cout << "\t\t\t\tAnd at 10pm sleep" << endl;
				cout << "\t\t\t\tThanks For Joinning" << endl;
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;

				break;
			case 3:
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				cout << "\t\t\t\tEAT EVERYTHING YOU WANT BUT EAT LESS CALORIES" << endl;
				cout << "\t\t\t\tThanks For Joinning" << endl;
				cout << "\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
				break;
			}
		}
	}

	void menu()
	{
		system("color D");
		cout << "\n\n";
		cout << "\n\n\t\t\t\t\t\t*BUILD YOUR BODY STRONG*" << endl;
		cout << "\n\n\t\t\t\tReady to change your physique,but cant work out in the gym?\n\n\n" << endl;
		cout << "\t\t\t\t\tWelcome To GYm Managment System!!\n\n\n\n" << endl;
		cout << "\t\t\t\tLoading ";

		char x = 219;   //ascii code

		for (int i = 0; i < 35; i++)
		{
			cout << x;
			if (i < 10)
				Sleep(300);
			if (i >= 10 && i < 20)
				Sleep(150);
			if (i >= 10)
				Sleep(25);
		}

		system("CLS");   //clear the screen

		system("color D");  //text colour

		cout << "\n\n\t\tGYM MEMBERS RECORD MANAGMENT SYSTEM" << endl;
		cout << "\n\n\t\tSign up" << endl;
		string username, password;
		cout << "\n\t\tEnter Username: ";
		cin >> username;
		cout << "\n\t\tEnter Password: ";
		cin >> password;
		cout << "\n\t\tYour id is creating please wait";
		for (int i = 0; i < 5; i++)
		{

			cout << ".";
			Sleep(1000);    //1000=1sec wait
		}
		system("CLS");
		cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tYour id is created successfully";
		Sleep(1000);
		system("CLS");

	start:     //goto call 

		cout << "\n\n\t\tGYM MEMBERS RECORD MANAGMENT SYSTEM" << endl;
		cout << "\n\t\tLogin" << endl;
		string username1, password1;
		cout << "Username: ";
		cin >> username1;
		cout << "Password: ";
		cin >> password1;

		if (username1 == username && password1 == password)
		{
			system("CLS");
			linklist gym;   //create link list class object

			string name, address, exercise, dateofjoin;
			int id, contact;
			float weight;

			// Menu
			while (true) {
				cout << "\n\t\t  Welcome to GYM MEMBERS  Record "
					"Management System\n\n\tPress\n\t1 to "
					"Add members \n\t2 to delete a "
					" Member record\n\t3 to Search a Member "
					"Record\n\t4 to Delete All Record"
					"\n\t5 to view all Members record\n\t6 to Display"
					" record\n\t7 to Update a Member record"
					"\n\t8 to Count Members\n\t9 For the payment\n"
					"\t10 For the Dietplan\n\t11 to Logout\n";

				cout << "\nEnter your Choice\n";
				int Choice;

				cin >> Choice;
				system("CLS");
				if (Choice == 1) {
					ofstream file;//create obj of ofstream

					file.open("hooor.txt", ios::app);// append add new data in file without erasing previous one

					if (!file)    //file not created
					{
						cout << "File not open error" << endl;
					}
					else {
						cin.ignore();

						cout << "Enter Name of Member\n";

						getline(cin, name);    //use to take full name of member

						file << "Name is: " << name << endl;//cout write the data to file

						cout << "Enter id Number of Member\n";

						while (!(cin >> id))//if id is not integer value
						{
							cout << "Must be a number: " << endl;     //explain error
							cin.clear();//clear the error on cin or inputstream

							cin.ignore(100, '\n'); //to ignore anything else on same line or discard previos input
						}
						file << "Id is: " << id << endl;

						//to take full address of member
						cin.ignore();
						cout << "Enter address of Member \n";
						getline(cin, address);

						file << "Adress  is: " << address << endl;
						cout << "Enter contact of Member\n";
						while (!(cin >> contact))
						{
							cout << "Must be a number: " << endl;
							cin.clear();
							cin.ignore(100, '\n');
						}

						file << "Contact  is: " << contact << endl;
						cin.ignore();
						cout << "Enter date of join of Member\n";
						getline(cin, dateofjoin);

						file << "Joinning date is: " << dateofjoin << endl;

						cout << "Enter Weight of Member\n";
						while (!(cin >> weight))
						{
							cout << "Must be a number: " << endl;
							cin.clear();
							cin.ignore(100, '\n');
						}

						file << "Weight  is: " << weight << endl;
						cin.ignore();
						cout << "Enter  Exercise  name for this Member\n";
						getline(cin, exercise);

						file << "Exercise is: " << exercise << endl;
						gym.Insert_Record(id, name, address, contact, dateofjoin, weight, exercise);
						Sleep(3000);
						system("CLS");
					}

				}
				else if (Choice == 2) {
					cout << "Enter id  of Member whose "
						"record is to be deleted\n";
					while (!(cin >> id))
					{
						//explain the error
						cout << "Must be a number: " << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}

					gym.Delete_Record(id);
					Sleep(3000);
					system("CLS");

				}
				else if (Choice == 3) {
					cout << "Enter id  of Member whose "
						"record you want to Search\n";
					while (!(cin >> id))
					{
						cout << "Must be a number: " << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
					// int id;
			// cin >> id;
					gym.Search_Record(id);
					Sleep(3000);     //3 sec wait
					system("CLS");
				}
				else if (Choice == 4)
				{
					gym.dlt_all();
					//	cout<<"All record deleted\n";
					Sleep(3000);
					system("CLS");
				}
				else if (Choice == 5) {
					gym.Show_Record();
					Sleep(6000);
					system("CLS");
				}
				else if (Choice == 6) {
					gym.displayrecord();
					Sleep(6000);
					system("CLS");
				}
				else if (Choice == 7)
				{
					cout << "Enter id of Member whose"
						" record you want to be updated\n";
					while (!(cin >> id))
					{
						cout << "Must be a number: " << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}
					cin.ignore();
					cout << "Enter Name of Member\n";
					getline(cin, name);

					cout << "Enter address of Member \n";
					getline(cin, address);

					cout << "Enter contact of Member\n";
					while (!(cin >> contact))
					{
						cout << "Must be a number: " << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}

					cin.ignore();
					cout << "Enter date of join of Member\n";
					getline(cin, dateofjoin);

					cout << "Enter Weight of Member\n";
					while (!(cin >> weight))
					{
						cout << "Must be a number: " << endl;
						cin.clear();
						cin.ignore(100, '\n');
					}

					cin.ignore();
					cout << "Enter  Exercise  name for this Member\n";
					getline(cin, exercise);

					gym.update(id, name, address, contact, dateofjoin, weight, exercise);
					Sleep(3000);   //3 sec wait
					system("CLS");
				}
				else if (Choice == 8)  //count function
				{
					cout << "total memebrs in gym are\n";
					gym.count();
					Sleep(3000);
					system("CLS");
				}
				else if (Choice == 9)    //fee function
				{
					gym.Fee();
					Sleep(3000);
					system("CLS");

				}
				else if (Choice == 10)      // diet plan function
				{
					gym.dietplan();
					Sleep(3000);
					system("CLS");

				}

				else if (Choice == 11) {
					cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
					cout << "\t\t\t\t\t GYm Managment System!!\n\n ";
					cout << "\t\t\t\t\tLoaging out ";
					char x = 219;
					for (int i = 0; i < 35; i++)
					{
						cout << x;
						if (i < 10)
							Sleep(300);
						if (i >= 10 && i < 20)
							Sleep(150);
						if (i >= 10)
							Sleep(25);
					}


					system("CLS");

					goto start;     	//control of the program move to start

				}

				else {
					cout << "Invalid Choice "     //wrong choice
						<< "Try Again\n";
					Sleep(2000);
					system("CLS");
				}
			}


		}
		else if (username1 != username)
		{
			cout << "Your username is incorrect" << endl;
			Sleep(2000);
			system("CLS");
			goto start;    	//control of the program move to start
		}
		else if (password1 != password)
		{
			cout << "Your password is incorrect" << endl;
			Sleep(2000);
			system("CLS");
			//control of the program move to start
			goto start;
		}

	}

};


int main()
{
	linklist obj;    //linklist class obj
	obj.menu();     //call the menu through obj
	return 0;

}

