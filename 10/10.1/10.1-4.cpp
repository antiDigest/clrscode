// QUEUE

#include <iostream>
#include <ctime>

using namespace std;

#define N 20

class Deque{
	public:
		int Q[N];
		int tail = 0;
		int head = 0;

		Deque(){
			cout << "Deque of size "<< N << " initialised" <<  endl;
		}
		int enqueue_start(int a){
			// if((this->tail==0&&this->head==N)||(this->head==this->tail+1)){
			// 	cout << "Queue Overflow";
			// 	return 0;
			// }
			if (this->head == 0){
				this->head = N;
			}
			else{
				this->head--;
			}
			this->Q[this->head] = a;
			return 1;
		}
		int enqueue_end(int a){
			// if((this->tail==0&&this->head==N)||(this->head==this->tail+1)){
			// 	cout << "Queue Overflow";
			// 	return 0;
			// }
			if (this->tail >= N){
				this->tail = 0;
			}
			else{
				this->tail++;
			}
			this->Q[this->tail] = a;
			return 1;
		}
		int dequeue_start(){
			if(this->tail==this->head){
				cout << "Queue Underflow";
				return 0;
			}
			int x = this->Q[this->head];
			if (this->head == N){
				this->head = 0;
			}
			else{
				this->head++;
			}
			return x;
		}
		int dequeue_end(){
			if(this->tail==this->head){
				cout << "Queue Underflow";
				return 0;
			}
			int x = this->Q[this->tail];
			if (this->tail == 0){
				this->tail = N;
			}
			else{
				this->tail--;
			}
			return x;
		}
		int display(){
			cout << "Elements of Queue:" << endl;
			if(this->head<this->tail){
				cout << "Head: " << this->head << endl;
				for(int i=this->head;i<=this->tail;i++){
					cout << this->Q[i] << endl;
				}
				cout << "Tail: " << this->tail << endl;
			}
			else{
				cout << "Head: " << this->head << endl;
				for(int i=this->head;i<=N;i++){
					cout << this->Q[i] << endl;
				}
				for(int i=0;i<=this->tail;i++){
					cout << this->Q[i] << endl;
				}
				cout << "Tail: " << this->tail << endl;
			}
		}
};

int main(){
	Deque dq;
	dq.enqueue_start(10);
	cout << dq.dequeue_start() << endl;
	cout << "head: " << dq.head << endl;
	cout << "tail: " << dq.tail << endl;

	dq.enqueue_start(21);
	dq.enqueue_end(98);
	cout << dq.dequeue_end() << endl;
	cout << "head: " << dq.head << endl;
	cout << "tail: " << dq.tail << endl;

	dq.enqueue_end(65);
	dq.enqueue_start(12);
	dq.enqueue_end(43);
	dq.enqueue_start(45);
	dq.enqueue_end(35);
	dq.enqueue_start(15);
	dq.enqueue_end(41);
	dq.enqueue_start(75);
	dq.enqueue_end(85);
	dq.enqueue_start(34);
	dq.enqueue_end(46);
	dq.enqueue_start(87);
	dq.display();
	cout << dq.dequeue_start() << endl;
	cout << dq.dequeue_end() << endl;
	cout << "head: " << dq.head << endl;
	cout << "tail: " << dq.tail << endl;

	return 0;
}