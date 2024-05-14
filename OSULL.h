/* Ordered Set Implemented in an Unrolled (Doubly)-Linked List */
// File: OSULL.h

#include <iostream>
#include <cstring>
using namespace std;


template <typename T, int initNodeCapacity = 10 > 
class OSULL
{
public:
   OSULL(){

      // set the node capacity  
      nodeCapacity = initNodeCapacity ;

      // make the front and back dummy nodes 
      front = new Node( nullptr, nullptr, nodeCapacity );
      back = new Node( front, nullptr, nodeCapacity );
      front->next = back;

      size = 0 ;
      nodeCount = 0 ; 
   }
   ~OSULL(){
      Node * cursor = front ;
      while( cursor != nullptr ){
         Node * current = cursor ;
         cursor = cursor-> next ;
         delete  current ;
      }
   }
   bool isEmpty(){ return size==0 ;}
   int get_size(){ return size ;}

   bool insert(T item){
      // inserts item into the list, if it is not there already
      // returns true if inserted; false if it was already there
      //
      // IMPLEMENT THIS
      int mid;

      //if theres no nodes
      if(nodeCount == 0){
         Node *newNode = new Node(front, back, nodeCapacity);
         front->next = newNode;
         back->prev = newNode;
         nodeCount++;
         //cout << "was able to insert: " << item << endl; 
         newNode->insert(item);
         return true; 
      }

      //if there is only one node
      Node* cursor = front->next; 

      if(nodeCount==1 && cursor->getSize() < cursor->getCapacity()){
          if(cursor->find(item)==true){
            //cout << "couldnt insert" << endl;
            return false;
         }
         cursor->insert(item);
         //cout << "was able to insert: " << item << endl; 
         return true; 
      }

      //if node is greater than 1
      else if(nodeCount>1){
        
         while(cursor != back && item <= cursor->getMax() ){
            cursor = cursor->next; 
         }

         if(cursor->find(item)==true){
            //cout << "couldnt insert" << endl;
            return false;
         }

      }

      if(cursor->getSize() == cursor->getCapacity()){
         Node *newNode = new Node(cursor, cursor->next, nodeCapacity);
         cursor->next->prev = newNode; 

         mid = cursor->getSize() / 2;
         for(int i=mid; i<cursor->getSize(); i++){
            newNode->insert(cursor->data[i]);
            cursor->remove(cursor->data[i]);
         }
         
         cursor->next = newNode;
         nodeCount++;
      }

      cursor->insert(item);
      //cout << "\nwas able to insert: " << item << endl;
      return true; 

   ; }

   bool find(T item){ 
      // returns true if found; false otherwise 
      //
      // IMPLEMENT THIS 
      //
       if(nodeCount==0) //if the list is empty
         return false; 

      Node* cursor = front -> next;
      
      while(cursor != back && item <= cursor->getMax()){
         if(cursor->find(item)==true){ //checks if its there
            //cout << "found item" << endl;
            return true; 
         }
         //cout << "checking next node" << endl; 
         cursor = cursor->next;
      }
      return false; //if not then false
      
   ; }

   bool remove(T item){
      // returns false if the item was not there; true if it was
      //
      // IMPLEMENT THIS
      //

      int i;
      //if list is mepty
      if(nodeCount==0){
         //cout << "empty set" << endl;
         return false; 
      }

      //go through the list to finnd item
      Node* cursor = front->next;
      while(cursor != back && item <= cursor->getMax()){
         if(cursor->find(item)==true){
            cursor->remove(item);
            break;
         }
         else {
            cursor = cursor -> next; 
         }
      }

      //return false if item not in list
      if(cursor==back && cursor->prev->find(item)==false){
         //cout << "coudnt find item in any nodes" << endl;
         return false; 
      }

      //check if node size is too small 
      if(cursor->getSize() < cursor->getCapacity() / 2 && cursor != front->next){
         //check the prev node
         Node *prevNode = cursor->prev;
         Node *nextNode = cursor->next;
          

         if(prevNode->getSize() > prevNode->getCapacity() / 2){ //take from prev node
            T val = prevNode->data[prevNode->getSize()-1]; //take last val
            //cout << "\nmoving over value " << val << endl; 
            prevNode->remove(val);
            cursor->insert(val);
            
         }

            //merge them together
         else{ 
            int cursorsize = cursor->getSize();
            //cout << "\nmerging list together" << endl;
            for(i=0; i<cursorsize; i++){
               prevNode->insert(cursor->data[i]);
               //cursor->remove(cursor->data[i]);
                  
            }
            //get rid of cursor
            prevNode->next = nextNode;
            if(nextNode != nullptr)
               nextNode->prev = prevNode; 
            delete cursor; 
            nodeCount--;
            cursor = prevNode;
            }

            //cout << "remvoed item: " << item << endl;
            return true; 
         }

         //cout << "remvoed item: " << item << endl;
         return true;         

   ; }

