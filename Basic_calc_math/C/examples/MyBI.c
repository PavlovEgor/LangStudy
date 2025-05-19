#include "bigd.h"

BIGD fact(int n){
    BIGD tmp, cur, j;

    bdSetShort(cur, 1);

    for (int i = 1; i <= n; i++)
    {
        bdSetShort(j, i);
        bdMultiply(tmp, cur, j);

        cur -> digits = (tmp -> digits);
        cur -> ndigits = (tmp -> ndigits);
        cur -> maxdigits = (tmp -> maxdigits);
    }
    return cur;
}

int main(void)
{
  BIGD u, v, w;
  /* Create new BIGD objects */
  u = bdNew();
  v = bdNew();
  w = bdNew();
  
  /* Compute 2 * 0xdeadbeefface */
  bdSetShort(u, 2);
  bdConvFromHex(v, "deadbeefface");
  bdMultiply(w, u, v);
  
  /* Display the result in hex and decimal */
  bdPrintHex("0x", w, "\n");
  bdPrintDecimal("", w, "\n");
  
  /* Free all objects we made */
  bdFree(&u);
  bdFree(&v);
  bdFree(&w);

  int n = 5;
  BIGD A;

  A = fact(n);
  bdPrintDecimal("", A, "\n");
  bdFree(&A);

  return 0;
}