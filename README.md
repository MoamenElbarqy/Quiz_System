# 📝 Quiz System

**Quiz System** developed using **Object-Oriented Programming (OOP) in C++**.  
This file-based project simulates a real quiz management system with features for **Student, Teacher**.  

## 📌 Features

###  User Management
- Three distinct user roles: Admin, Teacher, and Student
- User registration for student and Teacher(Note: You Can't Register directly as Admin, the internal admin must adding you)
- Access control based on user roles

###  Quiz Management
- Create and manage quizzes data
- Add multiple choice questions with answers
- Set time limits(Note: Because this is a simple console app, the system won’t automatically close when the time runs out during solving. However, the time limit attribute is there and may be fully implemented in the future.)
- Organize quizzes into different states (Drafted, Published, Deleted)

###  Student Features
- View available quizzes
- Start Solving Exsisted Quiz in the System(Note : you Can't Solve one Quiz Twice, The System Prevent You From This)
- Review all previous quiz results you have Solved Before
- View detailed Quiz You Have Solved With Your Previous Answers

###  Teacher Features
- Create Quizzes and Chosse You Want To Save In Your Draft Or publish it to the Students 
- When You Draft a quiz you can publish it later or chosse to delete it 
- View Quiz Report 
- Track quiz statistics


##  Installation & Usage

The system requires These Files for storing data in the same directory:

- `Students.txt`
- `Teachers.txt`
- `Admins.txt`
- `PublishedQuizzes.txt`
- `DraftedQuizzes.txt`
- `DeletedQuizzes.txt`
- `SolvedQuizzes.txt`

Clone this repository or download the source files.

Quiz System.cpp in your C++ development environment.

Compile and run the program.


##  User Interface

###  Login Menu
~~~
===================================
         Login Screen      
===================================
[1] Login As Student
[2] Login As Teacher
[3] Login As Admin
[4] Exit
===================================
~~~

### 🔹 Student Main Menu
~~~
===================================
      Student Main Menu
===================================
[1] View Available Quizzes
[2] Start New Quiz
[3] View Previous Results
[4] Review Solved Quiz
[5] Logout
===================================
~~~

### 🔹 Teacher Main Menu
~~~
===================================
      Teacher Main Menu
===================================
[1] Create New Quiz
[2] Edit Draft Quiz
[3] Publish Quiz
[4] View Quiz Reports
[5] Delete Quiz
[6] Logout
===================================
~~~

###  Admin Main Menu
~~~
===================================
      Admin Main Menu
===================================
[1] View All Students
[2] View All Teachers
[3] Add New Admin
[4] Update Admin Info
[5] Delete Admin
[6] Logout
===================================
~~~

## 📌 Quiz Features

###  Quiz Creation
- Set Quiz Name
- Set Number Of Question
- Set Each Question Title 
- Set Multiple Choices For Each Question (4 Choices )
- Set The True Asnwer Of These Question
- Set Question Time

###  Results and Analysis
- Grade  (A, B, C, D, F)
- Pass/Fail status
- Your Degree (8 / 10)

##  Project Structure
```
Quiz System/
├── Header Files/
│   ├── Person.h
│   ├── Student.h
│   ├── Teacher.h
│   ├── Admin.h
│   ├── Quiz.h
│   ├── SolvedQuiz.h
│   └── ...
├── Source Files/
│   └── Quiz System.cpp
├── Data Files/
│   ├── Students.txt
│   ├── Teachers.txt
│   ├── PublishedQuizzes.txt
│   ├── DraftedQuizzes.txt
│   ├── DeletedQuizzes.txt
│   └── SolvedQuizzes.txt
└── README.md
```
