#ifndef STUDENT_H
#define STUDENT_H
//header guard ^^
//imports vv
#include <iostream>

using namespace std;

class student{
 public:
  ///*
  student(/*char* setname*/);
  ~student();
  //*/
  char* getname(); //get student name
  char* setname(char* user); //set student name
  
  float getgpa(); //get student gpa
  void setgpa(int user); //set student gpa
  //*/
  
  int getid(); //get student id
  void setid(int user); //set student id

 private:
  char* name;
  float gpa;
  int id;
};
//end of header guard vv
#endif 
