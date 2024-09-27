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
	int arr[100];
	int top_index;
	public:
		stack(){
			top_index=-1;
		}
		bool isEmpty(){
			return(top_index==-1);
		}
		void push(int s){
			top_index++;
			arr[top_index]=s;
		}
		int pop(){
			if(!isEmpty()){
				int temp=arr[top_index];
				top_index--;
				return temp;
			}
		}
		int peek(){
			if(!isEmpty()){
				int temp=arr[top_index];
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
	string postexp;
	cout<<"Enter the expression: ";
	cin>>postexp;
	stack s;
	int result;
	int i=0;
	int j=0;
	while(postexp[i]!='\0'){
		if(isOperand(postexp[i])){
			s.push(postexp[i]-'0');
		}
		else {
			int operand2=s.pop();
			int operand1=s.pop();
			int resultant;
			if(postexp[i]=='+'){
				resultant=operand1+operand2;
			}else if(postexp[i]=='-'){
				resultant=operand1-operand2;
			}else if(postexp[i]=='*'){
				resultant=operand1*operand2;
			}else if(postexp[i]=='/'){
				resultant=operand1/operand2;
			}
			s.push(resultant);
		}
		i++;
	}
	result=s.pop();

	cout<<"Result : "<<result<<endl;

}
