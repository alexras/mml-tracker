#ifndef MMLTRACKER_TRACK_H
#define MMLTRACKER_TRACK_H

#include <stdint.h>
#include <vector>

class Note;

class Track {
public:
  Track();

  void setLength(uint64_t length);
  uint64_t getLength() const;

  const Note* getNotes() const;

  void addNote(Note* note, uint64_t position);

private:
  uint64_t length;

  std::vector<Note*> notes;
};

#endif // MMLTRACKER_TRACK_H
