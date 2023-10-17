#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    int number;
    int vote1;
    int vote2;
    int vote3;
}
candidates;

int main (int argc, string argv[])
{
    if(argc == 1)
    {
        printf("ERROR");
        return 1;
    }
    int s = argc;

    printf("%i\n",s);
    candidates cads[s];
    for(int m = 1; m<s; m++)
    {
        cads[m].vote1 = 0;
        cads[m].vote2 = 0;
        cads[m].vote3 = 0;
        cads[m].name = argv[m];
    }
    int x = get_int("votes: ");
    string e[(x*3)+1];
    int p;
    int r = 0;
    for(int q = 1; q<=x; q++)
    {
        for(int a = 1; a<=3; a++)
        {
            r++;
            e[r]=get_string("Rank %i: ",a);
            p = 0;
            for(int l = 1; l<s; l++)
            {
                if(strcmp(cads[l].name,e[r])==0)
                {
                    p++;
                    if(a==1)
                    {
                        cads[l].vote1++;
                    }
                    if(a==2)
                    {
                        cads[l].vote2++;
                    }
                    if(a==3)
                    {
                        cads[l].vote3++;
                    }
                }
            }
            if(p!=1)
            {
                printf("ERR0R\n");
                return 1;
            }
        }
    }
    int ç ;
    int y = s-1;
    for(int m = 0; m<(s-2);m++)
    {
        ç=1;
        for(int u = 2; u<=y;u++)
        {
            if(cads[ç].vote1<cads[u].vote1)
            {
                ç=u;
            }
        }
        cads[0] = cads[y];
        cads[y] = cads[ç];
        cads[ç] = cads[0];
        y--;
    }
    for(int m = 1; m<s; m++)
    if(cads[s-1].vote1>(x/2))
    {
        printf("candidate %s is the winner!\n", cads[s-1].name);
        return 1;
    }
    if(cads[s-1].vote1==cads[1].vote1)
    {
        printf("Tie\n");
        return 1;
    }
    else
    {
        for(int m = 1; m<s; m++)
        {
            cads[m].vote1 = 0;
            cads[m].vote2 = 0;
            cads[m].vote3 = 0;
        }
        for(int i=2; i<s; i++)
        {
                string q = cads[1].name;
                for(int m = 1; m<=(3*x); m++)
                {
                    if((strcmp(q,e[m]))==0)
                    {
                        if((m%3)==1)
                        {
                            e[m]=e[m+1];
                            e[m+1]=e[m+2];
                            e[m+2] = " ";
                        }
                        if((m%3)==2)
                        {
                            e[m]=e[m+1];
                            e[m+1] = " ";
                        }
                        if((m%3)==0)
                        {
                            e[m]=" ";
                        }
                    }
                }
                for(int m = 1; m<=(3*x); m++)
                {
                    for(int l = 1; l<s; l++)
                    {
                        if(strcmp(cads[l].name,e[m])==0)
                        {
                            if(m%3==1)
                            {
                                cads[l].vote1++;
                            }
                            if(m%3==2)
                            {
                                cads[l].vote2++;
                            }
                            if(m%3==0)
                            {
                                cads[l].vote3++;
                            }
                        }
                    }
                }
                y = s-1;
                for(int m = 0; m<(s-2);m++)
                {
                    ç=1;
                    for(int u = 2; u<=y;u++)
                    {
                        if(cads[ç].vote1<cads[u].vote1)
                        {
                            ç=u;
                        }
                    }
                    cads[0] = cads[y];
                    cads[y] = cads[ç];
                    cads[ç] = cads[0];
                    y--;
                }
                if(cads[s-1].vote1>(x/2))
                {
                    printf("candidate %s is the winner!\n", cads[s-1].name);
                    return 1;
                }
                if((i=s)&&(cads[argc-1].vote1==cads[argc-2].vote1))
                {
                    printf("TIE(allrolls)\n");
                    return 1;
                }
        }
    }
}

