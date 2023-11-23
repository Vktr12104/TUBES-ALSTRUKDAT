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

void Load(ListPenyanyi* Penyanyi,MapAlbum* Album, SetLagu* SetLagu, char* NamaFile, QueueLagu* QueueLagu, HistoriLagu* HistoryLagu, ListDinamik ListPlaylist, status *LaguSekarang){
    STARTCOMMAND(Penyanyi,Album,SetLagu,NamaFile);
    ADVWORD();
    if (StrComp(wordToString(currentWord),"-")){
        LaguSekarang->penyanyi = "-";
        LaguSekarang->album = "-";
        LaguSekarang->lagu = "-"                            ;
    }
    else{
        LaguSekarang->penyanyi = wordToString(takewordsemicolon(currentWord, 1));
        LaguSekarang->album = wordToString(takewordsemicolon(currentWord,2));
        LaguSekarang->lagu = wordToString(takewordsemicolon(currentWord,3));
    }

    ADVWORD();
    int JumlahQueueSongs = wordToInt(currentWord);
    for (int i = 0; i<JumlahQueueSongs; i++){
        ADVWORD();

        char* namaP = wordToString(takewordsemicolon(currentWord, 1));
        char* namaA = wordToString(takewordsemicolon(currentWord, 2));
        char* namaL = wordToString(takewordsemicolon(currentWord, 3));

        Cenqueue(QueueLagu, namaP, namaA, namaL);
    }

    ADVWORD();
    HistoriLagu HistoryRAW;
    CreateHist(&HistoryRAW);

    int JumlahHistorySongs = wordToInt(currentWord);

    for (int j = 0; j < JumlahHistorySongs; j++){
        ADVWORD();

        char* namaP = wordToString(takewordsemicolon(currentWord, 1));
        char* namaA = wordToString(takewordsemicolon(currentWord, 2));
        char* namaL = wordToString(takewordsemicolon(currentWord, 3));

        PushLagu(&HistoryRAW, namaP, namaA, namaL);
    }

    for (int j = 0; j < JumlahHistorySongs; j++){
        char* namaP = wordToString(takewordsemicolon(currentWord, 1));
        char* namaA = wordToString(takewordsemicolon(currentWord, 2));
        char* namaL = wordToString(takewordsemicolon(currentWord, 3));

        PopLagu(&HistoryRAW, &namaP, &namaA, &namaL);
        PushLagu(HistoryLagu,namaP, namaA, namaL);
    }

    ADVWORD();
    int jumlahDinPlaylist = wordToInt(currentWord);

    for (int k = 0; k<jumlahDinPlaylist; k++){
        ADVWORD();

        int jumlahLaguPlaylist = wordToInt(takeword(currentWord,1));
        char* namaPlaylist = wordToString((currentWord));
        CreatePlayList (&ListPlaylist.Content[k]);
        for (int l = 0; l < jumlahLaguPlaylist; l++){
            ADVWORD();
            char* namaP = wordToString(takewordsemicolon(currentWord, 1));
            char* namaA = wordToString(takewordsemicolon(currentWord, 2));
            char* namaL = wordToString(takewordsemicolon(currentWord, 3));

            // InsVLastlistb(&(ListPlaylist.Content[k]), namaP, namaA, namaL);
        }
    }
}
