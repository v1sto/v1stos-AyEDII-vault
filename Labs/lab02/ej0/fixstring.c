#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
  unsigned int i = 0;
  while (s[i] != '\0')
  {
    i++;
  }
  return i;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
  unsigned int i = 0;
  bool resp;

  if (fstring_length(s1) == fstring_length(s2))
  {
    while (s1[i] == s2[i] && i < FIXSTRING_MAX)
    {
      resp = true && resp;
      i++;
    }
  }
  else
  {
    resp = false;
  }
  return resp;
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
  unsigned int i = 0;
  while (s1[i] == s2[i] && i < FIXSTRING_MAX)
  {
    i++;
  }

  return s1[i] <= s2[i];
}
