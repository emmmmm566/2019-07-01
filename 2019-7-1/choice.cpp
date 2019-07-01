#include "choice.h"
void Choice::SetAnswer(string item){
	answer = item;
}
void Choice::SetId(int item){
	id = item;
}
void Choice::SetQuestion(string item){
	question = item;
}
void Choice::SetType(int item){
	type = item;
}
string Choice::GetAnswer(void){
	return answer;
}
int Choice::GetId(void){
	return id;
}
string Choice::GetQuestion(void){
	return question;
}
int Choice::GetType(void){
	return type;
}