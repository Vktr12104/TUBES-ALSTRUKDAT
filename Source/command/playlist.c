#include <stdio.h>
#include "playlist.h"
#include "../ADT/struc.h"
#include "../ADT/ADT_LinkedList/listb.h"
#include "../ADT/ADT_Mesin-Kata/mesinkata.h"
void CreatePlayList() {
    printf("Masukkan nama playlist yang ingin dibuat : \n");
    STARTCOMMAND();  
    int i=0;
    int count=0;
    while(currentCommand.Length>i){
        if(currentCommand.TabWord[i]!=' '){
            count++;
        }i++;
    }
    if (count>=3){
        InsertLast(list_dinamis.A->NamaPlaylist, currentCommand); 
        CreateEmpty(list_dinamis.A[list_dinamis.NEff-1]);
        printf("\n Playlist %s berhasil dibuat!",currentCommand);
    }else{
        printf("Minimal terdapat 3 karakter selain whitespace dalam nama playlist. Silakan coba lagi.");
    }
}

void playlist_add (listBerkait *input, ListPenyanyi lp, MapAlbum m2,SetLagu S) {
    printf("Daftar Penyanyi:\n");
    DisplayListPenyanyi(lp);
    
    printf("Masukkan Nama Penyanyi: ");
    STARTCOMMAND();
    char *comm=wordToString(currentCommand);
    int idxpenyanyi=albumtoidpenyanyi(lp,currentCommand);

    printf("Daftar Album oleh %s:\n",comm);
    displayMapAlbum(m2,idxpenyanyi);    

    printf("Masukkan Nama Album yang dipilih: ");
    STARTCOMMAND();
    char *comm1=wordToString(currentCommand);
    int idxalbum=laguAlbumID(currentCommand,m2);
    
    printf("Daftar Lagu Album %s oleh %s\n : ",comm1,comm);
    DisplaySetLagu(S,idxalbum);
    
    printf("Masukkan ID Lagu yang dipilih: ");
    STARTCOMMAND();
    int idxlagu=wordToInt(currentCommand);
    
    Word namalagu=namalagufromalbum(S,idxalbum,idxlagu);
    char *comm2=wordToString(namalagu);

    printf("Daftar Playlist Pengguna : \n");
    for(int i=0;i<list_dinamis.NEff;i++){
        printf("%d. %s\n",i+1,list_dinamis.A->NamaPlaylist);
    }print("Masukkan ID Playlist yang dipilih :\n");
    STARTCOMMAND();
    int x=wordToInt(currentCommand);
    InsVLast(input->First->infoplaylist,comm,comm1,comm2);
    printf("Lagu dengan judul “%s” pada album %s oleh penyanyi %s berhasil ditambahkan ke dalam playlist.",comm2,comm1,comm);
    
}

void MoveLagu() {
    STARTCOMMAND();
    int x = wordToInt(currentCommand);
    STARTCOMMAND();
    int y = wordToInt(currentCommand);

    if (x >= list_dinamis.NEff || x < 0) {
        printf("Tidak ada playlist dengan ID %d.", x);
    } else {
        listBerkait ply = list_dinamis.A[x];
        address P = First(ply);
        int sum = 0;
        if (P->next == Nil) {
            printf("Playlist %s kosong.",ply.NamaPlaylist);
        } else {
            while (sum != y && P != Nil) {
                sum++;
                P = Next(P);
            }
            if (sum == y) {
                DelP(&ply, Info(P).lagu_playlist); 
                printf("Lagu \"%s\" oleh \"%s\" telah dihapus dari playlist \"%s\"!",P->infoplaylist.lagu_playlist,P->infoplaylist.Penyanyi_playlist,ply.NamaPlaylist);
            } else {
                printf("Tidak ada lagu dengan urutan %d di playlist %s!", y, ply.NamaPlaylist);
            }
        }
    }
}

void SwapLagu(){
    STARTCOMMAND();
    int x=wordToInt(currentCommand);
    STARTCOMMAND();
    int y=wordToInt(currentCommand);
    STARTCOMMAND();
    int z=wordToInt(currentCommand);
    int sum=0;
    Isi_Que ytemp,ztemp;
    if (x>list_dinamis.NEff){
        printf("Tidak ada playlist dengan playlist ID %d",x);
    }else{
        listBerkait ply = list_dinamis.A[x];
        address P = First(ply);
        int count=NbElmt(ply);
        if (y>count || z>count){
            if(y>count){
                printf("Tidak ada lagu dengan urutan %d di playlist %s",y,ply.NamaPlaylist);
            }else {
                printf("Tidak ada lagu dengan urutan %d di playlist %s",z,ply.NamaPlaylist);
            }
        }else{
            while(P!=Nil){
                sum++;
                if(sum==y){
                    ytemp=P->infoplaylist;
                }else if(sum==z){
                    ztemp=P->infoplaylist;
                }P=Next(P);
            }DelP(&ply,ytemp.lagu_playlist);
            //InsertAfter(); // perbaiki InsertAt
            DelP(&ply,ztemp.lagu_playlist);
            //InsertAt();// perbaikin InsertAfter & InsertAt
        }
    }
} 

void DelPlayList(){
    
}