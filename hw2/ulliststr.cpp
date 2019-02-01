#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
using namespace std;

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

void ULListStr::set(size_t loc, const string& val)
{
  string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw invalid_argument("Bad location");
  }
  *ptr = val;
}
//Original:  std::string& ULListStr::get(size_t loc)
string& ULListStr::get(size_t loc)
{
  string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw invalid_argument("Bad location");
  }
  return *ptr;
}

string const & ULListStr::get(size_t loc) const
{
  string* ptr = getValAtLoc(loc);
  if(NULL == ptr){
    throw invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

string const & ULListStr::front() const{
  return head_->val[head_->first];
}

string const & ULListStr::back() const{
  return tail_->val[tail_->last];
}

void ULListStr::push_front(const string& value){


  //string* ptr = &(head_->val[head_->first]);
  //string* ptr2 = &(head_->val[head_->first-1]);

  //if list is empty
  if (this->empty()){
    cout << "1" << endl;
    Item* newHead = new Item();
    head_ = newHead;
    tail_ = newHead;

    head_->first++;
    head_->last++;
    head_->last++;

    head_->val[0] = value;
    size_++;
    return;
  }

  //If head array is full, 
  //create new Item and assign it to be new head
  if (head_->first == size_t(0)){
    Item* temp = head_;
    cout << "2" << endl;
    Item* newHead = new Item();
    temp->prev = newHead;
    newHead->next = temp;

    head_ = newHead;
    head_->val[ARRSIZE-1] = value;
    head_->first = ARRSIZE-1;
    head_->last = ARRSIZE;
    //Final update of newHead to head
    
    size_++;
    return;
    }

  
  else {
    cout << "3" << endl;
    //if array has space in the front for a new element
    head_->first--; 
    head_->val[head_->first] = value;
    size_++;
    return;
  }
}



void ULListStr::push_back(const string& value){

  //string* ptr2 = &(tail_->val[tail_->last]);

  //if list is empty
  if (this->empty()){
    cout << 1 << endl;
    Item* newTail = new Item();
    tail_=newTail;
    head_=newTail;
    newTail->val[ARRSIZE-1] = value;
    tail_->first = ARRSIZE-1;
    head_->first = ARRSIZE-1;
    tail_->last = ARRSIZE;
    head_->first = ARRSIZE;
    size_++;
    return;
  }

  //if the next element after tail_->last is out of bounds 
  if (tail_->last == ARRSIZE){
    cout << 2 << endl;
    Item* pos = tail_;
    Item* newTail = new Item();
    pos->next = newTail; 
    newTail->prev = pos;
    tail_ = newTail;
    newTail->val[0] = value;
    tail_->last++;
    size_++;
    return;
  }

  //last points to last index in array, so we create new node pointing to new array
  else {
    cout << 3 << endl;
    tail_->val[tail_->last] = value;
    tail_->last++;
    size_++;
    return;
  }
}


string* ULListStr::getValAtLoc(size_t loc) const{

  
  //unsigned int firstDim = loc/ARRSIZE;
  //unsigned int secondDim = loc%ARRSIZE;
  size_t realLoc = loc + head_->first;
  size_t endLoc = this->size();

  cout << "loc is: " << loc << "   realLoc is: " << realLoc << endl; 
  //Bad Location: Indexing before the first element in head
  if ((head_->first) > realLoc){
    //throw invalid_argument("Bad location");
    cout << "first is fucked" << endl;
    return NULL;
  }

  //Bad Location: Indexing after the last element in tail
  if ((tail_->last) <= loc){
    // throw invalid_argument("Bad location");
    cout << "second is fucked" << endl;
    return NULL;
  }
  //Item* runner = head_; 

  //loop over nodes then loop over array indexs
  /*for (unsigned int i=0; i<firstDim; i++){
    runner = runner->next;
  }*/
  return &(head_->val[loc]);
}



void ULListStr::pop_back(){
  

  //If list is empty, do nothing
  if (this->size() == 0){
    return;
  }
  if (this->size() == 1){
    head_ = NULL;
    tail_ = NULL;
  }

  //pop back by decrimenting last index of tail 
  (tail_->last)--;

  //If the last index of tail is 0,
  //then we need to delete tail and 
  //update the second to last Item to be the new tail  
  if (tail_->last == 0) {
    Item* temp = tail_->prev;
    delete tail_;
    tail_ = temp;
    tail_->next = nullptr;
  }
  size_--;
  return;
}

void ULListStr::pop_front(){
  

  if (this->size() == 0){
    return;
  }
  if (this->size() == 1){
    head_ = NULL;
    tail_ = NULL;
  }
  //string* ptr = &(head_->val[head_->first]);
  (head_->first)++;
  
  //If the head first index of head is at the last index of the array
  //then we need to delete head and 
  //update the second Item to be the new head
  if (head_->first == ARRSIZE-1){
    Item* temp = head_->next;
    delete head_;
    head_ = temp;
    temp->prev = nullptr;
  }
  size_--;
  return;
}
