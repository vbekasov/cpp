#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace::std;

struct Person
{
  char name[50];
  int age;
  char phone[24];
};

int main()
{
  Person me = {"Robert", 28, "364-2534"};
  Person book[30];
  int x = 123;
  double fx = 34.54;
  ofstream outfile;
  outfile.open("junk.dat", ios::binary | ios::out);
  outfile.write(&x, sizeof(int)); // sizeof can take a type
  outfile.write(&fx, sizeof(fx)); // or it can take a variable name
  outfile.write(&me, sizeof(me));
  outfile.write(&book, 30*sizeof(Person));
  outfile.close();
}