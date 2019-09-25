// Buica Mihai-Victoras 312CB
#include <stdio.h>
void tabla (int N, int M, int x, int y, char v,
 int l1, int l2, int l3, int c1, int c2, int c3){
//Functie de afisare a tablei de joc
    int i, j;
    for (i=0; i<=N+1; i++){
            for (j=0; j<=M+1; j++)           // 0->M+1/N+1 randurile/coloanele necesare delimitarii tablei
                if(i==0 || i==N+1 || j==0 || j==M+1) //Conditia de a se afla in afara spatiului de joc
                    printf("*");
                else 
                    if (i==x && j==y) //pozitia pe care se afla jucatorul
                        printf("%c",v);
                    else
                        if((i==l1 && j==c1) || (i==l2 && j==c2) || (i==l3 && j==c3)) //pozitia obstacolului
                            printf("x");
                        else 
                            printf(" ");
            printf("\n");
    }
}

void miscare (int lJucator, int cJucator, int *lObstacol, int *cObstacol){
//Functie de mutare a obstacolelor mobile   

    //  Obstacol pe aceeasi linie cu jucatorul
    if(lJucator==*lObstacol){
            if(cJucator>*cObstacol)
                *cObstacol+=1;
            else
                if(cJucator<*cObstacol)
                    *cObstacol-=1;
        }
    //  Obstacol pe aceeasi coloana cu jucatorul
    if(cJucator==*cObstacol){  
        if(lJucator>*lObstacol)
            *lObstacol+=1;
        else
            if(lJucator<*lObstacol)
                    *lObstacol-=1;
        }
    //  Obstacol in stanga sus, fata de jucator
    if(*cObstacol<cJucator && *lObstacol<lJucator){
        *cObstacol+=1;
        *lObstacol+=1;
    }
    //  Obstacol in dreapta sus, fata de jucator
    if(*cObstacol>cJucator && *lObstacol<lJucator){
        *cObstacol-=1;
        *lObstacol+=1;
    }
    //  Obstacol in dreapta jos, fata de jucator
    if(*cObstacol>cJucator && *lObstacol>lJucator){
        *cObstacol-=1;
        *lObstacol-=1;
    }
    //  Obstacol in stanga jos, fata de jucator
    if(*cObstacol<cJucator && *lObstacol>lJucator){
        *cObstacol+=1;
        *lObstacol-=1;
    }
}


int main()
{
    // N-linii, M- coloane
    //lJucator,cJucator = linia/coloana jucatorului; 
    //lObstacol, cObstacol= linia/coloana obstacol
    int M, N, lJucator, cJucator, numarObstacole, contorObstacol;
    int lObstacol1, lObstacol2, lObstacol3, cObstacol1, cObstacol2, cObstacol3;
    char tipObstacol1, tipObstacol2, tipObstacol3;  //tipul obstacolului
    char caracterCitit, v;  // caracterul introdus si modul in care se misca
    
    contorObstacol=0;       //contorul pentru miscarea din doua in doua mutari
    
    scanf("%d %d %d %d %d", &N, &M, &cJucator,&lJucator, & numarObstacole);

    if(numarObstacole==0){ //initializarea obstacolelor cu valori neglijabile
        lObstacol1=lObstacol2=lObstacol3=0;
        cObstacol1=cObstacol2=cObstacol3=0;
        tipObstacol1=tipObstacol2=tipObstacol3=' ';
    }
    if(numarObstacole==1){
        scanf("%d %d %c", &lObstacol1, &cObstacol1, &tipObstacol1);
        lObstacol2=lObstacol3=0; //obstacolele nedeclarate primesc valori negijabile
        cObstacol2=cObstacol3=0;
        tipObstacol2=tipObstacol3=' ';
    }
    if(numarObstacole==2){
        scanf("%d %d %c", &lObstacol1, &cObstacol1, &tipObstacol1);
        scanf("%d %d %c", &lObstacol2, &cObstacol2, &tipObstacol2);
        lObstacol3=cObstacol3=0;
        tipObstacol3=' ';
    }
    if(numarObstacole==3){
        scanf("%d %d %c", &lObstacol1, &cObstacol1, &tipObstacol1);
        scanf("%d %d %c", &lObstacol2, &cObstacol2, &tipObstacol2);
        scanf("%d %d %c", &lObstacol3, &cObstacol3, &tipObstacol3);
    }

    v='v';  //directia din afisarea initiala a tablei
    tabla(N,M,lJucator,cJucator,v,lObstacol1,lObstacol2,
          lObstacol3,cObstacol1,cObstacol2,cObstacol3);

    while( lJucator!=N || cJucator!=M){        //Jucatorul nu a ajuns in coltul 
                                                    //din dreapta jos al tablei   
        scanf("%c", &caracterCitit);

        if((caracterCitit>=65 && caracterCitit<=90)||
                (caracterCitit>=97 && caracterCitit<=122)){   //caracterul este litera
            switch (caracterCitit)      //Miscarea personajului
            {
                case 'w':
                    if(lJucator-1>=1)       //Verificare daca mutarea e valida
                    {                           //in caz negativ aceasta nu are loc
                     lJucator-=1;
                        v='^';             //Directia in care se muta jucatorul
                    }
                    break;
                case 's':
                    if(lJucator+1<=N)
                    {
                        lJucator+=1;
                        v='v';             //Directia in care se muta jucatorul
                    }
                    break;
                case 'd':
                    if(cJucator+1<=M)
                    {
                        cJucator+=1;
                        v='>';             //Directia in care se muta jucatorul
                    }
                    break;
                case 'a':
                    if(cJucator-1>=1)
                    {
                        cJucator-=1;
                        v='<';             //Directia in care se muta jucatorul
                    }
                    break;
                case 'q':
                    return 0;      //Incheierea jocului
            }

         contorObstacol+=1;    //Contorizarea mutarii

        if(contorObstacol%2==0){    //Verificare daca este a doua mutare, 
                                            //pentru a se deplasa obstacolul mobil
            if(tipObstacol1=='m')   //Verificarea tipului de obstacol
                    miscare(lJucator, cJucator, &lObstacol1, &cObstacol1);
            if(tipObstacol2=='m')
                    miscare(lJucator, cJucator, &lObstacol2, &cObstacol2);
            if(tipObstacol3=='m')
                    miscare(lJucator, cJucator, &lObstacol3, &cObstacol3);
            }

        if(((lJucator==lObstacol1 && cJucator==cObstacol1) ||
            (lJucator==lObstacol2 && cJucator==cObstacol2) ||
            (lJucator==lObstacol3 && cJucator==cObstacol3))){ //Verificare coliziune 
                printf("GAME OVER\n");
                return 0;
            }
        tabla(N,M,lJucator,cJucator,v,lObstacol1,lObstacol2,
                    lObstacol3,cObstacol1,cObstacol2,cObstacol3);
        }
    }
    printf("GAME COMPLETED\n");
}
