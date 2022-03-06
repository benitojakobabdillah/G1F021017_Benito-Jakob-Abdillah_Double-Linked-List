#include <iostream>
using namespace std;

struct helm{
  string merek, jenis, ukuran;
  helm *prev;
  helm *next;
};

helm *head, *tail, *cur, *newNode, *del, *beforeNode;

void createDoubleLinkedList( string SPT[3] ){
  head = new helm();
  head->merek = SPT[0];
  head->jenis = SPT[1];
  head->ukuran = SPT[2];
  head->prev = NULL;
  head->next = NULL;
  tail = head;
}

int countDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Tidak Ada DLL";
  }else{
    cur = head;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      
      cur = cur->next;
    }
    return jumlah;
  }
}


void addFirst( string SPT[3] ){
  if( head == NULL ){
    cout << "Tidak Lengkap";
  }else{
    newNode = new helm();
    newNode->merek = SPT[0];
    newNode->jenis = SPT[1];
    newNode->ukuran = SPT[2];
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void addLast( string SPT[3] ){
  if( head == NULL ){
    cout << "Belum Dibuat";
  }else{
    newNode = new helm();
    newNode->merek = SPT[0];
    newNode->jenis = SPT[1];
    newNode->ukuran = SPT[2];
    newNode->prev = tail;
    newNode->next = NULL;
    tail->next = newNode;
    tail = newNode;
  }
}


void addMiddle( string SPT[3], int posisi ){
  if( head == NULL ){
    cout << "Belum Dibuat";
  }else{

    if( posisi == 1 ){
      cout << "Tidak Ditengah" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Tidak dalam jangkauan" << endl;
    }else{
      newNode = new helm();
      newNode->merek = SPT[0];
      newNode->jenis = SPT[1];
      newNode->ukuran = SPT[2];
      
      
      cur = head;
      int NO = 1;
      while( NO <  posisi - 1){
        cur = cur->next;
        NO++;
      }

      beforeNode = cur->next;
      newNode->prev = cur;
      newNode->next = beforeNode;
      cur->next = newNode;
      beforeNode->prev = newNode;
    }

  }
}

void removeFirst()
{
  if( head == NULL ){
    cout << "Belum Dibuat";
  }else{
    del = head;
    head = head->next;
    head->prev = NULL;
    delete del;
  }
}


void removeLast()
{
  if( head == NULL ){
    cout << "Belum Dibuat";
  }else{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
  }
}


void removeMiddle(int posisi){
  if( head == NULL ){
    cout << "Belum dibuat";
  }else{
    if( posisi == 1 || posisi == countDoubleLinkedList() ){
      cout << "Posisi bukan posisi tengah!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int NO = 1;
      cur = head;
      while( NO < posisi - 1 ){
        cur = cur->next;
        NO++;
      }
      del = cur->next;
      beforeNode = del->next;
      cur->next = beforeNode;
      beforeNode->prev = cur;
      delete del;
    }
  }
}


void printDoubleLinkedList()
{
  if( head == NULL ){
    cout << "Belum Dibuat";
  }else{
    cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = head;
    while( cur != NULL ){
    	
      cout << "Merek sepatu : " << cur->merek << endl;
      cout << "Jenis sepatu : " << cur->jenis << endl;
      cout << "Ukuran sepatu : " << cur->ukuran << "\n" << endl;
      
      cur = cur->next;
    }
  }
}

int main(){

  string newSPT[3] = {"Shark", "Racing", "100"};
  createDoubleLinkedList(newSPT);

  printDoubleLinkedList();

  string SPT2[3] = {"KYT", "Slow Ride", "90"};

  addFirst( SPT2 );

  printDoubleLinkedList();

  string SPT3[3] = {"INK", "Basic", "95"};

  addLast( SPT3 );

  printDoubleLinkedList();

  string SPT4[3] = {"SHOEI", "Track", "100"};
  addMiddle(SPT4, 3);

  printDoubleLinkedList();

  removeMiddle(2);

  printDoubleLinkedList();
}