#include <bits/stdc++.h>
#include<conio.h>
#include "windows.h"
int ck=0;
using namespace std;
int menu ();
void welcome();
void gotoxy (int ,int );
class student
{
    string name;
    string address;s
    string faculty;
    string phone_no;
public:
    void addStudents();
    void newStudents();
    void displayStudents();
    void viewStudents();
    void searchStudents(string );
    void deleteStudents(string );
    void updateStudents(string );
};
void student :: addStudents()
{
    system("cls");
    ofstream file;
    file.open("source.DAT",ios::app|ios::binary);
    newStudents();
    file.write((char *)this,sizeof(*this));
    file.close();
}
void student :: newStudents()
{
    cout<<"Name = ";
    //cin.ignore();
    getline(cin,name);
    cout<<"Address= ";
   // cin.ignore();
    getline(cin,address);
    cout<<"faculty = ";
   // cin.ignore();
    getline(cin,faculty);
    cout<<"phone_no = ";
   // cin.ignore();
    getline(cin,phone_no);
}
void student :: displayStudents()
{
    cout<<setw(20)<<name<<" ";
    cout<<setw(20)<<address<<" ";
    cout<<setw(20)<<faculty<<" ";
    cout<<setw(20)<<phone_no<<endl;
}
void student :: viewStudents()
{
    ifstream file;
    file.open("source.DAT",ios::in);
    system("cls");
    if (!file.is_open())
        cout<<"failed"<<endl;
    else
    {
        cout<<setw(20)<<"NAME"<<setw(22)<<"ADDRESS"<<setw(22)<<"FACULTY"<<setw(22)<<"PHONE NUMBER"<<endl;
        while (file.read((char *)this,sizeof(*this)))
        {
        displayStudents();
        }
        file.close();
    }

}
void student::searchStudents(string p)
{
    system("cls");
    ck=0;
    ifstream file;
    file.open("source.DAT",ios::in);
    file.read((char *)this,sizeof(*this));
    cout<<setw(20)<<"NAME"<<setw(22)<<"ADDRESS"<<setw(22)<<"FACULTY"<<setw(22)<<"PHONE NUMBER"<<endl;
    while (file.eof()==0)
    {
        if (!(name.compare(p)))
        {
           displayStudents();
           ck=1;
        }
      file.read((char *)this,sizeof(*this));
    }
    if (ck==0)
        cout<<"Match Not Found"<<endl;
    file.close();
}
void student::deleteStudents(string p)
{
    system("cls");
    ck=0;
    ifstream inf;
    ofstream outf;
    inf.open("source.DAT");
    outf.open("temp.DAT");
    if (!inf.is_open())
        cout<<"error while opening the students and deleting students file "<<endl;
    else
    {
       inf.read((char *)this,sizeof(*this));
        while (inf.eof()==0)
       {
         if (name.compare(p))
         {
             outf.write((char *)this,sizeof(*this));
         }
         else
            ck=1;

        inf.read((char *)this,sizeof(*this));
       }
     inf.close();
     outf.close();
     remove("source.DAT");
     rename("temp.DAT","source.DAT");
    }
    if (ck==0)
        cout<<"the name entered is not found"<<endl;
    else
       cout<<"Deletion performed successfully"<<endl;
}
void student::updateStudents(string p)
{
    system("cls");
    ck=0;
    fstream file;
    file.open("source.DAT",ios::in|ios::out|ios::ate);
    file.seekg(0);
    while (file.read((char *)this,sizeof(*this)))
    {
        if (!(name.compare(p)))
        {
            ck=1;
            cout<<setw(20)<<"NAME"<<setw(22)<<"ADDRESS"<<setw(22)<<"FACULTY"<<setw(22)<<"PHONE NUMBER"<<endl;
            displayStudents();
            newStudents();
            file.seekp(file.tellp()-sizeof(*this));
            file.write((char *)this,sizeof(*this));
        }
    }
    if (ck==0)
        cout<<"Student not found\n";
    file.close();
}
void welcome()
{
    gotoxy(30,5);
    cout<<"---------------------------------------------------------------"<<endl;
    gotoxy(30,6);
    cout<<"|                 WELCOME TO WRC CANTEEN                      |"<<endl;
    gotoxy(30,7);
    cout<<"---------------------------------------------------------------"<<endl;
    Sleep(1000);
    system("cls");

}
int menu()
{
    int choice;
    fflush(stdin);
    gotoxy(30,7);
    cout<<"---------------------------------------------------------------"<<endl;
    gotoxy(30,8);
    cout<<"|                   ENTER THE OPTION                          |"<<endl;
    gotoxy(30,9);
    cout<<"---------------------------------------------------------------"<<endl;
    gotoxy(50,10);
    cout<<"1. Add new student"<<endl;
    gotoxy(50,11);
    cout<<"2. View all students"<<endl;
    gotoxy(50,12);
    cout<<"3. Search for the students"<<endl;
    gotoxy(50,13);
    cout<<"4. Delete a student"<<endl;
    gotoxy(50,14);
    cout<<"5. Update details about student"<<endl;
    gotoxy(50,15);
    cout<<"6. exit"<<endl;
    gotoxy(30,16);
    cout<<"enter your choice here"<<endl;
    gotoxy(30,17);
    scanf("%d",&choice);
    return (choice);
}
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    student s;
    string name1;
    welcome();
    while (1)
    {
        fflush(stdin);
        system("cls");
        switch(menu())
        {
          case 1:
            s.addStudents();
            cout<<"student is added successfully"<<endl;
            break;
          case 2:
            s.viewStudents();
            break;
          case 3:
              cout<<"enter the name you search for"<<endl;
              cin.ignore();
              getline(cin,name1);
              s.searchStudents(name1);
              break;
          case 4:
              cout<<"enter the name you delete for"<<endl;
              cin.ignore();
              getline(cin,name1);
              s.deleteStudents(name1);
              break;
          case 5:
            cout<<"enter the name you update for"<<endl;
            cin.ignore();
            getline(cin,name1);
            s.updateStudents(name1);
            break;
          case 6:
            exit(1);
            break;
          default :
            cout<<"Invalid choice"<<endl;
        }
        cout<<endl;
        cout<<"Press any key to relaod menu"<<endl;
        getch();
    }
    return 0;
}
