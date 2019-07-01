#include "choiceMapper.h"
int main(){
	ChoiceMapper mapper;
	Choice item;
	list<Choice> lists = mapper.SelectAll();
	for (auto i = lists.begin(); i != lists.end(); i++){
		cout << i->GetAnswer() << i->GetQuestion() << i->GetType()<<endl;
	}
	int c;
	cin >> c;
}