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

//Node* head = NULL;

void insertstudent(int userid, Student* newstudent, Node* &head, Node* current, Node* temp, Node* temp2);

void addstudent(Node* &head, char* name, char* lname, int id, float gpa) {
  //method to add a student
  //method calls method to add students based on id number
  
  Node* current = head;
  Node* temp = NULL;
  Node* temp2 = NULL;
  bool whiletrue = true;
   
  int userid;
  char* username = new char[15];
  char* userlname = new char[15];
  float usergpa;
  Student* newstudent = new Student();

  //asks and then records name, id and gpa
  cout << "enter name:" << endl; 
  cin >> username;
  cin.get();
  name = username;
  newstudent->setName(name);

  cout << "enter last name:" << endl; 
  cin >> userlname;
  cin.get();
  lname = userlname;
  newstudent->setLName(lname);

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
  insertstudent(userid, newstudent, head, current, temp, temp2);
}
    // */


void insertstudent(int userid, Student* newstudent, Node* &head, Node* current, Node* temp, Node* temp2) {
  //inserts students into the list
  if (head == NULL) {
    cout << "current is null" << endl;
    head = new Node(newstudent);
  }
  
  else if (current->getNext() == NULL) {
    cout << "current's next is null" << endl; 
    if (current->getStudent()->getId() > userid) {
      //if the node is greater than the new student
      //put the new student before it
      cout << "current is greater than new" << endl;
      cout << "new goes before" << endl;
      temp = current;
      head = new Node(newstudent);
      head->setNext(temp);
    }
    if (current->getStudent()->getId() < userid) {
      //if the node is less than the new student
      //put the new student after it
      cout << "current is less than new" << endl;
      cout << "new goes after" << endl;
      Node* temp = new Node(newstudent);
      temp2 = NULL;
      temp->setNext(temp2);
      current->setNext(temp);
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
      head->setNext(temp);
    }
    if (current->getStudent()->getId() < userid && current->getNext()->getStudent()->getId() > userid) {
      //if the current is smaller and the next is larger
      //new student goes in between
      cout << "current is smaller and next is greater" << endl;
      cout << "new goes inbetween" << endl;
      Node* temp = new Node(newstudent);
      temp2 = current->getNext();
      current->setNext(temp);
      temp->setNext(temp2);
    }
    if (current->getStudent()->getId() < userid && current->getNext()->getStudent()->getId() < userid) {
      //if both the current and the next nodes are smaller
      cout << "current and next are smaller" << endl;
      cout << "move forward" << endl;
      current = current->getNext();
      insertstudent(userid, newstudent, head, current, temp, temp2);
    }     
  }
}



