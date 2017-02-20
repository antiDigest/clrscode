// STACK

#include <iostream>
#include <ctime>

using namespace std;

class Stack{
	public:
		int S[20];
		int top=-1;

		Stack(){
			cout << "Stack of size 20 initialised" <<  endl;
		}
		int push(int a){
			this->S[++this->top] = a;
			return 1;
		}
		int pop(){
			if( this->top >= 0 ){
				int x = this->S[this->top];
				this->S[this->top--] = '\0';
				return x;
			}
			else{
				cout << "Stack Empty" << endl;
			}
		}
};

int main(){
	Stack stack;
	stack.push(10);
	cout << stack.pop() << endl;
	cout << "Top: " << stack.top << endl;

	stack.push(21);
	stack.push(98);
	cout << stack.pop() << endl;
	cout << "Top: " << stack.top << endl;

	stack.push(65);
	stack.push(12);
	stack.push(43);
	stack.push(45);
	cout << stack.pop() << endl;
	cout << "Top: " << stack.top << endl;

	return 0;
}