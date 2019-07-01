#ifndef SENTENCE_H
#define SENTENCE_H
#include "mysqlbase.h"
#include <string>
class Sentence :public MySQLBase{
private:
	string content;
	int type;
public:
	void SetContent(TString);
	void SetType(int);
	TString GetContent(void);
	int GetType(void);
}
#endif
