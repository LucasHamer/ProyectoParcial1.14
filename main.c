#include <stdio.h>
#include <stdlib.h>

int validar(int ,int ,int );
void ordenar(int [],int [],int );
int buscar(int ,int [],int );

int main()
{
    int codchofer;//1 a 30
    int dia;//1 a 7
    float km,totalkm;//3 a 1000
    int vcom[30]={23,25,45,65,87,97,89,35,32,1,13,15,15,15,17,17,19,15,12,2,33,35,25,25,27,27,29,25,22,7};

    int vchof[30]={0},pos,max,x,i,vrecaudo[30]={0},maxr,maxc,matchofer[7][30]={{0}},vdia[7]={0},solovys=0;

    codchofer=validar(0,30,1);
    while(codchofer!=0)
    {
        dia=validar(1,7,2);
        do{
            printf("Ingrese cantidad de Kilometros: ");
            scanf("%f",&km);
        }while(km<3||km>1000);

        vchof[codchofer-1]+=km;
        pos=buscar(codchofer,vcom,30);
        vrecaudo[pos]+=km*20;

        totalkm+=km;//punto 5

        matchofer[dia-1][codchofer-1]+=vrecaudo[pos];//punto 1

        if(vdia[1]==0&&vdia[2]==0&&vdia[3]==0&&vdia[4]==0&&vdia[5]!=0&&vdia[6]!=0&&vdia[7]==0)//punto 4
        {
            solovys++;
            printf("Solo trabajo viernes y sabado, el chofer: %d\n",codchofer);
        }

        for(i=0;i<7;i++)
        {
            if(vdia[i]==0)
                printf("El chofer %d no trabajo en la semana",vchof[codchofer-1]);//punto 3
        }

        codchofer=validar(0,30,1);
    }
        for(x=0;x<30;x++)
        {
            if(vchof[x]>vchof[x+1])
            {
                max=vchof[x];//punto 2
                maxr=vrecaudo[x];
                maxc=vcom[x];
            }
        }
        ordenar(vrecaudo,vdia,30);
        printf("Dia                 Comision");
            for(i=0;i<7;i++)
            {
                printf("%d                  %d\n",vdia[i],vrecaudo[i]);
            }
        printf("Total de kilometros: %.2f\n",totalkm);
        printf("El chofer que mas horas trabajo es %d\nRecaudo: %d\nCon una comision de: %d\n",max,maxr,maxc);
        printf("Trabajaron solo viernes y sabado: %d\n",solovys);

    return 0;
}
int buscar(int cod,int chof[],int cant)
{
    int pos=-1,x=0;

    while(pos==-1&&x<cant)
    {
        if(cod=chof[x])
            pos=x;
        else
            x++;
    }

    return pos;
};
int validar(int min,int max,int cual)
{
    int dato;

        do{
            if(cual==1)
            printf("Ingrese codigo de chofer: ");
            else
            printf("Ingrese dia: ");
        scanf("%d",&dato);
        }while(dato<min||dato>max);

    return dato;
};
void ordenar(int c[],int d[],int cant)
{
    int sen=0,x,aux,aux1;

    while(sen==0)
    {
        sen=1;
        for(x=0;x<cant-1;x++)
        {
            if(c[x]<c[x+1])
            {
                aux=c[x];
                c[x]=c[x+1];
                c[x+1]=aux;
                aux1=d[x];
                d[x]=d[x+1];
                d[x+1]=aux1;
                sen=0;
            }
        }
        cant=cant-1;
    }
};
