#ifndef CLASSIC_H
#define CLASSIC_H
#include "mysqlbase.h"
#include <string>
class Classic :public MySQLBase{
private:
	string answer;
	int id;
	string optionA;
	string optionB;
	string optionC;
	string optionD;
	string question;
	int type;
public:
	void SetAnswer(string);
	void SetId(int);
	void SetOptionA(string);
	void SetOptionB(string);
	void SetOptionC(string);
	void SetOptionD(string);
	void SetQuestion(string);
	void SetType(int);
	string GetAnswer(void);
	int GetId(void);
	string GetOptionA(void);
	string GetOptionB(void);
	string GetOptionC(void);
	string GetOptionD(void);
	string GetQuestion(void);
	int GetType(void);
};
#endif
