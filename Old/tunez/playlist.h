typedef struct playlist {
  char *artist;
  char *title;
  struct playlist* next;
} playlist;

playlist* add_song(char* art, char* tit);
char* song_finder(char *title);
char* artist_finder(char *artist);
int letter_print(char c);
int artist_print(char* art);
int lib_print();
int free_all();

//Primitive Functions
playlist* insert_front(char* art, char* tit, playlist* p);
playlist* insert_order(char* art, char* tit, playlist* p);
int print_list(playlist* p);
playlist* find_song(char* song_to_find, playlist* p);
playlist* find_artist(char* artist_to_find, playlist* p);
int list_length(playlist *p);
playlist* random_song(playlist* p);
playlist* remove_song(playlist* removing, playlist* p);
int free_list(playlist* p);
int mycmp(char* a, char* b);
