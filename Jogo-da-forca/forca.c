#include <stdio.h>

int main()
{   
    int erros = 6;
    int letraErrada;
    int flag;
    char letraUsuario;
    char palavra[] = "computador";
    char progresso[11];

    for (int i = 0; palavra[i] != '\0'; i++)
    {
        progresso[i] = '_';
    }
    progresso[10] = '\0';

    while (1)
    {
        printf("Chances: %d\n", erros);
        printf("Quantidade de letras: %d\n", 10);

        printf("%s\n", progresso);

        printf("Digite uma letra: \n");
        scanf(" %c", &letraUsuario);
        
        
        /*
        Verificar se a entrada é válida
        if(letraUsuario >= '0' && letraUsuario <= '9') {
            printf("A entrada é inválida!\n");
        }*/

        letraErrada = 1;

        // Verifica se a letra existe na palavra
        for (int i = 0; palavra[i] != '\0'; i++)
        {
            if (letraUsuario == palavra[i])
            {
                progresso[i] = letraUsuario;
                letraErrada = 0;
            }
        }

        // Detector de letra errada
        if(letraErrada == 1)
        {
            printf("Letra errada\n");
            erros--;
            // Se errar tudo então perde
            if(erros == 0) {
                printf("Derrota! Seu NEWBA!\n");
                break;
            }
        }

        // Se ganhou 1, se não 0
        flag = 0;

        // Verifica se progresso tem underscore
        for(int i=0; progresso[i] != '\0'; i++) {
            if(progresso[i] == '_') {
                flag = 1;
                break;
            }
        }

        // Verifica se progresso é igual a palavra
        if(flag == 0) {
            printf("%s\n", progresso);
            printf("Voce ganhou!\n");
            break;
        }
        
    }

    return 0;
}