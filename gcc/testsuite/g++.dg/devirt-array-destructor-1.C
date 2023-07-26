// PR c++/110057
/* { dg-do run } */
/* Virtual calls should be devirtualized because we know dynamic type of object in array at compile time */
/* { dg-options "-O3 -fdump-tree-optimized -fno-inline"  } */

class A
{
public:
  virtual ~A()
  {
  }
};

class B : public A
{
public:
  virtual ~B()
  {
  }
};

int main()
{
  B b[10];
  return 0;
}
