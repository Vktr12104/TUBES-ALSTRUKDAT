#include "listdinamis.h"
#include <stdio.h>

int main() {
    ListD playlist = MakeListD();

    Word playlistName1 = {"My Playlist 1"};
    Word playlistName2 = {"My Playlist 2"};
    Word playlistName3 = {"My Playlist 3"};

    InsertFirstListD(&playlist, playlistName1);
    InsertLastListD(&playlist, playlistName2);
    InsertAtListD(&playlist, playlistName3, 2);

    printf("Length of the playlist: %d\n", LengthListD(playlist));

    // Displaying playlist names
    for (IdxType i = FirstIdxListD(playlist); i <= LastIdxListD(playlist); i++) {
        printf("Playlist %d: %s\n", i, playlist.A[i - 1].NamaPlaylist);
    }

    // Testing IsMemberdinamis
    listBerkait playlistToCheck;
    playlistToCheck.NamaPlaylist = playlistName2;
    if (IsMemberdinamis(playlist, playlistToCheck)) {
        printf("%s is a member of the playlist.\n", playlistName2);
    } else {
        printf("%s is not a member of the playlist.\n", playlistName2);
    }

    // Deleting first playlist
    DeleteFirstListD(&playlist);

    // Displaying playlist names after deletion
    printf("\nAfter deleting the first playlist:\n");
    for (IdxType i = FirstIdxListD(playlist); i <= LastIdxListD(playlist); i++) {
        printf("Playlist %d: %s\n", i, playlist.A[i - 1].NamaPlaylist);
    }

    return 0;
}
