#include "OSLL.h"

#include <stdlib.h>
#include <iostream>
using namespace std; 

int main(){


    cout << "\nTesting linked list:\n" << endl;
    //create list
    OSLL<int> list;

    cout << "display empty list:\n" << endl; 
    list.display();
    cout << "\n" << endl; 

    cout << "\ninserting 1, 2, 3, 5..." << endl;
    list.insert(1);
    list.insert(2);
    list.insert(5);
    list.insert(3);
    list.display(); 
    cout << "\n" << endl;  

   cout << "\nfinding 1: (true/false)" << endl; 
   if(list.find(1)==true)
     cout << "\ntrue" << endl;
    else cout << "\nfalse" << endl; 

    cout <<"\nfinding 9: (true/false)" << endl;
    if(list.find(9))
        cout << "true" << endl;
    else cout << "false" << endl;

  

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

    cout <<"\nfinding 14: (true/false) " << endl; 
    if(list.find(20)==true)
        cout << "true" << endl;
    else cout << "false" << endl;
    
    cout << "\nsearching for maximum and minimum number (20 and 1): " << endl; 
    int retMax = list.getMax(); 
    int retMin = list.getMin();
    cout << "\nmax = " << retMax << endl;
    cout << "\nmin = " << retMin << endl;
    

    cout << "\nremoving 5: " << endl;
    list.remove(5);
    list.display();
    cout << "\n";
    cout << "\nremoving 9: " << endl;
    list.remove(9);
    list.display();
    cout << "\n";
    cout << "\nremoving 6: " << endl; 
    list.remove(6);
    list.display();
    cout << "\n";
    cout << "\nremoving 16: " << endl;
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
    cout << "\nremoving 11: " << endl;
    list.remove(11);
    list.display();
    cout << "\n";

    cout << "\nend of test" << endl; 

    
   
    
    
    
}

