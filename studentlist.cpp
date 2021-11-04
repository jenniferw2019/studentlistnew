/*
This program allows user to read in students, print them out, and delete them. User can enter student first and last name, id, and 
gpa.
Author: Jennifer Wang
11/3/21 
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
#include <cctype>

using namespace std;

// struct that contains student first and last name, id, and gpa. 
struct Student
{
  char firstName [40];
  char lastName [40];
  int id;
  float gpa;

};

//declare functions
bool addStudent(Student* pStudent, vector<Student*>* pVector);
void printStudent(vector<Student*> pVecPrint);
void deleteStudent(vector<Student*>* pDeleteVector);


int main ()
{

  bool runList = true;
  char strInput[10];
  vector<Student*> vecStudentList;
  vector<Student*>* ptrVecStudent;
  ptrVecStudent = &vecStudentList;
  

  while (runList == true)
    {
      cout << "Type ADD or PRINT or DELETE or QUIT" << endl;
      cin.get(strInput, 20);
      cin.get();

      // if ADD is typed, creates a new entry for a student.
      if (strcmp(strInput, "ADD") == 0)
	{
	  Student* ptrStudent = new Student();
	  runList = addStudent(ptrStudent, ptrVecStudent); 
	}

      // if PRINT is typed, all students currently stored are printed
      else if (strcmp(strInput, "PRINT") == 0)
	{ 
	  printStudent(vecStudentList); 
	}

      // if DELETE is typed, deletes the student with the corresponding id
      else if (strcmp(strInput, "DELETE") == 0)
	{
	  deleteStudent(ptrVecStudent);	  
	}

      // stops the program
      else if (strcmp(strInput, "QUIT") == 0)
	{
	  runList = false;
	}
    }
  return 0;
}

// add function
bool addStudent(Student* pStudent, vector<Student*>* pVector)
{
  //read in student name, id, gpa
  cout << "Type first name" << endl;
  cin >> pStudent->firstName;
  cin.get();
  cout << "Type last name" << endl;
  cin >> pStudent->lastName;
  cin.get();
  cout << "Type id" << endl;
  cin >> pStudent->id;
  if (cin.fail())
    {
      cout << "Error. Student ID input should be a integer value:" << endl;
      return false;
    }
  cin.get();
  cout << "Type gpa:" << endl;
  cin >> pStudent->gpa;
  if (cin.fail())
    {
      cout << "Error. Student gpa input should be a float value:" << endl;
      return false;
    }
  cin.get();
  // add student to vector of students
  pVector->push_back(pStudent);
  
  return true;
}

// print function
void printStudent(vector<Student*> pVecPrint)
{
  for (vector<Student*>::iterator it = pVecPrint.begin(); it != pVecPrint.end(); it++)
    {
      // prints out student name, id, and gpa. gpa shown in to 2 decimal places
      cout << (*it)->firstName << ", " << (*it)->lastName;
      cout << ", " << (*it)->id << ", ";
      cout << fixed << setprecision(2) << (*it)->gpa << endl;
    }
}

// delete student function
void deleteStudent(vector<Student*>* pDeleteVector)
{
  int index = 0;
  int deleteID = 0;

  // prompts user to enter student id
  cout << "Type student id to delete" << endl;
  cin >> deleteID;
  cin.get();

  
  for (vector<Student*>:: iterator it = pDeleteVector->begin(); it != pDeleteVector->end(); it++)
    {
      if (deleteID == (*it)->id)
	{
	  // delete the data and remove the struct of the entered id
	  delete *(pDeleteVector->begin()+ index);
	  pDeleteVector->erase(pDeleteVector->begin()+ index);
	  break;
	}
      else
	{
	  index++;
	}
    }

}





