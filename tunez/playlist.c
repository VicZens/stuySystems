#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "playlist.h"

playlist *whole_list[26];

int main() {
  
  return 0;
}

playlist* add_song(char* art, char* tit) { 
  playlist* temp;
  temp = whole_list[art[0]-'a'];

  if (whole_list[art[0]-'a']) {
    printf("O--- %s\n", tit);
    insert_order(art, tit, temp);
    return whole_list[art[0]-'a'];
  } else {
    printf("F--- %s\n", tit);
    whole_list[art[0]-'a'] = insert_front(art, tit, temp);
    return whole_list[art[0]-'a'];
  }
}

char* song_finder(char *title) {
  int curr = 0;
  playlist* temp = whole_list[0];
  
  while(temp) {
    if(!mycmp(title, (*temp).title)) {
      return (*temp).title;
    }
    
    if (!(*temp).next) {
      temp = whole_list[curr++];
    } else {
      temp = temp->next;
    }
  }
}


char* artist_finder(char *artist) {
  playlist* temp = whole_list[artist[0]-'a'];

  while(temp) {
    if (!mycmp(artist, (*temp).artist)) {
      return (*temp).artist;
    }
    temp = temp->next;
  }
}

int letter_print(char c) {
  playlist* temp = whole_list[c-'a'];
  print_list(temp);
  return 0;
}

int artist_print(char* art) {
  playlist* temp = whole_list[art[0]-'a'];
  
  while(temp) {
    if (!mycmp(art, temp->artist)) {
      print_list(temp);
    }
  }

  return 0;
}

int lib_print() {
  int curr = 0;
  playlist* temp;

  while(temp) {
    temp = whole_list[curr];
    print_list(temp);
    curr++;
  }

  return 0;
}

int lib_print() {
  int curr = 0;
  playlist* temp;

  while(temp) {
    temp = whole_list[curr];
    free_list(temp);
    curr++;
  }

  return 0;
}

//Primitive Functions
//Primitive Functions
//Primitive Functions
playlist* insert_front(char* art, char* tit, playlist* p) {
  playlist* temp = (playlist*)malloc(sizeof(playlist));
  
  (*temp).artist = art;
  (*temp).title = tit;
  (*temp).next = p;

  return temp;
}

playlist* insert_order(char* art, char* tit, playlist* p) {
  playlist* temp = (playlist*)malloc(sizeof(playlist));  
  playlist* helper = p->next;
  (*temp).artist = art;
  (*temp).title = tit;

  if(!mycmp((*p).artist, art)) {
    //Artists are the same

    //Is P the only item?
    if(p==whole_list[art[0]-'a'] && !helper) {
      printf("Only Item Run\n\n");
      //Check Titles
      if(mycmp((*p).title, tit)==1) {
	temp->next = p;
	whole_list[art[0]-'a'] = temp;
	return temp;
      } else {
	p->next = temp;
	return temp;
      }
    }
    //P is not the only item.

    //Is the next artist the same?
    if(!mycmp((*helper).artist, art)) {
      printf("Many Items Run\n\n");
      printf("Error 0");
      if(mycmp((*p).title, tit)==-1) {
	printf("Error 1");
	if(!helper) {
	  printf("Error 2");
	  p->next = temp;
	  return temp;
	}
	//Next title is greater?
	if(mycmp((*helper).title, tit)==1) {
	  printf("Error 3");
	  p->next = temp;
	  temp->next = helper;
	  return temp;
	}
	printf("Error 4");
	return insert_order(art, tit, p->next);
      }
    } else {
      printf("Error 5");
      p->next = temp;
      temp->next = helper;
      return temp;
    }
  } else {
    //Artists are different

    //P is the only other item
    if(p==whole_list[art[0]-'a'] && !helper) {
      //Check Artists
      if(mycmp((*p).artist, art)==1) {
	temp->next = p;
	whole_list[art[0]-'a'] = temp;
	return temp;
      } else {
	p->next = temp;
	return temp;
      }
    } else {
      //This artist smaller?
      if(mycmp((*p).artist, art)==-1) {
	//Next artist is greater?
	if(mycmp((*helper).artist, art)==1) {
	  p->next = temp;
	  temp->next = helper;
	  return temp;
	}
	return insert_order(art, tit, p->next);
      }
    }
  }

  return temp;
}

int print_list(playlist* p) {
  while (p) {
    printf("Artist: %s, Title: %s\n", (*p).artist, (*p).title);
    p = (*p).next;
  }
  return 0;
}

playlist* find_song(char* song_to_find, playlist* p) { 
  playlist* temp;
  while(p) {
    if(!mycmp(song_to_find, (*p).title)) {
      return p;
    }
    p = p->next;
  }
  return temp;
}

playlist* find_artist(char* artist_to_find, playlist* p) { 
  playlist* temp;
  while(p) {
    if(!mycmp(artist_to_find, (*p).artist)) {
      return p;
    }
    p = p->next;
  }
  return temp;
}

int list_length(playlist* p) {
  int i = 0;
  while(p) {
    i++;
    p = p->next;
  }
  return i;
}

playlist* random_song(playlist* p) {
  srand(time(NULL));
  int random = rand() % list_length(p);

  while(random) {
    p = p->next;
    random--;
  }

  return p;
}

playlist* remove_song(playlist* removing, playlist* p) {
  playlist* removed;
  while(p) {
    if (p->next == removing) {
      removed = p->next;
      p->next = removed->next;
    }
    p = p->next;
  }
  return removed;
}

int free_list(playlist *i) {
  while (i) {
    free(i);
    i = (*i).next;
  }
  return 0;
}

int mycmp(char* a, char* b) {
  int i = 0;
  while (*(a+i) || *(b+i)) {
    if (*(a+i) > *(b+i))
      return 1;
    if (*(a+i) < *(b+i))
      return -1;
    i++;
  }
  return 0;
}
