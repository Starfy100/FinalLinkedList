#include <iostream>
#include "student.h"

using namespace std;
///*

///*
student::student(){
}
student::~student(){
  delete name;
}
//*/
char* student::getname(){
  return name;
}
char* student::setname(char* user){
  name = user;
}

float student::getgpa(){
  return gpa;
}
void student::setgpa(int user){
  gpa = user;
}

//*/

int student::getid(){
  return id;
}
void student::setid(int user){
  id = user;
}
