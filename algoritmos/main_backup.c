void insertion(int size, int min, int max) {

  /**
     int size = atoi(argv[1]);
     int min = atoi(argv[2]);
     int max = atoi(argv[3]);
     
  **/

  int * v = generateRandomVector(size, min, max);
  
  
  insertionSort(v, size);
  binarySearchIterative(v, 0, size - 1, 3);

  
  printf("Vetor não ordenado:\n");
  printVector(v, size);

  printf("[MERGE SORT] Vetor ordenado:\n");
  mergeSort(v, 0, size - 1);
  printVector(v, size);
  
  v = generateRandomVector(size, min, max);

  printf("Vetor não ordenado:\n");
  printVector(v, size);

  insertionSort(v, size);
  
  printf("[INSERTION SORT] Vetor ordenado:\n");
  printVector(v, size);
}
