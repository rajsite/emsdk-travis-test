#include<stdio.h>
#include<emscripten.h>

// int main() {
//   printf("Hello to the entire HTML world!\n");
//   double test = 7;
//   // EM_ASM({
//   //   console.log('I received ' + $0);
//   // }, test);
//   return 0;
// }

EM_JS(void, read_data, (int* data), {
  debugger;
  console.log('Data: ' + HEAP32[data>>2] + ', ' + HEAP32[(data+4)>>2]);
});

int main() {
  int arr[2] = { 30, 45 };
  read_data(arr);
  return 0;
}