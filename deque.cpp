#include "deque.h"
#include <string>
#include <iostream>
using namespace std;
Deque::Deque(){
  left_p=NULL;
  right_p=NULL;
  current_size=0;
  cursor=NULL;
}

Deque::Deque( const Deque& dq ){

  if(dq.left_p==NULL){
    left_p=NULL;
    right_p=NULL;
    current_size=0;
    cursor=NULL;
  }
  else{
    node *p = dq.left_p;
    left_p = new node(p->data,NULL, NULL);
    node*temp = left_p;

    for(int i =0;i<dq.current_size;i++){
      right_p = temp;

      if(i!=dq.current_size-1){
      p =p->next;
      temp->next = new node(p->data, temp, NULL);
      temp=temp->next;

      }
      current_size=dq.current_size;
    }
  }


}

Deque::~Deque(){

	for(int i=0; i<current_size; i++){
		node *temp = left_p;
		left_p= temp->next;
		delete temp;
	}
}

void Deque::push_left(int item){

  if(left_p==NULL){
    node *p=new node(item,NULL,NULL);
    left_p=p;
    right_p=p;
    cursor=p;
    current_size++;
  }
  else{
    node *p=new node(item,NULL,NULL);
    left_p->prev=p;
    p->next=left_p;
    left_p=p;
    current_size++;
  }

}
void Deque::push_right(int item){

  if(right_p==NULL){
    node *p=new node(item,NULL,NULL);
    left_p=p;
    right_p=p;
    cursor=p;
    current_size++;
  }
  else{
    node *p=new node(item,NULL,NULL);
    right_p->next=p;
    p->prev=right_p;
    right_p=p;
    current_size++;
  }

}
int Deque::pop_left(){
if(left_p==NULL){
  cout<<"no element in the deque"<<endl;
  return -1;
}
else{
  node *temp=left_p;
  int val = left_p->data;
  left_p = left_p->next;
  if (current_size ==1){
    delete left_p;
	   cursor = NULL;
	    right_p = NULL;
      }
else if (cursor == temp){
	cursor_right();
}
delete temp;
current_size--;
return val;
}
}


int Deque::pop_right(){
if(right_p==NULL){
cout<<"no element in the deque"<<endl;
return -1;
}
else{
node *temp=right_p;
int val = right_p->data;
right_p = right_p->prev;
if (current_size ==1){
  delete right_p;
	cursor = NULL;
	left_p = NULL;
}
else if (cursor == temp){
	cursor_left();
}
delete temp;
current_size--;
return val;
}
}

bool Deque::empty(){
//If size is 0 return true. Else false
	if(size()==0){
		return true;
	}
	else{
		return false;
	}
}

int Deque::size(){
//Return the size
	return current_size;

}


bool Deque::cursor_left(){
  if(cursor->prev!=NULL){
    cursor=cursor->prev;
    return true;
  }
  else{
    return false;
  }
}


bool Deque::cursor_right(){
  if(cursor->next!=NULL){
    cursor=cursor->next;
    return true;
  }
  else{
    return false;
  }
}

 int Deque::peek_left(){
 if(left_p==NULL){
   return -1;
 }
 else{
   return left_p->data;
 }

 }
 int Deque::peek_right(){
 if(right_p==NULL){
   return -1;
 }
 else{
   return right_p->data;
 }


 }
int Deque::get_cursor(){
   if(left_p==NULL){
     return -1;
   }
   return cursor->data;
 }

 void Deque::set_cursor(int i){
cursor->data=i;
 }



void Deque::display(){

  if(left_p==NULL){
    cout << "[] size=0, cursor=NULL" << '\n';
    return ;
  }
   node * temp = left_p;
   cout<<"[";
      for(int k=0;k<current_size;k++){
        cout<<temp->data<<";";
        temp=temp->next;
      }
    cout<<"]";

    cout<<"  size="<<current_size<<"  cursor="<<cursor->data<<"."<<endl;

}


void Deque::verbose_display(){
  if(left_p==NULL){
    return ;
  }
   node * temp = left_p;
      for(int k=0;k<current_size;k++){
        cout<<temp->data<<endl;
        cout<<temp<<endl;
        cout<<temp->prev<<endl;
        cout<<temp->next<<endl;
        temp=temp->next;
      }
}
