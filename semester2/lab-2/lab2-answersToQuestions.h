Xander Gennarelli
CSI 1440 Section 07
Lab 2

1. What would be printed if we just incremented the pointer
   (myPtr++)?
      ello World!

2. How does “myArray += 6” differ from what we talked about
   in class - “*(myArray + 6)” - which we said was OK?
      "myArray += 6" attempts to change the address of the
      array, while "*(myArray + 6)" just gives the address of
      the seventh value in myArray or myArray[6].
3. Replace the array notation statements with pointer notation
   statements for the assignment of ‘o’, ‘w’, ‘d’, and ‘y’.
     *(myArray + 1) = 'o';
     *(myArray + 2) = 'w';
     *(myArray + 3) = 'd';
     *(myArray + 4) = 'y';

4. Could this code be fixed by using pointer notation instead
   of array notation? Why/Why not?
    No, because when you are operating on a pointer array and
    pointer notation have the same effect. Since the string
    literal is a constant there is no way to change it from
    the pointer.

5. Why did we not give the memory back to the computer,
   using the delete operator, within the function?
    Because then the function would be useless. It would
    assign and release the memory before the rest of the
    program had a chance to use it.

6. Why do we not need to use the indirection operator when
   printing the contents of myArray and myPtr? Could we
   print the contents of a differently typed (int, double,
   etc..) array?
    Because char type arrays end with a null character '\0'
    so the program knows when to stop printing. You couldn't
    do this with other array types.

7. Write two additional lines of code to print out the
   contents of str as a c-string representation using
   c_str() with both the indirection operator and the
   structure pointer operator.
   cout << (*str).c_str() << endl;
   cout << str->c_str() << endl;
