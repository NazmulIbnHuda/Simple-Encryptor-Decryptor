#include <stdio.h>
#include <string.h>

void Page(void);
void Encoder(void);
void Decoder(void);
int Engine(int i);

int main(void)
{
    printf("Welcome to Nazmul Ibn  Huda's Encryptor & Decryptor Application.\n");
    Page();
    return 0;
}

void Page(void)
{
    int choice;
    printf("1.Encrypt Message.\n");
    printf("2.Decrypt Message.\n");
    printf("0.Exit Program.\n");
    printf("Enter Your Choice: ");
    scanf("%d", &choice);
    if (choice == 1)
        Encoder();
    else if (choice == 2)
        Decoder();
    else if (choice == 0)
        return;
    printf("Enter 0 to Exit and 1 to Go back to Main page.\n");
    scanf("%d", &choice);
    if (choice == 1)
        Page();
}

void Encoder(void)
{
    printf("Enter Your Message to Encrypt : ");
    char str[9999];
    fgets(str, 10000, stdin);
    fgets(str, 10000, stdin);
    printf("Encrypted Message : ");
    for (int i = 0; str[i]; i++)
        printf("%.5d", Engine(str[i]));
    printf("\n");
}

void Decoder(void)
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
