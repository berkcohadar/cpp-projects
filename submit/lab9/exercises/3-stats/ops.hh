#ifndef OPS_HH_
#define OPS_HH_

/** sorting operations */
class Ops {
public:

  /** return < 0, == 0, > 0 if a < b, a == b, a > b */
  virtual int compare(int a, int b);
  
  /** swap a[i] and a[j] */
  virtual void swap(int a[], int i, int j);
};
class Counter : public Ops 
{ 
    public:

	/** return < 0, == 0, > 0 if a < b, a == b, a > b */
	virtual int compare(int a, int b);
  
	/** swap a[i] and a[j] */
	virtual void swap(int a[], int i, int j);

	int compare_counter=0;
	int swap_counter=0;
}; 

#endif //ifndef OPS_HH_
