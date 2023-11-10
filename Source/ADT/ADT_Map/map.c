#include "map.h"
#include "../struc.h"


/* ### Konstruktor ### */
/* Membuat Album kosong (A.lagu_length = Nil) sebagai Map dari Lagu */
void CreateMapLagu(Album* A){
    (*A).lagu_length = Nil;
}
/* Membuat Penyanyi kosong (P.album_length = Nil) sebagai Map dari Album */
void CreateMapAlbum(Penyanyi* P){
    (*P).album_length = Nil;
}
/* Mengirim true jika lagu Album A kosong (A.lagu_length = Nil) */
boolean IsEmptyMapLagu(Album A){
    return (A.lagu_length == Nil);
}
/* Mengirim true jika album Penyanyi P kosong (P.album_length = Nil) */
boolean IsEmptyMapAlbum(Penyanyi P){
    return (P.album_length == Nil);
}
/* Mengirim true jika lagu Album A penuh (A.lagu_length = MaxEl) */
boolean IsFullMapLagu(Album A){
    return (A.lagu_length == MaxEl);
}
/* Mengirim true jika album Penyanyi P penuh (P.album_length = MaxEl) */
boolean IsFullMapAlbum(Penyanyi P){
    return (P.album_length == MaxEl);
}
/* Mengembalikan true jika Key K adalah member dari Album A */
boolean IsMemberMapLagu(Album A, Key K){
    if (K < A.lagu_length){
        return true;
    } else {
        return false;
    }
}
/* Mengembalikan true jika Key K adalah member dari Penyanyi P */
boolean IsMemberMapAlbum(Penyanyi P, Key K){
    if (K < P.album_length){
        return true;
    } else {
        return false;
    }
}
/* ### Operator Dasar Map ### */


/* Mengembalikan nilai value Lagu dengan Key K dari Album A */
Lagu ValueMapLagu(Album A, Key K){
    if (!IsEmptyMapLagu(A)){
        if (IsMemberMapLagu(A, K)){
            return A.album_lagu[K];
        } else{
            Lagu L;
            L.nama_lagu[0] = IDX_UNDEF;
            return L;
        }
    }
}
/* Mengembalikan nilai value Album dengan Key K dari Penyanyi P */
Album ValueMapAlbum(Penyanyi P, Key K){
    if (!IsEmptyMapAlbum(P)){
        if (IsMemberMapAlbum(P, K)){
            return P.album_penyanyi[K];
        } else{
            Album A;
            A.lagu_length = IDX_UNDEF;
            return A;
        }
    }
}


/* Menghapus array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void DeleteMapLagu(Album *A, Key K){
    if (!IsEmptyMapLagu(*A)){
        if (IsMemberMapLagu(*A, K)){
            int i = 0;
            for (int j = K; j < (*A).lagu_length - 1; j++){
                (*A).album_lagu[j] = (*A).album_lagu[j + 1];
            }
            (*A).lagu_length--;
        }
    }
}
/* Menghapus array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void DeleteMapAlbum(Penyanyi *P, Key K){
    if (!IsEmptyMapAlbum(*P)){
        if (IsMemberMapAlbum(*P, K)){
            int i = 0;
            for (int j = K; j < (*P).album_length - 1; j++){
                (*P).album_penyanyi[j] = (*P).album_penyanyi[j + 1];
            }
            (*P).album_length--;
        }
    }
}