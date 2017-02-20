// QUEUE

#include <iostream>
#include <ctime>

using namespace std;

#define N 20

class Queue{
	public:
		int Q[N];
		int tail = -1;
		int head = -1;

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

int main(){
	Queue q;
	q.enqueue(10);
	cout << q.dequeue() << endl;
	cout << "head: " << q.head << endl;
	cout << "tail: " << q.tail << endl;

	q.enqueue(21);
	q.enqueue(98);
	cout << q.dequeue() << endl;
	cout << "head: " << q.head << endl;
	cout << "tail: " << q.tail << endl;

	q.enqueue(65);
	q.enqueue(12);
	q.enqueue(43);
	q.enqueue(45);
	cout << q.dequeue() << endl;
	cout << "head: " << q.head << endl;
	cout << "tail: " << q.tail << endl;

	return 0;
}