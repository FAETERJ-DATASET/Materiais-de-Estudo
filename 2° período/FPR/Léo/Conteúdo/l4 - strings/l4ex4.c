/*Implementar uma função que remova todas as
ocorrências de determinado caracter em uma
string.*/
#include <stdio.h>
#include <string.h>

void removerOcorrencia(char v1[], char c);

int main()
{
    char minhaString[] = "Bolo de chocolate";
    int tamanho = strlen(minhaString);
    char crt;
    int i;
    
    printf("Minha string: ");
    for(i = 0; i < tamanho; i++)
    {
        printf("%c", minhaString[i]);
    }
    
    printf("\nQual caractere deseja remover?\n");
    scanf("%c", &crt);
    getchar(); // Consumir o caractere de nova linha no buffer
    
    removerOcorrencia(minhaString, crt);
    
    printf("Nova string: ");
    for(i = 0; i < tamanho; i++)
    {
        printf("%c", minhaString[i]);
    }
    return 0;    
}

void removerOcorrencia(char v[], char c)
{
    int i, j;
    
    while(v[i])
    {
        if(v[i] == c)
        {
            for(j=i; v[j]; j++)
            {
                v[j] = v[j+1];
            }

            v[j] = '\0';
        }
        else
        {
            i++;
        }
    }
}

