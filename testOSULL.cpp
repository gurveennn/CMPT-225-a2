#include "OSULL.h"

#include <stdlib.h>
#include <iostream>
using namespace std; 

int main(){

    cout << "\nTesting Unrolled Linked List\n" << endl;
    //create list
    OSULL<int> list;

    cout << "display empty list:\n" << endl; //show empty list
    list.display();
    cout << "\n" << endl; 

    cout << "\ninserting 1, 2, 3, 5..." << endl; //seeing if insert function workds
    list.insert(1);
    list.insert(2);
    list.insert(5);
    list.insert(3);
    list.display(); 
    cout << "\n" << endl;  

   cout << "\nfinding 1: (true/false)" << endl; //seeing if find function works
   if(list.find(1)==true)
     cout << "\ntrue" << endl;
    else cout << "\nfalse" << endl; 

    cout <<"\nfinding 9: (true/false)" << endl;
    if(list.find(9))
        cout << "true" << endl;
    else cout << "false" << endl;

  
    //adding more numbers
    cout << "\ninserting numbers 0-19: " << endl;
    const int N = 20;
    for(int i=0; i<N ; i++){
        list.insert(i);
    }
    list.display();
    cout << "\n" << endl; 

    cout <<"\nfinding 14: (true/false) " << endl; 
    if(list.find(14)==true)
        cout << "true" << endl;
    else cout << "false" << endl;

    cout << "\ninserting 20..." << endl;
    list.insert(20);

    list.display();
    cout << "\n" << endl; 

    cout <<"\nfinding 20: (true/false) " << endl; 
    if(list.find(20)==true)
        cout << "true" << endl;
    else cout << "false" << endl;
    
    //checing if max and min return correct numbers
    cout << "\nsearching for maximum and minimum number (20 and 0): " << endl; 
    int retMax = list.getMax(); 
    int retMin = list.getMin();
    cout << "\nmax = " << retMax << endl;
    cout << "\nmin = " << retMin << endl;
    

    //removing a number, barrowing and merging
    cout << "\nremoving 5: " << endl;
    list.remove(5);
    list.display();
    cout << "\n";
    cout << "\nremoving 9, merging lists together: " << endl;
    list.remove(9);
    list.display();
    cout << "\n";
    cout << "\nremoving 6: " << endl; 
    list.remove(6);
    list.display();
    cout << "\n";
    cout << "\nremoving 16, moving over value 20: " << endl;
    list.remove(16);
    list.display();
    cout << "\n";
    cout << "\nremoving 15: " << endl; 
    list.remove(15);
    list.display();
    cout << "\n";
    cout << "\nremoving 14: " << endl;
    list.remove(14);
    list.display();
    cout << "\n";
    cout << "\nremoving 11, moving over 18: " << endl;
    list.remove(11);
    list.display();
    cout << "\n";

    cout << "\nend of test" << endl; 

    
   
    
    
    
}

