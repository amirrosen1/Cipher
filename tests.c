#include <string.h>

#include "tests.h"

#define K_1 3
#define K_2 2
#define K_3 -1
#define K_4 -3
#define K_5 29


int test_encode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "abc";
  char out[] = "def";
  encode (in, K_1);
  return strcmp (in, out) != 0;
}


int test_encode_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "y,z";
  char out[] = "a,b";
  encode (in, K_2);
  return strcmp (in, out) != 0;
}


int test_encode_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "d,e";
  char out[] = "c,d";
  encode (in, K_3);
  return strcmp (in, out) != 0;

}


int test_encode_cyclic_lower_case_negative_k ()
{
  char in[] = "abc";
  char out[] = "xyz";
  encode (in, K_4);
  return strcmp (in, out) != 0;
}


int test_encode_cyclic_upper_case_positive_k ()
{
  char in[] = "ABC";
  char out[] = "DEF";
  encode (in, K_5);
  return strcmp (in, out) != 0;
}


int test_decode_non_cyclic_lower_case_positive_k ()
{
  char in[] = "def";
  char out[] = "abc";
  decode (in, K_1);
  return strcmp (in, out) != 0;
}


int test_decode_cyclic_lower_case_special_char_positive_k ()
{
  char in[] = "a,b";
  char out[] = "y,z";
  decode (in, K_2);
  return strcmp (in, out) != 0;
}


int test_decode_non_cyclic_lower_case_special_char_negative_k ()
{
  char in[] = "d,e";
  char out[] = "e,f";
  decode (in, K_3);
  return strcmp (in, out) != 0;
}


int test_decode_cyclic_lower_case_negative_k ()
{
  char in[] = "xyz";
  char out[] = "abc";
  decode (in, K_4);
  return strcmp (in, out) != 0;
}


int test_decode_cyclic_upper_case_positive_k ()
{
  char in[] = "ABC";
  char out[] = "XYZ";
  decode (in, K_5);
  return strcmp (in, out) != 0;
}
