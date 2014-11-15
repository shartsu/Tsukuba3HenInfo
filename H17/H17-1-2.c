#include <stdio.h>

main()
{
  int x[100], i, n;
  float s, ss, a ,sigma2;
  scanf("%d", &n);

  /* ループ1 */
  for(i = 0; i < n; i++)
    scanf("%d", &x[i]);
  s = ss = 0.0;
  
  /* ループ2 */
  
  for(i = 0; i < n; i++)
    s += x[i];
  a = s/n;
  

  /*
    for(i = 0; i < n; i++)
    ss += ((x[i] - a) * (x[i] - a));
  sigma2 = ss/n;
  */

  for(i = 0; i < n; i++){
    ss += (x[i]*x[i])-(2*a*x[i])+(a*a);
  }

  sigma2 = ss/(n);

  printf("%f %f\n", a, sigma2);
}
