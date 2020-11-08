#include <iostream>

using namespace std;


class Node{
 friend class List;
 private :
	int data;
	Node* next;

 public :
	Node(int v, Node * n){data = v; next = n;}};

class List{
 private :
	Node *Head;
	Node *Tail;

 public :
	List();
	void Add(int);
	void Print();};

List::List(){
	Head = NULL;
	Tail = new Node(0, NULL);}

void List::Add(int a){
	Node *Temp = new Node(a, NULL);
	
	if(Head == NULL){
		Head = new Node(a, NULL);}

	else if((Head != NULL) && (Head -> next == NULL)){
		Head -> next = Temp;
		Tail = Temp;}
		

	else{
		Tail -> next = Temp;
		Tail = Temp;}}

void List::Print(){
	if(Head == NULL){
		cout << "List is Empty.\n" << endl;}

	else{
		Node *ps = Head;
		cout << "[HEAD] ";
		while(ps != NULL){
			cout << ' ' << ps -> data;
			ps = ps -> next;}
		cout << " [TAIL]\n" << endl;}}

int main(){
	List list;
	int n = 0;

	while(n != 3){
		cout << "Choose (1)Add / (2)Print / (3)End: "; cin >> n;

		if(n == 1){
			int k;
			cout << "Number to Add : "; cin >> k;
			list.Add(k);
			cout << "Finish Add\n" << endl;}

		else if(n == 2){
			list.Print();}

		else if(n == 3){
			break;}}


	return 0;}


	
