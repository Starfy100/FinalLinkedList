#ifndef STUDENT_H
#define STUDENT_H
//header guard ^^
//imports vv
#include <iostream>

using namespace std;

class Student{
 public:
  ///*
  Student();
  ~Student();
  //*/
  char* getName(); //get student name
  char* setName(char* user); //set student name
  char* getLName(); //get student last name
  char* setLName(char* user); //set student last name
  float getGpa(); //get student gpa
  void setGpa(float user); //set student gpa
  //*/
  
  int getId(); //get student id
  void setId(int user); //set student id

 private:
  char* name;
  char* lname;
  float gpa;
  int id;
};
//end of header guard vv
#endif 
