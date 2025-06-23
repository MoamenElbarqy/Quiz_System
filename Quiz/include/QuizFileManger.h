#pragma once
#include <vector>
#include "Quiz.h"

class QuizFileManger {
private:
	static Quiz *Find(string QuizID, string fileName);
	static vector<Quiz> LoadQuizzesData(string fileName);
	static void LoadDataToFile(vector<Quiz> quizzes, string fileName);
	static void AddToFile(string fileName, Quiz quiz);

public:
	static Quiz *FindInPublished(string QuizID);
	static Quiz *FindInDrafted(string QuizID);
	static Quiz *FindInDeleted(string QuizID);
	static void LoadDataToPublished(vector<Quiz> quizzes);
	static void LoadDataToDrafted(vector<Quiz> quizzes);
	static void LoadDataToDeleted(vector<Quiz> quizzes);
	static void AddToDrafted(Quiz quiz);
	static void AddToPublished(Quiz quiz);
	static void AddToDeleted(Quiz quiz);
	static vector<Quiz> LoadDraftedQuizzes();
	static vector<Quiz> LoadPublishedQuizzes();
	static vector<Quiz> LoadDeletedQuizzes();
};
