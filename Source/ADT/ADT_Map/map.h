#ifndef map_H
#define map_H
#include "../ADT_List/liststatis.h"
#include "../ADT_Mesin-Kata/mesinkata.h"
#include "../struc.h"



/*
typedef struct {
    Title nama_album[MaxEl]; // Maksimal Panjang judul album 100 char
    SetLagu album_lagu; // Banyak Lagu dalam album sebanyak 20 
    int lagu_length;
    int penyanyi_id;
} MapAlbum;
*/

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */


/* Membuat Lagu kosong (P.album_length = Nil) sebagai Map dari Album */
void CreateMapAlbum(MapAlbum *P);


/* Mengirim true jika album Penyanyi P kosong (P.album_length = Nil) */
boolean IsEmptyMapAlbum(MapAlbum P);


/* Mengirim true jika album Penyanyi P penuh (P.album_length = MaxEl) */
//boolean IsFullMapAlbum(Penyanyi P);

/* Mengembalikan true jika Key K adalah member dari Penyanyi P */
boolean IsMemberMapAlbum(MapAlbum P, Word AT);

/* ### Operator Dasar Map ### */





/* Mengembalikan nilai value Album dengan Key K dari Penyanyi P */
//MapAlbum ValueMapAlbum(Penyanyi P, Key K);


/* Menghapus array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
//void DeleteMapAlbum(Penyanyi *P, Key K);

void InsertMapAlbum(MapAlbum *P,valuetype idpenyanyi,Word AT);


//int IndexOfAlbum(Penyanyi P, MapAlbum A);

void displayMapAlbum(MapAlbum P,int idpenyanyi) ;

int albumtoidpenyanyi(ListPenyanyi P,Word nama);

int laguAlbumID(Word input,MapAlbum P);

int jumlahalbumperpenyanyi(MapAlbum P,int idpenyanyi);


#endif