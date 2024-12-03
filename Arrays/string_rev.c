// #include <stdio.h>
// #include <stdlib.h>
// int palindrome(char str[], int i, int n)
// {
//     if (i >= n/2)
//         return 1;
//     if (str[i] != str[n - i - 1])
//         return 0;
//     palindrome(str, i + 1, n);
// }
// int main()
// {
//     char str[6] = "MAD0AM";
//     if (palindrome(str,0,6) == 1)
//         printf("Palindrome");
//     else
//         printf("not a palindrome");

//     return 0;
// }

#include <stdio.h>

int main() {
    int s = 0;
    while (s++ < 10) {
        if (s < 4 && s < 9) {
            continue;
        }
        printf("%d\t", s);
    }

    return 0;
}
