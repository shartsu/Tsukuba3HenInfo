#include <stdio.h>

main()
{
  int x[100], i, n;
  float s, ss, a ,sigma2;
  scanf("%d", &n);

  /* Loop 1 */
  for(i = 0; i < n; i++)
    scanf("%d", &x[i]);
  s = ss = 0.0;

  /* Loop 2 */

  for(i = 0; i < n; i++)
    s += x[i];
  a = s/n;

  for(i = 0; i < n; i++){
    ss += (x[i]*x[i])-(2*a*x[i])+(a*a);
  }

  sigma2 = ss/(n);

  printf("%f %f\n", a, sigma2);
}
