/* Makefile */

/*
  SRC = file1.cpp file2.cpp
  OBJ = main

  CC = g++
  CC_FLAGS = -std=c++11 -Wall -O2
  LIBS_FLAGS = 

  all: $(SRC)
  $(CC) $(SRC) $(CC_FLAGS) $(LIBS_FLAGS) -o $(OBJ)

  clean:
  rm main

  run: clean all
  ./main
*/

/* Code Template */


#include <algorithm>
#include <bits/stdc++.h>


using namespace std;
/*
  int main()
  {
  
  }
*/
// Compile
// g++ -std=c++11 -O2 -Wall test.cpp -o test

struct P {
  int x, y;

  bool operator< (const P& p) {
	if (x != p.x) return x < p.x;
	else return y < p.y;
  }
};

class Person
{
private:
  string name;
  double rank;
public:
  // constructor Person();
  Person(string name, double rank)
  {
	this->name = name;
	this->rank = rank;
  }
  // destructor ~Person();
  // other members void doSomething();
  void printInfo()
  {
	cout << "Name: " << name << ", Rank: " << rank << "\n";
  }
};

enum Day {
  MONDAY,   // 0
  TUESDAY   // 1
};   
  
void swap(int& a, int& b);
void printvector(vector<int> v1);
bool strcomp(string a, string b);
bool ok(int num);
int hill(int k);
void displayPayRates(const double* rates, int size);

