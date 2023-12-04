#include <stdio.h>
#include <string.h>

void my_strlen(char *string, int *tamanho);
void my_strcpy(char *string1, int tam1, char *string2, int tam2);

int main()
{
    int op;
    int tam = 0;
    char minhaString2[20];
    
    char minhaString[] = "Bolo de chocolate";
    printf("Minha string: %s", minhaString);
    
    do 
    {
        printf("\n\nO que deseja fazer?\n[1] Usar a funcao 'strlen'\n[2] Usar a funcao 'strcpy'\n[3] Usar a funcao 'strcat'\n[4] Usar a funcao 'strcmp'\n[5] Sair\n============> ");
        scanf("%d", &op);
        
        switch(op)
        {
            case 1:
                my_strlen(minhaString, &tam);
                printf("\nO tamanho da string eh: %d", tam);
                break;
                
            case 2:
                my_strcpy(minhaString, 18, minhaString2, 20);
                break;
                
            case 3:
                //strcat(minhaString);
                break;
                
            case 4:
                //strcmp(minhaString);
                break;
            case 5:
                break;
            default:
                printf("\n\nInsira uma opcao valida.");
        }
        
    } while (op != 5);
    
    return 0;
}

void my_strlen(char *string, int *tamanho)
{
    int i;
    
    for(i = 0; string[i] != '\0'; i++)
    {
    }
    
    *tamanho = i;
}

void my_strcpy(char *string1, int tam1, char *string2, int tam2)
{
    int i;
    
    for(i = 0; i < tam1 && i < tam2 - 1; i++)
    {
        string2[i] = string1[i];
    }
    string2[i] = '\0';
    
    printf("\nPrintando string2:\n");
    int j;
    for (j = 0; j < tam2; j++)
    {
        printf("%c.", string2[j]);
    }
}

