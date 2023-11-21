#ifndef ADTPLAYLIST
#define ADTPLAYLIST
#include "../ADT/ADT_List/listdinamis.h"





void CreatePlayList(ListDinamik *DaftarPlaylist);

void PLAYLISTADDSONG(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist);

void PLAYLISTADDALBUM(ListPenyanyi lp, MapAlbum m2,SetLagu S ,ListDinamik *daftarplaylist);

void PLAYLISTSWAP(ListDinamik *DaftarPlaylist);

void PLAYLISTREMOVE(ListDinamik *DaftarPlaylist);

void PLAYLISTDELETE(ListDinamik *DaftarPlaylist);

#endif