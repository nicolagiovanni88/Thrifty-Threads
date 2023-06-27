#include <iostream>
#include <string>

using namespace std;

//Class for the Threads 
class Thread {
private: 
	string color; 
	int length; 
	int width;
public: 
	Thread(); 
	Thread(string c, int l, int w);
	
	//Accessors 
	string getColor(); 
	int getLength(); 
	int getWidth(); 

	//Mutators 
	void setColor(string c);  
	void setLength(int l); 
	void setWidth(int w); 
};

//Default Constructor 
Thread::Thread(){
	color = ""; 
	length = 0; 
	width = 0; 
}

//Parameterized Constructor
Thread::Thread(string c, int l, int w){
	color = c; 
	length = l; 
	width = w; 
}

//Accessors 
string Thread::getColor(){
	return color; 
}

int Thread::getLength(){
	return length;	
}

int Thread::getWidth(){
	return width; 
}

//Mutators 
void Thread::setColor(string c){
	color = c; 
}

void Thread::setLength(int l){
	length = l; 
}

void Thread::setWidth(int w){
	width = w; 
}

//Class for the Thrifty Threads 
class ThriftyThreads {
private: 
	Thread *threads; 
	int numThreads; 
public: 
	ThriftyThreads(); 
	ThriftyThreads(int num); 
	~ThriftyThreads(); 

	//Accessors 
	int getNumThreads(); 
	Thread getThread(int index); 

	//Mutators
	void setNumThreads(int n);
	void setThread(string c, int l, int w);
	void setThread(int index, string c, int l, int w); 
};

//Default Constructor 
ThriftyThreads::ThriftyThreads(){
	threads = nullptr; 
	numThreads = 0; 
}

//Parameterized Constructor
ThriftyThreads::ThriftyThreads(int n){
	numThreads = n; 
	threads = new Thread[numThreads]; 
}

//Destructor 
ThriftyThreads::~ThriftyThreads(){
	delete [] threads;
}

//Accessors 
int ThriftyThreads::getNumThreads(){
	return numThreads; 
}

Thread ThriftyThreads::getThread(int index){
	return threads[index]; 
}

//Mutators 
void ThriftyThreads::setNumThreads(int n){
	numThreads = n; 
}

void ThriftyThreads::setThread(string c, int l, int w){
	Thread t(c, l, w); 
	threads[numThreads] = t; 
	numThreads++; 
}

void ThriftyThreads::setThread(int index, string c, int l, int w){
	Thread t(c, l, w); 
	threads[index] = t; 
}

int main(){
	//Create an instance of ThriftyThreads 
	ThriftyThreads tt(3); 

	//Add threads to tt 
	tt.setThread("red", 50, 5); 
	tt.setThread("green", 60, 10); 
	tt.setThread("blue", 40, 15); 

	//Output the information about Threads 
	for(int i = 0; i < tt.getNumThreads(); i++){
		Thread t = tt.getThread(i); 
		cout << "Thread " << i+1 << ": " << endl; 
		cout << "\tColor: " << t.getColor() << endl; 
		cout << "\tLength: " << t.getLength() << endl; 
		cout << "\tWidth: " << t.getWidth() << endl; 
	}

	return 0; 
}