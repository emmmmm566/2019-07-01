#ifndef KNOWLEDGE_H
#define KNOWLEDGE_H
#include "mysqlbase.h"
#include <string>
class Knowledge :public MySQLBase{
private:
	string content;
	int id;
	string title;
	int type;
public:
	void SetContent(string);
	void SetId(int);
	void SetTitle(string);
	void SetType(int);
	TString GetContent(void);
	int GetId(void);
	TString GetTitle(void);
	int GetType(void);
}
#endif
