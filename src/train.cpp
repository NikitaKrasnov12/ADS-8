// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}
void Train::addCage(bool light) {
    Cage* nCage = new Cage;
    nCage->light = light;
    if (first == nullptr) {
        first = last = nCage;
        nCage->next = nullptr;
        nCage->prev = nullptr;
    }
    else{
        last->next = nCage;
        nCage->prev = last;
        nCage->next = nullptr;
        last = nCage;
    }
    count++;
}
int Train::getLength() {
  Cage* curCage = first;
  curCage->light = true;
  int result = 0;
  bool temp = true;
  while (temp){
    do {
      curCage = curCage->next;
      countOp++;
      result++;
    } while (true != curCage->light);
    curCage->light = false;
    for (int i = result; i > 0; i--) {
      curCage = curCage->prev;
      countOp++;
    }
    temp = currentCage->light;
  }
  return result;
}
int Train::getOpCount() {
    return countOp;
}
