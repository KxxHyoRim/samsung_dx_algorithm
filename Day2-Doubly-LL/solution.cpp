#define MAX_NODE 10000
#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;
Node *tail;
int cnt;

Node *getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init() {
    cnt = 0;
    nodeCnt = 0;
    head = getNode(-1);
    tail = getNode(-1);
    head->next = tail;
    tail->prev = head;
}

void addNode2Head(int data) {
    Node *n = getNode(data);
    head->next->prev = n;
    n->next = head->next;
    n->prev = head;
    head->next = n;
    cnt++;
}

void addNode2Tail(int data) {
    Node *n = getNode(data);
    Node *pre = tail->prev;
    pre->next = n;
    n->prev = pre;
    tail->prev = n;
    n->next = tail;
    cnt++;
}

void addNode2Num(int data, int num) {
    //지정된 순서(num)에 노드 추가
    Node *add = getNode(data);
    Node *cur = head;
    for (int i = 0; i < num; i++) {
        cur = cur->next;
    }
    Node *prev = cur->prev;
    prev->next = add;
    add->prev = prev;
    cur->prev = add;
    add->next = cur;
    cnt++;
}

// data를 가진 node의 순서를 리턴
int findNode(int data) {
    int rtn = 0;
    Node *n = head;
    while (n->next != nullptr) {
        if (n->data == data) {
            return rtn;
        }
        n = n->next;
        rtn++;
    }
    return -1;  // 찾는 값이 없는경우
}

void removeNode(int data) {
    Node *n = head;
    while (n->next != nullptr) {
        if (n->data == data) {
            break;
        }
        n = n->next;
    }
    if (n->next == nullptr) return;

    Node *prev = n->prev;
    Node *next = n->next;

    prev->next = next;
    next->prev = prev;
//    n->next = nullptr;
//    n->prev = nullptr;
    cnt--;
}

int getList(int output[MAX_NODE]) {
    Node *n = head -> next;
    for (int i = 0; i < cnt; i++) {
        output[i] = n->data;
        n = n->next;
    }
    return cnt;
}

int getReversedList(int output[MAX_NODE]) {
    Node *n = tail -> prev;
    for (int i = 0; i < cnt; i++) {
        output[i] = n->data;
        n = n->prev;
    }
    return cnt;
}