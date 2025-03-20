/* - o codigo deve ser executado no windows, pois a funcão Sleep() so funciona no windows
   - o código deve ser aberto com a codificaçãoo Wastern (ISO 8859-1)
     para que o set locale funcione adequeadamente.

     código escrito por: João Carlos de Sousa Gurgel Rocha.
     Curso: Bacharelado em Tecnologia da Informação.
     componente curricular: Algoritmos e estruturas de dados I.
     instituição: Universidade Federal do Rual do Semi-árido - UFERSA.
     campus: Pau dos ferros.

contato: 
Github - Joaonuvem
E-mail - joao.carlosdesousagurgelrocha@gmail.com

descrição: O código pede ao usuário o cadastro de sua turma, indicando quantidade de alunos e os seus nomes,
apó isso ele usa uma função quicksort para os ordenar e aplica a busca biinaria. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// função quick sort.
int particao(char *turma[], int baixo, int alto);

void quickSort(char *turma[], int baixo, int alto);
//são duas.

//função que realiza a busca binaria.
int buscaBinaria(char *turma[], int baixo, int alto, char *aluno) {
    while (baixo <= alto) {
        //faz a busca de um termo central para reduzir a quantidade de resultados possiveis.
        int meio = baixo + (alto - baixo) / 2;
        
        // usa a função strcmp para comprar as strings, se forem iguais, a variavél recebe 0.
        int comparar = strcmp(turma[meio], aluno);
        
        //se a variavél comparar for igual a 0, se for, devolve o meio.
        if (comparar == 0) 
            return meio; 

        //reajuste de termo central.
        if (comparar < 0) 
            baixo = meio + 1; 
        if (comparar > 0)
            alto = meio - 1;  
    }
    //retorna -1 para indicar que string não foi encontrada dentro do vetor.
    return -1; 
}

//função main.
int main()
{
    setlocale(LC_ALL,"portuguese");
    int n;
    printf("Quantos aulos sua turma possui? ");
    scanf("%d", &n);
    //evita um problema com o buffer
    getchar();

    //aloca dinamicamente a memoria para n strings
    char **alunos = (char **)malloc(n * sizeof(char *));
    //teste de erro
    if (alunos == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return 1;
    }


    for (int i = 0; i < n; i++)
    {
        char nome[100];

        printf("Digite do %dº aluno: ", i + 1);
        fgets(nome, sizeof(nome), stdin);

        nome[strcspn(nome, "\n")] = '\0';

        //aloca dinamicamente cada character da string, de acordo com seu tamanho.
        alunos[i] = (char *)malloc((strlen(nome) + 1) * sizeof(char));
        //teste de erro
        if (alunos[i] == NULL)
        {
            printf("Erro ao alocar memória para a palavra %d.\n", i + 1);
            return 1;
        }
        //pega o nome do aluno de índice i e armazena no vetor no índe i.
        strcpy(alunos[i], nome);
    }

    //faz a ordenação
    quickSort(alunos, 0, n - 1);

    printf("\nAlunos ordenados por ordem alfabetica:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", alunos[i]);
    }
    char aluno[100];
    printf("\nQual aluno deseja buscar?: ");
    fgets(aluno, sizeof(aluno), stdin);
    aluno[strcspn(aluno, "\n")] = '\0';

    //aplica a busca binaria
    int resultado = buscaBinaria(alunos, 0, n - 1, aluno);
    
    //teste lógico 
    if (resultado != -1)
        printf("Aluno encontado na posição %d.\n", resultado+1);
    else
        printf("%s não foi encontrado(a) entre seus alunos.\n",aluno);


    //liberação de mémoria.
    for (int i = 0; i < n; i++)
    {
        free(alunos[i]);
    }
    free(alunos);

    return 0;
}

//corpo das funções que realizam o quicksort.
int particao(char *turma[], int baixo, int alto)
{
    char *pivo = turma[alto];
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++)
    {
        if (strcmp(turma[j], pivo) <= 0)
        {
            i++;
            char *nome = turma[i];
            turma[i] = turma[j];
            turma[j] = nome;
        }
    }

    char *nome = turma[i + 1];
    turma[i + 1] = turma[alto];
    turma[alto] = nome;

    return i + 1;
}
void quickSort(char *turma[], int baixo, int alto)
{
    if (baixo < alto)
    {

        int pi = particao(turma, baixo, alto);

        quickSort(turma, baixo, pi - 1);
        quickSort(turma, pi + 1, alto);
    }
}
