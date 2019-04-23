/*
  nama : dzikri algiffari
  npm:140810180053
  tgl:23/04/2019
*/
#include<iostream>
using namespace std;
struct bola{
  int nodaftar;
  char namatim[20];
  char asaldaerah[20];
  int gol;
  bola* next;
};
typedef bola* pointer;
typedef pointer list;
void createList(list& First){
  First=NULL;
}
void createElmt(pointer& pBaru){
  pBaru= new bola;
  cout<<"Masukan no daftar ="; cin>>pBaru->nodaftar;
  cout<<"Masukan nama tim =";cin.ignore(); cin.getline(pBaru->namatim,20);
  cout<<"Masukan Asal daerah ="; cin.getline(pBaru->asaldaerah,20);
  pBaru->next=NULL;
}
void insertFirst(list& First, pointer pBaru){
  if(First==NULL){
    First=pBaru;
  }
  else{
    pBaru->next=First;
    First=pBaru;
  }
}
void updateGol(list& First){
  pointer pBantu;
  pBantu=First;
  while(pBantu!=NULL){
    cout<<"Masukan Gol :"; cin>>pBantu->gol;
    pBantu=pBantu->next;
  }
}
void traversal(list First){
  pointer pBantu;
  pBantu=First;
  cout<<"NO daftar   Nama tim\tAsal Daerah\tGol"<<endl;
  while(pBantu!=NULL){
    cout<<pBantu->nodaftar<<"\t"<<pBantu->namatim<<"\t"<<pBantu->asaldaerah<<endl;
    pBantu=pBantu->next;
  }
}
void traversalBaru(list First){
  pointer pBantu;
  pBantu=First;
  cout<<"NO daftar\tNama tim\tAsal Daerah\tGol"<<endl;
  while(pBantu!=NULL){
    cout<<pBantu->nodaftar<<"\t\t"<<pBantu->namatim<<"\t"<<pBantu->gol<<endl;
    pBantu=pBantu->next;
  }
}
 void swap(pointer& a,pointer& b){
     int temp = a->gol;
     a->gol = b->gol;
     b->gol = temp;
 }

 void sorting(list& First){
     int swapped, i;
     pointer ptr1;
     pointer lptr = NULL;

     if (First == NULL)
         return;

     do{
         swapped = 0;
         ptr1 = First;

         while(ptr1->next!=lptr){
             if (ptr1->gol < ptr1->next->gol){
                 swap(ptr1,ptr1->next);
                 swapped = 1;
             }
             ptr1 = ptr1->next;
         }
         lptr = ptr1;
     } while(swapped);
 }
/*
chubu miyazakai
furano hokaido
hirado nagasaki minamiwa ehime
toho suginami
nankatsu sizouka
*/

main(){
  pointer pb;
  list q;
  int n;
  cout<<"Masukan Banyak tim :"; cin>>n;
  createList(q);
  for(int i=0;i<n;i++){
    createElmt(pb);
    insertFirst(q,pb);
  }
  traversal(q);
  updateGol(q);
  cout<<"\nupdate setelah gol"<<endl;
  sorting(q);
  traversalBaru(q);
}
