
void swap_pointer(int** xPtr, int** yPtr);

int main()
{
    int x = 12345;
    int y = 67890;
    int* xPtr = &x;
    int* yPtr = &y;
    swap_pointer(&xPtr, &yPtr);
    return 0;
}

void swap_pointer(int** xPtr, int** yPtr)
{
    int* tmp = *xPtr;
    *xPtr = *yPtr;
    *yPtr = tmp;
}