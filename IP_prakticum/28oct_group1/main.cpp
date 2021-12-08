#include <iostream>
#include <bitset>

int main() {
    //Task 1
    /*int a,b;
    std::cin >> a;
    for (b=1; b>0 ; b<<=1) 
        if ( (a & b) && (a & (b<<1) ) ) {
            std::cout << "False" << std::endl;
            return 0;
        }
    std::cout << "True" << std::endl;*/


    //Task 2
    /*int a, b,mask=(1<<31);
    std::cin >> a >> b;
    std::cout << ( 
        ( (a & mask) != (b & mask) )
    ? "TRUE" : "FALSE" ) << std::endl;
    */

    //Task 3
    /*int x;
    std::cin >> x;
    x = ((x << 2) + (x << 1) + x) >> 1;
    std::cout << x << std::endl;
    */

    //Task 4
    /*int a;
    std::cin >> a;
    for (int i = 1; i; i <<= 1) 
        if (!(a ^ i)) {
            std::cout << "YES" << std::endl;
            return 0;
        }
    std::cout << "NO" << std::endl;
    */

    //Task 5
    /*int n, pos1, pos2;
    std::cin >> n >> pos1 >> pos2;
    if (pos2 > pos1) {int c = pos1; pos1 = pos2; pos2 = c;}
    int keybit1 = (n & (1 << pos1));
    int keybit2 = (n & (1 << pos2));
    n -= keybit1 | keybit2;
    keybit1 >>= pos1 - pos2;
    keybit2 <<= pos1 - pos2;
    n |= keybit1 | keybit2;
    std::cout << n << std::endl;
    */

    //Task 6
    /*int a = 0;
    short operation,pos;

    for (int i = 0; i < 6; i++) {
        std::cin >> operation >> pos;
        if (operation == 0)
            a |= (1 << pos);
        else if (operation == 1)
            a &= ~(1 << pos);
        else if (operation == 2)
            a = ~(a ^ (1 << pos));
        
        //0 0->0
        //0 1->1
        //1 0->1
        //1 1->0
        //
        else {
            std::cout << "?" << std::endl;
            return 0;
        }
    }
    std::cout << a << std::endl;
    */

    //Task 7
    /*int bag = 0;
    short buf;
    for (int i = 0; i < 6; i++) {
        std::cin >> buf;
        bag |= (1 << buf);
    }
    for (int i = 0; i < 6; i++) {
        std::cin >> buf;
        std::cout << (bag & (1 << buf) ? "true" : "false") << std::endl;
    }
    */

    //Task 8
    /*int a, b;
    std::cin >> a >> b;
    //Analogically to the algorithm
    //a = a + b;
    //b = a - b;
    //a = a - b;
    b = a ^ b;
    a = ((~a) & b) | (a & (~b));
      // <-> ( !a ^ (a xor b) ) V ( a ^ !(a xor b) )
      // <-> ( !a ^ ((a ^ !b) v (!a ^ b)) ) V ( a ^ !(a xor b) )
      //        ...
      // <-> (!a & b) v (a & b)
      // <->    b
    b = ((~a) & b) | (a & (~b));  //Analogically to getting a:=value of b
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    */

    //Task 9
    /*int n;
    std::cin >> n;
    for (int i = 2; i <= n; i <<= 2) {
        int bit1 = (n & i)>>1;
        int bit2 = (n & (i >> 1))<<1;
        n &= ~(i + (i >> 1));
        n += bit1 + bit2;
    }
    std::cout << n << std::endl;
    */

    //Task 10
    /*int n;
    std::cin >> n;
    for (int i = 8; i <= n; i <<= 4) {
        int bit1 = (n & i) >> 3;
        int bit2 = (n & (i >> 3)) << 3;
        n &= ~(i + (i >> 3));
        n += bit1 + bit2;

        bit1 = (n & i>>1) >> 1;
        bit2 = (n & (i >> 2)) << 1;
        n &= ~((i >> 1) + (i >> 2));
        n += bit1 + bit2;
    }
    std::cout << n << std::endl;
    */

    //Task 11
    /*int n,down=0,up=31;
    std::cin >> n;
    if ((1 << ((down + up) >> 1)) > n) up = ((down + up) >> 1);
    else  down = ((down + up) >> 1);
    if ((1 << ((down + up) >> 1)) > n) up = ((down + up) >> 1);
    else  down = ((down + up) >> 1);
    if ((1 << ((down + up) >> 1)) > n) up = ((down + up) >> 1);
    else  down = ((down + up) >> 1);
    if ((1 << ((down + up) >> 1)) > n) up = ((down + up) >> 1);
    else  down = ((down + up) >> 1);
    if ((1 << ((down + up) >> 1)) > n) up = ((down + up) >> 1);
    else  down = ((down + up) >> 1);

    if ((1 << ((down + up) >> 1)) == n) {
        std::cout << n << " is power of 2" << std::endl;
        std::cout << n << " = 2^" << ((down + up) >> 1) << std::endl;
    }
    else std::cout << n << " is NOT power of 2" << std::endl;
    */

    //Task 12
    /*
    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i <<= 1)
        if (n & i) {
            std::cout << i << std::endl;
            return 0;
        }
    */
   
    //Task 17
    int n,a=0;
    long long p = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        p += (1 << (4 * (a - 1)) );
    }
    n /= 2;
    for (long long i = (1<<4)-1,a=1; i >0; i<<=4,++a,n<<=4) {
        if ((i & p) > n) {
            std::cout << a << std::endl;
            return 0;
        }
    }
    std::cout << "No supermajority element!" << std::endl;

    // Moore's voting algorithm!!!!!!!!!
	return 0;
}