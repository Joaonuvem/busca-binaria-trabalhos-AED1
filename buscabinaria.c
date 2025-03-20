/*   - o código deve ser aberto com a codificaçãoo Wastern (ISO 8859-1)
     para que o set locale funcione adequeadamente.

     código escrito por: João Carlos de Sousa Gurgel Rocha.
     Curso: Bacharelado em Tecnologia da Informação.
     componente curricular: Algoritmos e estruturas de dados I.
     instituição: Universidade Federal do Rual do Semi-árido - UFERSA.
     campus: Pau dos ferros.

contato: 
Github - Joaonuvem
E-mail - joao.carlosdesousagurgelrocha@gmail.com

descrição: O código pede para a usuário digitar o tamanho de um array, em seguida o codigo usa uma função bubble sort para o organizar, após isso ele pergunta ao usuário qual valor
ele deseja encontrar dentro do array, para fazer a busca o código utiliza o método da busca binária. */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

// declaração global das váriaveis 
int n;
int *ponteiro;

//função para ler os valores.
void lervalores()
{
    printf("Favor, digitar a quantidade de valores que você deseja inserir.\n");
    scanf("%d", &n);

    //aloca um ponteiro para n valores.
    ponteiro = (int *)malloc(n * sizeof(int));

    int i = 0;
    while (i < n)
    {

        printf("Digite o %dº número\n", i + 1);
        scanf("%d", &ponteiro[i]);
        i++;
    }
}
//função para exibir os valores.
void exibirvalores()
{

    for (int i = 0; i < n; i++)
    {

        printf("%d ", ponteiro[i]);
    }
    printf("\n");
}
//função bubble sort para realizar a ordenação.
void bubblesort();

//função valor, que usa de uma busca binária para identificar uma valor em um ponteiro.
int buscar()
{
    int valor;
    printf("Digite o valor que você deseja encontrar");
    scanf("%d", &valor);
    {
        // (1,2,3,4,5,6,)
        int baixo = 0;
        int alto = n - 1;

        while (baixo <= alto)
        {
            //determina um termo central para dividir o array consecutivas vezes.
            int meio = baixo + (alto - baixo) / 2;
            if (ponteiro[meio] == valor)
            {
                //retorna o valor central caso ele seja igual ao número buscado
                return meio;
            }
            if (ponteiro[meio] < valor)
            {
                baixo = meio + 1;
            }
            if (ponteiro[meio] > valor)
            {
                alto = meio - 1;
            }
        }
    }
    //inidica que o número não foi encontrado
    return -1;
}

//função main.
int main()
{
    setlocale(LC_ALL, "portuguese");

    lervalores();

    exibirvalores();

    bubblesort();

    exibirvalores();

    //teste lógico
    int resultado = buscar();
    if (resultado != -1)
        printf("valor encontrado na %dº posição.\n", resultado + 1);
    else
        printf("número não encontrada.\n");

    //libera a memória
    free(ponteiro);

    return 0;
}

//corpo da funçao bubble sort.
void bubblesort()
{

    for (int i = 0; i < n - 1; i++)
    {
        int j = 0;
        do
        {
        //    exibirvalores();
            if (ponteiro[j] > ponteiro[j + 1])
            {
                int aux = ponteiro[j];
                ponteiro[j] = ponteiro[j + 1];
                ponteiro[j + 1] = aux;
            }

            j++;
        } while (j < n - 1 - i);
    }
}
