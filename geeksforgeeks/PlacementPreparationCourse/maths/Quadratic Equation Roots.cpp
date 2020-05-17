/*Given a quadratic equation in the form ax2 + bx + c. You need to print roots of it.

Input:
First line of input contains an integer, the number of test cases T. Each test case contains three positive numbers a, b and c in the same line seperated by space.

Output: 
If roots of equations exits, then print the two roots separated by space (Higher valued root should be printed before lower valued). If roots are imaginary, then print "Imaginary".

Note 1 :  Please do NOT to add "\n" or newline after printing output in your function.  Newline is added by the driver code.
Note 2 : Please do float division like (-b+sqrt(b2-4ac)) / 2.0*a.
Note 3 : Please use floor function, note that roots can be negative.

Your Task:
This is a function problem. You only need to complete the function quadraticRoots that takes a,b,c as parameters and prints the floor value of roots. The other tasks are already performed by the driver function. The newline is already appended by the driver code.

Constraints:
1 <= T <= 50
1 <= a <= 103
1 <= b <= 103
1 <= c <= 103

Example:
Input:
3
1 -2 1
1 -7 12
1 4 8

Output:
1 1
4 3
Imaginary

Explanation:
Testcase 1: Roots of equation x2-2x+1 are 1 and 1.
Testcase 2: Roots of equation x2 - 7x + 12 are 4 and 3.
Testcase 3: Roots of equation x2 + 4x + 8 are imaginary since it's discriminant is less than 0.

 
 */

//floor(-.232)=-1

//You need to complete this function
void quadraticRoots(int a, int b, int c)
{
    int D;
    D = pow(b, 2) - 4 * a * c;

    if (D < 0)
        cout << "Imaginary";

    else if (D > 0)
    {
        cout << floor((sqrt(D) - b) / (2.0 * a)) << " " << floor((-sqrt(D) - b) / (2.0 * a));
    }
    else
    {
        int ans = floor((-sqrt(D) - b) / (2.0 * a));
        cout << ans << " " << ans;
    }
    //Your code here

    // Your don't need to printline
    // It will automatically be
    // handled by driver code
}
