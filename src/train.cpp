// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() {
    countOp = 0;
    first = nullptr;
}
void Train::addCage(bool light) {
    if ((first->next == nullptr) && (first->prev == nullptr)) {
        first->next = new Cage;
        first->next->light = light;
        first->next->prev = first;
        first->next->next = first;
        first->prev = first->next;
    } else if (first == nullptr) {
        first = new Cage;
        first->light = light;
        first->next = nullptr;
        first->prev = nullptr;
    } else {
        Cage* tail = first->prev;
        tail->next = new Cage;
        tail->next->light = light;
        tail->next->prev = tail;
        tail->next->next = first;
        first->prev = tail->next;
    }
}
int Train::getLength() {
  Cage* curCage = first;
  curCage->light = true;
  int result = 0;
  bool temp = true;
  while (temp) {
    result = 0;
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