   T getMin(){// returns the minimum item in the list
      // requires: size not 0  
      //
      // IMPLEMENT THIS 
      //
      Node *cursor = front->next; 
      T min = cursor->getMin();

      while(cursor!=back){
         if(cursor->getMin() < min)
            min = cursor->getMin();
         cursor = cursor->next;
      }
      return min; 
      
    ; } 

   T getMax(){// returns the maximum item in the list
      // requires: size not 0 
      //
      // IMPLEMENT THIS
      //
      Node *cursor = front->next; 
      T max = cursor->getMax();
      while(cursor!=back){
         if(cursor->getMax() > max)
            max = cursor->getMax();
         cursor = cursor->next; 
      }
      return max; 
      
   ;}

   void display(){
      // prints out the list contents 
      Node * cursor = front-> next ;
      cout << "<" ;
      while( cursor != back ){
         cursor -> display() ; 
         cursor = cursor-> next ;
      }
      cout << " >" ;
   }
      
private:

   class Node{
      public: 
      Node( Node* prev, Node* next, int capacity ){
         // notice that we can use the constructor arguments to 
         // do most o the work of inserting a new node into the list 
         this->prev = prev ;
         this->next = next ;
         this->capacity = capacity ;
         data = new T[capacity] ;
         size = 0 ;
      }
      Node * prev ; // pointer to the next node 
      Node * next ; // pointer to the previous nodes 
      int capacity ; // capacity of this node 
      T * data ; // array of data items in this node 
      int size ; // current number of items in this node 
      int getCapacity(){// return the capacity of this node 
         return capacity; 
      }
      int getSize(){// return the number of items in this node
         return size; 
      }
      T getMin(){// return the smallest item in this node
         // requires: this->size not 0 
         return data[0] ; 
      }
      T getMax(){// return the largest item in this node 
         // requires: this->size not 0 
         return data[size-1] ; 
      }
      bool insert(T item){
         // inserts item into this node if it was not already there 
         // returns true if the item was inserted, false otherwise 
	 //
         // IMPLEMENT THIS 
         
         int index=0;
         while(index < size && data[index] < item){
            index++;
         }

         if (data[index] != item) { // Check if index is at the end or item is not found
            for (int i = size; i > index; i--) { // Shift elements to the right
               data[i]=data[i-1];
            }
            data[index] = item; // Insert the item at the correct position
            size++;
            //cout << "index: " << index << endl;
            return true;
         }
         return false; 
         
      ;}
      bool find(T item){
         // searches for item in this node 
         // returns true if found, false otherwise 
	 //
         // IMPLEMENT THIS
         int i=0;
         while(i<size){
            if(data[i]==item)
               return true; 
            i++;
         }
         return false; 
         
	 //
      ;}
      bool remove(T item){
         // remove item from this node
         // returns true if the item was removed, false otherwise 
	 //
         // IMLEMENT THIS
        
         int index=0;
         while(index<size){
            if(data[index]==item)
               break;
            index++;
         }

         if(data[index]==item){
            for(int i=index; i<size; i++){
               data[i] = data[i+1];
            }
            //cout << "\nremoved " << item << endl;
            size--;
            return true;
         }
         return false; 
         
          
	 //
      ;}
      void display(){// print the contents of this list 
	 // 
         // IMPLEMENT THIS
	 //
	 //
         int i=0;
         int size = getSize();
         cout << " <" ;  
         while(i<size) {
            cout << data[i] << ",";
            i++;
         }   
         cout << ">";

      ;} 
   };

   int size ; // current number of items 
   int nodeCount ; // current number of nodes 
   int nodeCapacity ; // capacity to assign to new nodes 
   Node * front ; // pointer to front dummy node 
   Node * back ;  // pointer to back dummy node 
};
