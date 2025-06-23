# 📝 Quiz System

**Quiz System** developed using **Object-Oriented Programming (OOP) in C++**.  
This file-based project simulates a real quiz management system with features for **Student, Teacher**.  

##  Features

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

###  Quiz Creation
- Set Quiz Name
- Set Number Of Question
- Set Degress Per Question
- Set Each Question Title 
- Set Multiple Choices For Each Question (2 - 5 Choices )
- Set The True Asnwer Of These Question
- 
##  Installation & Usage

The system requires These Files for storing data, you must change the path of files or deleting the absolute path from Misc/include/Global.h (if the work directory is same)  :

- `Students.txt`
- `Teachers.txt`
- `Admins.txt`
- `PublishedQuizzes.txt`
- `DraftedQuizzes.txt`
- `DeletedQuizzes.txt`
- `SolvedQuizzes.txt`

Clone this repository or download the source files.

Compile and run the program.

## Login

Register First With Your Data

###### Some Notes :

- You Must Enter 11 number for the Phone Number
- You Must Enter Your email like this  xxxxxx@gmail.com the input doesn't accept other domains like @hotmail @yahoo etc 

##  User Interface

###  Login Menu
~~~
===================================
         MainMenu      
===================================
[1] Login
[2] Register
[3] Exit
===================================
~~~

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

###  Register Menu
~~~
===================================
         Register Menu      
===================================
[1] Register As Student
[2] Register As Teacher
[3] Register As Admin
[4] Exit
===================================
~~~

###  Student Main Menu
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

###  Teacher Main Menu
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

##  Project Structure

![image](https://github.com/user-attachments/assets/251328a9-d3fb-4d58-8d2a-ea835139018b)
