#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <cstring>
#include <fstream>
using namespace std;

int ile;
clock_t start,stop;
double czas;

char znak;

void bubbleSort(int *tab, int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=n-1; j>=1; j--)
        {
            if(tab[j]<tab[j-1])
            {
                int bufor;
                bufor=tab[j-1];
                tab[j-1]=tab[j];
                tab[j]=bufor;
            }
        }
    }
}

void quicksort(int *tablica, int lewy, int prawy)
{
    int v=tablica[(lewy+prawy)/2];
    int i,j,x;
    i=lewy;
    j=prawy;
    do
    {
        while(tablica[i]<v) i++;
        while(tablica[j]>v) j--;
        if(i<=j)
        {
            x=tablica[i];
            tablica[i]=tablica[j];
            tablica[j]=x;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(j>lewy) quicksort(tablica,lewy, j);
    if(i<prawy) quicksort(tablica, i, prawy);
}

void SelectionSort( int *tab3, int ile)
{
    int k;
    for( int i = 0; i < ile; i++ )
    {
        k = i;
        for( int j = i + 1; j < ile; j++ )
        if( tab3[ j ] < tab3[ k ] )
             k = j;

        swap( tab3[ k ], tab3[ i ] );
    }
}

void insertionSort( int *tab4, int ile)
{
    int temp, j;

    for( int i = 1; i < ile; i++ )
    {
        temp = tab4[ i ];

        for( j = i - 1; j >= 0 && tab4[ j ] > temp; j-- )
             tab4[ j + 1 ] = tab4[ j ];

        tab4[ j + 1 ] = temp;
    }
}

void Porownanie()
{
    srand(time(NULL));
    cout<<"ile losowych liczb do posortowania : "<<endl;
    cin>>ile;
    //dynamiczna alokacja tablicy
    int *tablica;
    tablica=new int [ile];

    int *tablica2;
    tablica2=new int [ile];

     int *tablica3;
    tablica3=new int [ile];

         int *tablica4;
    tablica4=new int [ile];
    //wczytywanie losowych liczb do tablicy
        for(int i=0; i<ile; i++)
    {
        tablica[i] = rand()%100000+1;
    }

    //przepisanie tablicy do tablicy2
    for(int i=0; i<ile; i++)
    {
       tablica2[i]=tablica[i];
    }

        for(int i=0; i<ile; i++)
    {
       tablica3[i]=tablica[i];
    }

            for(int i=0; i<ile; i++)
    {
       tablica4[i]=tablica[i];
    }


//        cout<<"Liczby do posortowania : "<<endl;
//        for(int i=0; i<ile; i++)
//        {
//            cout<<tablica2[i]<<",";
//        }

cout<<" Wszystko zalezy od tego:"<<endl;
cout<<"ile elementow sortujemy ?"<<endl;
cout<<"co sortujemy (licznosc dziedziny danych) ?"<<endl;
cout<<"czy sortowane elementy czesto sie powtarzaja ?"<<endl;


        start = clock();
    insertionSort(tablica4 ,ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas insectionSort: "<<czas<<" s"<<endl;
    cout<<"Jest efektywny dla malych liczb, algorytm jest wydajny dla danych wstepnie posortowanych"<<endl;



    start = clock();
    quicksort(tablica2, 0, ile-1);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas quicksort: "<<czas<<" s"<<endl;
    cout<<"sortowanie quicksort jest bardzo szybkie natomiast zajmuje duzo pamieci"<<endl;


    start = clock();
    SelectionSort(tablica3 ,ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas SelectionSort: "<<czas<<" s"<<endl;

        start = clock();
    bubbleSort(tablica,ile);
    stop = clock();
    czas = (double)(stop-start) / CLOCKS_PER_SEC;
    cout<<endl<<"Czas bubblesort: "<<czas<<" s"<<endl;
    cout<<"wolny ale zajmuje malo pamieci"<<endl;



//
//       cout<<"Po posortowaniu: "<<endl;
//        for(int i=0; i<ile; i++)
//        {
//            cout<<tablica[i]<<" ";
//        }


    delete [] tablica;
    delete [] tablica2;
    delete [] tablica3;
    delete [] tablica4;


system("pause");


}
//int bubble()
//{
//    int x;
//    int liczby[x];
//    cout<<"ile liczb do posortowania"<<endl;
//    cin>>x;
//do{
//    cin>>liczby[x];
//    x--;
//}while(x==0);
//cout<<"Przed Posortowaniem : "<<endl;
//for(int i=0;i>=x;x++)
//{
//    cout<<liczby[x]<<" ";
//}
//}


//int Sortowanie()
//{
//    int wybor;
//    cout<<"WYBIERZ METODE SORTOWANIA "<<endl;
//    cout<<"1.quick sort "<<endl;
//    cout<<"2.insertion sort "<<endl;
//    cout<<"3.bubble sort "<<endl;
//    cout<<"4.wyjscie "<<endl;
//    cin>>wybor;
//    switch(wybor)
//    {
//// case 1: quick(); break;
//// case 2: insertion(); break;
// case 3: bubble(); break;
// default: return 0;
//
//
//
//
//
//
//}
//}



int main()
{
    cout<<"Wybierz "<<endl;
    //cout<<"1.Sortowanie "<<endl;
    cout<<"2.Sortowanie losowych liczb(porownanie metod sortowania) "<<endl;
    cout<<"3.Wyjdz "<<endl;
    int choice;
    cin>>choice;
    switch(choice)
    {
        //case 1:Sortowanie();
        case 2:Porownanie(); break;
        case 3: return 0; break;
        default:cout<<"nie ma takiej opcji ";

    }



return 0;
}

//void quick()
//{
//
//}
//void insertion()
//{
//
//}
