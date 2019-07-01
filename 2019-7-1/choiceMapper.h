#ifndef ChoiceMapper_H
#define ChoiceMapper_H
#include "mysqlbase.h"
#include "choice.h"
#include <list>
#include <map>
class ChoiceMapper :public MySQLBase{
public:
	list<Choice> SelectAll();
	int UpdateById(Choice item);
	int DeleteById(int id);
	int Insert(Choice item);
};
#endif