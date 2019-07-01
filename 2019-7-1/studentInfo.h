#ifndef STUDENTINFO_H
#define STUDENTINFO_H
#include "mysqlbase.h"
#include <string>
class StudentInfo :public MySQLBase{
private:
	string content;
	int id;
	int type;
public:
	void SetContent(TString);
	void SetId(int);
	void SetType(int);
	TString GetContent(void);
	int GetId(void);
	int GetType(void);
}
#endif