void deletestudent(int delid, Node* &head, Node* current, Node* temp, Node* temp2) { //method to delete a student 
  if (current == NULL) {
    //current is null, do nothing
    cout << "current is null, do nothing" << endl;
  }
  
  else if (current->getNext() == NULL) {
    //item is only item in list
    cout << "current is only" << endl;
    
    if (current->getStudent()->getId() == delid) {
      //if the current equals delid, delete current
      cout << "current is equal to delid" << endl;
      cout << "head = NULL" << endl;
      head = NULL;
      temp = current;
      delete temp;
    }
    if (current->getStudent()->getId() != delid) {
      //if the current does not equal delid
      //do nothing
      cout << "no student matches given ID" << endl;
    }
    
  }
  
  else if (current->getNext() != NULL && current->getNext()->getNext() == NULL) { //current is the last item
    cout << "current is second to last item" << endl;
    if (current->getStudent()->getId() != delid && current->getNext()->getStudent()->getId() == delid) {
      //if current does not equal delid, and current->next equals delid
      //delete next, link current to NULL
      cout << "current does not equal delid and current->next equals delid" << endl;
      cout << "delete next" << endl;
      temp = NULL;
      current->setNext(temp);
      temp2 = current->getNext();
      delete temp2;
    }
    if (current->getStudent()->getId() == delid && current->getNext()->getStudent()->getId() != delid) {
      cout << "current equals delid, current->next does not equal delid" << endl;
      temp = NULL;
      temp2 = current->getNext();
      head = temp2;
      current->setNext(temp);
      temp = current;
      delete temp;
    }
  }
  
  
  else if (current->getNext() != NULL && current->getNext()->getNext() != NULL) {
    ///*
    cout << "current is one of multiple items" << endl;
    
    if (current->getStudent()->getId() == delid && current->getNext()->getStudent()->getId() != delid) {
      //if the curent is equal to delid, and next does not equal delid
      //set head equal to current->next
      //item is the first item
      cout << "current is equal to delid and next is not equal to delid" << endl;
      cout << "delete current" << endl;
      temp2 = current->getNext();
      head = temp2;
      temp = current;
      delete temp;
    }
    if (current->getStudent()->getId() != delid && current->getNext()->getStudent()->getId() == delid) {
      //if current does not equal delid, and current->next equals delid
      //delete next, link current to next->next
      cout << "current does not equal delid and current->next equals delid" << endl;
      cout << "delete next" << endl;
      temp = current->getNext()->getNext();
      temp2 = current->getNext();
      delete temp2;
      current->setNext(temp);
    }
    if (current->getStudent()->getId() != delid && current->getNext()->getStudent()->getId() != delid) {
      //if both the current and the next nodes are not equal to delid
      //move on
      cout << "current and next do not equal delid" << endl;
      cout << "move forward" << endl;
      current = current->getNext();
      deletestudent(delid, head, current, temp, temp2);
    }     
  }
}

void printstudent(Node* head, Node* next) { //method to print all students
  if (next == head) {
    cout << "list: " << endl;
  }
  if (next != NULL) {
    cout << next->getStudent()->getName() << " ";
    cout << next->getStudent()->getLName() << " ";
    cout << next->getStudent()->getId() << " ";
    cout << fixed << setprecision(2) << next->getStudent()->getGpa() << " ";
    cout << endl;
    printstudent(head, next->getNext());
  } 
}

void meangpa(Node* next, float &total, int &n){
  //method to average the gpa's of all recorded students
  float ave; //total divided by n
  //for each student in the chain, take gpa and add it to "total", increment "n" for each student
  //after all students are accounted for, divide "total" by "n"
  //  /*  
  if (next != NULL) {
    total =  next->getStudent()->getGpa() + total;
    n++;
    meangpa(next->getNext(), total, n);    
  }
  if (next == NULL) {
    ave = total/n;
    cout << "average: " << ave << endl;
    cout << "n: " << n << endl;
    cout << "total: " << total << endl; 
  }  
}

int main() {
  bool running = true; //variable for program status
  char user1; //variable for user input
  int id; //varaible for id
  int delid; //variable for deleting id
  char* name = new char[15]; //variable for student name
  char* lname = new char[15]; //variable for student last name
  float gpa; //variable for gpa
  
  float total = 0; //sum of gpa
  int n = 0; //number of students

  Node* head = NULL; //head node
  Node* current = head; //current node
  Node* temp = NULL; //temporary node
  Node* temp2 = NULL; //temporary node
  
  while (running == true) {
    cout << "commands are q, a, d, p and m" << endl;
    cout << "(Quit, Add, Delete, Print, Mean/Average)" << endl;
    cin >> user1; //reads in user input
    cin.get();
    
    if (user1 == 'q'){ //exits the program
      running = false;
    }
    if (user1 == 'a'){//adds a student
      addstudent(head, name, lname, id, gpa);
    }
    if (user1 == 'd'){ //deletes a student
      Node* current = head;
      cout << "which student do you want to remove? (enter id)" << endl;
      cin >> delid;
      cin.get();
      deletestudent(delid, head, current, temp, temp2);
    }
    if (user1 == 'p'){ //prints all students
      printstudent(head, head);
    }
    if (user1 == 'm'){ //averages the gpa of all students
      meangpa(head, total, n);
    }
  }
  return 0;
}
