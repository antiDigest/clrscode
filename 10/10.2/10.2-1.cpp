// LINKED LIST

#include <iostream>
#include <ctime>

using namespace std;

class Node{
	public:
		int value;
		Node *next;

		Node(){
			// cout << "Stack of size 20 initialised" <<  endl;
			this->value = '\0';
			this->next = '\0';
		}
		Node(int a){
			// cout << "Stack of size 20 initialised" <<  endl;
			this->value = a;
			this->next = '\0';
		}
};

class List{
	public:
		Node head;

		List(){
			// Node head;
			cout << "Initialised empty list with a single node having value = Null." <<  endl;
		}
		List(int a){
			head.value = a;
			cout << "Initialised empty list with a single node." <<  endl;
		}
		int insert(int a){
			Node temp = this->head;
			if(temp.value=='\0'){
				this->head.value = a;
				return 1;
			}
			while(temp.next!='\0'){
				temp = *temp.next;
			}
			Node last(a);
			temp.next = &last;
			this->display();
		}
		int search(int a){
			Node temp = this->head;
			if(temp.value=='\0'){
				cout << "Empty List";
				return 0;
			}
			while(temp.next!='\0'){
				temp = *temp.next;
				if(temp.value==a){
					cout << temp.value << " " << temp.next << endl;
					return 1;
				}
			}
			return 0;
		}
		int del(int a){
			Node temp = this->head;
			if(temp.value=='\0'){
				cout << "Empty List";
				return 0;
			}
			while(temp.next!='\0'){
				temp = *temp.next;
				if(temp.next->value==a){
					Node *empty;
					empty = temp.next->next;
					// delete temp.next;
					temp.next = empty;
				}
			}
			return 0;
		}
		int display(){
			Node temp = this->head;
			if(temp.value=='\0'){
				cout << "Empty List";
				return 0;
			}
			while(temp.next!='\0'){
				temp = *temp.next;
				cout << temp.value << " " << temp.next << endl;
			}
			return 0;
		}
};

int main(){
	List list;
	list.insert(10);
	list.insert(21);
	list.insert(98);
	list.del(98);

	cout << "None" << endl;

	list.display();

	list.insert(65);
	list.insert(12);
	list.insert(43);
	list.insert(45);
	list.del(45);

	list.display();

	return 0;
}