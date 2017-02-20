// STACK

#include <iostream>
#include <ctime>

using namespace std;

#define N 20

class Stack{
	public:
		int S[N];
		int top1 = -1;
		int top2 = N;

		Stack(){
			cout << "Double Sided Stack of size " << N << " initialised" <<  endl;
		}
		int push_1(int a){
			this->S[++this->top1] = a;
			return 1;
		}
		int push_2(int a){
			this->S[--this->top2] = a;
			return 1;
		}
		int pop_1(){
			if( this->top1 >= 0 ){
				int x = this->S[this->top1];
				this->S[this->top1--] = '\0';
				return x;
			}
			else{
				cout << "Stack Empty" << endl;
			}
		}
		int pop_2(){
			if( this->top2 < N ){
				int x = this->S[this->top2];
				this->S[this->top2++] = '\0';
				return x;
			}
			else{
				cout << "Stack Empty" << endl;
			}
		}
};

int main(){
	Stack stack;
	stack.push_2(10);
	cout << stack.pop_2() << endl;
	cout << "Top2: " << N-stack.top2 << endl;

	stack.push_1(21);
	stack.push_2(98);
	cout << stack.pop_1() << endl;
	cout << "Top1: " << stack.top1 << endl;

	stack.push_1(65);
	stack.push_2(12);
	stack.push_1(43);
	stack.push_2(45);
	stack.push_1(35);
	stack.push_2(52);
	stack.push_1(63);
	stack.push_2(75);
	cout << stack.pop_2() << endl;
	cout << "Top2: " << N-stack.top2 << endl;
	cout << "Top1: " << stack.top1 << endl;

	return 0;
}