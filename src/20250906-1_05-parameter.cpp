#include <iostream>

using namespace std;

// x は引数のコピー
void f1(int x) {
  cout << ++x << endl;
}

// x は引数のコピー(変更不可)
void f2(const int x) {
  cout << x +1 << endl;
}

// x は引数の参照
void f3(int& x) {
  cout << ++x << endl;
}

// x 引数の参照(変更不可)
void f4(const int& x) {
  cout << x +1 << endl;
}

// x は引数の右辺値参照
void f5(int&& x) {
  cout << ++x << endl;
}

// x は引数の右辺値参照(参照不可)
void f6(const int&& x) {
  cout << x + 1 << endl;
}

// p はint型変数のアドレスのコピー
void f7(int* p) {

}



int main() {
  int a = 12345;
  cout << a << endl;
}