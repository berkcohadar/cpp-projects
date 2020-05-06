#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>

#include <memory>
#include <string>
#include <istream>

#include <cstdlib>

#include "job.hh"
#include "command.hh"
#include "command-stream.hh"

using namespace std;

struct PriorityQueue 
{
private:
	vector<int> A;

	int PARENT(int i)  {  return (i - 1) / 2; }

	int LEFT(int i) { return (2 * i + 1); }

	int RIGHT(int i) { return (2 * i + 2); }

	void heapify_down(int i)
	{
		int right = RIGHT(i);
		int left = LEFT(i);
		int largest = i;
		if (left < size() && A[left] > A[i]) largest = left;

		if (right < size() && A[right] > A[largest]) largest = right;

		if (largest != i) {
			swap(A[i], A[largest]);
			heapify_down(largest);
		}
	}

	void heapify_up(int i)
	{
		if (i && A[PARENT(i)] < A[i]) 
		{
			swap(A[i], A[PARENT(i)]);
			heapify_up(PARENT(i));
		}
	}
	
public:
	unsigned int size() { return A.size(); }

	bool empty() { return size() == 0; }
	
	void push(int key)
	{
		A.push_back(key);

		int index = size() - 1;
		heapify_up(index);
	}

	void pop()
	{
		try {
			if (size() == 0) throw out_of_range("Vector<X>::at() : " "out of range");

			A[0] = A.back();
			A.pop_back();

			heapify_down(0);
		}
		catch (const out_of_range& oor) { cout << "\n" << oor.what(); }
	}

	int top()
	{
		try {
			if (size() == 0)
				throw out_of_range("Vector<X>::at() : " "out of range");

			return A.at(0);
		}
		catch (const out_of_range& oor) {
			cout << "\n" << oor.what();
		}
	}
};

int main(int argc, char* argv[]){


	PriorityQueue pq;
	PriorityQueue pq1;
	
	
	struct entry{std::string name; int q1; int q2;};
	/* key=2 value={"id0",2,5}	key=1 value={"id0",1,6} */
	/* myqueue.key = value.q1	myqueue.key = value.q2 */

	if (argc != 2) {
		std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
		std::exit(1);
	}
  
	CommandStream commandIn(argv[1]); //create command stream
	for (std::unique_ptr<Command> commandP = commandIn.next(); commandP != nullptr;
								commandP = commandIn.next()) {
		std::cout << *commandP << std::endl; /* prints "enter id0 2 5" */

		/*std::string arguement = *commandP.toString();*/

		/* argument[0] = "enter" , argument[1] = "id0" , arguement[2] = 2 , arguement[3] = 5 */ /* should be */

		/*struct entry value = {argument[1], (int) arguement[2], (int) argument[3]}


		if(argument[0] == "enter") pq.push(value.q1);
		if(argument[0] == "move") { pq.pop(); pq1.push(value.q2); } // value.q2 should be popped value from pq 
		if(argument[0] == "leave") pq1.pop();*/
	}
	

	return 0;
}


















