#include"choiceMapper.h"
int ChoiceMapper::Insert(Choice item){
	string sql = "insert into choice(id,type,answer,question) values(?,?,?,?)";
	return ExcuteUpdate(sql, item.GetId(), item.GetType(), item.GetAnswer(), item.GetQuestion());
}
int ChoiceMapper::DeleteById(int id){
	string sql = "delete from choice where id=?";
	int count = ExcuteUpdate(sql, id);
	return count;
}
list<Choice> ChoiceMapper::SelectAll(){
	list<Choice> lists;
	Choice item;
	string sql = "select * from choice";
	m_res = ExcuteQuery(sql, nullptr);
	while (m_res->next()){
		item.SetAnswer(m_res->getString("answer"));
		item.SetQuestion(m_res->getString("question"));
		item.SetType(m_res->getInt("type"));
		item.SetId(m_res->getInt("id"));
		lists.push_back(item);
	}
	return lists;
}
int ChoiceMapper::UpdateById(Choice item){
	string sql = "update choice set type=?,answer=?,question=? where id=?";
	return ExcuteUpdate(sql, item.GetType(), item.GetAnswer(), item.GetQuestion(), item.GetId());
}