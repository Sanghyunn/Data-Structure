#include <iostream>
#define MAX 100

using namespace std;

class Queue{
 private :
	int Top;
	int Data[MAX];
 public :
	void Init_Queue();
	int Choice();
	int Put(int);
	int Get();
	void Print_Queue();
};


void Queue::Init_Queue(){
	for(int i = 0; i < MAX; i++){
		Data[i] = 0;}

	Top = -1;}

int Queue::Choice(){
	char s[5];
	
	cout << "Choose Put or Get or End : "; cin >> s;

	if(strcmp(s, "Put") == 0) return 1;
	else if(strcmp(s, "Get") == 0) return 2;
	else if(strcmp(s, "End") == 0) return 0;
	else return -1;}

int Queue::Put(int n){
	if(Top >= MAX - 1){
		cout << "Queue Overflow\n" << endl;
		return -1;}

	else{
		Top++;
		for(int i = Top; i >= 1; i--){
			Data[i] = Data[i-1];}
		Data[0] = n;}
		return 0;}
			
int Queue::Get(){
	if(Top < 0){
		cout << "Queue Underflow\n" << endl;
		return -1;}

	else{
		Top--;
		for(int i = 0; i <= Top; i++){
			Data[i] = Data[i+1];}
		Data[Top + 1] = 0;
		return 0;}}

void Queue::Print_Queue(){
	if(Top < 0) cout << "Queue에 자료가 없습니다.\n" << endl;
	else {
		cout << "Queue의 자료를 보여드리겠습니다.\n" << endl;
		cout << "First <==";
		for(int i = 0; i <= Top; i++){
			if(i == 0) printf("%4d", Data[i]);
			else printf("  <-%4d", Data[i]);}
	cout << "  <== Last\n" << endl;}} 


int main(){
	Queue queue;
	int ps = -1; int ck = 0;

	queue.Init_Queue();

	while(ps != 0){
		while(ps == -1){
			ps = queue.Choice();
			switch(ps){
				int n;
				case -1 :
					cout << "Plz choose [Put / Get / End] CORRECTLY\n" << endl;
					break;

				case 1 :
					cout << "Put할 숫자를 입력하세요. "; cin >> n;	
					ck = queue.Put(n);
					break;

				case 2 :
					ck = queue.Get();
					if(ck == 0) cout << "Get을 완료했습니다.\n" << endl;
					break;}}

		if(ps == 0) break;

		ps = -1;


		if(ck == 0) queue.Print_Queue();}

	cout << "Queue 종료." << endl;

	return 0;}
