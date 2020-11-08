#include <iostream>
#define MEMORY_SIZE 100
#define MAX_QUEUE 10


using namespace std;


class Multi_Queue{
 private:
	int n;
	int memory[MEMORY_SIZE];

 public:
	int front[MAX_QUEUE];
	int rear[MAX_QUEUE];
	Multi_Queue();
	int Choice();
	int Put(int);
	int Get();
	void Print();};

Multi_Queue::Multi_Queue(){
	for(int i = 0; i < MEMORY_SIZE; i++){
		memory[i] = 0;}
	
	for(int i = 0; i < MAX_QUEUE; i++){
		front[i] = 0;
		rear[i] = front[i];}}

int Multi_Queue::Choice(){
	n = MAX_QUEUE;
	int ps = 0;
	char s[10];

	cout << "Choose Put or Get or Print or End : "; cin >> s;

	if(strcmp(s, "Put") == 0) ps = 1;
	else if(strcmp(s, "Get") == 0) ps = 2;
	else if(strcmp(s, "Print") == 0) ps = 3;
	else if(strcmp(s, "End") == 0) return 0;
	else return -1;


	while(n < 0 || n >= MAX_QUEUE){
		cout << "Choose the Queue Number(0 ~ " << MAX_QUEUE - 1 << ") : "; cin >> n; 
		if(n >= 0 && n < MAX_QUEUE) continue;
		else cout << n << " QUEUE is not in range. Choose another QUEUE.\n" << endl;}

	return ps;}

int Multi_Queue::Put(int a){
	if(front[n] == rear[n] && memory[n * MAX_QUEUE + front[n] + 1] != 0){
		cout << n << " Stack Overflow\n" << endl;
		return -1;}

	else{
		memory[n * MAX_QUEUE + rear[n]] = a;
		rear[n] = (rear[n] + 1) % MAX_QUEUE;
		cout << "Put Finish\n" << endl;
		cout << "front is " << front[n] << endl;
		cout << "rear is " << rear[n] << endl;
		cout << memory[n * MAX_QUEUE + front[n] + 1] << endl;}
		return 0;}

int Multi_Queue::Get(){
	if(front[n] == rear[n] && memory[n * MAX_QUEUE + (front[n] + 1)] == 0){
		cout << n << " Stack Underflow\n" << endl;
		return -1;}

	else{
		memory[n * MAX_QUEUE + front[n]] = 0;
		front[n] = (front[n] + 1) % MAX_QUEUE;
		cout << "Get Finish\n" << endl;
		return 0;}}

void Multi_Queue::Print(){
	if(front[n] == rear[n] && memory[n * MAX_QUEUE + front[n] + 1] == 0){
		cout << n << " Stack is Empty\n" << endl;}

	else{
		cout << n << " Stack\t" << "[FRONT] " << memory[n * MAX_QUEUE + front[n]];
		if(front[n] < rear[n]){
			for(int i = (front[n] + 1) % MAX_QUEUE; i < rear[n]; i++){
				cout << " -> " << memory[n * MAX_QUEUE + i];}}

		else{
			for(int i = (front[n] + 1) % MAX_QUEUE; i < MAX_QUEUE; i++){
				cout << " -> " << memory[n * MAX_QUEUE + i];}

			for(int i = 0; i < rear[n]; i++){
				cout << " -> " << memory[n * MAX_QUEUE + i];}}

		cout << " [LAST]\n" << endl;}}


int main(){
	Multi_Queue multi;
	int ps = -1;
	
	while(ps != 0){
		while(ps == -1){
			ps = multi.Choice();

			if(ps == 1){
				int a;
				cout << "Insert Number to Put : "; cin >> a;
				multi.Put(a);}

			else if(ps == 2){
				multi.Get();}

			else if(ps == 3){
				multi.Print();}

			else if(ps == 0) break;}

		if(ps == 0) break;

		else ps = -1;}


	cout << "Multi_Queue End\n" << endl;

	return 0;}

