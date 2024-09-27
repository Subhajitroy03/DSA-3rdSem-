#include<iostream>
#include<string.h>
using namespace std;
int isOperator(char symbol){
	if(symbol=='*'||symbol=='/'){
		return 2;
	}	
	else if(symbol=='+'||symbol=='-'){
		return 1;
	}else{
		return 0;
	}
}
int isParenthesis(char symbol){
	if(symbol=='('){
		return 1;
	}else if (symbol==')'){
		return 2;
	}else{
		return 0;
	}
}
int isOperand(char symbol){
	if(isOperator(symbol)==0 && isParenthesis(symbol)==0){
		return 1;
	}else{
		return 0;
	}
}
void print(char arr[]){
	int i=0;
	while(arr[i]!='\0'){
		cout<<arr[i];
		i++;
	}
}
class stack{
	char arr[100];
	int top_index;
	public:
		stack(){
			top_index=-1;
		}
		bool isEmpty(){
			return(top_index==-1);
		}
		void push(char s){
			top_index++;
			arr[top_index]=s;
		}
		char pop(){
			if(!isEmpty()){
				char temp=arr[top_index];
				top_index--;
				return temp;
			}
		}
		char peek(){
			if(!isEmpty()){
				char temp=arr[top_index];
				return temp;
			}
		}
		void display(){
			int i;
			for(i=0;i<=top_index;i++){
				cout<<arr[i]<<endl;
			}
		}
};
int main(void){
	char result[100];
	string s1;
	stack s;
	cout<<"Enter your expression : ";
	cin>>s1;
	int i=0;
	int j=0;
	while(s1[i]!='\0'){
		char t=s1[i];
		if(isOperand(t)){
			result[j++]=t;
		}
		else if(isParenthesis(t)==1){
			s.push(t);
		}
		else if(isParenthesis(t)==2){
			while(s.peek()!='(' && s.isEmpty()==0){
				result[j++]=s.pop();
			}
			s.pop();
		}else if(isOperator(t)!=0){
			if(s.isEmpty() || s.peek()=='('){
				s.push(t);
			}
			else if(isOperator(t)>isOperator(s.peek())){
				s.push(t);
			}
			else{
				while(isOperator(t)<=isOperator(s.peek())){
					result[j++]=s.pop();
				}
				s.push(t);
			}
		}
		
		
		i++;
		
	}
	while(s.isEmpty()==0){
		result[j++]=s.pop();
	}
	result[j]='\0';
	cout<<"The postfix expression is: ";
	print(result);
	cout<<endl;


}
