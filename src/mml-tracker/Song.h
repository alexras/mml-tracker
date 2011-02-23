#ifndef MMLTRACKER_SONG_H
#define MMLTRACKER_SONG_H

class Song {
public:
  Song();
  
private:
  Sequence sequence;
  
  // Multiplier on tempo
  uint64_t speed;
  
  // Tempo of the song
  uint64_t tempo;
};

#endif // MMLTRACKER_SONG_H
