// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int i, j, k;
  for (i = 0; i < len - 1; i++) {
    for (j = i + 1; j < len; j++) {
      if (arr[j] + arr[i] == value) {
        k++;
      }
    }
  }
  if (k > 0) {
    return k;
  } else {
    return 0;
  }
}

int countPairs2(int *arr, int len, int value) {
int i, j, k, rb;
rb = len - 1;
for (i = 0; i < len / 2; i++) {
  if (arr[i] >= 50) {
    continue;
  }
  for (j = rb; j > i; j--) {
    if (arr[j] >= 50) {
      rb--;
      continue;
    }
    if (arr[j] + arr[i] == value) {
      k++;
    }
  }
}
if (k > 0) {
  return k;
} else {
  return 0;
}
}

int countPairs3(int *arr, int len, int value) {
  int i, j, index;
  for (i = 0; i < len - 1; i++) {
    index = i;
    for (j = i + 1; j < len; j++) {
      if (arr[j] < arr[index]) {
        index = j;
      }
    }
    int t = arr[index];
    arr[index] = arr[i];
    arr[i] = t;
  }

  int l, p, k;
  int rb, lb, fg = 0;
  rb = len;
  lb = 0;
  while (fg == 0) {
    if ((arr[rb] + arr[lb]) < 50) {
      rb--;
    }
    if ((arr[rb] + arr[lb]) > 50) {
      lb++;
    }
    if ((arr[rb] + arr[lb]) == 50) {
      k++;
      rb--;
    }
    if (rb > lb) {
      break;
    }
  }
  if (k > 0) {
    return k;
  } else {
    return 0;
  }
}
