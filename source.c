// Credit : Nazmul Ibn Huda
// GitHub : https://github.com/NazmulIbnHuda

#include <stdio.h>
#include <string.h>

//Function Proto-types
void Page(void);
void Encryptor(void);
void Decryptor(void);
int Engine(int i);

//Driver Function
int main(void)
{
    printf("Welcome to Nazmul Ibn  Huda's Encryptor & Decryptor Application.\n");
    Page();
    return 0;
}

//Managing Function
void Page(void)
{
    int choice;
    printf("1.Encrypt Message.\n");
    printf("2.Decrypt Message.\n");
    printf("0.Exit Program.\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    if (choice == 1)
        Encryptor();
    else if (choice == 2)
        Decryptor();
    else if (choice == 0)
        return;
    printf("Enter 0 to Exit and 1 to Go back to Main page.\n");
    scanf("%d", &choice);
    if (choice == 1)
        Page();
}

//Encryptor Function
void Encryptor(void)
{
    printf("Enter Your Message to Encrypt : ");
    char null[5],str[9999];
    fgets(null, 5, stdin);
    fgets(str, 9999, stdin);
    printf("Encrypted Message : ");
    for (int i = 0; str[i]; i++)
        printf("%.5d", Engine(str[i]));
    printf("\n");
}

//Decryptor Function
void Decryptor(void)
{
    printf("Enter Encrypted Message to Decrypt : ");
    char str[50000];
    scanf("%s", str);
    printf("Decrypted Message: ");
    for (int i = 0; i < strlen(str); i += 5)
    {
        int num = 10000 * (str[i] - 48) + 1000 * (str[i + 1] - 48) + 100 * (str[i + 2] - 48) + 10 * (str[i + 3] - 48) + 1 * (str[i + 4] - 48);
        printf("%c", Engine(num));
    }
    printf("\n");
}

//Main Engine. Used by both Encryptor & Decryptor Function.
int Engine(int i)
{
    union
    {
        int a;
        char c[2];
    } crypt;
    char ch;
    crypt.a = i;
    ch = crypt.c[0];
    crypt.c[0] = crypt.c[1];
    crypt.c[1] = ch;
    i = crypt.a;
    return i;
}
