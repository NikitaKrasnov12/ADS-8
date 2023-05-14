// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}
void Train::addCage(bool light) {
    if (first->next == nullptr && first->prev == nullptr) {
        first->next = new Cage;
        first->next->light = light;
        first->next->prev = first;
        first->next->next = first;
    } else if (first==nullptr) {
        first = new Cage;
        first->next = nullptr;
        first->prev = nullptr;
        first->light = light;
    } else {
        Cage* tail = first->prev;
        tail->next = new Cage;
        tail->next->light = light;
        first->prev = tail->next;
        tail->next->prev = tail;
        tail->next->next = first;
    }
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
    temp = curCage->light;
  }
  return result;
}
int Train::getOpCount() {
    return countOp;
}
