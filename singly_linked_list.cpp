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
	int index;

 public :
	List(){Head = NULL; Tail = NULL; index = 0;}
	int Choice();
	void Add(int);
	void Print();
	void Search(int);
	void Insert(int, int);
	void Delete(int);
	~List(){while(Head != NULL){Delete(index);} cout << "Linked List End" << endl;}};

int List::Choice(){
	int n = 0;

	
	while( n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6){
		cout << "Choose (1) Add / (2) Print / (3) End / (4) Search / (5) Insert / (6) Delete : "; cin >> n; 
		if( n != 1 && n != 2 && n != 3 && n != 4 && n != 5 && n != 6) cout << "Plz Choose Number CORRECTLY\n" << endl;}
	return n;} 

void List::Add(int a){
	Node * Temp = new Node(a, NULL); 

	if(Head == NULL){
		Head = Temp;
		Tail = Temp;}

	else if((Head != NULL) && (Head -> next == NULL)){
		Head -> next = Temp;
		Tail = Temp;}

	else {
		Tail -> next = Temp;
		Tail = Temp;}

	index++;

	cout << "Number "<< a << " is Added\n" << endl;}

void List::Print(){
	if(Head == NULL){
		cout << "Unavailable to Print(List is Emtpy)\n" << endl;}

	else{
		int cnt = 1;
		Node * ps = Head;
		cout << "[HEAD] (" << cnt << ") " << ps -> data;
		ps = ps -> next;

		while(ps != NULL){
			cnt++;
			cout << " -> (" << cnt << ") " << ps -> data;
			ps = ps -> next;}
		cout << " [TAIL]\n" << endl;}}

void List::Insert(int a, int i){

	if(i > index){
		cout << "Unavailable to Insert(Index Overflow)\n" << endl;}

	else{
		Node *insert = new Node(a, NULL);
		Node *ps = Head;

		if(i == 1){
			insert -> next = Head;
			Head = insert;}
		
		else {
			for(int j = 1; j < i - 1; j++){
				ps = ps -> next;}
		
			insert -> next = ps -> next;
			ps -> next = insert;}

		index++;

		cout << "Number " << a << " is Inserted at " << i << " index\n" << endl;}}

		


void List::Search(int i){
	if(Head == NULL){
		cout << "Unavailable to Search (List is Empty)\n" << endl;}

	else if(i > index){
		cout << "Unavailable to Search (Index Overflow)\n" << endl;}

	else{
		Node *ps = Head;
		
		for(int j = 1; j < i; j++){
			ps = ps -> next;}

		cout << i << " index's data : " << ps -> data << '\n' << endl;}}	

	
void List::Delete(int i){
	if(Head == NULL){
		cout << "Unavailable to Delete (List is Empty)\n" << endl;}

	else if(i > index){
		cout << "Unavailable to Delete (Index Overflow)\n" << endl;}

	else{
		Node *Temp;
		Node *ps = Head;

		if(i == 1){
			Temp = Head -> next;
			delete Head;

			Head = Temp;}

		else{
			for(int j = 1; j < i - 1; j++){
				ps = ps -> next;}

			Temp = ps -> next -> next;
			delete ps -> next;
	
			ps -> next = Temp;}

		cout << index << " index is Deleted\n" << endl;
	
		index--;}}

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

		else if(ps == 3) break;

		else if(ps == 4){
			int index;
			cout << "Index to Search : "; cin >> index;
			list.Search(index);}

		else if(ps == 5){
			int index;
			int number;
			cout << "Number to Insert : "; cin >> number;
			cout << "Index to Search : "; cin >> index;
			list.Insert(number, index);}

		else if(ps == 6){
			int index;
			cout << "Index to Delete : "; cin >> index;
			list.Delete(index);}}


	return 0;}
