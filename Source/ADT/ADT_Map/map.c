#include "map.h"
#include "../struc.h"


boolean WordCompare(Title *currentWord, Title *inputWord) {
    int i = 0;
    
    // Continue looping until a null terminator is encountered in one of the strings
    while (currentWord[i] != '\0' && inputWord[i] != '\0') {
        if (currentWord[i] != inputWord[i]) {
            return false; // Words are different
        }
        i++;
    }

    // If we reach here, it means at least one of the strings has ended
    // If both strings end at the same position, they have the same length
    // Otherwise, they have different lengths
    return currentWord[i] == '\0' && inputWord[i] == '\0';
}

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

/* Menambahkan array of character (Title) ST sebagai value elemen Album A dengan Key K. */
void InsertMapLagu(Penyanyi* P, Album* A, Title* ST){
    if (!IsFullMapLagu(*A)){
        int i = 0;
        boolean found = false;
        while (!found && i < (*A).lagu_length){
            if (WordCompare(&(*A).album_lagu[i].nama_lagu[0], &*ST)){ 
                    found = true;
            }
            (*A).album_lagu[i].album_id = IndexOfAlbum(*P, *A);
            i++;  
        }
    }
}
/* Menambahkan array of character (Title) AT sebagai value elemen Penyanyi P dengan Key K. */
void InsertMapAlbum(ListPenyanyi* LP, Penyanyi P, Title AT){
    if (!IsFullMapAlbum(P)){
        int i = 0;
        boolean found = false;
        while (!found && i < (P).album_length){
            if (WordCompare(&(P).album_penyanyi[i].nama_album[0], &AT)){ 
                    found = true;
            }
            (P).album_penyanyi[i].penyanyi_id = IndexOfPenyanyi(*LP, P);
            i++;  
        }
    }
}

/* ### Operator Dasar Map ### */
/* Mendapatkan indeks sebuah Album pada Penyanyi */
int IndexOfAlbum(Penyanyi P, Album A){
    boolean found = false;
    int i = 0;
    while (!found && i < P.album_length){
        if (WordCompare(P.album_penyanyi[i].nama_album, A.nama_album)){
            found = true;
        }
        i++;
    }
    if (found){
        return i - 1;
    } else{
        return IDX_UNDEF;
    }
}
/* Mendapatkan indeks sebuah Penyanyi pada List Penyanyi  */
int IndexOfPenyanyi(ListPenyanyi LP, Penyanyi P){
    boolean found = false;
    int i = 0;
    while (!found && i < LP.penyanyi_length){
        if (WordCompare(LP.penyanyi[i].nama_penyanyi, P.nama_penyanyi)){
            found = true;
        }
        i++;
    }
    if (found){
        return i - 1;
    } else{
        return IDX_UNDEF;
    }
}

void displayMapAlbum(Album* mapAlbum) {
    int i, j;

    for (i = 0; mapAlbum[i].penyanyi_id != INT_UNDEF; i++) {
        printf("Album %d:\n", i + 1);
        printf("Nama Album: %s\n", mapAlbum[i].nama_album);

        printf("Daftar Lagu:\n");
        for (j = 0; j < mapAlbum[i].lagu_length; j++) {
            printf("  Lagu %d: %s\n", j + 1, mapAlbum[i].album_lagu[j].nama_lagu);
        }

        printf("Penyanyi ID: %d\n", mapAlbum[i].penyanyi_id);
        printf("\n");
    }
}