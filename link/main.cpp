#include <iostream>
#include <iomanip>
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

Node* head = NULL;

void addstudent(char* name, int id, float gpa) {
  //method to add a student
  //method also adds students based on id number (not implemented)

  //node* head = NULL;
  Node* current = head;  
  int userid;
  char* username = new char[15];
  float usergpa;
  Student* newstudent = new Student();
  //asks and then records name, id and gpa
  cout << "enter name:" << endl; 
  cin >> username;
  cin.get();
  name = username;
  newstudent->setName(name);

  cout << "enter id:" << endl;
  cin >> userid;
  cin.get();
  id = userid;
  newstudent->setId(id);

  cout << "enter gpa:" << endl;
  cin >> usergpa;
  cin.get();
  gpa = usergpa;
  newstudent->setGpa(gpa);

    
  if (current == NULL) {
    head = new Node();
    //head = new student();
    head->setStudent(newstudent);
  }
  else {
    while (current->getNext() != NULL) {
      current = current->getNext();
    }
    current->setNext(new Node());
    //current->setnext(new student());
    current->getNext()->setStudent(newstudent);
  }
  
}

void deletestudent() { //method to delete a student (not implemented)
  cout << "which student do you want to remove? (enter id)" << endl;
    
}

void printstudent(Node* next) { //method to print all students
  //  node* head = NULL;
  //  cout << "1st if statement" << endl;
  if (next == head) {
    cout << "list: ";
  }
  // cout << "2nd if statement" << endl;
  if (next != NULL) {
    cout << next->getStudent()->getName() << " ";
    cout << next->getStudent()->getId() << " ";
    cout << fixed << setprecision(2) << next->getStudent()->getGpa() << " ";
    cout << endl;
    printstudent(next->getNext());
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
