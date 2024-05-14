#include "OSLL.h"
#include "OSULL.h"

#include <stdlib.h>
#include <iostream>
#include <chrono>
#include <ctime>
#include <ratio>
//#include <vector>
//#include <time.h>

using std::cout;
using std::endl;
using namespace std; 


//Gurveen Nanua
//301546459
// running an experiemnt on array, LL, and ULL

int main(){

using namespace chrono; 

//const int SIZE = 100000;
const int CACHE_SIZE = 196608; // using command sysctl -a | grep hw.l1 in terminal to find cache size
const int INT_SIZE = sizeof(int);
const int TEN = 10; 
const int SIZE = CACHE_SIZE/INT_SIZE * TEN; //muliply by number to garuntee chache misses

cout << "\nArray traveral..." << endl;
steady_clock::time_point a1 = steady_clock::now();

//mkae an array list
int a[SIZE]; 
for(long int i=0; i<SIZE; i++){
    a[i] = i;
}
steady_clock::time_point a2 = steady_clock::now();
duration<double> aTime = duration_cast<duration<double> >(a2 - a1); 

cout << "\nDoubly linked list traversal..." << endl; 
steady_clock::time_point b1 = steady_clock::now();
//make a linked list 
OSLL <int> b; 
for(int i=0; i<SIZE; i++){
    b.insert(i);
}

steady_clock::time_point b2 = steady_clock::now();
duration<double> bTime = duration_cast<duration<double> >(b2 - b1); 


cout << "\nUnrolled linked list traversal..." << endl;
steady_clock::time_point c1 = steady_clock::now();

//make an unrolled linked list
OSULL <int> c;
for(int i=0; i<SIZE; i++){
    c.insert(i);
}

steady_clock::time_point c2 = steady_clock::now();
duration<double> cTime = duration_cast<duration<double> >(c2 - c1);

//output results
cout << "\ntraversal insert time for array: " << aTime.count() << endl;
cout << "traversal insert time for doubly linked list: " << bTime.count() << endl;
cout << "traversal insert time for unrolled linked list: " << cTime.count() << endl;

//measuring traveral time for array
cout << "\nArray traveral..." << endl;
steady_clock::time_point aout1 = steady_clock::now();

//printing array
for(int i=0; i<SIZE; i++){
    cout << a[i] << " " << endl; 
    
}

steady_clock::time_point aout2 = steady_clock::now();
duration<double> aoutTime = duration_cast<duration<double> >(aout2 - aout1); 


//measuring traversal time for doubly linked list
cout << "\nDoubly linked list traversal..." << endl; 
steady_clock::time_point bout1 = steady_clock::now();

//printing linked list
b.display();


steady_clock::time_point bout2 = steady_clock::now();
duration<double> boutTime = duration_cast<duration<double> >(bout2 - bout1); 


//measuring traversal time for unrolled linked list
cout << "\nUnrolled linked list traversal..." << endl;
steady_clock::time_point cout1 = steady_clock::now();

//printing unrolled linked list
c.display(); 


steady_clock::time_point cout2 = steady_clock::now();
duration<double> coutTime = duration_cast<duration<double> >(cout2 - cout1); 

//output results
cout << "\ntraversal print time for array: " << aoutTime.count() << endl;
cout << "traversal print time for doubly linked list: " << boutTime.count() << endl;
cout << "traversal print time for unrolled linked list: " << coutTime.count() << endl;
 


//finding item in array 
cout << "\nArray traveral..." << endl;
steady_clock::time_point A1 = steady_clock::now();

//printing array
for(int i=0; i<SIZE; i++){
    if(a[i]==SIZE-1){
        break;
    }
    
}

steady_clock::time_point A2 = steady_clock::now();
duration<double> ATime = duration_cast<duration<double> >(A2 - A1); 


//finding item in doubly linked list 
cout << "\nDoubly linked list traveral..." << endl;
steady_clock::time_point B1 = steady_clock::now();

//finding SIZE-2 int the linked list
b.find(SIZE-1);

steady_clock::time_point B2 = steady_clock::now();
duration<double> BTime = duration_cast<duration<double> >(B2 - B1); 


//finding item in an unrolled linked list 
cout << "\nUnrolled linked list traversal..." << endl;
steady_clock::time_point C1 = steady_clock::now();

//finding SIZE-2 in unrolled linked list
c.find(SIZE-1);

steady_clock::time_point C2 = steady_clock::now();
duration<double> CTime = duration_cast<duration<double> >(C2 - C1);

//output results
cout << "\ntraversal find time for array: " << ATime.count() << endl;
cout << "traversal find time for doubly linked list: " << BTime.count() << endl;
cout << "traversal find time for unrolled linked list: " << CTime.count() << endl;  



return 0;
}



