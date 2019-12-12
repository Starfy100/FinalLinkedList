#ifndef NODE_H
#define NODE_H
//header guard ^^

//imports vv
#include <iostream>
#include "student.h"

using namespace std;

class node{
 public: //public functions
  node(); //constructor
  ~node(); //destructor 
  void setstudent(student* user); //set new student, sets "newstudent" = "user"
  student* getstudent(); //get student pointer, returns "newstudent"
  void setnext(node* user); //set where node points to
  node* getnext(); //get the node pointer, returns "next"
  
 private:
  student* newstudent;
  node* next;
};

#endif
