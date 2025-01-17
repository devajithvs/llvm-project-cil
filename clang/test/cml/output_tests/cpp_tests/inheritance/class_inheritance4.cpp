// RUN: %cml -cpp %s -o %t && %t | FileCheck %s
#include <stdio.h>

class C {
private:
  int c;

public:
  void set_c(int val) { c = val; }
  int get_c() { return c; }
};

class F : public C {
private:
  float f;

public:
  void set_f(float val) { f = val; }
  float get_f() { return f; }
};

class D {
private:
  double f;

public:
  void set_d(double val) { f = val; }
  double get_d() { return f; }
};

class B : public F, public D {
public:
  int e;
};

int main() {

  B o;
  o.e = 12;
  o.set_c(11);
  o.set_f(13.32);
  o.set_d(14.42);
  printf("%d %d %f\n", o.get_c(), o.e, o.get_f()); // CHECK:11 12 13.32
  printf("%lf\n", o.get_d());                      // CHECK: 14.42
  return 0;
}
