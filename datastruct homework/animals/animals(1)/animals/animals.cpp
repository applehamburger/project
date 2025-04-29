#include"animals.h"



Status InitList(AnimalList& A) {
    A = new ANode;//创建头结点
    A->next = NULL;
    return OK;
}

void CreateList_R(AnimalList& A, string n) {
    A = new ANode;
    A->next = NULL;
    AnimalList r = A;
        AnimalList p = new ANode;
        p->name=n;
        p->next = r->next;
        r->next = p;
        r = p;
}

  void ListTraverse(const AnimalList & A) {
        AnimalList p = A->next;
        while (p) {
            cout << p->name << " ";
            p = p->next;
        }
    }





  void RemoveCats(AnimalList& A) {
      if (A == NULL || A->next == NULL) {
          return;
      }

      AnimalList p = A->next;
      AnimalList pre = A;
      while (p) {
          if (p->name == "Cat") {
              pre->next = p->next;
              delete p;
              p = pre->next;
          }
          else {
              pre = p;
              p = p->next;
          }
      }
  }

  void SortList(AnimalList& A) {
      if (A == NULL || A->next == NULL) {
          return;
      }

      AnimalList p = A->next;
      int len = 0;
      while (p) {
          len++;
          p = p->next;
      }

      for (int i = 0; i < len - 1; i++) {
          p = A->next;
          AnimalList q = p->next;
          for (int j = 0; j < len - i - 1; j++) {
              if (p->name > q->name) {
                  p->next = q->next;
                  q->next = p;
                  if (j == 0) {
                      A->next = q;
                  }
                  else {
                      p = q->next;
                      AnimalList pre = A;
                      while (pre->next != q) {
                          pre = pre->next;
                      }
                  }
              }
          }
      }
  }