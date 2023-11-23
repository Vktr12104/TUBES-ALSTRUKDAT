#include "load.h"

boolean FileExists(char *fname) {
     FILE *file;
     if ((file = fopen(fname, "r")))
     {
          fclose(file);
          return true;
     }
     return false;
}

void Load(ListPenyanyi * LP, SetLagu *lagu2,MapAlbum *m2,ListDinamik *daftarplaylist, char* NamaFile, QueueLagu* QueueLagu, HistoriLagu* HistoryLagu, status *LaguSekarang){
    
    if (FileExists(NamaFile)){
        startWFile(NamaFile);
        // inisiasi
        Word NamaPenyanyi;
        Word NamaAlbum;
        Word NamaLagu;
        int panjg;
        CreateMapAlbum(&*m2);
        NotPlaying();
        NotPlayingPlaylist();
        *daftarplaylist = CreateLD();
        CreateEmptySetLagu(&*lagu2);
        *LP = MakeListPenyanyi();
        //CreateMapAlbum(&mapAl);
        


        
        int loop = wordToInt(currentWord);
        int album,lagu;
        int number =1;
        int idalbum=1;
        for (int i = 0; i < loop; i++){
            ADVSATUKATA();
            album = currentWord.TabWord[0] - 48;   
            ADVKALIMAT();  
            InsertLast(&*LP, currentWord);
            for (int j = 0; j < album; j++){
            ADVSATUKATA();
            lagu = currentWord.TabWord[0] - 48;
            ADVKALIMAT();
            InsertMapAlbum(&*m2,i,currentWord);
            for (int k = 0; k < lagu; k++)
            {
                ADVKALIMAT();
                InsertSetLagu(&*lagu2,currentWord,number);    
            }
            number++;
            }
            idalbum++;
        }
        ADVWORD();
        displayWord(currentWord);
        if (StrComp(wordToString(currentWord),"-")){
        LaguSekarang->penyanyi = "-";
        LaguSekarang->album = "-";
        LaguSekarang->lagu = "-";
        }
        else{
            LaguSekarang->penyanyi = wordToString(takewordsemicolon(currentWord, 1));
            LaguSekarang->album = wordToString(takewordsemicolon(currentWord,2));
            LaguSekarang->lagu = wordToString(takewordsemicolon(currentWord,3));
        }                          
        
    }
    else {
        printf("Save file tidak ditemukan. WayangWave gagal dijalankan.\n");
    }

    // ADVWORD();
    // int jumlahDinPlaylist = wordToInt(currentWord);

    // for (int k = 0; k<jumlahDinPlaylist; k++){
    //     ADVWORD();

    //     int jumlahLaguPlaylist = wordToInt(takeword(currentWord,1));
    //     char* namaPlaylist = wordToString((currentWord));
    //     CreatePlayList (&ListPlaylist.Content[k]);
    //     for (int l = 0; l < jumlahLaguPlaylist; l++){
    //         ADVWORD();
    //         char* namaP = wordToString(takewordsemicolon(currentWord, 1));
    //         char* namaA = wordToString(takewordsemicolon(currentWord, 2));
    //         char* namaL = wordToString(takewordsemicolon(currentWord, 3));

    //         // InsVLastlistb(&(ListPlaylist.Content[k]), namaP, namaA, namaL);
    //     }
    // }
}
