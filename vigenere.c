#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

//* CS50 Vigenere solution
//  Author James Meehan
//*

int main (int argc, string argv[]) 
{
  // check that proper command line argument was entered    
  if (argc != 2)
  {
      printf("O hai! You did enter a proper command line prompt!!!\n");
      return 1;
  }
  else if 
  (argc == 2)
  {
      for (int i = 0, n = strlen(argv[1]); i < n; i++)
      {
        if (argv[1][i] < 65 || (argv[1][i] > 90 && argv[1][i] < 97) || argv[1][i] > 123)
        {
          printf("O hai! The command prompt must be all alphabetical!!!");
          return 1;
        }
      }
  }
  
  // get plaintext string from user
  printf("plaintext: ");
  string s = get_string();
  printf("ciphertext: ");
  int keyword_pos = 0;
  
  // iterate through string and output ciphertext
  for (int i = 0; i < strlen(s); i++)
  {
  int key_length = strlen(argv[1]);
  int cipherkey = (toupper(argv[1][keyword_pos % key_length])) - 65;
  
    // check to see if character is a letter 
    if (s[i] < 65 || (s[i] > 90 && s[i] < 97) || s[i] > 122)
    {
      printf("%c", s[i]);
    }
      // output if character is a letter and doesn't need to wrap around
      else if (toupper(s[i]) + cipherkey <= 90)
      {
      printf("%c", s[i] + cipherkey);
      keyword_pos++;
      }
        // output if character is a letter and needs to wrap around
        else 
        {
        printf("%c", s[i] + cipherkey - 26);
        keyword_pos++;
        }
  }
  printf("\n");
  return 0;
}
