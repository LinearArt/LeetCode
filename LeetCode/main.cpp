//
//  main.cpp
//  LeetCode
//
//  Created by 何皓源 on 2021/10/2.
//

#include <iostream>
#include "MyArray.hpp"
#include "MyLinkedList.hpp"

void testLinkedList() {
  LinkedList* obj = new LinkedList();
  obj->addAtHead(1);
  obj->addAtTail(1);
  obj->addAtTail(2);
  obj->addAtTail(3);
  obj->addAtTail(4);
  obj->addAtIndex(1, 2);
  obj->displayList();
  obj->reverseList();
  obj->displayList();
  obj->swapPairs();
  obj->removeNthFromEnd(2);
  obj->displayList();
  delete obj;
}

int main(int argc, const char * argv[]) {
  testLinkedList();
  return 0;
}
