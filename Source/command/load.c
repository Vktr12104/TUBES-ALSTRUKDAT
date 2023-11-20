#include "load.h"

boolean CekLoad(char* NamaFile){
    FILE* cek = fopen(NamaFile,"r");
    if (cek == NULL){
        return false;
    }
    else{
        return true;
    }
}

void Load(ListPenyanyi* Penyanyi,MapAlbum* Album, SetLagu* SetLagu, char* NamaFile, QueueLagu* QueueLagu, HistoriLagu* HistoryLagu, ListD ListPlaylist, status *LaguSekarang){
    STARTCOMMAND(Penyanyi,Album,SetLagu,NamaFile);
}
