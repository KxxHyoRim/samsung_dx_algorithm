#define MAX_NODE 10000

#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;
int cnt;

Node *getNode(int data) {
    node[nodeCnt].data = data;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init() {
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Head(int data) {
    Node *n = getNode(data);
    n->next = head->next;
    head->next = n;
    cnt++;
}

void addNode2Tail(int data) {
    Node *n = head;
    while (n->next != nullptr) {
        n = n->next;
    }
    Node *add = getNode(data);
    n->next = add;
    cnt++;
}

void addNode2Num(int data, int num) {
    Node *n = head;
    for (int i = 0; i < num - 1; i++) {
        n = n->next;
    }
    Node *add = getNode(data);
    add->next = n->next;
    n->next = add;
    cnt++;
}

void removeNode(int data) {
    Node *n = head;
    while (n-> next->data != data) {
        n = n->next;
        if ( n->next == nullptr) {
            cout << "지울 값 없음" << endl;
            return; // 값 없음
        }
    }
    cout << "cur : " <<  n->data << endl;
    n->next = n->next->next;
    cnt--;
}

int getList(int output[MAX_NODE]) {
    Node *n = head->next;
    for (int i = 0; i < cnt; i++) {
        output[i] = n->data;
        n = n->next;
    }
    return cnt;
}