int main(int argc, char *argv[])
{

  // Optimize i/o operation in C++
  //ios::sync_with_stdio(0);
  //cin.tie(0);

  /*
  // Input Oputput
  
  int a, b;
  string x;
  cin >> a >> b >> x;
  cout << a << " " << b << " " << x << "\n";
  scanf("%d %d", &a, &b);
  printf("%d %d\n", a, b);

  string s;
  getline(cin, s);

  
  while (cin >> x) {
  // keep on reading x until there is input
  }
  

  // Open file and change stdio
  freopen("input_file.txt", "r", stdin);
  freopen("output_file.txt", "w", stdout);
  */


  // Working with Numbers
  long long x = 1;
  int a = 2;
  long long b = (long long) (a * a);

  long long m = 1e9 + 7;
  for (int i = 2; i <= 10; i++) {
	x = (x * i) % m;
  }

  cout << "Factorial(10) mod " << m << " " << (x % m) << "\n";

  double c = 1.23000009;
  double d = 1.230000089;
  if (abs(c - d) < 1e-9) {
	cout << "c and d are equal" << "\n";
  }

  // Shorten Code
  typedef long long ll;
  ll shortenNum1 = 134323243;
  cout << shortenNum1 << "\n";

  typedef vector<int> vi;
  typedef pair<int,int> pi;

#define F first
#define S second
#define PB push_back
#define MP make_pair

  pi pair1({2, 3});
  cout << "pair1: " << pair1.first << ", " << pair1.S << "\n";

#define REP(i, a, b) for (int i = a; i <= b; i++)

  REP(i, 1, 5) {
	cout << "Say hello 5 times" << "\n";
  }

  // Be careful using macro
#define SQ(a) (a) * (a)
  // a * a would result in wrong answer
  cout << "Square (3 + 3) " << SQ(3 + 3) << "\n";

  // Loop
  // Double loop
  for (int i = 0; i < 2; i++) {
	for (int j = 0; j < 2; j++) {
	  printf("%d x %d: %d\n", i, j, (i * j));
	}
  }

  // Find best consecutive sum
  int sumarr[] = {2, 4, -12, 1, -3, 14};
  int arrsize = 6;
  int best = 0, sum = 0;
  for (int i = 0; i < arrsize; i++) {
	sum = max(sumarr[i], sumarr[i] + sum);
	best = max(sum, best);
  }

  cout << "Best: " << best << "\n";

  /*
	Recursion
    void f(int n)
    {
	if (n == 1) return;
	f(n-1);
    }
  */


  // Sorting Algorithms
  // Bubble Sort
  for (int i = 0; i < arrsize; i++) {
	for (int j = 0; j < arrsize - i - 1; j++) {
	  if (sumarr[j] > sumarr[j+1]) {
		swap(sumarr[j], sumarr[j+1]);
	  }
	}
  }

  cout << "Sumarr: \n";
  for (auto a1 : sumarr) {
	cout << a1 << " ";
  }
  cout << "\n";


  // Sorting using C++ library functions
  vector<int> v1 = {4, 3, 2, 5, 4, 2};
  sort(v1.begin(), v1.end());
  cout << "Sorted vector\n";
  printvector(v1);
  cout << "Reverse sorted vector\n";
  sort(v1.rbegin(), v1.rend());
  printvector(v1);

  int a1[] = {4, 3, 2, 5, 4, 2};
  sort(a1, a1 + 6);
  cout << "Sorted array\n";
  for (auto a11 : a1) {
	cout << a11 << " ";
  }
  cout << "\n";

  cout << "Sorted string\n";
  string s = "greenleaf";
  sort(s.begin(), s.end());
  cout << s << "\n";

  typedef vector<pair<int,int>> vpi;
  vpi vpi1;
  vpi1.push_back({4, 3});
  vpi1.push_back({4, 5});
  sort(vpi1.begin(), vpi1.end());
  cout << "Vector pair\n";
  for (auto vpi11 : vpi1) {
	cout << vpi11.first << ":" << vpi11.second << " ";
  }
  cout << "\n";

  vector<tuple<int,int,int>> vti;
  vti.push_back({7,3,4});
  vti.push_back({5,3,2});
  sort(vti.begin(), vti.end());
  cout << "Vector tuple\n";
  for (auto vti1 : vti) {
	cout << get<0>(vti1) << " : " << get<1>(vti1) << " : " << get<2>(vti1) << ",  ";
  }
  cout << "\n";

  // Sort struct, operator< is used
  P ps[2];
  ps[0] = {2, 3};
  ps[1] = {1, 2};
  sort(ps, ps + 2);
  cout << "Struct array\n";
  for (auto p1 : ps) {
	cout << p1.x << ":" << p1.y << " ";
  }
  cout << "\n";

  // Sort string using comparator function comp, sort first by length than alphabetical
  // works with array as well
  vector<string> strs = {"hello", "zoo"};
  sort(strs.begin(), strs.end(), strcomp);  
  for (string s1 : strs) {
	cout << s1 << " ";
  }
  cout << "\n";
  
  // Binary Search method 1
  int binsarr[] = {2, 3, 4, 5, 6, 7};
  int binsize = 6;
  int f = 0, g = binsize-1;
  int searchterm = 6;
  sort(binsarr, binsarr + binsize);
  
  while (f <= g) {
	int mid = f + (g - f) / 2;

	if (binsarr[mid] == searchterm) {
	  cout << "Found at index: " << mid << "\n";
	}

	if (binsarr[mid] < searchterm) {
	  f = mid + 1;
	} else {
	  g = mid - 1;
	}
  }

  // Binary Search method 2
  f = 0;
  for (int i = binsize/2; i >= 1; i /= 2) {
	while (i + f < binsize && binsarr[i + f] <= searchterm) {
	  f += i;
	}
  }

  if (binsarr[f] == searchterm) {
	cout << "Found at index: " << f << "\n";
  }

  // C++ binary search functions
  // lower_bound pointer to equal or greater
  // upper_bound pointer to greater
  auto h = lower_bound(binsarr, binsarr + binsize, searchterm) - binsarr;
  if (h < binsize && binsarr[h] == searchterm) {
	cout << "Fppound at index: " << h << "\n";
  }

  // count number of 2
  // can also use equal_range(binsarr2, binsarr2 + binsarr2size, searchterm);
  // returns pair<int,int>
  int binsarr2[] = {1, 2, 2, 2, 3, 4};
  int binsarr2size = 6;
  searchterm = 2;
  auto lower = lower_bound(binsarr2, binsarr2 + binsarr2size, searchterm);
  auto upper = upper_bound(binsarr2, binsarr2 + binsarr2size, searchterm);
  cout << "Number of 2: " << upper - lower << "\n";


  // Finding the smallest solution
  // if ok(x) = true when x >= 5 and false otherwise
  // we want to find 5
  // we use binary search to find last x that is false, add + 1 to it
  // we use some number outside range, we start from big number and come towards false
  // if we find false, we move forward
  // here f = -1, because we always add +1, and x = 0 could be true
  f = -1;
  int z = 50; // big number outside range
  for (int i = z; i >= 1; i /= 2) {
	while (!ok(f + i)) {   // this is true when ok is false
	  f += i;
	}
  }

  // we found maximum value where ok(f) is false
  // add 1 to get first true after false
  cout << "First true is at: " << (f + 1) << "\n";

  // Find peak of a hill i.e. f(x) < f(x+1), when x < k, f(x) > f(x+1) when x >= k


  f = -1;
  for (int i = 20; i >= 1; i /= 2) {
	while (hill(f + i) < hill(f + i + 1)) {
	  f += i;
	}
  }
  cout << "Hill is at " << (f + 1) << "\n";



  
  // C++ specific elements
  int j = 5;
  int* y = new int(j);
  delete y;
  y = nullptr;   // good practice for preventing errors

  // Dynamically allocated
  char* sarr = new char[4];
  delete sarr;
  sarr = nullptr;

  Person person1("John", 2.3);
  person1.printInfo();

  Person* person2 = new Person("John", 2.3);
  person2->printInfo();
  
  delete person2;
  person2 = nullptr;


  
  // Can use unique_ptr(one pointer), shared_ptr(multiple owners using reference count) and
  // weak_ptr (multiple owners but no reference count)
  // If used inside a method, gets deleted when method exits, without needing to use delete 
  unique_ptr<Person> person3(new Person("John", 2.3));
  person3->printInfo();


  
  P manyps[2];
  P p1 = {3, 2};
  P p2 = {4}; // only set x
  cout << "X: " << p1.x << ", Y: " << p1.y << "\n";

  P* manypspointer = new P[2];
  P* singleppointer = new P;
  manypspointer[0].x = 3;
  singleppointer->x = 3;

  // Array elements are not pointer
  cout << "Manypspointer[0].x: " << manypspointer[0].x << "\n";
  cout << "Singlepointer->x: " << singleppointer->x << "\n";


  int l = TUESDAY;
  Day day1 = static_cast<Day>(1);
  bool o = TUESDAY > MONDAY;
  // Can use
  // enum class Day : char {MONDAY, TUESDAY};
  // to use strongly typed enum

  /*
  // Template
  template <class T>
  void swap(T& a, T& b)
  {
  T tmp = a;
  a = b;
  b = tmp;
  }		
  */
  
  // use const so that value cannot be changed
  double* rates = new double[2];
  rates[0] = 2.3;
  rates[1] = 3.2;
  cout << "Rates\n";
  displayPayRates(rates, 2);

  // Some cctype functions
  // Method are same with ctype.h
  // Check man pages
  // isalpha(int c) - checks for an alphabetic character; 0 no match, +ve match
  // isalnum(int c) - checks for alphanumeric character; equivalent to (isalpha(c) || isdigit(c))
  // isdigit - checks for a digit (0 through 9)
  // islower - checks for a lowercase character
  // isprint - checks for any printable character including space
  // ispunct - checks for any printable character which is not a space or an alphanumeric character
  // isupper - checks for an uppercase letter
  // isspace - checks for white-space. space, form-feed(\f), \n, \r, \t, vertial tab (\v)
  // toupper - returns uppercase equivalent
  // tolower - returns lowercase equivalent
  // for more man above functions and check more.


  // Some cstring functions;
  char strcharvar[] = "Hello, World";
  cout << strlen(strcharvar) << "\n";
  char strcharvar2[100];
  strcpy(strcharvar2, "Hello, World");
  strcat(strcharvar2, ". Chau");
  cout << strcharvar2 << "\n";

  // Search and return pointer where it is found
  char *ptr = strstr(strcharvar2, "ll");
  cout << ptr << "\n";

  cout << strcmp("Hi", "Hi") << "\n";
  
  // Numeric conversion
  int intval = atoi("1000");
  long longVal = atoi("100000");
  float floatVal = atof("12.54");
  double doubleVal = atof("12.67");

  // String
  // Convert 
  string somecstr = to_string(123322);
  cout << somecstr << "\n";

  string str1;
  string str2 = "Hello World";
  string str3("Greetings");
  string str4(str3);
  char cStr[] = "Hello,World";
  string str5(cStr, 7);   // First 7 chars
  string str6(str5, 2, 4);  // start from 2 4 chars
  cout << "Str6: " << str6 << "\n";
  string str7('x', 10);   // 10 x chars
  string str8 = str2 + str3;
  char cfromcstr = str8[3];

  // other members: append, assign, at, back, begin, c_str, capacity, clear,
  // compare, copy, empty()? end(), find(), front, insert, length, replace,
  // resize, size, substr, swap


  // Data Structures

  // A data strcture is a way to store data in the memory of a computer.
  // It is importanat to choose an appropriate data structure for a problem,
  // because each data structure has its own advantages and disadvantages. The
  // crucial question is: which operations are effecient in the chosen data
  // structure ?

  // Dynamic arrays
  // Dynamic arraay is an array whose size can be changed during execution of
  // the program. The most popular dynamic array in C++ is vector
  vector<int> dv;
  dv.push_back(3);  // [3]
  dv.push_back(2);  // [3, 2]
  dv.push_back(5);  // [3, 2, 5];  // vector<int> dv = {3, 2, 5};
  cout << dv[0] << "\n";  // 3

  for (int i = 0; i < dv.size(); i++) {
	cout << dv[i] << "\n";
  }

  // A shorter way to iterate through a vector is as follows
  for (auto x : dv) {
	cout << x << "\n";
  }

  // The back function returns last element and pop_back removes it
  cout << dv.back(); // 5
  dv.pop_back();

  vector<int> dv1(10, 5);
  // The internal implementation of vector uses an ordinary array. It resizes
  // when size becomes large or too small, however amortized time is O(1).

  // String also works like dynamic array. In addition it supports + symbol,
  // substr(k, x) // returns the substring that begins at k and has legnth x
  // find(t) finds the positon of the first occurrence of a string t
  string s331 = "hatti";
  string s332 = s331 + s331;
  cout << s332 << "\n";
  s332[2] = 'v';
  cout << s332 << "\n";
  string c331 = s332.substr(3, 4); // start from 3, 4 chars
  cout << c331 << "\n";



  // Set structures
  // A set is a data structure that mains a collections of elements. The
  // type set is based on balanced binary tree and has O(logn) operations.
  // The structure unordered_set uses hasing thus has O(1) runtime on average.
  // Function insert adds and element to set,
  // Function count returns the number of occurences of an element
  // Function erase removes an element from the set
  // Set has distinct elements
  set<int> sset;
  sset.insert(3);
  sset.insert(5);
  sset.insert(5);

  cout << sset.count(5) << "\n"; // 1, as set does not have duplicate
  sset.erase(5);  // removes the only occurence of 5
  cout << sset.count(5) << "\n";  // there is no more occurence of 5
  cout << sset.size() << "\n";  // size is 1
  
  for (auto x : sset) {
	cout << x << " ";
  }
  cout << "\n";

  // C++ also has multiset and unordered_multiset to work with duplicate elements
  multiset<int> mset;
  mset.insert(5);
  mset.insert(5);
  cout << mset.count(5) << "\n"; // 2

  // Function erase erases all instances
  // mset.erase(5);
  // cout << mset.count(5); // 0
  // If you want to remvoe first instance use find
  mset.erase(mset.find(5));


  cout << mset.count(5) << "\n";  // 1
  
  
  // Map Structure
  // A map is generalized array consisting of key-value pair
  // Map uses balanced binary tree, has O(logn) time
  // There is also unordered_map that operates in O(1)
  // If a value does not exist, a default values is added while accessing the map
  // The count funciton cna be used to check if a key is in map

  map<string,int> mmap;
  mmap["monkey"] = 4;
  mmap["banana"] = 3;
  cout << mmap["banana"] << "\n";
  cout << mmap["cat"] << "\n";  // 0, adds key

  if (mmap.count("cat")) {
	cout << "key cat exists" << "\n";
  } else {
	cout << "key does not exist" << "\n";
  }


  // Iterators and ranges
  // Many functions in C++ standard library operate with iterators. An iterator
  // is a variable that points to an element in a data structure. The iterator
  // begin points to the first element and end points to the position after the
  // last element. Thus the range is half-open

  // Working with ranges
  vector<int> v44 = {4,2,4};
  sort(v44.begin(), v44.end());
  reverse(v44.begin(), v44.end());
  random_shuffle(v44.begin(), v44.end());

  // Array uses pointers instead of begin and end
  int v44arr[] = {4, 2, 4};
  reverse(v44arr, v44arr + 3);
  random_shuffle(v44arr, v44arr + 3);

  // Set Iterators

  // Iterators are often used to access elements of a set. Following code
  // points and accesses the first element

  set<int> v44set = {2, 3};
  set<int>::iterator itset = v44set.begin();
  cout << *itset << "\n";

  // Iterators are moved forward with ++ operator and backward with -- operator
  for (auto it = v44set.begin(); it != v44set.end(); it++) {
	cout << *it << "\n";
  }

  itset = v44set.end();
  itset--;
  cout << *itset << "\n";

  // The find(x) returns an iterator that points to an element whose value is x.
  // However, if the set does not contain x, the iterator will be end
  itset = v44set.find(5);
  if (itset == v44set.end()) {
	cout << "5 is not found in the set" << "\n";
  }

  // The function lower_bound(x) returns the smallest element in the set whose
  // value is at least x, and the function upper_bound(x) returns an iterator
  // to the smallest element in the set whose value is larger than x.
  // If the element does not exist, it returns end. These functions are not
  // supported by the unordered_set structure whoch does not maintain the order
  // of the elements

  // Following code finds the element nearest to x
  // If the first or last element is found print that, otherwise find the difference of x with previous and current element and pick smaller of two

  itset = v44set.lower_bound(4);
  if (itset == v44set.begin()) {
	cout << *itset << "\n";
  } else if (itset == v44set.end()) {
	itset--;
	cout << *itset << "\n";
  } else {
	int a = *itset; itset--;
	int b = *itset;

	if (4 - b < a - 4) cout << b << "\n";
	else cout << a << "\n";
  }

  // Other structures

  // Bitset
  // A bitset is an array, whose each value is either 0 or 1. It requires less
  // memory as only 1 bit is used to store single value.
  bitset<10> bits;
  bits[1] = 1;
  bits[3] = 1;
  cout << bits[3] << "\n"; // 1
  cout << bits[5] << "\n"; // 0

  // We can also initialize using string
  bitset<10> bits2(string("0010011110"));   // count from right to left
  cout << bits2.count() << "\n"; //5

  // Supports various operations
  bitset<10> bits3(string("1001110001"));
  cout << (bits2 & bits3) << "\n";  // 0000010000
  cout << (bits2 | bits3) << "\n";  // 101111111
  cout << (bits2 ^ bits3) << "\n";  // 1011101111

  // Deque

  // A deque is a dynamic array whose size can be changed at both ends. Like a
  // vector, a deque provides function push_back and pop_back. It also supports
  // push_front and pop_front.
  // Adding and removing elements takes O(1), but is more complex and slower
  // than vector

  deque<int> dqq;
  dqq.push_back(5);    // [5]
  dqq.push_back(2);    // [5,2]
  dqq.push_front(3);   // [3,5,2]
  dqq.pop_back();      // [3,5]
  dqq.pop_front();     // [5]


  // Stack

  // A stack is a data structure that provides two O(1) time operations.
  // Adding an element to the top and removing an element from the top

  stack<int> stk;
  stk.push(3);
  stk.push(2);
  stk.push(5);
  cout << stk.top() << "\n";  // 5;
  stk.pop();
  cout << stk.top() << "\n";  // 2

  // Queue

  // A queue also provides two O(1) operations. Adding an element at the end
  // of the queue and removing the first element.

  queue<int> quq;
  quq.push(3);
  quq.push(2);
  quq.push(5);
  cout << quq.front() << "\n";  // 3
  quq.pop();
  cout << quq.front() << "\n";  // 2

  // Priority Queue

  // A priority queue maintains a set of elements depending on the type of the
  // queue
  // Retrieval and removal of either minimum or maximum element
  // Insertion and removal takes O(logn) time, and retrieval takes O(1) time

  // While ordered set efficiently supports all the operations of a priority queue
  // A priority queue has smaller constant factors.
  // It is usually implemented using a heap structure (logn) that is much
  // simpler than a balanced binary tree used in ordered set

  // By default C++ priority queue are sorted in decreasing order, and it is
  // possible to find and remove the largest element in queue.

  priority_queue<int> pqq;
  pqq.push(3);
  pqq.push(5);
  pqq.push(7);
  pqq.push(2);
  cout << pqq.top() << "\n"; // 7
  pqq.pop();
  cout << pqq.top() << "\n";  // 5
  pqq.pop();
  pqq.push(6);
  cout << pqq.top() << "\n";  // 6
  pqq.pop();

  // If we want to create a priority queue that supports finding and removing
  // smallest element we can use following format
  priority_queue<int,vector<int>,greater<int>> pqq1;

  // In lots of cases sorting can be faster than using some data structures, as sorting is single operation.

  
  return 0;
}


