#include <iostream>

using namespace std;


class Node{
 friend class List;
 private :
	int data;
	Node * next;

 public :
	Node(int v, Node * n){data = v; next = n;}};

class List{
 private :
	Node * Head;
	Node * Tail;

 public :
	List(){Head = NULL; Tail = NULL;}
	int Choice();
	void Add(int);
	void Print();};

int List::Choice(){
	int n = 0;

	
	while( n != 1 && n != 2 && n != 3 ){
		cout << "Choose (1) Add / (2) Print / (3) End : "; cin >> n; 
		if( n != 1 && n != 2 && n != 3 ) cout << "Plz Choose Number CORRECTLY\n" << endl;}
	return n;} 

void List::Add(int a){
	Node * Temp = new Node(a, NULL); 

	if(Head == NULL){
		Head = Temp;}

	else if((Head != NULL) && (Head -> next == NULL)){
		Head -> next = Temp;
		Tail = Temp;}

	else {
		Tail -> next = Temp;
		Tail = Temp;}

	cout << "Number "<< a << " is Added\n" << endl;}

void List::Print(){
	if(Head == NULL){
		cout << "List is Emtpy\n" << endl;}

	else{
		Node * ps = Head;
		cout << "[HEAD] " << ps -> data;
		ps = ps -> next;

		while(ps != NULL){
			cout << " -> " << ps -> data;
			ps = ps -> next;}
		cout << " [TAIL]\n" << endl;}}

int main(){
	List list;

	int ps = 0;
	
	while(ps != 3){
		ps = list.Choice();
		if(ps == 1){
			int number;
			cout << "Number to Add : "; cin >> number;
			list.Add(number);}

		else if(ps == 2){
			list.Print();}

		else if(ps == 3) break;}


	cout << "Linked List End" << endl;

	return 0;}

			
	
	
		


