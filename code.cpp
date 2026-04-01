#include<bits/stdc++.h>
using namespace std;
class animal {
public:
   virtual void sound() {
    cout << "Animal\n";
  }
};

class dog : public animal {
public:
  void sound ()  {
    cout << "Barks\n";
  }
};


int main() {
  dog *cur = new dog();
  animal *temp = cur;
  temp->sound();
}