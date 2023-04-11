#include <iostream>
#include <set>
using namespace std;
int main() {

  // 宣告整數 set
  set<int> numSet;

  // 新增元素
  numSet.insert(1);
  numSet.insert(6);
  numSet.insert(8);
  numSet.insert(6);

  // 檢查 set 是否包含指定元素
  set<int>::iterator iter;
  iter = numSet.find(6);
  if (iter != numSet.end()) {
    cout << "Found: " << *iter << endl;
  } else {
    cout << "Not found." << endl;
  }

  // 以迴圈逐一處理 set 中的每個元素
  cout << "All elements:" << endl;
  for (iter = numSet.begin(); iter != numSet.end(); iter++) {
    cout << *iter << endl;
  }

  return 0;
}