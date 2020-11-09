#include <iostream>

using namespace std;

class Node{
friend class List;
 private :
	int data; Node *next;
	Node *prev; public :
	Node(int v, Node *p, Node *n){data = v; next = n; prev = p;}
};

class List{
 private :
	Node *Head;
	int index;

 public:
	List(){Head = NULL; index = 0;}
	void Add(int);
	void Insert(int, int);
	void Delete(int);
	void Print();
	~List(){while(index != 0){Delete(index);} cout << "Double Linked List End\n" << endl;}
};

void List::Add(int a){
	Node *temp = new Node(a, NULL, NULL);

	if(Head == NULL){
		Head = temp;}


	else{
		Node *ps = Head;
		while(ps -> next != NULL){
			ps = ps -> next;}
		
		temp -> prev = ps;
		ps -> next = temp;}

	cout << "Number " << a << " is Added\n" << endl;

	index++;}
		

void List::Insert(int i, int n){
	if(Head == NULL){
		cout << "Unavailable to Insert(List is Empty. Try Add Function)\n" << endl;}

	else if(i > index){
		cout << "Unavailable to Insert(Index Oveflow)\n" << endl;}

	else{
		Node *temp = new Node(n, NULL, NULL);
		Node *ps = Head;

		for(int j = 1; j < i; j++){
			ps = ps -> next;}

		if(ps == Head){
			temp -> next = Head;
			Head -> prev = temp;
			Head = temp;}

		else{
			ps -> prev -> next = temp;
			temp -> prev = ps -> prev;
			temp -> next = ps;
			ps -> prev = temp;}

		cout << "Number " << n << " is Inserted to " << i << " index\n" << endl;

		index++;}}

 
			
void List::Delete(int i){
	if(Head == NULL){
		cout << "Unavailable to Delete(List is Empty)\n" << endl;}

	else if(i > index){
		cout << "Unavailable to Delete(Index Overflow)\n" << endl;}

	else{

		Node *ps = Head;

		
		for(int j = 1; j < i; j++){
			ps = ps -> next;}

		if(ps == Head){
			Head = Head -> next;}

		else{
			if(ps -> next == NULL){
				ps -> prev -> next = NULL;}
			
			else{
				ps -> prev -> next = ps -> next;
				ps -> next -> prev = ps -> prev;}}
		


		cout << i << " index is Deleted\n" << endl;
		delete ps;
		index--;}}


void List::Print(){
	if(Head == NULL){
		cout << "List is Empty\n" << endl;}

	else{ 
		int num = 1;
		Node *ps = Head;
		cout << "[HEAD] (" << num << ") " << ps -> data;
		ps = ps -> next;

		while(ps != NULL){
			num++;
			cout << " -> (" << num << ") " << ps -> data;
			ps = ps -> next;}

		cout << " [TAIL] \n" << endl;}}



int main(){
	List list;
	int ps = 0;

	while(ps != 5){
		while(ps > 5 || ps < 1){
			cout << "Choose (1) Add / (2) Delete / (3) Insert / (4) Print / (5) End : "; cin >> ps;
			if(ps == 1){
				int a; cout << "Number to Add : "; cin >> a;
				list.Add(a);}

			else if(ps == 2){
				int i; cout << "Index to Delete : ";  cin >> i;
				list.Delete(i);}

			else if(ps == 3){
				int a; int i;
				cout << "Index to Insert : "; cin >> i;
				cout << "Number to Insert : "; cin >> a;
				list.Insert(i, a);}

			else if(ps == 4){
				list.Print();}
			
			else if(ps == 5) break;

			else cout << "Choose Number CORRECTLY\n" << endl;}


		if(ps == 5) break;

		else ps = 0;}

	return 0;}

