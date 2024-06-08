#include "cipher.h"

/// IN THIS FILE, IMPLEMENT EVERY FUNCTION THAT'S DECLARED IN cipher.h.



void encode (char s[], int k)
{
  if (k >= 0)
  {
    for (int i = 0; s[i] != '\0'; i++)
    {
      if ('a' <= s[i] && s[i] <= 'z')
      {
        s[i] = (char) ('a' + (s[i] - 'a' + k) % 26);
      }
      if ('A' <= s[i] && s[i] <= 'Z')
      {
        s[i] = (char) ('A' + (s[i] - 'A' + k) % 26);
      }
    }
  }
  else
  {
    while (k < 0)
    {
      k += 26;
    }
    for (int i = 0; s[i] != '\0'; i++)
    {
      if ('a' <= s[i] && s[i] <= 'z')
      {
        s[i] = (char) ('a' + ((s[i] - 'a' + k) % 26));
      }
      if ('A' <= s[i] && s[i] <= 'Z')
      {
        s[i] = (char) ('A' + ((s[i] - 'A' + k) % 26));
      }
    }
  }
}

void decode (char s[], int k)
{
  encode (s, -k);
}




