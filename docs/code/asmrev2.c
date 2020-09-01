#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
 * Program to print stdin to stdout in reverse order.
 *
 * This program reads stdin into a buffer dynamically allocated
 * at the (low) end of the stack. The data is read one byte at a time
 * starting at high memory, continuing down into low memory. Thus when
 * it's written to stdout from low memory, it will appear in
 * reverse order.
 */

#define Alloc16BytesOnStack(addr) asm volatile ("subq $16, %%rsp; movq %%rsp, %0;" : "=r"((addr)))
#define PopBytesOffStack(size)  asm("addq %0, %%rsp;" : :"r"(size))

int main( ) {
        char *buf; // buf will point to space at the low end of the stack
        unsigned long cnt=0; // the number of bytes read in
        long i;
        unsigned long ssize; // the number of bytes added to the stack

        for (ssize=16;; ssize += 16) {
                /* Grow the stack by 16 bytes, setting buf to refer
                   to its end. That it's 16 bytes is important for
                   alignment purposes.
                 */
	        Alloc16BytesOnStack(buf);
                for (i=15; i>=0; i--, cnt++) {
                    // read input into the newly allocated
                    // stack space, starting at the high end
                    if ((buf[i] = getchar()) == EOF)
                            goto done;
                }
        }
done:
        // write out everything read in
        write(1, &buf[i+1], cnt);
        write(1, "\n", 1);

        // pop all the added space off the stack
		PopBytesOffStack(ssize);
        return 0;
}