// C ++ namespace
namespace Q
{
  // V is a member of Q, and is defined within Q
  namespace V
  {
	// C is a member of V, full defined here
	class C
	{
	  // C::m is only declared
	  void m();
	};

	// if is a member of V, only declared
	void f();
  }

  // V::f() is defined here inside Q
  void V::f()
  {
	cout << "I am f" << "\n";
  }

} // namespace Q
  

void Q::V::C::m()
{
  cout << "I am m" << "\n";
}



// Swap using reference
void swap(int& a, int& b)
{
  int tmp = a;
  a = b;
  b = tmp;
}

// print vector int
void printvector(vector<int> v1)
{
  for (auto tmp : v1) {
	cout << tmp << " ";
  }
  cout << "\n";
}

// comparator that can be passed separately as third parameter to sort
bool strcomp(string a, string b)
{
  if (a.size() != b.size()) return a.size() < b.size();
  else return a < b;
}

// when x >= 5 return true, false otherwise
bool ok(int num)
{
  if (num >= 5) {
	return true;
  } else {
	return false;
  }
}

int hill(int k)
{
  if (k == 5) {
	return 20;
  } else if (k < 5) {
	return k - 1;
  } else if (k > 20) {
	return 0;
  } else if (k > 5) {
	return 20 - k;
  } else {
	return 0;
  }
}

// this function accepts a pointer to an array of constants
void displayPayRates(const double* rates, int size)
{
  for (int i = 0; i < size; i++) {
	cout << rates[i] << "\n";
  }
}
