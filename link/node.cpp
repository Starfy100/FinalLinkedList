#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

Node::Node(Student* user){
  newstudent = NULL;
  next = NULL;
}

Node::~Node(){
  delete &newstudent;
  next = NULL;
}

///*
void Node::setStudent(Student* user){
 newstudent = user;
}

Student* Node::getStudent(){
  return newstudent;
}
//*/

void Node::setNext(Node* user){
  next = user;
}

Node* Node::getNext(){
  return next;
}
