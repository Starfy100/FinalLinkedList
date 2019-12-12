#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

node::node(){
  newstudent = NULL;
  next = NULL;
}

node::~node(){
  delete &newstudent;
  next = NULL;
}

///*
void node::setstudent(student* user){
 newstudent = user;
}

student* node::getstudent(){
  return newstudent;
}
//*/

void node::setnext(node* user){
  next = user;
}

node* node::getnext(){
  return next;
}
