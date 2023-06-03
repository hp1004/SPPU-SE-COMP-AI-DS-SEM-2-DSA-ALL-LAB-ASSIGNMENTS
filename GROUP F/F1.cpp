/*
🔘 PROBLEM STATEMENT:- 
Department maintains a student information. The file contains
roll number, name, division and address. Allow user to add,
delete information of student. Display information of particular
employee. If record of student does not exist an appropriate
message is displayed. If it is, then the system displays the student
details. Use sequential file to maintain the data
*/ 

/*
#️⃣Quick Revision Notes:-
🔹Sequential Files:- Sequential files refer to a method of organizing and storing data in a linear or sequential manner.

1. Data is not store in specific order.
2. In sequential files elements are accessed and precessed in the order they are stored.

EX :- Bill of shopping. 
*/ 

#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;

void addStudent(){
    ofstream f("db.txt", ios::app);

    string roll_no, name, div, address;

    cout<<"--- ADD STUDENT IN DATABASE ---"<<endl;

    cout<<"Enter Student Roll No : ";
    cin>>roll_no;
    cout<<"\nEnter Student Name : ";
    cin>>name;
    cout<<"\nEnter Sudent Division : ";
    cin>>div;
    cout<<"\nEnter Student Address : ";
    cin>>address;
    cout<<endl;

    f<<left<<setw(20)<<roll_no<<setw(20)<<name <<setw(20)<< div <<setw(20)<<address<<endl;
    cout<<"Student Added Successfully.\n";
    f.close();

}

void deleteStudent(){
    ifstream f("db.txt");
    string line;
    string roll_no;
    cout<<"Enter Student Roll No To Delet : ";
    cin>>roll_no;
    string fileData;

    while(getline(f,line)){
        if(line.find(roll_no) == string::npos){
            fileData+=line;
            fileData+="\n";
        }
    }
    f.close();

    ofstream f1("db.txt", ios::out);
    f1<<fileData;
    f1.close();
}

void searchStudent(){
    ifstream f("db.txt");
    string line;
    string roll_no;
    cout<<"Enter Student Roll No To Search : ";
    cin>>roll_no;

    bool found = false;

    while(getline(f,line)){
        if(line.find(roll_no) != string::npos){
            cout<<"Student Details: "<<endl;
            cout<<"\n"<<line <<endl;
            found =true;
            break;
        }
    }
    f.close();

    if(!found){
        cout<<"Sorry, Not found"<<endl;
    }

}

void displayData(){
    ifstream f("db.txt");
    string line;
    cout<<"\nDisplaying Data :- "<<endl;
    while(getline(f,line)){
        cout<<"\n"<<line<<endl;
    }
    f.close();
}

int main(){

    ofstream f("db.txt", ios::out);
    f<<left<<setw(20) << "Roll No" << setw(20) << "Name" << setw(20) << "Divison" << setw(20) <<"Address"<<endl;
    f.close();

    int choice;
    while(choice != -1){
        cout<<"\n--------- M E N U -----------"<<endl;
        cout<<"1. Add Student."; 
        cout<<"\n2. Delete Student.";
        cout<<"\n3. Search Student. ";
        cout<<"\n4. Display Data.";
        cout<<"\n5. Exit. "<<endl;
        cout<<"-------------------------------"<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        cout<<endl;

        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                displayData();
                break;
            case 5:
                return 0;
                break;
            default:
                cout<<"Please ReEnter Your Choice: ";
                break;
        }

    }
}