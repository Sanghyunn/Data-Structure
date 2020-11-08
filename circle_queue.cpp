#include <iostream>
#define MAX 10

using namespace std;

class Queue{
 private:
	int front;
	int rear;
	int ary[MAX];

 public:
	void init_queue();
	int Choice();
	int Put(int);
	int Get();
	void print_queue();
};

void Queue::init_queue(){
	front = 0;
	rear = 0;
	
	for(int i = 0; i < MAX; i++){
		ary[i] = 0;}
	}

int Queue::Choice(){
	char s[5];
	cout << "Choose Put or Get or End : ";
	cin >> s;

	if(strcmp(s, "Put") == 0) return 1;
	
	else if(strcmp(s, "Get") == 0) return 2;

	else if(strcmp(s, "End") == 0) return 0;
	
	else return -1;}

int Queue::Put(int n){
	if((rear == front) && (ary[(rear + 1) % MAX] != 0)){
		cout << "Stack Overflow\n" << endl;
		return -1;}

	else{
		ary[rear] = n;
		rear = (rear + 1) % MAX;
		cout << "숫자 " << n << "을 Put 했습니다." << endl;
		print_queue();

		return 0;}}

int Queue::Get(){
	if((front == rear) && (ary[(rear + 1) % MAX] == 0)){
		cout << "Stack UnderFlow\n" << endl;
		return -1;}

	else{
		cout << "숫자 " << ary[front] <<"을 Get 헀습니다." << endl; 
		ary[front] = 0;
		front = (front + 1) % MAX;
		print_queue();
		return 0;}}

void Queue::print_queue(){
	if((front == rear) && (ary[(rear + 1) % MAX] == 0)){
		cout << "Queue is Empty.\n" << endl;}

	else{
		cout << " [FIRST] -> ";
		if(front < rear){
			for(int i = front; i < rear; i++){
				cout << ary[i] << " -> ";}}

		else{
			for(int i = front; i < MAX; i++){
				cout << ary[i] << " -> ";}

			for(int i = 0; i < rear; i++){
				cout << ary[i] << " -> ";}}

		cout << " [LAST] \n" << endl;}}
int main(){
	Queue queue;
	
	queue.init_queue();

	int ps = -1;

	while(ps != 0){
		while(ps == -1){
			ps = queue.Choice();

			if(ps == 1){
				int n;
				cout << "어떤 숫자를 Put 하시겠습니까? : "; cin >> n;
				queue.Put(n);}

			else if(ps == 2){
				queue.Get();}

			else if(ps == 0) {break;}

			else {cout << "Plz Choose [ Put / Get / End] CORRECTLY\n" << endl;}}


			if(ps == 0) break;

			else ps = -1;}

	cout << "Circle Queue를 종료합니다." << endl;


	return 0;}

