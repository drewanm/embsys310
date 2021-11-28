int func1(int arg1, int arg2, int arg3, int arg4, int arg5);
int func2(void);

int main(void)
{
    int sum = func2();
    return 0;
}

// function 1 - problem 2
int func1(int arg1, int arg2, int arg3, int arg4, int arg5)
{
    return arg1 + arg2 + arg3 + arg4 + arg5;
}

// function 2 - problem 2
int func2(void)
{
    return func1(0x10,0x20,0x30,0x40,0x50);
}