#include <iostream>
#include <cstring>

using namespace std;

int Cstrlen(const char* abc)
{
  int length = 0;
  char str = *abc;
  while(str != '\0')
  {
    length ++;
    str = *(abc+length);
  }
  return length;
}

bool Cstrcmp(const char* str1, const char* str2)
{
  char char1 = *str1;
  char char2 = *str2;
  while(char1 != '\0' && char2 != '\0')
  {
    if(char1 != char2)
    {
      return false;
      break;
    }
    char1 = *(str1++);
    char2 = *(str2++);
  }
  return true;
}

char* Cstrcat(char* dest, const char* src)
{
  // char abc = *dest;
  // char xyz = *src;
  // while(abc != '\0')
  // {
  //   abc = *dest;
  //   dest++;
  // }
  // //cout << *(dest);
  // while(xyz != '\0')
  // {
  //   *dest = xyz;
  //   dest++;
  //   xyz = *(src++);
  // }

  // *(dest++) = '\0';
  
  // return dest;
  // size_t i,j;

  //   for (i = 0; dest[i] != '\0'; i++)

  //       ;

  //   for (j = 0; src[j] != '\0'; j++)

  //       dest[i+j] = src[j];

  //   dest[i+j] = '\0';

  //   return dest;
}

char* Cstrchr(const char* str, int character)
{
  char* result = (char*)str;
  while(*(result) != character)
  {
    result++;
  }
  return result;
}

int main() 
{
  cout << Cstrlen("Hello World") << "\n";
  cout << Cstrcmp("Hello", "Hello") << "\n";
  char a[10]={"123"}, b[10]={"def"};
  Cstrcat(a,b);

  char str[] = "This is a sample string";
  char * pch;
  printf ("Looking for the 's' character in \"%s\"...\n",str);
  pch=Cstrchr(str,'s');

  while (pch!=NULL)
  {
    printf ("found at %d\n",pch-str+1);
    pch=strchr(pch+1,'s');
  }
}