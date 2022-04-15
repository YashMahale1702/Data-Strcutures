#include <stdio.h>
#include <stdlib.h>

struct Sparse {
  int m;
  int n;
  int num;
  struct Element *e;
};

struct Element {
  int row;
  int col;
  int ele;
};

// Creation of the sparse matrix
void create(struct Sparse *s) {
  int i;
  printf("Enter the dimensions of the matrix m*n\n");
  scanf("%d %d", &s->m, &s->n);
  printf("Enter the total no of non-zero elements\n");
  scanf("%d", &s->num);

  // allocate memory for struct Element array
  s->e = (struct Element *)malloc(sizeof(struct Element) * s->num);
  printf("Enter %d elements row, column, element itself\n", s->num);

  for (i = 0; i < s->num;) {
    scanf("%d %d %d", &s->e[i].row, &s->e[i].col, &s->e[i].ele);
    if (s->e[i].row > s->m || s->e[i].col > s->n) {
      printf("Invalid combination. Enter again\n");
      continue;
    }
    i++;
  }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2) {
  if (s1->m != s2->m || s1->n != s1->n) {
    return NULL;
  }

  // else
  int i = 0, j = 0, k = 0;
  struct Sparse *sum =
      (struct Sparse *)malloc(sizeof(struct Sparse) * (s1->m + s1->n));

  while (i < s1->num && j < s2->num) {
    // s1 row is small
    if (s1->e[i].row < s2->e[j].row) {
      sum->e[k++] = s1->e[i++];
    } // greater
    else if (s1->e[i].row > s2->e[j].row) {
      sum->e[k++] = s2->e[j++];
    } //
    else {
      if (s1->e[i].col < s2->e[j].col) {
        sum->e[k++] = s1->e[i++];
      } // greater
      else if (s1->e[i].col > s2->e[j].col) {
        sum->e[k++] = s2->e[j++];
      } //
      else {
        sum->e[k] = s2->e[j++];
        sum->e[k++].ele += s1->e[i++].ele;
      }
    }
  }

  // If elemets remain after copying
  for (; i < s1->num; i++) {
    sum->e[k++] = s1->e[i];
  }

  for (; j < s2->num; j++) {
    sum->e[k++] = s1->e[j];
  }

  ///
  sum->n = s1->n;
  sum->m = s1->m;
  sum->num = k;

  return sum;
}

// Display Function
void display(struct Sparse s) {
  int i;
  for (i = 0; i < s.num; i++) {
    printf("row : %d column : %d element : %d\n", s.e[i].row, s.e[i].col,
           s.e[i].ele);
  }
}

int main() {
  struct Sparse s1, s2;

  // This function modifies the sparse s
  create(&s1);
  create(&s2);

  //
  struct Sparse *s3 = add(&s1, &s2);

  // display
  display(s1);

  return 0;
}
