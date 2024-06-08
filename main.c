#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cipher.h"
#include "tests.h"

int k_check (char const k[])
{
  int i = 0;
  while (k[i] != '\0')
  {
    if (k[0] == '-')
    {
      if (k[1] == '\0')
      {
        fprintf (stderr, "The given shift value is invalid.\n");
        return EXIT_FAILURE;
      }
      i += 1;
      continue;
    }
    if (k[i] > '9' || k[i] < '0')
    {
      fprintf (stderr, "The given shift value is invalid.\n");
      return EXIT_FAILURE;
    }
    i += 1;
  }
  return EXIT_SUCCESS;
}

int validate (int argc, char *argv[])
{
  if (argc != 2 && argc != 5)
  {
    fprintf (stderr, "The program receives 1 or 4 arguments only.\n");
    return EXIT_FAILURE;
  }
  if (argc == 2 && strcmp (argv[1], "test") != 0)
  {
    fprintf (stderr, "Usage: cipher test\n");
    return EXIT_FAILURE;
  }
  if (argc != 2)
  {
    if (strcmp (argv[1], "encode") != 0
        && strcmp (argv[1], "decode") != 0)
    {
      fprintf (stderr, "The given command is invalid.\n");
      return EXIT_FAILURE;
    }
    int yyyyyyy = k_check (argv[2]);
    if (yyyyyyy == EXIT_FAILURE)
    {
      return EXIT_FAILURE;
    }
  }
  return EXIT_SUCCESS;
}

int tests ()
{
  int a = test_encode_non_cyclic_lower_case_positive_k ();
  int b = test_encode_cyclic_lower_case_negative_k ();
  int c = test_encode_cyclic_upper_case_positive_k ();
  int d = test_encode_cyclic_lower_case_special_char_positive_k ();
  int e = test_encode_non_cyclic_lower_case_special_char_negative_k ();
  int f = test_decode_non_cyclic_lower_case_positive_k ();
  int g = test_decode_cyclic_lower_case_special_char_positive_k ();
  int h = test_decode_non_cyclic_lower_case_special_char_negative_k ();
  int i = test_decode_cyclic_lower_case_negative_k ();
  int j = test_decode_cyclic_upper_case_positive_k ();
  int sum = a + b + c + d + e + f + g + h + i + j;
  return sum;
}

int main (int argc, char *argv[])
{
  int res = validate (argc, argv);
  if (res == EXIT_FAILURE)
  {
    return EXIT_FAILURE;
  }
  if (argc == 5)
  {
    FILE *in_file = fopen (argv[3], "r");
    FILE *out_file = fopen (argv[4], "w");
    if (in_file == NULL || out_file == NULL)
    {
      fprintf (stderr, "The given file is invalid.\n");
      return EXIT_FAILURE;
    }
    char line[1025] = {0};
    long key = strtol (argv[2], NULL, 10);
    if (strcmp (argv[1], "encode") == 0)
    {
      while (fgets (line, 1025, in_file))
      {
        encode (line, key);
        fputs (line, out_file);
      }
    }
    if (strcmp (argv[1], "decode") == 0)
    {
      while (fgets (line, 1025, in_file))
      {
        encode (line, key);
        fputs (line, out_file);
      }
    }
    return EXIT_SUCCESS;
  }
  else if (argc == 2)
  {
    int sum2 = tests ();
    if (sum2 != 0)
    {
      return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
  }
}

