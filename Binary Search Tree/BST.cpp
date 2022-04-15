#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *lchild;
  int data;
  struct Node *rchild;
};

struct Node *insert(struct Node *root, int key) {

  struct Node *p = root, *q;

  // First time to create root node
  if (p == NULL) {
    struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
    newnode->data = key;
    newnode->lchild = newnode->rchild = NULL;
    return newnode;
  }

  while (p != NULL) {
    // No insertion if equal
    if (key == p->data)
      return NULL;
    else if (key > p->data) {
      q = p;
      p = p->rchild;
    } else {
      q = p;
      p = p->lchild;
    }
  }
  struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
  newnode->data = key;
  newnode->lchild = newnode->rchild = NULL;
  if (key > q->data)
    q->rchild = newnode;
  else
    q->lchild = newnode;

  return root;
}

void inorder(struct Node *root) {
  if (root) {
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
  }
}

struct Node *search(struct Node *root, int key) {
  struct Node *p = root;
  while (p != NULL) {
    if (p->data == key)
      return p;
    else if (key > p->data)
      p = p->rchild;
    else
      p = p->lchild;
  }
  return NULL;
}

struct Node *InorderPred(struct Node *root) {
  struct Node *p = root->lchild;

  while (p != NULL && p->rchild != NULL)
    p = p->rchild;
  return p;
}

struct Node *InorderSucc(struct Node *root) {
  struct Node *p = root->rchild;

  while (p != NULL && p->lchild != NULL)
    p = p->lchild;
  return p;
}

int height(struct Node *root) {
  if (root == NULL)
    return -1;
  else {
    int left, right;
    left = height(root->lchild);
    right = height(root->rchild);

    return left > right ? left + 1 : right + 1;
  }
}

int main() {
  struct Node *root = NULL;
  struct Node *temp;
  int arr[] = {9, 15, 5, 20, 16, 8, 12, 3, 6}, n = sizeof(arr) / sizeof(int);

  // insert
  //   root = insert(root, arr[0]);
  for (int i = 0; i < n; i++) {
    root = insert(root, arr[i]);
  }

  // Inorder Traversal
  inorder(root);
  printf("Root is %d\n", root->data);

  //   Search
  temp = search(root, 100);
  printf("Searched element is %d\n", temp != NULL ? temp->data : -1);

  //   Inorder Predecessor
  printf("InorderPred is %d\n", InorderPred(root)->data);
}