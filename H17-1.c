#include <stdio.h>

main()
{
  int x[100], i, n;
  float s, ss, a ,sigma2;
  scanf("%d", &n);

  /* ���[�v1 */
  for(i = 0; i < n; i++)
    scanf("%d", &x[i]);
  s = ss = 0.0;
  
  /* ���[�v2 */
  for(i = 0; i < n; i++)
    s += x[i];
  a = s/n;

  /* ���[�v3 */
  for(i = 0; i < n; i++)
    ss += ((x[i] - a) * (x[i] - a));
  sigma2 = ss/n;

  printf("%f %f\n", a, sigma2);
}
