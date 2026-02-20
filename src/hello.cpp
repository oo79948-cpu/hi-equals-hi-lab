#include <string>

size_t numberCompare(std::string s1, std::string s2) {
   std::string digitString1;
   int i = 0;
   while (isdigit(s1[i])) {
      digitString1 += (s1[i]);
      i++;
   }

   std::string digitString2;
   int j = 0;
   while (isdigit(s2[j])) {
      digitString2 += (s2[j]);
      j++;
   }

   int digit1 = std::stoi(digitString1);
   int digit2 = std::stoi(digitString2);

   if (digit1 == digit2) {
      return 0;
   } if (digit1 < digit2) {
      return -1;
   }
   return 1;
}


size_t strcmp_case_insensitive(std::string string1, std::string string2, bool skipSpaces = false, int maxCharacters = -1) {
   std::string s1 = string1;
   std::string s2 = string2;

   if (skipSpaces) {
      std::erase(s1, ' ');
      std::erase(s2, ' ');
   }

   size_t size1 = s1.size();
   size_t size2 = s2.size();
   size_t minsize = size1 < size2 ? size1 : size2;
   if (minsize > maxCharacters && maxCharacters >= 0) {
      minsize = maxCharacters;
      size1 = size2 = minsize;
   }

   char c1;
   char c2;

   std::string digitString1;
   std::string digitString2;

   for( int i=0; i<(minsize); i++ ) {
      c1 = std::tolower(s1[i]);
      c2 = std::tolower(s2[i]);


      if (i == 0 && isdigit(c1) && isdigit(c2)) {
         return numberCompare(s1, s2);
      }

      if (c1 > c2) {
         return 1;
      } if (c1 < c2) {
         return -1;
      }
   }
   if (size1 > size2) {
      return 1;
   } if (size1 < size2) {
      return -1;
   }
   return 0;
}
