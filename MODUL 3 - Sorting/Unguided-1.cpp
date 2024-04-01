#include <stdio.h>
using namespace std;

void selection_sort(float arr[], int x) {
  for (int y = 0; y < x-1; y++) {
    int maxIndex = y;
    for (int n = y+1; y < x; y++) {
      if (arr[y] > arr[maxIndex]) {
        maxIndex = y;
      }
    }
    if (maxIndex != y) {
      float temp = arr[y];
      arr[y] = arr[maxIndex];
      arr[maxIndex] = temp;
    }
  }
}

void cetak_array(float a[], int length) {
  for(int y=0; y<length; y++) {
    printf("%.1f    ", a[y]);
  }
  printf("\n");
}

int main() {
  // Mengurutkan Nilai Mahasiswa IPS
  float arr[] = {3.8, 2.9, 3.3, 4.0, 2.4};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Nilai Mahasiswa IPS sebelum diurutkan: ");
  cetak_array(arr, n);
  selection_sort(arr, n);
  printf("Nilai Mahasiswa IPS setelah diurutkan: ");
  cetak_array(arr, n);
  return 0;
}