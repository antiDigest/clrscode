// STACK USING Qs

#include <iostream>
#include <ctime>

using namespace std;

#define N 20


class Queue{
	public:
		int Q[N];
		int tail = 0;
		int head = 0;

		Queue(){
			cout << "Queue of size "<< N << " initialised" <<  endl;
		}
		int enqueue(int a){
			if (this->tail == N){
				this->tail = 1;
			}
			else{
				this->tail++;
			}
			this->Q[this->tail] = a;
			return 1;
		}
		int dequeue(){
			int x = this->Q[this->head];
			if (this->head == N){
				this->head = 1;
			}
			else{
				this->head++;
			}
			return x;
		}
};

class Stack{
	public:
		Queue q1;
		Queue q2;
		int top=-1;

		Stack(){
			cout << "Stack of size "<<N << " initialised" <<  endl;
		}
		int push(int a){
			// this->S[++this->top] = a;

			while(q1.head!=q1.tail){
				q2.enqueue(q1.dequeue());
			}
			q1.enqueue(a);
			while(q2.head!=q2.tail){
				q1.enqueue(q2.dequeue());
			}
			this->top == q1.tail;

			return 1;
		}
		int pop(){
			// if( this->top >= 0 ){
				// int x = this->S[this->top];
				// this->S[this->top--] = '\0';
			this->top--;
			return q1.dequeue();
			// }
			// else{
			// 	cout << "Stack Empty" << endl;
			// 	return -1;
			// }
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