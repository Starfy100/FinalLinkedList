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

void insertstudent(char* name, int id, float gpa);

void addstudent(char* name, int id, float gpa) {
  //method to add a student
  //method calls method to add students based on id number
  
  Node* current = head;
  Node* temp = NULL;
  Node* temp2 = NULL;
  bool whiletrue = true;
   
  int userid;
  char* username = new char[15];
  float usergpa;
  Student* newstudent = new Student();
  //Student* oldstudent = new Student();

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
  // /*
  cout << "enter gpa:" << endl;
  cin >> usergpa;
  cin.get();
  gpa = usergpa;
  newstudent->setGpa(gpa);
  //*/
  
  //insertstudent();

  
  while (whiletrue == true) {
    
    if (current == NULL) {
      cout << "current is null" << endl;
      head = new Node(newstudent);
      //head = new student();
      head->setStudent(newstudent);
      whiletrue = false;
    }
    
    else if (current->getNext() == NULL) {
      cout << "current's next is null" << endl;
      // while (current->getNext() != NULL) {
      
      if (current->getStudent()->getId() > userid) {
	//if the node is greater than the new student
	//put the new student before it
	cout << "current is greater than new" << endl;
	cout << "new goes before" << endl;
	temp = current; 
	head = new Node(newstudent);
	head->setStudent(newstudent);
	head->setNext(temp);
	whiletrue = false;
      }
      if (current->getStudent()->getId() < userid) {
	//if the node is less than the new student
	//put the new student after it
	cout << "current is less than new" << endl;
	cout << "new goes after" << endl;
	temp = new Node(newstudent);
	temp->setStudent(newstudent);    
	current->setNext(temp);
	whiletrue = false;
	
	
	//head->setNext(temp);
	//temp->setNext();
      }
      
      
    }
    
    
    else if (current->getNext() != NULL) {
      ///*
      cout << "current's next is not null" << endl;
      if (current->getStudent()->getId() > userid) {
	//if the curent is greater
	//put new student before
	cout << "current is greater" << endl;
	cout << "new goes before" << endl;
	temp = current; 
	head = new Node(newstudent);
	head->setStudent(newstudent);
	head->setNext(temp);
	whiletrue = false;
      }
      if (current->getStudent()->getId() < userid && current->getNext()->getStudent()->getId() > userid) {
	//if the current is smaller and the next is larger
	//new student goes in between
	cout << "current is smaller and next is greater" << endl;
	cout << "new goes inbetween" << endl;
	temp = new Node(newstudent);
	temp->setStudent(newstudent);
	temp2 = current->getNext();
	current->setNext(temp);
	temp->setNext(temp2);
	whiletrue = false;
      }
      if (current->getStudent()->getId() < userid && current->getNext()->getStudent()->getId() < userid) {
	//if both the current and the next nodes are smaller
	cout << "current and next are smaller" << endl;
	cout << "move forward" << endl;
	current = current->getNext();
      }     
    }
  }
  
}
    // */


void insertstudent(char* name, int id, float gpa) { //inserts students into the list
  Node* current = head;
  Node* temp = NULL;
  Node* temp2 = NULL;



}



void deletestudent() { //method to delete a student (not implemented)
  int user3;
  cout << "which student do you want to remove? (enter id)" << endl;
  cin >> user3;
  cin.get();
  
    
}

void printstudent(Node* next) { //method to print all students
  //  node* head = NULL;
  //  cout << "1st if statement" << endl;
  if (next == head) {
    cout << "list: " << endl;
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

void meangpa(Node* next, float &total, int &n){ // (not implemented)
 //method to average the gpa's of all recorded students

  // float total; //sum of gpa
 // int n; //number of numbers
  float ave; //total divided by n

  //for each student in the chain, take gpa and add it to "total", increment "n" for each student
  //after all students are accounted for, divide it by "n"

  //  /*  
if (next == head) {
    cout << "list: " << endl;
  }
  
  // cout << "2nd if statement" << endl;
  if (next != NULL) {

    
    meangpa(next->getNext(), total, n);
  }

  if (next->getNext() == NULL){
    total = total + next->getStudent()->getGpa();
    cout << "Average GPA: " << ave << endl;
  }

  //*/
  
}

int main() {
  bool running = true; //variable for program status
  char user1; //variable for user input
  int id; //varaible for id
  char* name = new char[15]; //variable for student name
  float gpa; //variable for gpa

  float total; //sum of gpa
  int n; //number of numbers
  
  while (running == true) {
    cout << "commands are q, a, d, p and m" << endl;
    cin >> user1; //reads in user input
    cin.get();
    
    if (user1 == 'q'){ //exits the program
      running = false;
    }
    if (user1 == 'a'){//adds a student
      addstudent(name, id, gpa);
    }
    if (user1 == 'd'){ //deletes a student
      //deletestudent();
    }
    if (user1 == 'p'){ //prints all students
      //cout << "Before method call" << endl;
      printstudent(head);
    }
    if (user1 == 'm'){
      meangpa(head, total, n);
    }
    
  }
  return 0;
}
