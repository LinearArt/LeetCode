//
//  List.hpp
//  LeetCode
//
//  Created by 何皓源 on 2021/10/2.
//

#ifndef LinkedList
#define LinkedList

#include "Common.hpp"

// 707
class Node {
public:
  Node() {
    val = 0;
    next = nullptr;
  }
  Node(int v, Node* n) {
    val = v;
    next = n;
  }
  int val;
  Node* next;
};

class List {
public:
  List() {
    head_ = nullptr;
  }
  List(List& aList) {
    while (head_) {
      delete head_;
      head_ = head_->next;
    }
    head_ = aList.getHead();
  }
  
  ~List() {
    while (head_) {
      delete head_;
      head_ = head_->next;
    }
  }
  
  Node* getHead() {
    return head_;
  }
  
  int getValue(int index) {
    if (index < 0) {
      return -1;
    }
    Node* cur = head_;
    for (int i = 0; i < index && cur; ++ i) {
      cur = cur->next;
    }
    if (cur) {
      return cur->val;
    } else {
      return -1;
    }
  }
  
  void addAtHead(int val) {
    head_ = new Node(val, head_);
  }
  
  void addAtTail(int val) {
    if (head_) {
      Node* cur = head_;
      while (cur->next) {
        cur = cur->next;
      }
      cur->next = new Node(val, nullptr);
    } else {
      addAtHead(val);
    }
  }
  
  void addAtIndex(int index, int val) {
    if (index <= 0) {
      addAtHead(val);
    } else {
      Node* cur = head_;
      for (int i = 0; i < index - 1 && cur; ++ i) {
        cur = cur->next;
      }
      if (cur) {
        cur->next = new Node(val, cur->next);
      }
    }
  }
  
  void deleteAtIndex(int index) {
    if (index < 0) {
      return;
    } else if (index == 0 && head_) {
      Node* tmp = head_;
      head_ = head_->next;
      delete tmp;
    } else if (head_) {
      Node* cur = head_;
      for (int i = 0; i < index - 1 && cur->next; ++ i) {
        cur = cur->next;
      }
      if (cur->next) {
        Node* tmp = cur->next->next;
        delete cur->next;
        cur->next = tmp;
      }
    }
  }
  
  void displayList() {
    Node* cur = head_;
    while (cur) {
      cout << cur->val << ' ';
      cur = cur->next;
    }
    cout << '\n';
  }
  
  // 206
  void reverseList() {
    if (head_ && head_->next) {
      Node* pre = head_;
      Node* cur = head_->next;
      Node* tmp;
      head_->next = nullptr;
      while (cur) {
        tmp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = tmp;
      }
      head_ = pre;
    }
  }
  
  // 24
  void swapPairs() {
    if (head_ && head_->next) {
      Node* pre = head_;
      Node* cur = head_->next->next;
      Node* tmp = head_->next;
      head_->next->next = head_;
      head_->next = cur;
      head_ = tmp;
      while (cur && cur->next) {
        pre->next = cur->next;
        pre = cur;
        tmp = cur->next->next;
        cur->next->next = cur;
        cur->next = tmp;
        cur = cur->next;
      }
    }
  }
  
  // 19
  void removeNthFromEnd(int index) {
    if (head_ && index > 0) {
      Node* fast = head_;
      Node* slow = head_;
      for (int i = 0; i < index; ++ i) {
        if (fast == nullptr) {
          return;
        }
        fast = fast->next;
      }
      while (fast && fast->next) {
        fast = fast->next;
        slow = slow->next;
      }
      if (fast) {
        Node* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
      } else {
        Node* tmp = head_->next;
        delete head_;
        head_ = tmp;
      }
    }
  }
  
  // 面试题 02.07
  int getSize() {
    int size = 0;
    Node* cur = head_;
    while (cur) {
      ++ size;
      cur = cur->next;
    }
    return size;
  }
  
  Node* getInterNode(List& aList) {
    int sizeA = this->getSize();
    int sizeB = aList.getSize();
    Node* curA = head_;
    Node* curB = aList.getHead();
    if (sizeA > sizeB) {
      for (int i = 0; i < (sizeA - sizeB); ++ i) {
        curA = curA->next;
      }
    } else if (sizeA < sizeB) {
      for (int i = 0; i < (sizeB - sizeA); ++ i) {
        curB = curB->next;
      }
    }
    while (curA) {
      if (curA == curB) {
        return curA;
      }
      curA = curA->next;
      curB = curB->next;
    }
    return nullptr;
  }
  
  // 142
  Node* getCycleNode() {
    Node* fast = head_;
    Node* slow = head_;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (fast == slow) {
        Node* left = head_;
        Node* right = fast;
        while (left != right) {
          left = left->next;
          right = right->next;
        }
        return left;
      }
    }
    return nullptr;
  }
  
private:
  Node* head_;
};

#endif /* LinkedList */

//  设计链表的实现。您可以选择使用单链表或双链表。单链表中的节点应该具有两个属性：val 和 next。val 是当前节点的值，next
//  是指向下一个节点的指针/引用。如果要使用双向链表，则还需要一个属性 prev 以指示链表中的上一个节点。假设链表中的所有节点都是 0-index 的。
//
//  在链表类中实现这些功能：
//
//  getValue(index)：获取链表中第 index 个节点的值。如果索引无效，则返回-1。
//  addAtHead(val)：在链表的第一个元素之前添加一个值为 val 的节点。插入后，新节点将成为链表的第一个节点。
//  addAtTail(val)：将值为 val 的节点追加到链表的最后一个元素。
//  addAtIndex(index,val)：在链表中的第 index 个节点之前添加值为 val  的节点。如果 index 等于链表的长度，则该节点将附加到链表的末尾。如果 index 大于链表长度，则不会插入节点。如果index小于0，则在头部插入节点。
//  deleteAtIndex(index)：如果索引 index 有效，则删除链表中的第 index 个节点。
//
//  来源：力扣（LeetCode）
//  链接：https://leetcode-cn.com/problems/design-linked-list
//  著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
