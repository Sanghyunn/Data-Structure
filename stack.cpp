#include <iostream>
#define MAX 100

using namespace std;

class Stack{
 private :
	int Top;
	int data[MAX];
 
 public :
	void Stack_init();
	int Stack_Choice();
	int Push(int);
	int Pop(int);
	void Stack_print();
};

int Stack::Stack_Choice(){
	char s[5];
	cout << "Push or Pop or End : ";
	cin >> s;

	if(strcmp(s, "Push") == 0) return 1;
	else if(strcmp(s, "Pop") == 0) return 2;
	else if(strcmp(s, "End") == 0) return 0;
	else return -1;}

	
void Stack::Stack_init(){
	for(int i = 0; i < MAX; i++){
		data[i] = 0;}
	
	Top = -1;}

int Stack::Push(int n){
	if(Top >= MAX - 1) {cout << "Stack Overflow\n" << endl; return -1;}
	else {data[++Top] = n; return 0;}}

int Stack::Pop(int n){
	if(Top < 0) {cout << "Stack Underflow\n" << endl; return -1;}
	else {data[Top--] = 0; return 0;}}

void Stack::Stack_print(){
	cout << endl;
	if(Top < 0) cout << "Stack에 자료가 Empty 합니다." << endl;
	else{
		cout << "Stack의 자료를 보여드리겠습니다. " << endl;
		cout << " First ==> ";
		for(int i = 0; i <= Top; i++){
			if(i == 0)printf("%3d ", data[i]);
			else printf("->%3d ", data[i]);}
		cout << " ==> Last "  << endl;}
	cout << endl;}

int main(){
	int ps = - 1;
	int ck = 0;
	Stack stack;

	stack.Stack_init();

	while(ps != 0){
		while(ps == -1){
			ps = stack.Stack_Choice();
			if(ps == -1) cout << "Plz choose [Push / Pop / End] CORRECTLY\n" << endl;}

		switch(ps){
		
		int n;
	
		case 1 :
			cout << "어떤 숫자를 Push 하겠습니까? "; cin >> n;
			ck = stack.Push(n);
			break;


		case 2 : 
			ck = stack.Pop(n);
			if(ck == 0) cout << "Pop 완료." << endl;
			break;}

		if(ps == 0) break;

		if(ck == 0) stack.Stack_print();
	
		ps = -1;}


	cout << "Stack Finish\n" << endl;
	return 0;}
