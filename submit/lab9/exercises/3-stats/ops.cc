#include "ops.hh"

/** return < 0, == 0, > 0 if a < b, a == b, a > b */
int
Ops::compare(int a, int b) {
  /*Counter::compare_counter++;*/
  return a - b;
}

/** swap a[i] and a[j] */
void
Ops::swap(int a[], int i, int j)
{
  /*Counter::swap_counter++;*/
  int t = a[i];
  a[i] = a[j];
  a[j] = t;
}

int
Counter::compare(int a, int b) {
	compare_counter++;
	return (this->Ops::compare(a,b));
}

void
Counter::swap(int a[], int i, int j) {
	swap_counter++;
	return (this->Ops::swap(a,i,j));
}

	

