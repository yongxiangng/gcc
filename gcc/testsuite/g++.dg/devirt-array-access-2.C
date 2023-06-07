/* { dg-do run } */
/* Virtual calls should be devirtualized because we know dynamic type of object in array at compile time */
/* { dg-options "-O3 -fdump-tree-optimized -fno-inline"  } */

class A
{
public:
    virtual void f() {};
};

class B : public A
{
public:
    virtual void f() {};
};

int __attribute__ ((noinline,noclone)) get_input(void)
{
    return 1;
}

int main()
{
    B* b = new B[10];
    b[get_input()].f();
    delete[] b;
    return 0;
}

/* { dg-final { scan-tree-dump-times "OBJ_TYPE_REF" 0 "optimized"} } */
