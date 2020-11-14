void quick_sort(int b[], int left, int right) {
    if (left < right) {
        int mid = get_mid(b, left, right);
        quick_sort(b, left, mid - 1);
        quick_sort(b, mid + 1, right);
    }
}

int get_mid(int b[], int left, int right) {
    int pivot = b[left];
    while (left < right) {
        while(b[right] >= pivot && left < right) --right;
        b[left] = b[right];
        while(b[left] <= pivot && left < right) ++left;
        b[right] = b[left];
    }
    b[left] = pivot;
    return left;
}
