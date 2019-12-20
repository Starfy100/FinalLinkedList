#include <iostream>
#include "student.h"

using namespace std;
///*

///*
Student::Student(){
}
Student::~Student(){
  delete name;
}
//*/
char* Student::getName(){
  return name;
}
char* Student::setName(char* user){
  name = user;
}

float Student::getGpa(){
  return gpa;
}
void Student::setGpa(float user){
  gpa = user;
}

//*/

int Student::getId(){
  return id;
}
void Student::setId(int user){
  id = user;
}
