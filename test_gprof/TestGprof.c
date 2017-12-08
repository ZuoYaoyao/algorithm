#include<stdio.h>
#include <stdlib.h>
void TestFunc();
static void StaticFunc();

void TestFunc()
{
        int i = 0;

        printf("In TestFunc\n");

        for (i=0; i<20; i++)
                StaticFunc();

}

static void StaticFunc()
{
        int i = 0;

        printf("In StaticFunc\n");

        for (i=0; i<1000000000; i++);
}

int main(void)
{
        printf("In main\n");

        TestFunc();

        return 0;
}