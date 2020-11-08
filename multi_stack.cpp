#include <iostream>
#define MEMORY_SIZE 100
#define MAX_STACKS 10

using namespace std;


class Multi_stack{
 private:
	int memory[MEMORY_SIZE];
	int n;
 
 public:
	int top[MAX_STACKS];
	int bottom[MAX_STACKS];
	void Init_Stack();
	int Choice();
	int Push(int);
	int Pop();
	void Print_Stack();};



void Multi_stack::Init_Stack(){

	n = MAX_STACKS;

	for(int i = 0;  i < MEMORY_SIZE; i++){
		memory[i] = 0;}

	for(int i = 0; i < MAX_STACKS; i++){
		top[i] = MEMORY_SIZE / MAX_STACKS * i;
		bottom[i] = top[i];}}

int Multi_stack::Choice(){
	int ps = 0;
	char s[8];
	cout << "Choose Push or Pop or Print or End : "; cin >> s;

	if(strcmp(s, "End") == 0) return 0;
	else if(strcmp(s, "Push") == 0) ps = 1;
	else if(strcmp(s, "Pop") == 0) ps = 2;
	else if(strcmp(s, "Print") == 0) ps = 3;
	else return -1;

	n = MAX_STACKS;

	while(n < 0 || n >= MAX_STACKS){
		cout << "Which Stack Do you want?(0 ~ " << MAX_STACKS - 1 << ") : "; cin >> n;
		if(n < 0 || n >= MAX_STACKS) cout << n << " Stack is not in range. Choose another stack.\n" << endl;}


	return ps;}
	
	
int Multi_stack::Push(int a){
	if(top[n] == bottom[n+1]){
		cout << n << " Stack Overflow\n" << endl;
		return -1;}

	else{
		memory[top[n]] = a;
		top[n]++;
		cout << "Push Finish\n" << endl;
		return 0;}}

int Multi_stack::Pop(){
	if(top[n] == bottom[n]){
		cout << n << " Stack Undeflow\n" << endl;
		return -1;}

	else{
		top[n]--;	
		memory[top[n]] = 0;
		cout << "Pop Finish\n" << endl;
		return 0;}}

void Multi_stack::Print_Stack(){
	if(top[n] == bottom[n]) cout << n << " Stack Is Empty.\n" << endl;

	else{
		cout << "[FIRST] " << memory[bottom[n]];
		for(int i = bottom[n] + 1; i < top[n]; i++){
			cout << " -> " << memory[i];}
		cout << " [LAST]\n" << endl;}}


int main(){
	Multi_stack multi;
	int k = -1;

	multi.Init_Stack();

	while(k != 0){
		while(k == -1){
			k = multi.Choice();
			
			if(k == 1){
				int a;
				cout << "Insert Number to Push : "; cin >> a;
				multi.Push(a);}
			
			else if(k == 2) multi.Pop();

			else if(k == 3) multi.Print_Stack();
			
			else if(k == 0) break;}

		if(k == 0) break;


		else k = -1;}


	cout << "Multi Stack End\n" << endl;}

			
