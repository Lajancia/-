#include<iostream>
#include<stack>
#include<cstdlib>

using namespace std;

const int MAX_STACK_SIZE=100;
typedef int ItemType;


class Stack{
	int top;
	ItemType data[MAX_STACK_SIZE];

public:
	Stack(){
		top=-1;
	}
	~Stack(){

	}
	bool is_empty(){
		return top==-1;
	}
	bool is_full(){
		return top==MAX_STACK_SIZE-1;
	}
	void push(ItemType item){
		if(is_full()){
			cout<<"스택 포화 오류"<<endl;
			exit(1);
		}
		else {
			top++;
			data[top]=item;
		}
	}
	ItemType pop(){
		if(is_empty()){
				cout<<"스택 비어있음 오류"<<endl;
				exit(1);//비정상적으로 끝난 에러
			}

			else{
				ItemType temp=data[top];
				top=top-1;
				ItemType item=temp;
				return item;
			}
	}
};


int main(){
	Stack s;

	bool balanced = true;
	char symbol;
	char open_symbol;


	while(cin.get(symbol)&&balanced){
	if(symbol=='('){
		s.push(symbol);
	}
		if(symbol=='{'){
		s.push(symbol);
	}
		if(symbol=='['){
		s.push(symbol);
	}
	else if(symbol == ')'){
		if(s.is_empty()){
			balanced=false;

			}
		else{
		open_symbol=s.pop();
		balanced = (open_symbol=='('&&symbol ==')')||(open_symbol=='{'&&symbol =='}')||(open_symbol=='['&&symbol ==']');
			}
		}
		else if(symbol == '}'){
		if(s.is_empty()){
			balanced=false;

			}
		else{
		open_symbol=s.pop();
		balanced = (open_symbol=='('&&symbol ==')')||(open_symbol=='{'&&symbol =='}')||(open_symbol=='['&&symbol ==']');
			}
		}
		else if(symbol == ']'){
		if(s.is_empty()){
			balanced=false;

			}
		else{
		open_symbol=s.pop();
		balanced = (open_symbol=='('&&symbol ==')')||(open_symbol=='{'&&symbol =='}')||(open_symbol=='['&&symbol ==']');
			}
		}
	else{}//아무것도 안함
	}

	if(!balanced){
		cout<<"-1"<<endl;
	}
	else if(s.is_empty()){
		cout<<"1"<<endl;
	}
	else {
		cout<<"-1"<<endl;
	}

	return 0;
}
