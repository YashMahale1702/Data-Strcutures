#include "./queue.h"

struct Node *createBT(struct Node *root) {
  struct Queue que;
  struct Node *p;
  int data;

  // Create a Queue to store the address
  createQueue(&que, 7);

  printf("Enter the root value:\n");
  scanf("%d", &data);
  root = (struct Node *)malloc(sizeof(struct Node));
  root->data = data;
  root->lchild = root->rchild = NULL;
  Enqueue(&que, root);

  //
  while (!isEmpty(que)) {

    p = Dequeue(&que);

    // left child
    printf("Enter left child of %d:\n", p->data);
    scanf("%d", &data);

    // child exists
    if (data != -1) {
      struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
      newnode->data = data;
      newnode->lchild = newnode->rchild = NULL;
      p->lchild = newnode;
      Enqueue(&que, newnode);
    }

    // right child
    printf("Enter right child of %d:\n", p->data);
    scanf("%d", &data);
    // child exists
    if (data != -1) {
      struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
      newnode->data = data;
      newnode->lchild = newnode->rchild = NULL;
      p->rchild = newnode;
      Enqueue(&que, newnode);
    }
  }

  return root;
}

// Tree Traversals

void preorder(struct Node *root) {
  if (root) {
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
  }
}

void inorder(struct Node *root) {
  if (root) {
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
  }
}

void postorder(struct Node *root) {
  if (root) {
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
  }
}

void levelOrder(struct Node *root) {
  struct Node *p;
  // init queue
  struct Queue que;
  createQueue(&que, 100);

  printf("%d ", root->data);
  Enqueue(&que, root);

  while (!isEmpty(que)) {
    p = Dequeue(&que);

    if (p->lchild != NULL) {
      printf("%d ", p->lchild->data);
      Enqueue(&que, p->lchild);
    }

    if (p->rchild != NULL) {
      printf("%d ", p->rchild->data);
      Enqueue(&que, p->rchild);
    }
  }
}

int main() {
  struct Node *root = NULL;

  //
  root = createBT(root);

  //
  preorder(root);

  printf("\n");

  levelOrder(root);

  //
  return 0;
}