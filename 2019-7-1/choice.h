#ifndef CHOICE_H
#define CHOICE_H
#include "mysqlbase.h"
#include"mysqlbase.h"
class Choice :public MySQLBase{
private:
	string answer;
	int id;
	string question;
	int type;
public:
	void SetAnswer(string);
	void SetId(int);
	void SetQuestion(string);
	void SetType(int);
	string GetAnswer(void);
	int GetId(void);
	string GetQuestion(void);
	int GetType(void);
};
#endif
