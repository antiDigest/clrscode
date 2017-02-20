// Q USING STACKs

#include <iostream>
#include <ctime>

using namespace std;

#define N 20

class Stack{
	public:
		int S[N];
		int top=-1;

		Stack(){
			cout << "Stack of size "<<N << " initialised" <<  endl;
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
				// cout << "Stack Empty" << endl;
				return -1;
			}
		}
};

class Deque{
	public:
		int tail = 0;
		int head = 0;
		Stack stack1;
		Stack stack2;

		Deque(){
			cout << "Deque of size "<< N << " initialised" <<  endl;
		}
		int enqueue(int a){
			if(this->tail==N){
				cout << "Queue Overflow";
				return 0;
			}
			while(stack1.top >=0){
				stack2.push(stack1.pop());
			}
			stack1.push(a);
			while(stack2.top >=0){
				stack1.push(stack2.pop());
			}
			this->tail = stack1.top;
			return 1;
		}
		int dequeue(){
			if(this->tail==this->head){
				cout << "Queue Underflow";
				return 0;
			}
			this->tail--;
			return stack1.pop();
		}
};

int main(){
	Deque dq;
	dq.enqueue(10);
	cout << dq.dequeue() << endl;
	cout << "head: " << dq.head << endl;
	cout << "tail: " << dq.tail << endl;

	dq.enqueue(21);
	dq.enqueue(98);
	cout << dq.dequeue() << endl;
	cout << "head: " << dq.head << endl;
	cout << "tail: " << dq.tail << endl;

	dq.enqueue(65);
	dq.enqueue(12);
	dq.enqueue(43);
	dq.enqueue(45);
	dq.enqueue(35);
	dq.enqueue(15);
	dq.enqueue(41);
	dq.enqueue(75);
	dq.enqueue(85);
	dq.enqueue(34);
	dq.enqueue(46);
	dq.enqueue(87);
	// dq.display();
	cout << dq.dequeue() << endl;
	cout << dq.dequeue() << endl;
	cout << "head: " << dq.head << endl;
	cout << "tail: " << dq.tail << endl;

	return 0;
}