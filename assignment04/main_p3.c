#include <assert.h>
#include "stack.h"

int main(void)
{
    int result1;
    int result2;
    int result3;
    int result4;
    int result5;
    int testInt1;
    int testInt2;
    
    /* --------------- TEST 1: check is_empty and is_full when stack is empty --------------- */
    // Arrange:
    result1 = 2;
    result2 = 2;
    stack_init();
    
    // Act:
    result1 = stack_is_empty();
    result2 = stack_is_full();
    
    // Assert:
    assert(1 == result1);
    assert(0 == result2);
    
    /* --------------- TEST 2: push 1 element onto stack --------------- */
    // Arrange:
    result1 = 2;
    testInt1 = 42;
    stack_init();
    
    // Act:
    result1 = stack_push(testInt1);
    
    // Assert:
    assert(0 == result1);
    
    /* --------------- TEST 3: push, then pop 1 element from stack --------------- */
    // Arrange:
    result1 = 2;
    result2 = 2;
    testInt1 = 42;
    testInt2 = 33;
    stack_init();
    
    // Act:
    result1 = stack_push(testInt1);
    result2 = stack_pop(&testInt2);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(42 == testInt2);
    
    /* --------------- TEST 4: pop from empty stack --------------- */
    // Arrange:
    result1 = 2;
    testInt1 = 42;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt1);
    
    // Assert:
    assert(-1 == result1);
    assert(42 == testInt1);
    
    /* --------------- TEST 5: fill stack, check is_empty and is_full --------------- */
    // Arrange:
    result1 = 2;
    result2 = 2;
    result3 = 2;
    result4 = 2;
    result5 = 2;
    testInt1 = 42;
    stack_init();
    
    // Act:
    result1 = stack_push(testInt1);
    result2 = stack_push(testInt1);
    result3 = stack_push(testInt1);
    result4 = stack_is_empty();
    result5 = stack_is_full();
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(0 == result3);
    assert(0 == result4);
    assert(1 == result5);
    
    
    /* --------------- TEST 6: push onto stack when full --------------- */
    // Arrange:
    result1 = 2;
    result2 = 2;
    result3 = 2;
    result4 = 2;
    testInt1 = 42;
    stack_init();
    
    // Act:
    result1 = stack_push(testInt1);
    result2 = stack_push(testInt1);
    result3 = stack_push(testInt1);
    result4 = stack_push(testInt1);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(0 == result3);
    assert(-1 == result4);
    
    /* --------------- TEST 7: fill stack, then pop all data --------------- */
    // Arrange:
    testInt1 = 42;
    stack_init();
    
    // Act:
    stack_push(11);
    stack_push(22);
    stack_push(33);
    
    // Assert:
    assert(0 == stack_pop(&testInt1));
    assert(33 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(22 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(11 == testInt1);

    /* --------------- TEST 8: fill stack, pop 1, fill, then pop all --------------- */
    // Arrange:
    testInt1 = 42;
    stack_init();
    
    // Act:
    stack_push(11);
    stack_push(22);
    stack_push(33);
    
    // Assert:
    assert(0 == stack_pop(&testInt1));
    assert(33 == testInt1);
    
    assert(0 == stack_push(44));
    
    assert(0 == stack_pop(&testInt1));
    assert(44 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(22 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(11 == testInt1);
    
    /* --------------- TEST 9: fill stack, pop all, fill, pop all--------------- */
    // Arrange:
    testInt1 = 42;
    stack_init();
    
    // Act:
    stack_push(11);
    stack_push(22);
    stack_push(33);
    
    // Assert:
    assert(0 == stack_pop(&testInt1));
    assert(33 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(22 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(11 == testInt1);
    
    assert(0 == stack_push(44));
    assert(0 == stack_push(55));
    assert(0 == stack_push(66));
    
    assert(0 == stack_pop(&testInt1));
    assert(66 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(55 == testInt1);
    
    assert(0 == stack_pop(&testInt1));
    assert(44 == testInt1);
    
    return 0;
}