#include <iostream>
#include "node.h"
#include "student.h"

//imports ^^

/*
  Written by Ned F.
  Linked Lists
  Asks and Records a student's name, id and gpa
  Students are stored based on their id, from lowest to highest
  Program has a add, delete, print and average function
  Average fucntion finds the mean gpa's of all students stored 
  Start date: 12/4/19
 */

using namespace std;

node* head = NULL;

void addstudent(char* name, int id, float gpa) {
  //method to add a student
  //method also adds students based on id number (not implemented)

  //node* head = NULL;
  node* current = head;  
  int userid;
  char* username = new char[15];
  float usergpa;
  student* newstudent = new student();
  //asks and then records name, id and gpa
  cout << "enter name:" << endl; 
  cin >> username;
  cin.get();
  name = username;
  newstudent->setname(name);

  cout << "enter id:" << endl;
  cin >> userid;
  cin.get();
  id = userid;
  newstudent->setid(id);

  cout << "enter gpa:" << endl;
  cin >> usergpa;
  cin.get();
  gpa = usergpa;
  newstudent->setgpa(gpa);

    
  if (current == NULL) {
    head = new node();
    //head = new student();
    head->setstudent(newstudent);
  }
  else {
    while (current->getnext() != NULL) {
      current = current->getnext();
    }
    current->setnext(new node());
    //current->setnext(new student());
    current->getnext()->setstudent(newstudent);
  }
  
}

void deletestudent() { //method to delete a student (not implemented)
  cout << "which student do you want to remove? (enter id)" << endl;
    
}

void printstudent(node* next) { //method to print all students
  //  node* head = NULL;
  //  cout << "1st if statement" << endl;
  if (next == head) {
    cout << "list: ";
  }
  // cout << "2nd if statement" << endl;
  if (next != NULL) {
    cout << next->getstudent()->getname() << " ";
    cout << next->getstudent()->getid() << " ";
    cout << next->getstudent()->getgpa() << " ";
    cout << endl;
    printstudent(next->getnext());
  } 
}

void averagegpa(){ // (not implemented)
 //method to average the gpa's of all recorded students


  

}

int main() {
  bool running = true; //variable for program status
  char user1; //variable for user input
  int id; //varaible for id
  char* name = new char[15]; //variable for student name
  float gpa;
  
  while (running == true) {
    cout << "test" << endl;
    cin >> user1; //reads in user input
    cin.get();
    
    if (user1 == 'q'){ //exits the program
      running = false;
    }
    if (user1 == 'a'){//adds a student
      addstudent(name, id, gpa);
    }
    if (user1 == 'd'){ //deletes a student
      // deletestudent();
    }
    if (user1 == 'p'){ //prints all students
      // cout << "Before method call" << endl;
      printstudent(head);
    }
    
  }
  return 0;
}
