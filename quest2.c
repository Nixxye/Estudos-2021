#include <stdio.h>
#include <stdlib.h>
//PRECO = {2000, 3000, 5000, 7000,8000,5100,2200,2300,2000,1800}
//DESCONTO= {0.10, 0.15,0.10,0.10,0.10, 0.10, 0.10,0.20,0.3,0}
//LOTE_DESCONTO={50, 50, 10, 20, 20, 100, 10, 20, 10,0}
int main(void)
{
    double preco[10]={2000, 3000, 5000, 7000,8000,5100,2200,2300,2000,1800};
    double desconto[10]={0.10, 0.15,0.10,0.10,0.10, 0.10, 0.10,0.20,0.3,0};
    double ldesc[10]={50, 50, 10, 20, 20, 100, 10, 20, 10,0};
    int posi[10]={0,1,2,3,4,5,6,7,8,9};//salva as posições das variáveis
    int p;
    double troca;
    double preco1[10]={2000, 3000, 5000, 7000,8000,5100,2200,2300,2000,1800};
    int emp;//posição da empresa com menor valor
    double val;//valor da empresa com menor valor
    int emp1;//posição da empresa com maior desconto
    double val1;//valor do maior desconto
    printf("Pelo menor preço:\n");//PELO MENOR PREÇO
    for(int i=0;i<10;i++)
    {
        for(int x = i+1;x<10;x++)
        {
            if(preco1[i]>preco1[x])//muda a posição das variáveis
            {
                troca = preco1[i];
                preco1[i]=preco1[x];
                preco1[x]=troca;
                p=posi[i];//salva as posições
                posi[i]=posi[x];//--
                posi[x]=p;//--
            }
        }
        printf("Empresa %i %1.lf\n",posi[i], preco1[i]);//resposta
        if(i==0)//salva as informações da empresa com o menor valor
        {
            emp = posi[i];
            val = preco1[i];
        }
    }
        double desconto1[10]={0.10, 0.15,0.10,0.10,0.10, 0.10, 0.10,0.20,0.3,0};
        int posi1[10]={0,1,2,3,4,5,6,7,8,9};
        printf("Pelo maior desconto:\n");//PELO MAIOR DESCONTO
        for(int i=0;i<10;i++)
        {
            for(int x = i+1;x<10;x++)
            {
                if(desconto1[i]<desconto1[x])
                {
                    troca = desconto1[i];
                    desconto1[i]=desconto1[x];
                    desconto1[x]=troca;
                    p=posi1[i];//salva as posições
                    posi1[i]=posi1[x];//--
                    posi1[x]=p;//--
                }
                if(i==0)//salva as informações da empresa com o maior desconto;
                {
                    emp1 = posi1[i];
                    val1= desconto1[i];
                }
            }
            printf("Empresa %i %.2lf\n",posi1[i], desconto1[i]);
        }
        //Qual vale mais a pena???
        if(val*ldesc[emp1]>preco[emp1]*val1*ldesc[emp1])//calcula qual vale mais a pena
        {
            printf("A empresa com o maior desconto (%i) vale mais a pena\n",emp1);//r1
        }
        else
        {
            printf("A empresa com o menor valor (%i) vale mais a pena\n",emp);//r2
        }
}