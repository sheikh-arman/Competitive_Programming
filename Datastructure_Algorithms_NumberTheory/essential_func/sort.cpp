sort(b.begin(), b.end(), [&](int i, int j) {
    if (a[i] != a[j]) {
      return a[i] < a[j];
    }
    return i < j;
});
